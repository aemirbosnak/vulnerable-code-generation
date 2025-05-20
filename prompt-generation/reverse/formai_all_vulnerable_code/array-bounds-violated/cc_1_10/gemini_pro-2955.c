//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <curl/curl.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
  pthread_t thread;
} connection_t;

typedef struct {
  char *name;
  char *value;
} sensor_data_t;

typedef struct {
  char *name;
  char *value;
  char *unit;
} actuator_data_t;

typedef struct {
  char *name;
  char *value;
  char *unit;
  int min;
  int max;
} threshold_data_t;

connection_t connections[MAX_CONNECTIONS];
int num_connections = 0;
int running = 1;

void *handle_connection(void *arg) {
  connection_t *connection = (connection_t *)arg;
  char buffer[1024];
  int n;

  while (running) {
    n = recv(connection->sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
      break;
    }

    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    char *response = "OK";
    send(connection->sockfd, response, strlen(response), 0);
  }

  close(connection->sockfd);
  return NULL;
}

int add_connection(int sockfd, struct sockaddr_in addr) {
  if (num_connections >= MAX_CONNECTIONS) {
    return -1;
  }

  connections[num_connections].sockfd = sockfd;
  connections[num_connections].addr = addr;
  pthread_create(&connections[num_connections].thread, NULL, handle_connection, &connections[num_connections]);
  num_connections++;

  return 0;
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in addr, cli_addr;
  socklen_t clilen;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return -1;
  }

  if (listen(sockfd, MAX_CONNECTIONS) < 0) {
    perror("listen");
    return -1;
  }

  while (running) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("accept");
      continue;
    }

    add_connection(newsockfd, cli_addr);
  }

  close(sockfd);
  return 0;
}