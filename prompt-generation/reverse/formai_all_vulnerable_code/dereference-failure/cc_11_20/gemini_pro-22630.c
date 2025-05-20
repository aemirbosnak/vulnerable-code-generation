//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Check if the user provided all the necessary arguments.
    if (argc != 4)
    {
        printf("Usage: %s <hostname> <port> <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the hostname, port, and file from the command line arguments.
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *file = argv[3];

    // Create a socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) != 1)
    {
        perror("inet_pton");
        return EXIT_FAILURE;
    }
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the FTP command to retrieve the file.
    char command[1024];
    sprintf(command, "RETR %s\r\n", file);
    if (send(sock, command, strlen(command), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    char response[1024];
    if (recv(sock, response, sizeof(response), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response indicates success.
    if (strncmp(response, "226 Transfer complete", 20) != 0)
    {
        fprintf(stderr, "Error: Failed to retrieve the file: %s\n", response);
        return EXIT_FAILURE;
    }

    // Open the file for writing.
    FILE *fp = fopen(file, "w");
    if (fp == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Receive the file data from the FTP server.
    char buffer[1024];
    while (1)
    {
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received == -1)
        {
            perror("recv");
            return EXIT_FAILURE;
        }
        if (bytes_received == 0)
        {
            break;
        }
        fwrite(buffer, bytes_received, 1, fp);
    }

    // Close the file.
    fclose(fp);

    // Close the socket.
    close(sock);

    return EXIT_SUCCESS;
}