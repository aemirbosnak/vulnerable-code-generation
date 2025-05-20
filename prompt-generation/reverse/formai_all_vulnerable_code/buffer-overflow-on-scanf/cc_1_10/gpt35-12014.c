//FormAI DATASET v1.0 Category: Networking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {

  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char buffer[1024] = {0};
    
  // Creating socket file descriptor
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      printf("Socket creation error.\n");
      return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
    
  // Convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
      printf("Invalid address/ Address not supported.\n");
      return -1;
  }
    
  // Connect to server
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
      printf("Connection failed.\n");
      return -1;
  }
    
  // Peaceful greetings
  printf("Welcome! You have entered a calm and peaceful chatroom.\n");
  printf("Please introduce yourself: ");

  // Get user's name and send to server
  char name[20];
  scanf("%s", name);
  send(sock, name, strlen(name), 0);
    
  // Begin chat loop
  while(1) {

    // Wait for message from other user
    valread = read(sock, buffer, 1024);
      
    // Print message from other user
    printf("%s: %s", name, buffer);
        
    // Get user's response and send to server
    char message[1024];
    printf("%s: ", name);
    scanf("%s", message);
    send(sock, message, strlen(message), 0);
      
  }
  return 0;
}