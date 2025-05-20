//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[BUFFER_SIZE];

  if (argc < 3) {
    printf("Usage: %s hostname port\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }
  memset(&serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

  if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }
  printf("Connected to %s:%d\n", argv[1], portno);

  // Send the initial command to the server
  printf("Sending user command...\n");
  char user_command[BUFFER_SIZE];
  sprintf(user_command, "USER <username>\r\n");
  n = write(sockfd, user_command, strlen(user_command));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  printf("Sent: %s\n", user_command);

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response: %s\n", buffer);

  // Send the password command to the server
  printf("Sending password command...\n");
  char pass_command[BUFFER_SIZE];
  sprintf(pass_command, "PASS <password>\r\n");
  n = write(sockfd, pass_command, strlen(pass_command));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  printf("Sent: %s\n", pass_command);

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response: %s\n", buffer);

  // List messages on the server
  printf("Listing messages on server...\n");
  char list_command[BUFFER_SIZE];
  sprintf(list_command, "LIST\r\n");
  n = write(sockfd, list_command, strlen(list_command));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  printf("Sent: %s\n", list_command);

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response: %s\n", buffer);

  // Quit session
  printf("Quitting session...\n");
  char quit_command[BUFFER_SIZE];
  sprintf(quit_command, "QUIT\r\n");
  n = write(sockfd, quit_command, strlen(quit_command));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  printf("Sent: %s\n", quit_command);

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response: %s\n", buffer);

  // Close connection
  close(sockfd);
  printf("Connection closed\n");

  return 0;
}