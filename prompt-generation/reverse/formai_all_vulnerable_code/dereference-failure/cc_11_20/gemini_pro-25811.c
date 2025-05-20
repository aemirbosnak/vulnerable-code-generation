//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <hostname> <port> <message>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the hostname and port number
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Get the IP address of the hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Unknown hostname: %s\n", hostname);
    exit(EXIT_FAILURE);
  }

  // Connect to the SMTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *(struct in_addr *)*host->h_addr_list;
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send the EHLO command
  char ehlo_cmd[100];
  sprintf(ehlo_cmd, "EHLO %s\r\n", hostname);
  if (send(sockfd, ehlo_cmd, strlen(ehlo_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response to the EHLO command
  char buf[256];
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print the response to the EHLO command
  printf("%s", buf);

  // Send the MAIL FROM command
  char mail_from_cmd[100];
  sprintf(mail_from_cmd, "MAIL FROM: <%s>\r\n", argv[3]);
  if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response to the MAIL FROM command
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print the response to the MAIL FROM command
  printf("%s", buf);

  // Send the RCPT TO command
  char rcpt_to_cmd[100];
  sprintf(rcpt_to_cmd, "RCPT TO: <%s>\r\n", argv[4]);
  if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response to the RCPT TO command
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print the response to the RCPT TO command
  printf("%s", buf);

  // Send the DATA command
  char data_cmd[10];
  strcpy(data_cmd, "DATA\r\n");
  if (send(sockfd, data_cmd, strlen(data_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response to the DATA command
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print the response to the DATA command
  printf("%s", buf);

  // Send the message body
  if (send(sockfd, argv[5], strlen(argv[5]), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Send the QUIT command
  char quit_cmd[10];
  strcpy(quit_cmd, "QUIT\r\n");
  if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response to the QUIT command
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print the response to the QUIT command
  printf("%s", buf);

  // Close the socket
  close(sockfd);
}