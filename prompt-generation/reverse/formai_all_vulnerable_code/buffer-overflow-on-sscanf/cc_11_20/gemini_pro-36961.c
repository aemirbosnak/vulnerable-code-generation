//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110
#define MAX_RESPONSE_SIZE 4096

int main() {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  char buffer[MAX_RESPONSE_SIZE];

  /* Create a socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error creating socket\n");
    exit(1);
  }

  /* Set up the server address */
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(POP3_PORT);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  /* Connect to the server */
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error connecting to server\n");
    exit(1);
  }

  /* Send the USER command */
  snprintf(buffer, MAX_RESPONSE_SIZE, "USER %s\r\n", "username");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    fprintf(stderr, "Error sending USER command\n");
    exit(1);
  }

  /* Receive the response */
  n = recv(sockfd, buffer, MAX_RESPONSE_SIZE, 0);
  if (n < 0) {
    fprintf(stderr, "Error receiving response to USER command\n");
    exit(1);
  }

  /* Check the response */
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", buffer);
    exit(1);
  }

  /* Send the PASS command */
  snprintf(buffer, MAX_RESPONSE_SIZE, "PASS %s\r\n", "password");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    fprintf(stderr, "Error sending PASS command\n");
    exit(1);
  }

  /* Receive the response */
  n = recv(sockfd, buffer, MAX_RESPONSE_SIZE, 0);
  if (n < 0) {
    fprintf(stderr, "Error receiving response to PASS command\n");
    exit(1);
  }

  /* Check the response */
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", buffer);
    exit(1);
  }

  /* Send the STAT command */
  snprintf(buffer, MAX_RESPONSE_SIZE, "STAT\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    fprintf(stderr, "Error sending STAT command\n");
    exit(1);
  }

  /* Receive the response */
  n = recv(sockfd, buffer, MAX_RESPONSE_SIZE, 0);
  if (n < 0) {
    fprintf(stderr, "Error receiving response to STAT command\n");
    exit(1);
  }

  /* Check the response */
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", buffer);
    exit(1);
  }

  /* Parse the response */
  int num_messages, total_size;
  sscanf(buffer, "+OK %d %d\r\n", &num_messages, &total_size);

  /* Print the number of messages and the total size */
  printf("Number of messages: %d\n", num_messages);
  printf("Total size: %d\n", total_size);

  /* Send the LIST command */
  snprintf(buffer, MAX_RESPONSE_SIZE, "LIST\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    fprintf(stderr, "Error sending LIST command\n");
    exit(1);
  }

  /* Receive the response */
  n = recv(sockfd, buffer, MAX_RESPONSE_SIZE, 0);
  if (n < 0) {
    fprintf(stderr, "Error receiving response to LIST command\n");
    exit(1);
  }

  /* Check the response */
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", buffer);
    exit(1);
  }

  /* Parse the response */
  int message_number, message_size;
  while (sscanf(buffer, "+OK %d %d\r\n", &message_number, &message_size) > 0) {
    /* Print the message number and the message size */
    printf("Message number: %d\n", message_number);
    printf("Message size: %d\n", message_size);

    /* Receive the message */
    n = recv(sockfd, buffer, message_size, 0);
    if (n < 0) {
      fprintf(stderr, "Error receiving message\n");
      exit(1);
    }

    /* Print the message */
    printf("%s\n", buffer);
  }

  /* Send the QUIT command */
  snprintf(buffer, MAX_RESPONSE_SIZE, "QUIT\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    fprintf(stderr, "Error sending QUIT command\n");
    exit(1);
  }

  /* Receive the response */
  n = recv(sockfd, buffer, MAX_RESPONSE_SIZE, 0);
  if (n < 0) {
    fprintf(stderr, "Error receiving response to QUIT command\n");
    exit(1);
  }

  /* Check the response */
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", buffer);
    exit(1);
  }

  /* Close the socket */
  close(sockfd);

  return 0;
}