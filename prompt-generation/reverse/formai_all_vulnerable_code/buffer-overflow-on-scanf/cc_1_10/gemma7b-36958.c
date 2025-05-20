//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

int main()
{
    int sockfd, port, n, host_num, target_port;
    char hostname[256], buf[4096], command[1024], output[4096];
    struct sockaddr_in serv_addr, client_addr;
    FILE *fp;
    system("clear");
    // Get the hostname and port number from the user
    printf("Enter the hostname or IP address: ");
    scanf("%s", hostname);
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a command to the server
    printf("Enter your command: ");
    scanf("%s", command);
    send(sockfd, command, strlen(command) + 1, 0);

    // Receive the server's output
    n = recv(sockfd, output, 4096, 0);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    // Print the server's output
    printf("Server's output:\n");
    printf("%s", output);

    // Close the socket
    close(sockfd);

    return 0;
}