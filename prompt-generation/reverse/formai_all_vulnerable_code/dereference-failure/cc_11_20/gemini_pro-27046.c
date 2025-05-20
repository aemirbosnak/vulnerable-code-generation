//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXDATASIZE 100
#define FTPSERVERPORT 21

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server IP address> <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *server_ip = argv[1];
  char *filename = argv[2];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(FTPSERVERPORT);
  server_addr.sin_addr.s_addr = inet_addr(server_ip);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send the USER command
  char user_cmd[MAXDATASIZE];
  sprintf(user_cmd, "USER anonymous\r\n");
  if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the server's response
  char server_response[MAXDATASIZE];
  if (recv(sockfd, server_response, MAXDATASIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the PASS command
  char pass_cmd[MAXDATASIZE];
  sprintf(pass_cmd, "PASS ftp@example.com\r\n");
  if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the server's response
  if (recv(sockfd, server_response, MAXDATASIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the TYPE command
  char type_cmd[MAXDATASIZE];
  sprintf(type_cmd, "TYPE I\r\n");
  if (send(sockfd, type_cmd, strlen(type_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the server's response
  if (recv(sockfd, server_response, MAXDATASIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the PASV command
  char pasv_cmd[MAXDATASIZE];
  sprintf(pasv_cmd, "PASV\r\n");
  if (send(sockfd, pasv_cmd, strlen(pasv_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the server's response
  char pasv_response[MAXDATASIZE];
  if (recv(sockfd, pasv_response, MAXDATASIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Extract the IP address and port number from the PASV response
  char *ip_address = strtok(pasv_response, ",");
  char *port_number = strtok(NULL, ",");
  int data_port = atoi(port_number);

  // Create a data socket
  int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (data_sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the data port on the server
  struct sockaddr_in data_server_addr;
  data_server_addr.sin_family = AF_INET;
  data_server_addr.sin_port = htons(data_port);
  data_server_addr.sin_addr.s_addr = inet_addr(ip_address);
  if (connect(data_sockfd, (struct sockaddr *)&data_server_addr, sizeof(data_server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send the RETR command
  char retr_cmd[MAXDATASIZE];
  sprintf(retr_cmd, "RETR %s\r\n", filename);
  if (send(sockfd, retr_cmd, strlen(retr_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the server's response
  if (recv(sockfd, server_response, MAXDATASIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Open a file for writing
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Receive the file data from the server
  char buffer[MAXDATASIZE];
  while (1) {
    int bytes_received = recv(data_sockfd, buffer, MAXDATASIZE, 0);
    if (bytes_received == 0) {
      break;
    }
    fwrite(buffer, 1, bytes_received, fp);
  }

  // Close the file
  fclose(fp);

  // Close the data socket
  close(data_sockfd);

  // Send the QUIT command
  char quit_cmd[MAXDATASIZE];
  sprintf(quit_cmd, "QUIT\r\n");
  if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Close the socket
  close(sockfd);

  return 0;
}