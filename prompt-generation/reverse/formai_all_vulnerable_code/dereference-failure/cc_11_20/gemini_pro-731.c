//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server> <port> <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *server = argv[1];
  int port = atoi(argv[2]);
  const char *username = argv[3];
  const char *password = getpass("Password: ");

  SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());
  if (ssl_ctx == NULL) {
    perror("SSL_CTX_new");
    return EXIT_FAILURE;
  }

  SSL *ssl = SSL_new(ssl_ctx);
  if (ssl == NULL) {
    perror("SSL_new");
    return EXIT_FAILURE;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  SSL_set_fd(ssl, sockfd);
  if (SSL_connect(ssl) != 1) {
    perror("SSL_connect");
    return EXIT_FAILURE;
  }

  char buf[1024];
  snprintf(buf, sizeof(buf), "A01 CAPABILITY\r\n");
  if (SSL_write(ssl, buf, strlen(buf)) <= 0) {
    perror("SSL_write");
    return EXIT_FAILURE;
  }

  while (SSL_read(ssl, buf, sizeof(buf)) > 0) {
    printf("%s", buf);
  }

  if (SSL_shutdown(ssl) != 1) {
    perror("SSL_shutdown");
    return EXIT_FAILURE;
  }

  close(sockfd);
  return EXIT_SUCCESS;
}