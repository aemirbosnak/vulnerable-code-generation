//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 993
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *host = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in server_addr;
  socklen_t server_len = sizeof(server_addr);
  memset(&server_addr, 0, server_len);

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    fprintf(stderr, "socket() failed: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if (connect(sock, (struct sockaddr *)&server_addr, server_len) == -1) {
    fprintf(stderr, "connect() failed: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
  if (!ctx) {
    fprintf(stderr, "SSL_CTX_new() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
    exit(EXIT_FAILURE);
  }

  SSL *ssl = SSL_new(ctx);
  if (!ssl) {
    fprintf(stderr, "SSL_new() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
    exit(EXIT_FAILURE);
  }

  SSL_set_fd(ssl, sock);
  if (SSL_connect(ssl) == -1) {
    fprintf(stderr, "SSL_connect() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
    exit(EXIT_FAILURE);
  }

  printf("Connected to %s:%d\n", host, port);

  char buffer[BUFSIZE];
  int bytes_read;
  while ((bytes_read = SSL_read(ssl, buffer, BUFSIZE)) > 0) {
    printf("%s", buffer);
  }

  if (bytes_read == -1) {
    fprintf(stderr, "SSL_read() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
    exit(EXIT_FAILURE);
  }

  SSL_shutdown(ssl);
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(sock);

  return 0;
}