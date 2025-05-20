//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: enthusiastic
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>

    int main(int argc, char *argv[]) {
      // Check if the number of arguments is correct
      if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
      }

      // Get the port number from the argument
      int port = atoi(argv[1]);

      // Create a socket
      int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
      if (sock < 0) {
        perror("socket() failed");
        return 1;
      }

      // Bind the socket to the specified port
      struct sockaddr_in addr;
      memset(&addr, 0, sizeof(addr));
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);
      if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind() failed");
        return 1;
      }

      // Listen for incoming connections
      if (listen(sock, 1) < 0) {
        perror("listen() failed");
        return 1;
      }

      printf("Listening on port %d\n", port);

      // Accept incoming connections
      while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
          perror("accept() failed");
          return 1;
        }

        // Get the client's IP address and port number
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        int client_port = ntohs(client_addr.sin_port);

        printf("Connection from %s:%d\n", client_ip, client_port);

        // Receive and print the incoming message
        char buffer[1024];
        int bytes_received = recv(client_sock, buffer, 1024, 0);
        if (bytes_received < 0) {
          perror("recv() failed");
          return 1;
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);

        // Send a reply to the client
        char reply[] = "Hello, client!";
        if (send(client_sock, reply, strlen(reply), 0) < 0) {
          perror("send() failed");
          return 1;
        }

        // Close the client socket
        close(client_sock);
      }

      // Close the server socket
      close(sock);

      return 0;
    }