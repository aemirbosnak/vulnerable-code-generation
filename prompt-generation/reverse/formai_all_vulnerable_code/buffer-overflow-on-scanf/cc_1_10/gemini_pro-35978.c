//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Curiosity starts with an inquisitive connection
int talk_socket;

// Primrose ports tickle our fancy
#define PORT 49152

// A whisper into the ether
void whisper(char *message) {
  send(talk_socket, message, strlen(message), 0);
}

// A murmur from the void
char *hear() {
  char *buffer = malloc(1024);
  recv(talk_socket, buffer, 1024, 0);
  return buffer;
}

// The client's quest for connection
void secret_handshake() {
  // A clandestine meeting in the digital realm
  talk_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (talk_socket == -1) {
    printf("Connection woes, alas!\n");
    exit(1);
  }

  // A rendezvous at Primrose Port
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

  // A request for audience
  if (connect(talk_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    printf("Connection woes, alas!\n");
    exit(1);
  }
}

// An exchange of curious whispers
void curious_exchange() {
  while (1) {
    // A query into the void
    char *query = hear();
    printf("%s", query);
    free(query);

    // A response, seasoned with curiosity
    char *reply = malloc(1024);
    printf("Your response, oh curious one: ");
    scanf("%s", reply);
    whisper(reply);
    free(reply);
  }
}

// A farewell whisper
void part_ways() {
  close(talk_socket);
}

int main() {
  secret_handshake();
  curious_exchange();
  part_ways();
  return 0;
}