//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
// A Simple Chat Application using Socket Programming.
// This program allows two users to chat with each other.
// The chat begins once both users join the chat room.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

void *sendMessage(void *);
void *receiveMessage(void *);

int main(int argc, char const *argv[]) {
  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char *hello = "Hello from client", buffer[1024] = {0};

  // Create a socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  // Specify socket addresses
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  // Connect the client socket to server socket
  if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  // Join the chat
  printf("Welcome to the Chat Room! Please Enter Your Name: ");
  char name[20];
  scanf("%s", name);
  printf("Hello %s, Wait For The Other User To Join The Chat Room...\n", name);

  // Send message to server
  send(sock, name, strlen(name), 0);

  // Receive message from server
  valread = read(sock, buffer, 1024);
  printf("%s\n", buffer);

  // Create threads
  pthread_t sendThread, receiveThread;

  // Create send thread
  if (pthread_create(&sendThread, NULL, sendMessage, (void *) &sock) < 0) {
    perror("Could not create thread");
    return 1;
  }

  // Create receive thread
  if (pthread_create(&receiveThread, NULL, receiveMessage, (void *) &sock) < 0) {
    perror("Could not create thread");
    return 1;
  }

  // Wait for threads to complete
  pthread_join(sendThread, NULL);
  pthread_join(receiveThread, NULL);

  return 0;
}

// Send message to server thread
void *sendMessage(void *socket) {
  int sock = *(int *) socket;
  char message[1024] = {0};
  while (1) {
    fgets(message, 1024, stdin);
    send(sock, message, strlen(message), 0);
    memset(message, 0, 1024);
  }
}

// Receive message from server thread
void *receiveMessage(void *socket) {
  int sock = *(int *) socket;
  char buffer[1024] = {0};
  while (1) {
    int valread = read(sock, buffer, 1024);
    printf("%s", buffer);
    memset(buffer, 0, 1024);
  }
}