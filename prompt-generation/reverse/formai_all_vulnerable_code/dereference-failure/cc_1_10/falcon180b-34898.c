//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER "localhost"
#define PORT 25
#define BUFFER_SIZE 1024

int main() {
  int sockfd, retval;
  struct sockaddr_in serveraddr;
  char buffer[BUFFER_SIZE];
  time_t current_time;
  struct tm *time_info;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error: Socket creation failed.\n");
    exit(EXIT_FAILURE);
  }

  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(PORT);
  serveraddr.sin_addr.s_addr = inet_addr(SERVER);

  retval = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
  if (retval == -1) {
    printf("Error: Connection failed.\n");
    exit(EXIT_FAILURE);
  }

  printf("Connected to SMTP server.\n");

  time(&current_time);
  time_info = localtime(&current_time);

  snprintf(buffer, BUFFER_SIZE, "HELO %s\r\n", SERVER);
  send(sockfd, buffer, strlen(buffer), 0);

  snprintf(buffer, BUFFER_SIZE, "MAIL FROM:<%s@%s>%s\r\n", "user", SERVER, time_info->tm_zone);
  send(sockfd, buffer, strlen(buffer), 0);

  snprintf(buffer, BUFFER_SIZE, "RCPT TO:<%s@%s>%s\r\n", "recipient", SERVER, time_info->tm_zone);
  send(sockfd, buffer, strlen(buffer), 0);

  snprintf(buffer, BUFFER_SIZE, "DATA\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  snprintf(buffer, BUFFER_SIZE, "Subject: SMTP Test Message\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  snprintf(buffer, BUFFER_SIZE, "Test message sent at %s\r\n", asctime(time_info));
  send(sockfd, buffer, strlen(buffer), 0);

  snprintf(buffer, BUFFER_SIZE, ".\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  close(sockfd);

  printf("Message sent successfully.\n");

  return 0;
}