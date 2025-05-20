//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: imaginative
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #include <netinet/in.h>
  #include <sys/socket.h>
  #include <sys/types.h>
  #include <sys/wait.h>

  int main(int argc, char **argv) {
    // Check for command-line arguments
    if (argc != 4) {
      printf("Usage: %s <host> <port> <message>\n", argv[0]);
      return 1;
    }

    // Parse command-line arguments
    char *host = argv[1];
    char *port = argv[2];
    char *message = argv[3];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
      perror("socket");
      return 1;
    }

    // Setup address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port));
    addr.sin_addr.s_addr = inet_addr(host);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("connect");
      return 1;
    }

    // Send message
    if (send(sock, message, strlen(message), 0) < 0) {
      perror("send");
      return 1;
    }

    // Close socket
    if (close(sock) < 0) {
      perror("close");
      return 1;
    }

    return 0;
  }