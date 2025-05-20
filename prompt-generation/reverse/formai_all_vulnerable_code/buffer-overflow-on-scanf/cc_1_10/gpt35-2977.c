//FormAI DATASET v1.0 Category: Client Server Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

void client(int clientSock) {
  char clientMsg[MAX_MSG_LEN] = {0};
  printf("Enter message to send to server: ");
  fgets(clientMsg, MAX_MSG_LEN, stdin); // Get client message from user input
  send(clientSock, clientMsg, strlen(clientMsg), 0); // Send message to server
  printf("Message Sent\n");
}

void server(int serverSock) {
  char serverMsg[MAX_MSG_LEN] = {0};
  int readVal = read(serverSock, serverMsg, MAX_MSG_LEN); // Receive message from client
  printf("Message Received: %s\n", serverMsg);
}

int main(int argc, char const *argv[]) {
  int serverSock = 0, clientSock = 0;
  struct sockaddr_in servAddr;
  struct sockaddr_in cliAddr;
  int addrLen = sizeof(servAddr);

  // Create socket file descriptor
  if ((serverSock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    return 1;
  }

  // Set server socket properties
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
  servAddr.sin_port = htons(PORT);

  // Bind the socket to the specified IP address and port
  if (bind(serverSock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
    perror("Socket bind failed");
    return 1;
  }

  // Listen for incoming client connection requests
  if (listen(serverSock, 3) < 0) {
    perror("Socket listen failed");
    return 1;
  }

  // Accept incoming client connection request
  if ((clientSock = accept(serverSock, (struct sockaddr *)&cliAddr, (socklen_t*)&addrLen)) < 0) {
    perror("Socket accept failed");
    return 1;
  }

  // Prompt user to choose between server and client mode
  char mode;
  printf("Enter 'S' for server mode, 'C' for client mode: ");
  scanf("%c", &mode);
  getchar(); // Consume newline character left by scanf

  if (mode == 'S') { // Server mode
    while (1) {
      server(clientSock); // Receive message from connected client
    }
  } else if (mode == 'C') { // Client mode
    client(clientSock); // Send message to connected server
  } else {
    printf("Invalid mode selected. Exiting...\n");
    return 1;
  }
  
  close(clientSock);
  close(serverSock);
  return 0;
}