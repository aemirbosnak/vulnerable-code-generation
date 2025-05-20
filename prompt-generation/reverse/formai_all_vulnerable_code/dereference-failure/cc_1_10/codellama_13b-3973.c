//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: surprised
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sys/socket.h>
  #include <arpa/inet.h>
  #include <netinet/in.h>

  int main(int argc, char *argv[]) {
    int sock;
    char buf[1024];
    struct sockaddr_in server;
    struct hostent *host;

    if (argc != 2) {
      fprintf(stderr, "Usage: %s <port>\n", argv[0]);
      exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
      perror("socket");
      exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
      perror("bind");
      exit(1);
    }

    if (listen(sock, 5) < 0) {
      perror("listen");
      exit(1);
    }

    printf("Waiting for connections...\n");

    while (1) {
      int client = accept(sock, NULL, NULL);
      if (client < 0) {
        perror("accept");
        exit(1);
      }

      printf("Connection established\n");

      while (1) {
        int n = recv(client, buf, 1024, 0);
        if (n < 0) {
          perror("recv");
          exit(1);
        }
        if (n == 0) {
          printf("Client disconnected\n");
          break;
        }
        printf("Received message: %s\n", buf);
      }

      close(client);
    }

    close(sock);
    return 0;
  }