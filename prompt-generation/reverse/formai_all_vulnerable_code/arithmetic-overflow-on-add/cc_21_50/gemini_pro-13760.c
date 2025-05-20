//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define POP3_PORT 110

int main(int argc, char **argv)
{
  char *host;
  char *user;
  char *pass;

  if (argc < 4) {
    fprintf(stderr, "Usage: %s <host> <user> <pass>\n", argv[0]);
    return EXIT_FAILURE;
  }

  host = argv[1];
  user = argv[2];
  pass = argv[3];

  int sockfd;
  struct sockaddr_in servaddr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct hostent *he = gethostbyname(host);
  if (he == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(POP3_PORT);
  servaddr.sin_addr = *((struct in_addr *)he->h_addr);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buf[1024];

  // Receive welcome message
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send USER command
  snprintf(buf, sizeof(buf), "USER %s\r\n", user);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive USER response
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send PASS command
  snprintf(buf, sizeof(buf), "PASS %s\r\n", pass);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive PASS response
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send STAT command
  snprintf(buf, sizeof(buf), "STAT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive STAT response
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send LIST command
  snprintf(buf, sizeof(buf), "LIST\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive LIST response
  int num_messages;
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  sscanf(buf, "+OK %d messages\r\n", &num_messages);

  for (int i = 0; i < num_messages; i++) {
    // Send RETR command
    snprintf(buf, sizeof(buf), "RETR %d\r\n", i + 1);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
      perror("send");
      return EXIT_FAILURE;
    }

    // Receive RETR response
    int message_size;
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    sscanf(buf, "+OK %d octets\r\n", &message_size);

    // Receive message data
    char *message = malloc(message_size + 1);
    if (message == NULL) {
      perror("malloc");
      return EXIT_FAILURE;
    }

    int received_bytes = 0;
    while (received_bytes < message_size) {
      int n = recv(sockfd, message + received_bytes, message_size - received_bytes, 0);
      if (n == -1) {
        perror("recv");
        return EXIT_FAILURE;
      }
      received_bytes += n;
    }

    message[message_size] = '\0';

    // Print message
    printf("Message %d:\n%s\n", i + 1, message);

    free(message);
  }

  // Send QUIT command
  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive QUIT response
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  close(sockfd);

  return EXIT_SUCCESS;
}