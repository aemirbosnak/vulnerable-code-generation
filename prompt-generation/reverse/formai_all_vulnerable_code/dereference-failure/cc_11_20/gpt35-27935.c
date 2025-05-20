//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <server_ip> <port>\n", argv[0]);
    exit(1);
  }
  
  int port = atoi(argv[2]);
  
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket creation failed");
    exit(1);
  }
  
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(port);
  
  int is_connected = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (is_connected < 0) {
    perror("connection failed");
    close(sockfd);
    exit(1);
  }
  
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  int n;
  
  // Read server response
  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("error reading from socket");
    close(sockfd);
    exit(1);
  }
  
  printf("FROM SERVER: %s", buffer);
  memset(buffer, 0, BUFFER_SIZE);
  
  // Send HELO
  char *helo = "HELO test.com\r\n";
  n = send(sockfd, helo, strlen(helo), 0);
  if (n < 0) {
    perror("error sending data");
    close(sockfd);
    exit(1);
  }
  
  // Read server response
  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("error reading from socket");
    close(sockfd);
    exit(1);
  }
  
  printf("FROM SERVER: %s", buffer);
  memset(buffer, 0, BUFFER_SIZE);
  
  // Send MAIL FROM
  char *mail_from = "MAIL FROM: <test@sender.com>\r\n";
  n = send(sockfd, mail_from, strlen(mail_from), 0);
  if (n < 0) {
    perror("error sending data");
    close(sockfd);
    exit(1);
  }
  
  // Read server response
  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("error reading from socket");
    close(sockfd);
    exit(1);
  }
  
  printf("FROM SERVER: %s", buffer);
  memset(buffer, 0, BUFFER_SIZE);
  
  // Send RCPT TO
  char *rcpt_to = "RCPT TO: <test@receiver.com>\r\n";
  n = send(sockfd, rcpt_to, strlen(rcpt_to), 0);
  if (n < 0) {
    perror("error sending data");
    close(sockfd);
    exit(1);
  }
  
  // Read server response
  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("error reading from socket");
    close(sockfd);
    exit(1);
  }
  
  printf("FROM SERVER: %s", buffer);
  memset(buffer, 0, BUFFER_SIZE);
  
  // Send DATA
  char *data = "DATA\r\n";
  n = send(sockfd, data, strlen(data), 0);
  if (n < 0) {
    perror("error sending data");
    close(sockfd);
    exit(1);
  }
  
  // Read server response
  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("error reading from socket");
    close(sockfd);
    exit(1);
  }
  
  printf("FROM SERVER: %s", buffer);
  memset(buffer, 0, BUFFER_SIZE);
  
  // Send message body
  char *message_body = "Subject: Test Email\r\nThis is a test email\r\n.\r\n";
  n = send(sockfd, message_body, strlen(message_body), 0);
  if (n < 0) {
    perror("error sending data");
    close(sockfd);
    exit(1);
  }
  
  // Read server response
  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("error reading from socket");
    close(sockfd);
    exit(1);
  }
  
  printf("FROM SERVER: %s", buffer);
  memset(buffer, 0, BUFFER_SIZE);
  
  // Send QUIT
  char *quit = "QUIT\r\n";
  n = send(sockfd, quit, strlen(quit), 0);
  if (n < 0) {
    perror("error sending data");
    close(sockfd);
    exit(1);
  }
  
  // Read server response
  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("error reading from socket");
    close(sockfd);
    exit(1);
  }
  
  printf("FROM SERVER: %s", buffer);
  
  close(sockfd);
  
  return 0;
}