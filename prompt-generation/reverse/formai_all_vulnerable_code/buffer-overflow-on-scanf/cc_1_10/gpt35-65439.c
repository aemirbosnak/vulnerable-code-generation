//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 995
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("Usage: ./pop3_client <server> <username>\n");
    exit(1);
  }
  
  // Create a TCP socket
  int socket_fd;
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  
  if (socket_fd == -1) {
    perror("Error: Failed to create socket");
    exit(1);
  }
  
  // Connect to the POP3 server
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(POP3_PORT);
  inet_pton(AF_INET, argv[1], &(server_address.sin_addr));
  
  int connect_success = connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address));
  
  if (connect_success == -1) {
    perror("Error: Failed to connect to server");
    exit(1);
  }
  
  // Receive server greeting
  char buffer[BUFFER_SIZE];
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  printf("%s", buffer);
  
  // Send USER command
  char user_command[BUFFER_SIZE];
  snprintf(user_command, BUFFER_SIZE, "USER %s\r\n", argv[2]);
  send(socket_fd, user_command, strlen(user_command), 0);
  
  // Receive response to USER command
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  printf("%s", buffer);
  
  // Prompt for password and send PASS command
  char* password;
  printf("Enter password: ");
  scanf("%ms", &password);
  
  char pass_command[BUFFER_SIZE];
  snprintf(pass_command, BUFFER_SIZE, "PASS %s\r\n", password);
  send(socket_fd, pass_command, strlen(pass_command), 0);
  
  // Receive response to PASS command and check for success
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  if (strncmp(buffer, "+OK", 3) != 0) {
    printf("%s", buffer);
    exit(1);
  }
  
  printf("%s", buffer);
  
  // Send LIST command
  char list_command[] = "LIST\r\n";
  send(socket_fd, list_command, strlen(list_command), 0);
  
  // Receive response to LIST command
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  printf("%s", buffer);
  
  // Send QUIT command
  char quit_command[] = "QUIT\r\n";
  send(socket_fd, quit_command, strlen(quit_command), 0);
  
  // Receive server farewell
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  printf("%s", buffer);
  
  // Close the socket
  close(socket_fd);
  
  return 0;
}