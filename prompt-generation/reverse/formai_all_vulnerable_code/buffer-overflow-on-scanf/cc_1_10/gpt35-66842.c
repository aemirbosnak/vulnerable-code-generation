//FormAI DATASET v1.0 Category: Socket programming ; Style: ultraprecise
// This program demonstrates a simple client-server communication using C sockets
// The client sends a message to the server, and the server responds with an acknowledgment message

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int sock = 0;
  struct sockaddr_in serv_addr;
  char message[1024] = {0};
  char buffer[1024] = {0};

  // Creating socket file descriptor
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  // Connect the socket with the server address
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  printf("Enter a message to send to the server: ");
  scanf("%s", message);

  // Send the message to the server
  send(sock, message, strlen(message), 0);
  printf("Message sent to the server\n");

  // Receive the acknowledgment message from the server
  read(sock, buffer, 1024);
  printf("Received acknowledgment from the server: %s\n", buffer);

  // Close the socket
  close(sock);

  return 0;
}