//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Usage: %s hostname\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  struct hostent *hostinfo = gethostbyname(hostname);

  if(!hostinfo) {
    printf("Could not find host: %s\n", hostname);
    exit(1);
  }

  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(993);
  server_address.sin_addr = *(struct in_addr*)hostinfo->h_addr;

  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if(socketfd < 0) {
    perror("Could not create socket");
    exit(1);
  }

  if(connect(socketfd, (const struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
    perror("Could not connect to server");
    exit(1);
  }

  char buffer[1024];
  int bytes_read = recv(socketfd, buffer, sizeof(buffer), 0);
  buffer[bytes_read] = '\0';
  printf("Server message: %s\n", buffer);
  
  // Login using USER and PASS commands
  char user[100], pass[100];
  printf("User: ");
  scanf("%s", user);
  char user_msg[200];
  sprintf(user_msg, "USER %s\r\n", user);
  send(socketfd, user_msg, strlen(user_msg), 0);

  bytes_read = recv(socketfd, buffer, sizeof(buffer), 0);
  buffer[bytes_read] = '\0';
  printf("%s\n", buffer);

  printf("Password: ");
  scanf("%s", pass);
  char pass_msg[200];
  sprintf(pass_msg, "PASS %s\r\n", pass);
  send(socketfd, pass_msg, strlen(pass_msg), 0);

  bytes_read = recv(socketfd, buffer, sizeof(buffer), 0);
  buffer[bytes_read] = '\0';
  printf("%s\n", buffer);

  // List all messages
  send(socketfd, "LIST\r\n", 6, 0);
  bytes_read = recv(socketfd, buffer, sizeof(buffer), 0);
  buffer[bytes_read] = '\0';
  printf("%s\n", buffer);

  // Logout
  send(socketfd, "LOGOUT\r\n", 9, 0);
  bytes_read = recv(socketfd, buffer, sizeof(buffer), 0);
  buffer[bytes_read] = '\0';
  printf("%s\n", buffer);

  close(socketfd);

  return 0;
}