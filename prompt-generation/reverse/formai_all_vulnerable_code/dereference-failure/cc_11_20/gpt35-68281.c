//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 25
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

  // Check if we have the correct input parameters
  if (argc != 4) {
    printf("Usage: smtp_client <from_email_address> <to_email_address> <message>\n");
    return 1;
  }

  // Get the input parameters
  char *from_email_address = argv[1];
  char *to_email_address = argv[2];
  char *message = argv[3];

  // Get the server name from the to_email_address
  char server_name[100];
  int i;
  for (i = 0; i < strlen(to_email_address); i++) {
    if (to_email_address[i] == '@') {
      strcpy(server_name, &to_email_address[i+1]);
      break;
    }
  }

  // Get the server details using DNS lookup
  struct hostent *server = gethostbyname(server_name);
  if (server == NULL) {
    printf("Could not get server details for %s\n", server_name);
    return 1;
  }

  // Create a TCP socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Could not create socket\n");
    return 1;
  }

  // Set the server address and port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  memcpy(&server_addr.sin_addr, server->h_addr_list[0], server->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Could not connect to server\n");
    return 1;
  }

  // Receive the welcome message from the server
  char buffer[MAX_BUFFER_SIZE];
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Could not receive welcome message from server\n");
    return 1;
  }

  printf("%s\n", buffer);

  // Send the HELO command to the server
  char helo_command[MAX_BUFFER_SIZE];
  sprintf(helo_command, "HELO %s\r\n", server_name);
  if (send(sockfd, helo_command, strlen(helo_command), 0) < 0) {
    printf("Could not send HELO command to server\n");
    return 1;
  }

  // Receive the reply from the server
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Could not receive reply from server\n");
    return 1;
  }

  printf("%s\n", buffer);

  // Send the MAIL FROM command to the server
  char mail_from_command[MAX_BUFFER_SIZE];
  sprintf(mail_from_command, "MAIL FROM:<%s>\r\n", from_email_address);
  if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) < 0) {
    printf("Could not send MAIL FROM command to server\n");
    return 1;
  }

  // Receive the reply from the server
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Could not receive reply from server\n");
    return 1;
  }

  printf("%s\n", buffer);

  // Send the RCPT TO command to the server
  char rcpt_to_command[MAX_BUFFER_SIZE];
  sprintf(rcpt_to_command, "RCPT TO:<%s>\r\n", to_email_address);
  if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
    printf("Could not send RCPT TO command to server\n");
    return 1;
  }

  // Receive the reply from the server
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Could not receive reply from server\n");
    return 1;
  }

  printf("%s\n", buffer);

  // Send the DATA command to the server
  char data_command[MAX_BUFFER_SIZE];
  sprintf(data_command, "DATA\r\n");
  if (send(sockfd, data_command, strlen(data_command), 0) < 0) {
    printf("Could not send DATA command to server\n");
    return 1;
  }

  // Receive the reply from the server
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Could not receive reply from server\n");
    return 1;
  }

  printf("%s\n", buffer);

  // Send the email message to the server
  if (send(sockfd, message, strlen(message), 0) < 0) {
    printf("Could not send message to server\n");
    return 1;
  }

  // Send the QUIT command to the server
  char quit_command[MAX_BUFFER_SIZE];
  sprintf(quit_command, "QUIT\r\n");
  if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
    printf("Could not send QUIT command to server\n");
    return 1;
  }

  // Receive the reply from the server
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Could not receive reply from server\n");
    return 1;
  }

  printf("%s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}