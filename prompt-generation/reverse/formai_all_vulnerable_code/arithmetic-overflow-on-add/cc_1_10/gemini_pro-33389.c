//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_USERS 100

struct user {
  char username[32];
  int socket_fd;
};

struct chat_server {
  int socket_fd;
  struct user users[MAX_USERS];
  int num_users;
};

int create_socket() {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    exit(1);
  }
  return socket_fd;
}

void bind_socket(int socket_fd, int port) {
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);
  if (bind(socket_fd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(1);
  }
}

void listen_socket(int socket_fd) {
  if (listen(socket_fd, 5) == -1) {
    perror("listen");
    exit(1);
  }
}

int accept_connection(int socket_fd) {
  struct sockaddr_in addr;
  socklen_t addr_len = sizeof(addr);
  int new_socket_fd = accept(socket_fd, (struct sockaddr *) &addr, &addr_len);
  if (new_socket_fd == -1) {
    perror("accept");
    exit(1);
  }
  return new_socket_fd;
}

void add_user(struct chat_server *server, int socket_fd) {
  char username[32];
  recv(socket_fd, username, sizeof(username), 0);
  strcpy(server->users[server->num_users].username, username);
  server->users[server->num_users].socket_fd = socket_fd;
  server->num_users++;
}

void remove_user(struct chat_server *server, int socket_fd) {
  int i;
  for (i = 0; i < server->num_users; i++) {
    if (server->users[i].socket_fd == socket_fd) {
      break;
    }
  }
  if (i != server->num_users) {
    server->num_users--;
    for (int j = i; j < server->num_users; j++) {
      server->users[j] = server->users[j + 1];
    }
  }
}

void broadcast_message(struct chat_server *server, char *message) {
  int i;
  for (i = 0; i < server->num_users; i++) {
    send(server->users[i].socket_fd, message, strlen(message), 0);
  }
}

int main() {
  struct chat_server server;
  server.socket_fd = create_socket();
  bind_socket(server.socket_fd, PORT);
  listen_socket(server.socket_fd);

  while (1) {
    int new_socket_fd = accept_connection(server.socket_fd);
    add_user(&server, new_socket_fd);
    char welcome_message[] = "Welcome to the chat server!\n";
    send(new_socket_fd, welcome_message, strlen(welcome_message), 0);
    broadcast_message(&server, "A new user has joined the chat!");

    while (1) {
      char message[1024];
      memset(message, 0, sizeof(message));
      recv(new_socket_fd, message, sizeof(message), 0);
      if (strcmp(message, "/quit") == 0) {
        remove_user(&server, new_socket_fd);
        broadcast_message(&server, "A user has left the chat.");
        break;
      } else {
        broadcast_message(&server, message);
      }
    }
  }

  close(server.socket_fd);
  return 0;
}