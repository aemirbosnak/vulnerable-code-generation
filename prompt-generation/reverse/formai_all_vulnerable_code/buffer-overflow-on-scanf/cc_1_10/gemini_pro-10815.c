//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 6666

// Client function
void client() {
  char *message = "Top secret mission files for Project Osiris";
  int clientSocket;
  struct sockaddr_in serverAddr;

  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(PORT);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
    perror("Connection failed");
    close(clientSocket);
    exit(EXIT_FAILURE);
  }

  if (send(clientSocket, message, strlen(message), 0) < 0) {
    perror("Message delivery failed");
    close(clientSocket);
    exit(EXIT_FAILURE);
  }

  printf("Delivered secret files to Project Osiris.\n");
  close(clientSocket);
}

// Server function
void server() {
  int serverSocket;
  int newSocket;
  struct sockaddr_in serverAddr;
  struct sockaddr_in clientAddr;
  socklen_t addrSize;
  char buffer[1024];

  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(PORT);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
    perror("Bind failed");
    close(serverSocket);
    exit(EXIT_FAILURE);
  }

  if (listen(serverSocket, 1) < 0) {
    perror("Listen failed");
    close(serverSocket);
    exit(EXIT_FAILURE);
  }

  addrSize = sizeof(clientAddr);
  while(1) {
    newSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &addrSize);
    if (newSocket < 0) {
      perror("Accept failed");
      close(serverSocket);
      exit(EXIT_FAILURE);
    }

    if (recv(newSocket, buffer, 1024, 0) < 0) {
      perror("Receive failed");
      close(newSocket);
      exit(EXIT_FAILURE);
    }

    printf("Received secret files from the Midnight Express Courier Service:\n%s\n", buffer);
    close(newSocket);
  }

  close(serverSocket);
}

int main() {
  int choice;

  printf("Welcome to the Midnight Express Courier Service.\n");
  printf("1. Client (deliver secret files)\n");
  printf("2. Server (receive secret files)\n");
  printf("Choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      client();
      break;
    case 2:
      server();
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  return 0;
}