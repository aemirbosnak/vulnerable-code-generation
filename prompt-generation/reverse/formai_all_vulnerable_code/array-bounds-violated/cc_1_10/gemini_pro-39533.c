//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

typedef struct {
  char *host;
  int port;
  char *username;
  char *password;
} pop3_client_config_t;

typedef struct {
  int sockfd;
  char *response;
  int response_len;
} pop3_client_t;

void pop3_client_init(pop3_client_t *client, pop3_client_config_t *config) {
  client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (client->sockfd == -1) {
    perror("socket() failed");
    exit(1);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(config->port);
  if (inet_pton(AF_INET, config->host, &server_addr.sin_addr) <= 0) {
    perror("inet_pton() failed");
    exit(1);
  }

  if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    exit(1);
  }

  char response[1024];
  int response_len = recv(client->sockfd, response, sizeof(response) - 1, 0);
  if (response_len <= 0) {
    perror("recv() failed");
    exit(1);
  }
  response[response_len] = '\0';
  client->response = strdup(response);
  client->response_len = response_len;
}

void pop3_client_login(pop3_client_t *client, pop3_client_config_t *config) {
  char request[1024];
  sprintf(request, "USER %s\r\n", config->username);
  if (send(client->sockfd, request, strlen(request), 0) < 0) {
    perror("send() failed");
    exit(1);
  }

  char response[1024];
  int response_len = recv(client->sockfd, response, sizeof(response) - 1, 0);
  if (response_len <= 0) {
    perror("recv() failed");
    exit(1);
  }
  response[response_len] = '\0';
  client->response = strdup(response);
  client->response_len = response_len;

  sprintf(request, "PASS %s\r\n", config->password);
  if (send(client->sockfd, request, strlen(request), 0) < 0) {
    perror("send() failed");
    exit(1);
  }

  response_len = recv(client->sockfd, response, sizeof(response) - 1, 0);
  if (response_len <= 0) {
    perror("recv() failed");
    exit(1);
  }
  response[response_len] = '\0';
  client->response = strdup(response);
  client->response_len = response_len;
}

void pop3_client_list(pop3_client_t *client) {
  if (send(client->sockfd, "LIST\r\n", 6, 0) < 0) {
    perror("send() failed");
    exit(1);
  }

  char response[1024];
  int response_len = recv(client->sockfd, response, sizeof(response) - 1, 0);
  if (response_len <= 0) {
    perror("recv() failed");
    exit(1);
  }
  response[response_len] = '\0';
  client->response = strdup(response);
  client->response_len = response_len;
}

void pop3_client_retr(pop3_client_t *client, int message_number) {
  char request[1024];
  sprintf(request, "RETR %d\r\n", message_number);
  if (send(client->sockfd, request, strlen(request), 0) < 0) {
    perror("send() failed");
    exit(1);
  }

  char response[1024];
  int response_len = recv(client->sockfd, response, sizeof(response) - 1, 0);
  if (response_len <= 0) {
    perror("recv() failed");
    exit(1);
  }
  response[response_len] = '\0';
  client->response = strdup(response);
  client->response_len = response_len;
}

void pop3_client_quit(pop3_client_t *client) {
  if (send(client->sockfd, "QUIT\r\n", 6, 0) < 0) {
    perror("send() failed");
    exit(1);
  }

  close(client->sockfd);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <host> <port> <username> <password>\n", argv[0]);
    exit(1);
  }

  pop3_client_config_t config;
  config.host = argv[1];
  config.port = atoi(argv[2]);
  config.username = argv[3];
  config.password = argv[4];

  pop3_client_t client;
  pop3_client_init(&client, &config);
  pop3_client_login(&client, &config);
  pop3_client_list(&client);
  pop3_client_retr(&client, 1);
  pop3_client_quit(&client);

  return 0;
}