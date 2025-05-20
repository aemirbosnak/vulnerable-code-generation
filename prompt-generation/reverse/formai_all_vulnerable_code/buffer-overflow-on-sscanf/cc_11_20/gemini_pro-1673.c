//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT          110
#define POP3_BUFFER_SIZE   1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_aton(argv[1], &server_addr.sin_addr) == 0)
    {
        printf("Invalid server address\n");
        return EXIT_FAILURE;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message
    char buffer[POP3_BUFFER_SIZE];
    memset(buffer, 0, POP3_BUFFER_SIZE);
    if (recv(sock, buffer, POP3_BUFFER_SIZE, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the user command
    snprintf(buffer, POP3_BUFFER_SIZE, "USER %s\r\n", argv[2]);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the user response
    memset(buffer, 0, POP3_BUFFER_SIZE);
    if (recv(sock, buffer, POP3_BUFFER_SIZE, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the pass command
    snprintf(buffer, POP3_BUFFER_SIZE, "PASS %s\r\n", argv[3]);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the pass response
    memset(buffer, 0, POP3_BUFFER_SIZE);
    if (recv(sock, buffer, POP3_BUFFER_SIZE, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the stat command
    snprintf(buffer, POP3_BUFFER_SIZE, "STAT\r\n");
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the stat response
    memset(buffer, 0, POP3_BUFFER_SIZE);
    if (recv(sock, buffer, POP3_BUFFER_SIZE, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Get the number of messages
    int number_of_messages = 0;
    sscanf(buffer, "+OK %d messages", &number_of_messages);

    // Send the retr command
    snprintf(buffer, POP3_BUFFER_SIZE, "RETR %d\r\n", number_of_messages);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the retr response
    memset(buffer, 0, POP3_BUFFER_SIZE);
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, POP3_BUFFER_SIZE, 0)) > 0)
    {
        printf("%s", buffer);
    }

    // Send the quit command
    snprintf(buffer, POP3_BUFFER_SIZE, "QUIT\r\n");
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}