//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  int sock_fd;
  struct sockaddr_in server_addr;
  char buffer[1024] = {0};

  sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("Failed to create socket");
    return 1;
  }

  memset(&server_addr, '0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(110);

  if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
    perror("Invalid address/ Address not supported");
    return 1;
  }

  if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Connection failed");
    return 1;
  }

  recv(sock_fd, buffer, 1024, 0);
  printf("%s\n", buffer);

  char username[50], password[50];
  printf("Enter username: ");
  scanf("%s", username);
  printf("Enter password: ");
  scanf("%s", password);

  sprintf(buffer, "USER %s\r\n", username);
  send(sock_fd, buffer, strlen(buffer), 0);
  recv(sock_fd, buffer, 1024, 0);
  printf("%s\n", buffer);

  sprintf(buffer, "PASS %s\r\n", password);
  send(sock_fd, buffer, strlen(buffer), 0);
  recv(sock_fd, buffer, 1024, 0);
  printf("%s\n", buffer);

  sprintf(buffer, "LIST\r\n");
  send(sock_fd, buffer, strlen(buffer), 0);
  recv(sock_fd, buffer, 1024, 0);
  printf("%s\n", buffer);

  sprintf(buffer, "QUIT\r\n");
  send(sock_fd, buffer, strlen(buffer), 0);
  recv(sock_fd, buffer, 1024, 0);
  printf("%s\n", buffer);

  close(sock_fd);

  return 0;
}