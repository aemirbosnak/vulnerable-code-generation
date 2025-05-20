//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 21
#define MAX_BUFF_SIZE 1024

// Function to establish a connection to a FTP server
int connect_to_server(char *ip_address) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Failed to create socket");
    exit(1);
  }
  
  // Set server address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr(ip_address);
  
  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to connect to server");
    exit(1);
  }
  
  return sockfd;
}

// Function to send a command to the FTP server
void send_command(int sockfd, char *command) {
  // Send the command to the server
  if (send(sockfd, command, strlen(command), 0) < 0) {
    perror("Failed to send command");
    exit(1);
  }
}

// Function to receive a response from the FTP server
char *receive_response(int sockfd) {
  // Receive the response from the server
  char *response = malloc(MAX_BUFF_SIZE);
  if (recv(sockfd, response, MAX_BUFF_SIZE, 0) < 0) {
    perror("Failed to receive response");
    exit(1);
  }
  
  return response;
}

// Main Function
int main() {
  // Get the IP address of the FTP server
  char ip_address[50];
  printf("Enter the IP address of the FTP server: ");
  scanf("%s", ip_address);

  // Connect to the FTP server
  int sockfd = connect_to_server(ip_address);

  // Receive the welcome message from the server
  char *welcome_msg = receive_response(sockfd);
  printf("%s\n", welcome_msg);

  // Send the user command
  char command[100];
  printf("Enter the FTP command: ");
  scanf("%s", command);

  // Send the command to the server
  send_command(sockfd, command);

  // Receive the response from the server
  char *response = receive_response(sockfd);
  printf("%s\n", response);

  // Close the connection with the server
  close(sockfd);
  free(welcome_msg);
  free(response);

  return 0;
}