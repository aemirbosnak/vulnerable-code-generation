//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
  int socket_fd;
  struct sockaddr_in server_addr;
  char buffer[BUFFER_SIZE];

  if (argc!= 4) {
    printf("Usage:./ftp_client <IP_address> <username> <password>\n");
    exit(1);
  }

  char *ip_address = argv[1];
  char *username = argv[2];
  char *password = argv[3];

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    printf("Error creating socket\n");
    exit(1);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

  if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Error connecting to server\n");
    exit(1);
  }

  char login_command[50] = "USER ";
  strcat(login_command, username);
  send(socket_fd, login_command, strlen(login_command), 0);

  char password_command[50] = "PASS ";
  strcat(password_command, password);
  send(socket_fd, password_command, strlen(password_command), 0);

  char list_command[20] = "LIST";
  send(socket_fd, list_command, strlen(list_command), 0);

  char buffer_list[BUFFER_SIZE];
  memset(buffer_list, 0, BUFFER_SIZE);

  if (recv(socket_fd, buffer_list, BUFFER_SIZE, 0) == -1) {
    printf("Error receiving list\n");
    exit(1);
  }

  printf("List of files:\n%s", buffer_list);

  close(socket_fd);
  return 0;
}