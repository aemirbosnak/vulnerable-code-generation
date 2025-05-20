//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUF_SIZE 4096

int main(int argc , char *argv[]) {
  if (argc != 4) {
    printf("Usage: ./imap-client [hostname] [port] [username]\n");
    return 1;
  }

  char *hostname = argv[1];
  char *port = argv[2];
  char *username = argv[3];

  struct hostent *server = gethostbyname(hostname);
  if (server == NULL) {
    printf("Error: could not resolve hostname\n");
    return 1;
  }

  int sockfd = socket(AF_INET , SOCK_STREAM , 0);
  if (sockfd < 0) {
    printf("Error: could not create socket\n");
    return 1;
  }

  struct sockaddr_in server_address;
  bzero((char *) &server_address, sizeof(server_address));
  server_address.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
  server_address.sin_port = htons(atoi(port));

  if (connect(sockfd , (struct sockaddr *)&server_address , sizeof(server_address)) < 0) {
    printf("Error: could not connect to server\n");
    return 1;
  }

  char read_buffer[MAX_BUF_SIZE];
  char write_buffer[MAX_BUF_SIZE];
  memset(read_buffer, 0, sizeof(read_buffer));
  memset(write_buffer, 0, sizeof(write_buffer));
  SSL *ssl;

  SSL_load_error_strings();
  SSL_library_init();
  SSL_CTX *ssl_context = SSL_CTX_new(TLSv1_2_client_method());
  if (ssl_context == NULL) {
    printf("Error: could not create SSL context\n");
    return 1;
  }

  ssl = SSL_new(ssl_context);
  if (ssl == NULL) {
    printf("Error: could not create SSL object\n");
    return 1;
  }

  if (!SSL_set_fd(ssl, sockfd)) {
    printf("Error: could not associate SSL object with socket\n");
    return 1;
  }

  if (SSL_connect(ssl) != 1) {
    printf("Error: could not establish SSL connection\n");
    return 1;
  }

  memset(read_buffer, 0, sizeof(read_buffer));
  if (SSL_read(ssl, read_buffer, sizeof(read_buffer) - 1) < 1) {
    printf("Error: could not read from server\n");
    return 1;
  }

  printf("%s\n", read_buffer);

  sprintf(write_buffer, "a1 LOGIN %s\r\n", username);
  if (SSL_write(ssl, write_buffer, strlen(write_buffer)) < 1) {
    printf("Error: could not write to server\n");
    return 1;
  }

  memset(read_buffer, 0, sizeof(read_buffer));
  if (SSL_read(ssl, read_buffer, sizeof(read_buffer) - 1) < 1) {
    printf("Error: could not read from server\n");
    return 1;
  }

  printf("%s\n", read_buffer);

  sprintf(write_buffer, "a2 SELECT INBOX\r\n");
  if (SSL_write(ssl, write_buffer, strlen(write_buffer)) < 1) {
    printf("Error: could not write to server\n");
    return 1;
  }

  memset(read_buffer, 0, sizeof(read_buffer));
  if (SSL_read(ssl, read_buffer, sizeof(read_buffer) - 1) < 1) {
    printf("Error: could not read from server\n");
    return 1;
  }

  printf("%s\n", read_buffer);

  sprintf(write_buffer, "a3 LOGOUT\r\n");
  if (SSL_write(ssl, write_buffer, strlen(write_buffer)) < 1) {
    printf("Error: could not write to server\n");
    return 1;
  }

  memset(read_buffer, 0, sizeof(read_buffer));
  if (SSL_read(ssl, read_buffer, sizeof(read_buffer) - 1) < 1) {
    printf("Error: could not read from server\n");
    return 1;
  }

  printf("%s\n", read_buffer);

  SSL_shutdown(ssl);
  SSL_free(ssl);
  return 0;
}