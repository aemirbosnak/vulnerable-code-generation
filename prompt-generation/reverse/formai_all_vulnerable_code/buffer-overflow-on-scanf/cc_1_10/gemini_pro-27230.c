//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

// Client Code
void client() {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create a UDP socket
  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(1);
  }

  // Server Address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = INADDR_ANY;

  // A message from the wizard
  char message[1024] = "Greetings, fair server!";

  int msglen = strlen(message);

  // Send the message to the server
  if(sendto(sockfd, (const char *)message, msglen, MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("sendto failed");
    exit(1);
  }

  printf("Client: Message sent.\n");

  // Receive a response from the server
  char buffer[1024];
  socklen_t len = sizeof(servaddr);
  int recvlen = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
  if(recvlen < 0) {
    perror("recvfrom failed");
    exit(1);
  }

  buffer[recvlen] = '\0';
  printf("Client: Received: %s\n", buffer);

  // Close the socket
  close(sockfd);
}

// Server Code
void server() {
  int sockfd;
  struct sockaddr_in servaddr, cliaddr;

  // Create a UDP socket
  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(1);
  }

  // Server Address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the server address
  if(bind(sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("bind failed");
    exit(1);
  }

  // A message from the server
  char message[1024] = "Greetings, brave adventurer!";

  int msglen = strlen(message);

  // Receive a message from the client
  char buffer[1024];
  socklen_t len = sizeof(cliaddr);
  int recvlen = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *) &cliaddr, &len);
  if(recvlen < 0) {
    perror("recvfrom failed");
    exit(1);
  }

  buffer[recvlen] = '\0';
  printf("Server: Received: %s\n", buffer);

  // Send a response to the client
  if(sendto(sockfd, (const char *)message, msglen, MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len) < 0) {
    perror("sendto failed");
    exit(1);
  }

  printf("Server: Message sent.\n");

  // Close the socket
  close(sockfd);
}

int main() {
  int choice;

  printf("1. Client\n2. Server\nEnter your choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      client();
      break;
    case 2:
      server();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}