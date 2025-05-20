//FormAI DATASET v1.0 Category: Socket programming ; Style: unmistakable
// This program demonstrates a simple client-server communication using Socket programming.
// The client sends an integer to the server, the server then calculates the square of the integer and sends it back to the client.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080

int main()
{
    int sockfd, new_socket, valread;
    struct sockaddr_in serv_addr;
    int opt = 1;
    int client_int, server_int;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Binding socket to the specified address and port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(sockfd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connection
    if ((new_socket = accept(sockfd, (struct sockaddr *)&serv_addr, (socklen_t *)&serv_addr)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Receiving integer from client
    valread = read(new_socket, &client_int, sizeof(client_int));
    printf("Integer received from client: %d\n", client_int);

    // Calculating square of integer
    server_int = client_int * client_int;

    // Sending calculated result back to client
    send(new_socket, &server_int, sizeof(server_int), 0);
    printf("Square of integer sent to client: %d\n", server_int);

    return 0;
}