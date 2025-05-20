//Gemma-7B DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024

typedef struct Email {
  char *from;
  char *to;
  char *subject;
  char *body;
} Email;

int main() {
  Email email;
  email.from = malloc(MAX_BUFFER_SIZE);
  email.to = malloc(MAX_BUFFER_SIZE);
  email.subject = malloc(MAX_BUFFER_SIZE);
  email.body = malloc(MAX_BUFFER_SIZE);

  // Connect to the server
  int sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  connect(sockfd, NULL, NULL);

  // Send email data
  printf("Enter from: ");
  scanf("%s", email.from);

  printf("Enter to: ");
  scanf("%s", email.to);

  printf("Enter subject: ");
  scanf("%s", email.subject);

  printf("Enter body: ");
  scanf("%s", email.body);

  char message[MAX_BUFFER_SIZE];
  sprintf(message, "FROM: %s\r\nTO: %s\r\nSUBJECT: %s\r\n\r\n%s", email.from, email.to, email.subject, email.body);

  write(sockfd, message, strlen(message));

  // Receive confirmation
  char reply[MAX_BUFFER_SIZE];
  read(sockfd, reply, MAX_BUFFER_SIZE);

  printf("Server reply: %s\n", reply);

  // Close the socket
  close(sockfd);

  return 0;
}