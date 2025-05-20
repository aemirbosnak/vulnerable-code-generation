//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: artistic
// A symphony of ethereal strings,
// A play of notes, a dance of bytes,
// Welcome to our POP3 client's artistic design.

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

// Brushstrokes of color, our palette unveiled,
// Hues of connection, server details concealed.
typedef struct {
  int sockfd;
  char *host;
  int port;
} Connection;

// A canvas for messages, a fleeting embrace,
// Where words unfold, their contents traced with grace.
typedef struct {
  char *from;
  char *to;
  char *subject;
  char *body;
} Message;

// A harmonious blend of notes and sound,
// Our client's journey, forever unbound.
int main(int argc, char **argv) {
  if (argc < 4) {
    printf("Usage: %s <server> <port> <username> <password>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // A connection's birth, a bridge to the unknown,
  // The server's embrace, our digital home.
  Connection connection;
  connection.host = argv[1];
  connection.port = atoi(argv[2]);
  connection.sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (connection.sockfd == -1) {
    perror("Unable to create socket");
    return EXIT_FAILURE;
  }

  // A touch of elegance, a graceful dance,
  // The connection forged, a serendipitous trance.
  struct hostent *server = gethostbyname(connection.host);
  if (server == NULL) {
    perror("Unable to resolve hostname");
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  server_addr.sin_port = htons(connection.port);

  if (connect(connection.sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Unable to connect");
    return EXIT_FAILURE;
  }

  // A symphony of notes, a gentle caress,
  // Login complete, our presence blessed.
  char buffer[1024];
  recv(connection.sockfd, buffer, sizeof(buffer), 0);
  send(connection.sockfd, "USER ", 5, 0);
  send(connection.sockfd, argv[3], strlen(argv[3]), 0);
  send(connection.sockfd, "\r\n", 2, 0);
  recv(connection.sockfd, buffer, sizeof(buffer), 0);
  send(connection.sockfd, "PASS ", 5, 0);
  send(connection.sockfd, argv[3], strlen(argv[3]), 0);
  send(connection.sockfd, "\r\n", 2, 0);
  recv(connection.sockfd, buffer, sizeof(buffer), 0);

  // A journey of discovery, messages unveiled,
  // Their secrets revealed, their stories unraveled.
  int message_count;
  sscanf(buffer, "+OK %d messages", &message_count);
  for (int i = 0; i < message_count; i++) {
    Message message;
    recv(connection.sockfd, buffer, sizeof(buffer), 0);
    send(connection.sockfd, "RETR ", 5, 0);
    sprintf(buffer, "%d", i + 1);
    send(connection.sockfd, buffer, strlen(buffer), 0);
    send(connection.sockfd, "\r\n", 2, 0);
    recv(connection.sockfd, buffer, sizeof(buffer), 0);
    while (strcmp(buffer, ".\r\n") != 0) {
      if (strstr(buffer, "From: ") != NULL) {
        message.from = strdup(strstr(buffer, "From: ") + 6);
      } else if (strstr(buffer, "To: ") != NULL) {
        message.to = strdup(strstr(buffer, "To: ") + 4);
      } else if (strstr(buffer, "Subject: ") != NULL) {
        message.subject = strdup(strstr(buffer, "Subject: ") + 9);
      } else if (strstr(buffer, "Body: ") != NULL) {
        message.body = strdup(strstr(buffer, "Body: ") + 6);
      }
      recv(connection.sockfd, buffer, sizeof(buffer), 0);
    }
    printf("Message %d\n", i + 1);
    printf("From: %s\n", message.from);
    printf("To: %s\n", message.to);
    printf("Subject: %s\n", message.subject);
    printf("Body: %s\n", message.body);
  }

  // A graceful exit, a harmonious end,
  // The connection closed, our digital thread unbend.
  send(connection.sockfd, "QUIT\r\n", 6, 0);
  recv(connection.sockfd, buffer, sizeof(buffer), 0);
  close(connection.sockfd);

  return EXIT_SUCCESS;
}