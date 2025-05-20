#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
  char host[256];
  int port = 25;
  struct sockaddr_in server_addr;
  int sockfd;

  printf("Enter the hostname: ");
  scanf("%s", host);

  // Resolve the hostname
  struct hostent *host_entry = gethostbyname(host);

  // If the hostname resolution failed, exit
  if (host_entry == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

  // If the socket creation failed, exit
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Connect to the server
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = host_entry->h_addr;

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Send a message
  char message[] = "Hello, world!";
  send(sockfd, message, strlen(message), 0);

  // Receive a message
  char received_message[1024];
  int bytes_received = recv(sockfd, received_message, 1024, 0);

  // If the message reception failed, exit
  if (bytes_received < 0) {
    perror("recv");
    exit(1);
  }

  // Print the received message
  printf("Received message: %s", received_message);

  // Close the socket
  close(sockfd);

  return 0;
}
