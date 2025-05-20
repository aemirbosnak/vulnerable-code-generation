//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scientific
/* 
  This program is a simple IMAP client implementation that connects to a mail server,
  logs in, and retrieves all messages from a specified folder.

  The program uses the IMAP protocol to interact with the mail server, and relies on 
  the OpenSSL library to establish a secure connection.

  Author: John Doe
  Date: August 20, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {

  // Check command line arguments
  if (argc != 4) {
    printf("Usage: imap_client <server> <username> <password>\n");
    exit(EXIT_FAILURE);
  }

  // Initialize SSL library
  SSL_library_init();
  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();

  // Create SSL context
  SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
  if (ctx == NULL) {
    printf("SSL context creation failed\n");
    goto cleanup;
  }

  // Set up connection details
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  int status = getaddrinfo(argv[1], "imap", &hints, &res);
  if (status != 0) {
    printf("Failed to get server address\n");
    goto cleanup;
  }

  // Connect to mail server
  int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol); 
  if (sock == -1) {
    printf("Failed to create socket\n");
    goto cleanup;
  }

  status = connect(sock, res->ai_addr, res->ai_addrlen);
  if (status == -1) {
    printf("Failed to connect to server\n");
    goto cleanup;
  }

  // Set up SSL connection
  SSL *ssl = SSL_new(ctx);
  if (ssl == NULL) {
    printf("Failed to create SSL structure\n");
    goto cleanup;
  }

  SSL_set_fd(ssl, sock);
  status = SSL_connect(ssl);
  if (status != 1) {
    printf("SSL connection failed\n");
    goto cleanup;
  }

  // Authenticate with mail server
  char command[BUF_SIZE];
  char *response = malloc(BUF_SIZE);
  int recv_size;
  snprintf(command, sizeof(command), "LOGIN %s %s\r\n", argv[2], argv[3]);

  status = SSL_write(ssl, command, strlen(command));
  if (status <= 0) {
    printf("Failed to send LOGIN command\n");
    goto cleanup;
  }

  recv_size = SSL_read(ssl, response, BUF_SIZE);
  if (recv_size <= 0) {
    printf("Failed to receive response\n");
    goto cleanup;
  }

  // Check server response
  if (strstr(response, "OK") == NULL) {
    printf("Authentication failed\n");
    goto cleanup;
  }

  // Select mailbox
  snprintf(command, sizeof(command), "SELECT Inbox\r\n");

  status = SSL_write(ssl, command, strlen(command));
  if (status <= 0) {
    printf("Failed to send SELECT command\n");
    goto cleanup;
  }

  recv_size = SSL_read(ssl, response, BUF_SIZE);
  if (recv_size <= 0) {
    printf("Failed to receive response\n");
    goto cleanup;
  }

  // Check server response
  if (strstr(response, "EXISTS") == NULL) {
    printf("Failed to select mailbox\n");
    goto cleanup;
  }

  // Retrieve messages
  snprintf(command, sizeof(command), "FETCH 1:* BODY[HEADER]\r\n");

  status = SSL_write(ssl, command, strlen(command));
  if (status <= 0) {
    printf("Failed to send FETCH command\n");
    goto cleanup;
  }
  
  do {
    recv_size = SSL_read(ssl, response, BUF_SIZE);
    if (recv_size <= 0) {
      printf("Failed to receive response\n");
      goto cleanup;
    }

    response[recv_size] = '\0';
    printf("%s", response);
  } while (strstr(response, "FETCH completed") == NULL);

cleanup:
  // Clean up and exit
  if (ssl != NULL) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
  }

  if (ctx != NULL) {
    SSL_CTX_free(ctx);
  }

  if (response != NULL) {
    free(response);
  }

  return 0;
}