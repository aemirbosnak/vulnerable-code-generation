//Code Llama-13B DATASET v1.0 Category: Networking ; Style: Linus Torvalds
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>

  int main(int argc, char *argv[]) {
      if (argc < 2) {
          printf("Usage: %s <port>\n", argv[0]);
          return 1;
      }

      int port = atoi(argv[1]);
      int sock = socket(AF_INET, SOCK_STREAM, 0);
      if (sock < 0) {
          perror("socket");
          return 1;
      }

      struct sockaddr_in addr;
      memset(&addr, 0, sizeof(addr));
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);
      addr.sin_addr.s_addr = INADDR_ANY;

      if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
          perror("bind");
          return 1;
      }

      if (listen(sock, 3) < 0) {
          perror("listen");
          return 1;
      }

      struct sockaddr_in client_addr;
      socklen_t client_len = sizeof(client_addr);
      int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
      if (client_sock < 0) {
          perror("accept");
          return 1;
      }

      char buffer[1024];
      while (1) {
          int n = recv(client_sock, buffer, sizeof(buffer), 0);
          if (n < 0) {
              perror("recv");
              break;
          } else if (n == 0) {
              break;
          }

          printf("Received: %s\n", buffer);

          char *response = "Hello, client!";
          if (send(client_sock, response, strlen(response), 0) < 0) {
              perror("send");
              break;
          }
      }

      close(client_sock);
      close(sock);
      return 0;
  }