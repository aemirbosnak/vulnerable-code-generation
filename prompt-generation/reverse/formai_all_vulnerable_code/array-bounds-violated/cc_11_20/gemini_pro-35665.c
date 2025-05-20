//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 4433

int main() {
  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set socket options.
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Bind the socket to the port.
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for connections.
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Initialize the SSL library.
  SSL_library_init();
  SSL_load_error_strings();

  // Create an SSL context.
  SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_server_method());
  if (ctx == NULL) {
    perror("SSL_CTX_new");
    return EXIT_FAILURE;
  }

  // Load the server certificate and private key.
  if (SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM) <= 0) {
    perror("SSL_CTX_use_certificate_file");
    return EXIT_FAILURE;
  }

  if (SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM) <= 0) {
    perror("SSL_CTX_use_PrivateKey_file");
    return EXIT_FAILURE;
  }

  // Accept a connection.
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (clientfd == -1) {
    perror("accept");
    return EXIT_FAILURE;
  }

  // Create an SSL session.
  SSL *session = SSL_new(ctx);
  if (session == NULL) {
    perror("SSL_new");
    return EXIT_FAILURE;
  }

  // Set the file descriptor for the session.
  SSL_set_fd(session, clientfd);

  // Accept the SSL connection.
  if (SSL_accept(session) <= 0) {
    perror("SSL_accept");
    return EXIT_FAILURE;
  }

  // Read the request.
  char request[1024];
  int num_bytes = SSL_read(session, request, sizeof(request) - 1);
  if (num_bytes == -1) {
    perror("SSL_read");
    return EXIT_FAILURE;
  }

  request[num_bytes] = '\0';

  // Parse the request.
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Validate the request.
  if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
    SSL_write(session, "HTTP/1.1 400 Bad Request\r\n\r\n", strlen("HTTP/1.1 400 Bad Request\r\n\r\n"));
    SSL_shutdown(session);
    SSL_free(session);
    close(clientfd);
    return EXIT_FAILURE;
  }

  // Generate the response.
  char response[1024];
  sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>");

  // Write the response.
  SSL_write(session, response, strlen(response));

  // Close the SSL session.
  SSL_shutdown(session);

  // Free the SSL session.
  SSL_free(session);

  // Close the client connection.
  close(clientfd);

  // Free the SSL context.
  SSL_CTX_free(ctx);

  // Close the socket.
  close(sockfd);

  // Clean up the OpenSSL library.
  ERR_free_strings();
  EVP_cleanup();

  return EXIT_SUCCESS;
}