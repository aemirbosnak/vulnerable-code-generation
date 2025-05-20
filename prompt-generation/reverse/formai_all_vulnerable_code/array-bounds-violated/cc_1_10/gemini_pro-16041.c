//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define BUFFSIZE 4096
#define MAXCONN  10

int connections[MAXCONN];
int num_connections = 0;

void cleanup() {
  for (int i = 0; i < num_connections; i++) {
    close(connections[i]);
  }
  exit(0);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }
 
  int port = atoi(argv[1]);
  
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;
  int server_sock, client_sock;
  
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock == -1) {
    perror("socket");
    exit(1);
  }
  
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(port);
  
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    exit(1);
  }
  
  if (listen(server_sock, MAXCONN) == -1) {
    perror("listen");
    exit(1);
  }
  
  signal(SIGINT, cleanup);
  
  while (1) {
    client_addr_len = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock == -1) {
      perror("accept");
      continue;
    }
    
    if (num_connections == MAXCONN) {
      close(client_sock);
      continue;
    }
    
    connections[num_connections++] = client_sock;
    
    pid_t pid = fork();
    if (pid == 0) {
      close(server_sock);
      
      char request[BUFFSIZE], response[BUFFSIZE];
      int request_len, response_len;
      
      request_len = recv(client_sock, request, BUFFSIZE, 0);
      if (request_len == -1) {
        perror("recv");
        exit(1);
      }
      
      request[request_len] = '\0';
      
      // Parse the request
      char *method = strtok(request, " ");
      char *uri = strtok(NULL, " ");
      char *version = strtok(NULL, "\r\n");
      
      // Send the request to the server
      int server_sock = socket(AF_INET, SOCK_STREAM, 0);
      if (server_sock == -1) {
        perror("socket");
        exit(1);
      }
      
      struct sockaddr_in server_addr;
      memset(&server_addr, 0, sizeof(server_addr));
      server_addr.sin_family = AF_INET;
      server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
      server_addr.sin_port = htons(80);
      
      if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
      }
      
      send(server_sock, request, request_len, 0);
      
      // Receive the response from the server
      response_len = recv(server_sock, response, BUFFSIZE, 0);
      if (response_len == -1) {
        perror("recv");
        exit(1);
      }
      
      response[response_len] = '\0';
      
      // Send the response to the client
      send(client_sock, response, response_len, 0);
      
      close(server_sock);
      close(client_sock);
      
      exit(0);
    }
    
    close(client_sock);
  }
  
  cleanup();
  
  return 0;
}