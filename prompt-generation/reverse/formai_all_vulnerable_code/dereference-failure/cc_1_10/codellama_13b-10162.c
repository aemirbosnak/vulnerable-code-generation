//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: energetic
// Web Server in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);

  if (argc < 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    return 1;
  }

  // Forcefully attaching socket to the port
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    return 1;
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(atoi(argv[1]));

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    return 1;
  }

  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    return 1;
  }

  printf("Web Server started on port %d\n", atoi(argv[1]));

  while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("accept failed");
      return 1;
    }

    // Accept request
    char buffer[1024] = {0};
    int n = read(new_socket, buffer, 1024);

    if (n < 0) {
      perror("read failed");
      return 1;
    }

    // Print request
    printf("Request: %s\n", buffer);

    // Send response
    char response[1024] = "HTTP/1.1 200 OK\r\n\r\n<html><body><h1>Hello World</h1></body></html>\r\n\r\n";
    int m = write(new_socket, response, strlen(response));

    if (m < 0) {
      perror("write failed");
      return 1;
    }

    // Close socket
    close(new_socket);
  }

  return 0;
}