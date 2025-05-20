//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define PORT 8080

int main() {
  // Socket descriptor
  int sockfd;
  // Server address
  struct sockaddr_in server_addr;
  // Client address
  struct sockaddr_in client_addr;
  // Client length
  socklen_t client_len;
  // Buffer for receiving data
  char recv_buf[1024];
  // Buffer for sending data
  char send_buf[1024];

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Socket creation failed");
    exit(1);
  }

  // Set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Bind failed");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) == -1) {
    perror("Listen failed");
    exit(1);
  }

  // Accept a connection
  client_len = sizeof(client_addr);
  if ((sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
    perror("Accept failed");
    exit(1);
  }

  // Receive data from the client
  if (recv(sockfd, recv_buf, 1024, 0) == -1) {
    perror("Recv failed");
    exit(1);
  }

  // Parse the HTTP request
  char *method = strtok(recv_buf, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Check if the request is valid
  if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
    // Send a 400 Bad Request response
    sprintf(send_buf, "HTTP/1.1 400 Bad Request\r\n\r\n");
    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
      perror("Send failed");
      exit(1);
    }
  } else {
    // Send a 200 OK response
    sprintf(send_buf, "HTTP/1.1 200 OK\r\n\r\n");
    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
      perror("Send failed");
      exit(1);
    }

    // Get the host header
    char *host = strtok(recv_buf, "\r\n");
    host = strtok(NULL, "\r\n");

    // Resolve the hostname
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
      // Send a 404 Not Found response
      sprintf(send_buf, "HTTP/1.1 404 Not Found\r\n\r\n");
      if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
        perror("Send failed");
        exit(1);
      }
    } else {
      // Create a socket to connect to the server
      int server_sockfd;
      if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Server socket creation failed");
        exit(1);
      }

      // Set server address
      struct sockaddr_in server_addr;
      server_addr.sin_family = AF_INET;
      server_addr.sin_port = htons(80);
      server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)he->h_addr)));

      // Connect to the server
      if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connect failed");
        exit(1);
      }

      // Send the request to the server
      if (send(server_sockfd, recv_buf, strlen(recv_buf), 0) == -1) {
        perror("Send failed");
        exit(1);
      }

      // Receive the response from the server
      char server_recv_buf[1024];
      if (recv(server_sockfd, server_recv_buf, 1024, 0) == -1) {
        perror("Recv failed");
        exit(1);
      }

      // Send the response to the client
      if (send(sockfd, server_recv_buf, strlen(server_recv_buf), 0) == -1) {
        perror("Send failed");
        exit(1);
      }
    }
  }

  // Close the connection
  close(sockfd);

  return 0;
}