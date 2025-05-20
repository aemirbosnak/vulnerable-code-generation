//FormAI DATASET v1.0 Category: Client Server Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void server()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accepting connection from client
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection established\n");

    // Receiving message from client
    valread = read(new_socket, buffer, BUFFER_SIZE);
    printf("Client says: %s\n", buffer);

    // Sending message to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Closing connection with client
    close(new_socket);

    printf("Connection closed\n");
}

void client()
{
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from client!";

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converting IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established\n");

    // Sending message to server
    send(sockfd, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Receiving message from server
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server says: %s\n", buffer);

    // Closing connection with server
    close(sockfd);

    printf("Connection closed\n");
}

int main()
{
    int choice;

    printf("1. Run as server\n");
    printf("2. Run as client\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        server();
    }
    else if (choice == 2)
    {
        client();
    }
    else
    {
        printf("Invalid choice\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}