//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  // Get the server's IP address
  char server_ip[] = "127.0.0.1";
  struct hostent *host = gethostbyname(server_ip);
  if (host == NULL) {
    perror("gethostbyname");
    return 1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(110);
  server_addr.sin_addr = *(struct in_addr *) host->h_addr;
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the USER command
  char user_cmd[100];
  sprintf(user_cmd, "USER your_username\r\n");
  if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server's response
  char server_response[100];
  if (recv(sockfd, server_response, sizeof(server_response), 0) == -1) {
    perror("recv");
    return 1;
  }

  // Send the PASS command
  char pass_cmd[100];
  sprintf(pass_cmd, "PASS your_password\r\n");
  if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server's response
  if (recv(sockfd, server_response, sizeof(server_response), 0) == -1) {
    perror("recv");
    return 1;
  }

  // Send the LIST command
  char list_cmd[] = "LIST\r\n";
  if (send(sockfd, list_cmd, strlen(list_cmd), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server's response
  char list_response[1000];
  if (recv(sockfd, list_response, sizeof(list_response), 0) == -1) {
    perror("recv");
    return 1;
  }

  // Print the list of messages
  printf("%s", list_response);

  // Send the QUIT command
  char quit_cmd[] = "QUIT\r\n";
  if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
    perror("send");
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}