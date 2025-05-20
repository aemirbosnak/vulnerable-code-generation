//GEMINI-pro DATASET v1.0 Category: Networking ; Style: medieval
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
  // Create a socket
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("socket");
    return 1;
  }

  // Bind the socket to an address
  struct sockaddr_in myaddr;
  memset(&myaddr, 0, sizeof(myaddr));
  myaddr.sin_family = AF_INET;
  myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myaddr.sin_port = htons(12345);
  if (bind(sock_fd, (struct sockaddr *) & myaddr, sizeof(myaddr)) < 0) {
    perror("bind");
    close(sock_fd);
    return 1;
  }

  // Listen for connections
  if (listen(sock_fd, 5) < 0) {
    perror("listen");
    close(sock_fd);
    return 1;
  }

  // Accept a connection
  int client_sock_fd = accept(sock_fd, NULL, NULL);
  if (client_sock_fd < 0) {
    perror("accept");
    close(sock_fd);
    return 1;
  }

  // Receive a message from the client
  char buf[1024];
  int recv_len = recv(client_sock_fd, buf, sizeof(buf), 0);
  if (recv_len < 0) {
    perror("recv");
    close(client_sock_fd);
    close(sock_fd);
    return 1;
  }

  // Print the message from the client
  buf[recv_len] = '\0';
  printf("Received message from client: %s\n", buf);

  // Send a message to the client
  const char *msg = "Hello from the server!\n";
  int send_len = send(client_sock_fd, msg, strlen(msg), 0);
  if (send_len < 0) {
    perror("send");
    close(client_sock_fd);
    close(sock_fd);
    return 1;
  }

  // Close the client socket
  close(client_sock_fd);

  // Close the server socket
  close(sock_fd);

  return 0;
}