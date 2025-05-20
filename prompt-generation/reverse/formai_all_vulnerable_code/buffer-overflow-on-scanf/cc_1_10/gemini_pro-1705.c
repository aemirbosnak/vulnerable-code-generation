//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
  char hostname[100], username[100], password[100];
  printf("Embark on a POP3 adventure!\n");
  printf("Enter the server's hostname: ");
  scanf("%s", hostname);
  printf("Enter your email username: ");
  scanf("%s", username);
  printf("Enter your email password: ");
  scanf("%s", password);

  // Let's find the server's location
  struct hostent *server = gethostbyname(hostname);
  if (server == NULL) {
    printf("Oops! Couldn't locate the server.\n");
    return -1;
  }

  // It's time to connect!
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    printf("Darn! Socket creation failed.\n");
    return -1;
  }

  // Let's say hello!
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(110);
  memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Oops! Connection failed.\n");
    close(socket_fd);
    return -1;
  }

  // Let the server know we're here
  char buffer[1024];
  recv(socket_fd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // Time to identify ourselves
  sprintf(buffer, "USER %s\r\n", username);
  send(socket_fd, buffer, strlen(buffer), 0);
  recv(socket_fd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // Now let's prove our worth
  sprintf(buffer, "PASS %s\r\n", password);
  send(socket_fd, buffer, strlen(buffer), 0);
  recv(socket_fd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // Let's list our treasures!
  sprintf(buffer, "LIST\r\n");
  send(socket_fd, buffer, strlen(buffer), 0);
  recv(socket_fd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // Time to say goodbye
  sprintf(buffer, "QUIT\r\n");
  send(socket_fd, buffer, strlen(buffer), 0);
  recv(socket_fd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // That's it! We're done with our POP3 journey
  close(socket_fd);
  return 0;
}