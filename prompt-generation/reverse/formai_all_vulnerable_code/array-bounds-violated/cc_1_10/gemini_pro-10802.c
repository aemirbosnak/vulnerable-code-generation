//GEMINI-pro DATASET v1.0 Category: Networking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  // What's our destiny?
  int destiny = socket(AF_INET, SOCK_STREAM, 0);
  if (destiny == -1) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Where do we want to go?
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(8080);
  address.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Let's connect!
  if (connect(destiny, (struct sockaddr *)&address, sizeof(address)) == -1) {
    perror("Connection failed");
    exit(EXIT_FAILURE);
  }

  // What do we want to say?
  char message[] = "Hello, world!";

  // Let's send it!
  if (send(destiny, message, strlen(message), 0) == -1) {
    perror("Message sending failed");
    exit(EXIT_FAILURE);
  }

  // Let's listen for a reply!
  char buffer[1024];
  int bytes_received = recv(destiny, buffer, 1024, 0);
  if (bytes_received == -1) {
    perror("Message receiving failed");
    exit(EXIT_FAILURE);
  }

  // What did we hear?
  buffer[bytes_received] = '\0';
  printf("Server reply: %s\n", buffer);

  // Let's go back to our own world!
  close(destiny);

  return EXIT_SUCCESS;
}