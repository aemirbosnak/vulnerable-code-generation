//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define PORT 8080

struct client_data {
  int client_socket;
  struct sockaddr_in client_addr;
};

void handle_client(struct client_data *client) {
  char buffer[BUFFER_SIZE];
  int bytes_received;

  // Receive the HTTP request from the client
  bytes_received = recv(client->client_socket, buffer, BUFFER_SIZE - 1, 0);
  if (bytes_received < 0) {
    perror("Error receiving request");
    close(client->client_socket);
    return;
  }

  buffer[bytes_received] = '\0';

  // Parse the HTTP request
  char *host = strstr(buffer, "Host:");
  if (host == NULL) {
    fprintf(stderr, "Error parsing request: no Host header");
    close(client->client_socket);
    return;
  }

  host += strlen("Host:");
  while (*host == ' ') {
    host++;
  }

  char *port = strstr(buffer, "Port:");
  if (port == NULL) {
    port = "80";
  } else {
    port += strlen("Port:");
    while (*port == ' ') {
      port++;
    }
  }

  char *path = strstr(buffer, "GET ") + 4;
  *strstr(path, " HTTP") = '\0';

  // Connect to the remote server
  int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (remote_socket < 0) {
    perror("Error creating remote socket");
    close(client->client_socket);
    return;
  }

  struct sockaddr_in remote_addr;
  remote_addr.sin_family = AF_INET;
  remote_addr.sin_port = htons(atoi(port));
  remote_addr.sin_addr.s_addr = inet_addr(host);

  if (connect(remote_socket, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
    perror("Error connecting to remote server");
    close(client->client_socket);
    close(remote_socket);
    return;
  }

  // Send the HTTP request to the remote server
  send(remote_socket, buffer, bytes_received, 0);

  // Receive the HTTP response from the remote server
  bytes_received = recv(remote_socket, buffer, BUFFER_SIZE - 1, 0);
  if (bytes_received < 0) {
    perror("Error receiving response");
    close(client->client_socket);
    close(remote_socket);
    return;
  }

  buffer[bytes_received] = '\0';

  // Send the HTTP response to the client
  send(client->client_socket, buffer, bytes_received, 0);

  // Close the client and remote sockets
  close(client->client_socket);
  close(remote_socket);
}

int main() {
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Error creating socket");
    return 1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    return 1;
  }

  if (listen(server_socket, 5) < 0) {
    perror("Error listening");
    return 1;
  }

  while (1) {
    struct client_data client;
    socklen_t client_addr_len = sizeof(client.client_addr);

    client.client_socket = accept(server_socket, (struct sockaddr *)&client.client_addr, &client_addr_len);
    if (client.client_socket < 0) {
      perror("Error accepting connection");
      continue;
    }

    pthread_t thread;
    pthread_create(&thread, NULL, (void *(*)(void *))handle_client, &client);
  }

  close(server_socket);
  return 0;
}