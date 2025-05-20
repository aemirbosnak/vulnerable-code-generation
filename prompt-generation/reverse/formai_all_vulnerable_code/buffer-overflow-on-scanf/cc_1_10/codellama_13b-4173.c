//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: genius
// Client Server Application in C

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>

  // Server Function
  void server() {
    int sockfd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[256];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
    }

    // Preparing server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    // Binding server address to socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
    }

    // Listening to incoming connections
    listen(sockfd, 3);

    // Accept incoming connections
    while (1) {
      new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
      if (new_fd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
      }

      // Receiving data from client
      recv(new_fd, buffer, 256, 0);
      printf("Received data: %s\n", buffer);

      // Sending data to client
      send(new_fd, "Hello, client!", 13, 0);

      // Closing connection
      close(new_fd);
    }
  }

  // Client Function
  void client() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[256];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
    }

    // Preparing server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("connect failed");
      exit(EXIT_FAILURE);
    }

    // Sending data to server
    send(sockfd, "Hello, server!", 13, 0);

    // Receiving data from server
    recv(sockfd, buffer, 256, 0);
    printf("Received data: %s\n", buffer);

    // Closing connection
    close(sockfd);
  }

  int main() {
    int server_or_client;
    printf("Enter 1 for server and 2 for client: ");
    scanf("%d", &server_or_client);
    if (server_or_client == 1) {
      server();
    } else if (server_or_client == 2) {
      client();
    } else {
      printf("Invalid input\n");
    }
    return 0;
  }