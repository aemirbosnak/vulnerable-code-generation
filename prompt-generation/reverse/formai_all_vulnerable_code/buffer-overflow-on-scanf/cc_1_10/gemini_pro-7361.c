//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  // Initialize variables
  int sockfd, port_num;
  struct sockaddr_in serv_addr;
  char *host_name;

  // Get the host name
  printf("Enter the hostname: ");
  scanf("%s", host_name);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error creating socket\n");
    return -1;
  }

  // Set the server address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port_num);
  serv_addr.sin_addr.s_addr = inet_addr(host_name);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error connecting to server\n");
    return -1;
  }

  // Send data to the server
  char *data = "Hello, world!";
  if (send(sockfd, data, strlen(data), 0) < 0) {
    printf("Error sending data to server\n");
    return -1;
  }

  // Receive data from the server
  char buffer[1024];
  if (recv(sockfd, buffer, 1024, 0) < 0) {
    printf("Error receiving data from server\n");
    return -1;
  }

  // Print the data received from the server
  printf("Data received from server: %s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}