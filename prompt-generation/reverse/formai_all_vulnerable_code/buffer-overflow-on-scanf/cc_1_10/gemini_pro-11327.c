//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define HOSTNAME_MAX_LEN 256
#define PORT_MAX_LEN 6

typedef struct {
  char hostname[HOSTNAME_MAX_LEN];
  char port[PORT_MAX_LEN];
} EmailServer;

typedef struct {
  char from[256];
  char to[256];
  char subject[256];
  char body[1024];
} EmailMessage;

void get_email_server(EmailServer *server) {
  printf("Enter email server hostname: ");
  scanf("%s", server->hostname);

  printf("Enter email server port: ");
  scanf("%s", server->port);
}

void get_email_message(EmailMessage *message) {
  printf("Enter sender email address: ");
  scanf("%s", message->from);

  printf("Enter recipient email address: ");
  scanf("%s", message->to);

  printf("Enter email subject: ");
  scanf("%s", message->subject);

  printf("Enter email body: ");
  scanf("%s", message->body);
}

int main() {
  EmailServer server;
  EmailMessage message;

  get_email_server(&server);
  get_email_message(&message);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Resolve the hostname
  struct hostent *host = gethostbyname(server.hostname);
  if (host == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }

  // Create the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(server.port));
  memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send the email message
  char buffer[1024];
  sprintf(buffer, "From: %s\nTo: %s\nSubject: %s\n\n%s",
          message.from, message.to, message.subject, message.body);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Close the socket
  close(sockfd);

  return 0;
}