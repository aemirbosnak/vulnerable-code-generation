#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ClientState {
  int sockfd;
  struct sockaddr_in server_addr;
  char buffer[MAX_BUFFER_SIZE];
  pthread_t thread_id;
} ClientState;

void* client_thread(void* state) {
  ClientState* client_state = (ClientState*)state;

  while (1) {
    // Receive data from the server
    int bytes_received = recv(client_state->sockfd, client_state->buffer, MAX_BUFFER_SIZE, 0);

    // Check if the server has closed the connection
    if (bytes_received == 0) {
      break;
    }

    // Send a response to the server
    send(client_state->sockfd, client_state->buffer, bytes_received, 0);
  }

  pthread_exit(NULL);
}

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, htons(21));

  // Connect to the server
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

  // Create a thread for each client
  ClientState client_state;
  client_state.sockfd = sockfd;
  client_state.server_addr = server_addr;
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, client_thread, (void*)&client_state);

  // Wait for the thread to complete
  pthread_join(thread_id, NULL);

  // Close the socket
  close(sockfd);

  return 0;
}
