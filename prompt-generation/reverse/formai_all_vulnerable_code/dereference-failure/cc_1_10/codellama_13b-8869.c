//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define POP3_PORT 110
#define POP3_TIMEOUT 10

int main(int argc, char *argv[]) {
  int sock, ret;
  char buf[256];
  char *host, *username, *password;
  struct sockaddr_in server;

  // Check arguments
  if (argc < 4) {
    printf("Usage: %s <host> <username> <password>\n", argv[0]);
    return 1;
  }

  // Initialize OpenSSL
  SSL_load_error_strings();
  SSL_library_init();

  // Get command-line arguments
  host = argv[1];
  username = argv[2];
  password = argv[3];

  // Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set server address
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(POP3_PORT);
  inet_pton(AF_INET, host, &server.sin_addr);

  // Connect to server
  ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
  if (ret < 0) {
    perror("connect");
    return 1;
  }

  // Set up SSL connection
  SSL *ssl = SSL_new(SSL_CTX_new(TLS_client_method()));
  SSL_set_fd(ssl, sock);
  ret = SSL_connect(ssl);
  if (ret < 0) {
    perror("SSL_connect");
    return 1;
  }

  // Send username and password
  sprintf(buf, "USER %s\r\n", username);
  ret = SSL_write(ssl, buf, strlen(buf));
  if (ret < 0) {
    perror("SSL_write");
    return 1;
  }
  sprintf(buf, "PASS %s\r\n", password);
  ret = SSL_write(ssl, buf, strlen(buf));
  if (ret < 0) {
    perror("SSL_write");
    return 1;
  }

  // Get response
  ret = SSL_read(ssl, buf, sizeof(buf));
  if (ret < 0) {
    perror("SSL_read");
    return 1;
  }
  printf("%s", buf);

  // Close connection
  SSL_shutdown(ssl);
  SSL_free(ssl);
  close(sock);

  return 0;
}