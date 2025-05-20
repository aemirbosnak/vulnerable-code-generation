//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <netdb.h>

  int main(int argc, char *argv[]) {
      if (argc != 3) {
          fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
          exit(1);
      }

      int sock = socket(AF_INET, SOCK_STREAM, 0);
      if (sock < 0) {
          perror("socket");
          exit(1);
      }

      struct hostent *host = gethostbyname(argv[1]);
      if (!host) {
          fprintf(stderr, "Failed to resolve hostname %s\n", argv[1]);
          exit(1);
      }

      struct sockaddr_in addr;
      memset(&addr, 0, sizeof(addr));
      addr.sin_family = AF_INET;
      addr.sin_port = htons(atoi(argv[2]));
      memcpy(&addr.sin_addr, host->h_addr, host->h_length);

      if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
          perror("connect");
          exit(1);
      }

      char *msg = "Hello from client!";
      if (send(sock, msg, strlen(msg), 0) < 0) {
          perror("send");
          exit(1);
      }

      char buf[256];
      int n = recv(sock, buf, sizeof(buf), 0);
      if (n < 0) {
          perror("recv");
          exit(1);
      }
      buf[n] = '\0';
      printf("Received message: %s\n", buf);

      close(sock);
      return 0;
  }