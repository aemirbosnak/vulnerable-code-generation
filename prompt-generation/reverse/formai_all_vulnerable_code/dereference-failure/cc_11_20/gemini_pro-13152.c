//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *server = argv[1];
  char *username = argv[2];
  char *password = argv[3];

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  struct addrinfo *result;
  int status = getaddrinfo(server, NULL, &hints, &result);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return EXIT_FAILURE;
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    freeaddrinfo(result);
    return EXIT_FAILURE;
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
    perror("connect");
    freeaddrinfo(result);
    close(sockfd);
    return EXIT_FAILURE;
  }

  freeaddrinfo(result);

  SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
  if (ctx == NULL) {
    ERR_print_errors_fp(stderr);
    close(sockfd);
    return EXIT_FAILURE;
  }

  SSL *ssl = SSL_new(ctx);
  if (ssl == NULL) {
    ERR_print_errors_fp(stderr);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (SSL_set_fd(ssl, sockfd) == 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (SSL_connect(ssl) != 1) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  char *greeting = NULL;
  size_t len = 0;
  if (SSL_read(ssl, greeting, len) <= 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("%s", greeting);

  char *login = "LOGIN";
  if (SSL_write(ssl, login, strlen(login)) <= 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  char *username_label = "USERNAME";
  if (SSL_write(ssl, username_label, strlen(username_label)) <= 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (SSL_write(ssl, username, strlen(username)) <= 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  char *password_label = "PASSWORD";
  if (SSL_write(ssl, password_label, strlen(password_label)) <= 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (SSL_write(ssl, password, strlen(password)) <= 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  char *ok = "OK";
  if (SSL_read(ssl, ok, len) <= 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("%s\n", ok);

  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(sockfd);

  return EXIT_SUCCESS;
}