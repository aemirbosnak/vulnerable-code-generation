//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main() {
  // Define variables
  int sockfd, n, response_code, message_len = 0, i;
  char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
  const char *hostname = "imap.gmail.com";
  const char *username = "example@gmail.com";
  const char *password = "password";
  struct hostent *server;
  struct sockaddr_in serv_addr;
  SSL_CTX *ctx;
  SSL *ssl;

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Get host by name
  server = gethostbyname(hostname);
  if (server == NULL) {
      perror("ERROR, no such host");
      exit(1);
  }

  // Set server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(993); // IMAP port

  // Connect to server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Initialize SSL
  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();
  ctx = SSL_CTX_new(TLSv1_2_client_method());
  ssl = SSL_new(ctx);
  SSL_set_fd(ssl, sockfd);

  // Start SSL handshake
  if (SSL_connect(ssl) != 1) {
    ERR_print_errors_fp(stderr);
    perror("ERROR during SSL handshake");
    exit(1);
  }

  // Authenticate
  sprintf(message, "A01 LOGIN %s %s\r\n", username, password);
  message_len = strlen(message);
  if (SSL_write(ssl, message, message_len) != message_len) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Read response from server
  bzero(buffer, BUFFER_SIZE);
  if (SSL_read(ssl, buffer, BUFFER_SIZE) <= 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Check response code
  sscanf(buffer, "%*s %d", &response_code);
  if (response_code != 2) {
    perror("ERROR: Invalid credentials");
    exit(1);
  }

  // Fetch inbox
  sprintf(message, "A02 SELECT INBOX\r\n");
  message_len = strlen(message);
  if (SSL_write(ssl, message, message_len) != message_len) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Read response from server
  bzero(buffer, BUFFER_SIZE);
  if (SSL_read(ssl, buffer, BUFFER_SIZE) <= 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Print mailbox status
  printf("%s\n", buffer);

  // Fetch latest email
  sprintf(message, "A03 FETCH 1 BODY[HEADER]\r\n");
  message_len = strlen(message);
  if (SSL_write(ssl, message, message_len) != message_len) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Read response from server
  bzero(buffer, BUFFER_SIZE);
  if (SSL_read(ssl, buffer, BUFFER_SIZE) <= 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Print email header
  printf("%s", buffer);

  // Close socket
  close(sockfd);

  // Clean up SSL
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  ERR_free_strings();

  return 0;
}