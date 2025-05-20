//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8888

void *handle_client(void *client_socket);

int main(int argc, char const *argv[]) {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  pthread_t thread_id;

  // Create socket
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("Could not create socket.\n");
    return 1;
  }

  // Bind socket to port
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Could not bind to port.\n");
    return 1;
  }

  // Listen for connections
  listen(server_socket, 5);
  printf("Server listening on port %d...\n", PORT);

  // Accept connections and handle in separate threads
  while(1) {
    int client_address_size = sizeof(client_address);
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_size)) < 0) {
      printf("Could not accept client connection.\n");
      continue;
    }

    printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
  }

  close(server_socket);
  return 0;
}

void *handle_client(void *client_socket) {
  int socket = *(int*)client_socket;
  char message[256];
  int read_size;

  while((read_size = recv(socket, message, 256, 0)) > 0 ) {
    message[read_size] = '\0';
    printf("Client says: %s\n", message);
    fflush(stdout);

    send(socket, "Message received!", 17, 0);
  }

  if(read_size == 0) {
    printf("Client disconnected.\n");
    fflush(stdout);
  } else if(read_size == -1) {
    printf("Receive failed.\n");
  }

  close(socket);
  return 0;
}