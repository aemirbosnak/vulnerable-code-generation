//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, port, n, len, i;
    char hostname[256], buffer[MAX_BUFFER_SIZE], filename[256];
    struct sockaddr_in server_addr;

    // Get the hostname and port number from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to the server");
        exit(1);
    }

    // Send a file name
    printf("Enter the file name: ");
    scanf("%s", filename);

    send(sockfd, filename, strlen(filename), 0);

    // Receive a file
    len = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Write the file to disk
    FILE *fp = fopen(filename, "w");
    fwrite(buffer, len, 1, fp);
    fclose(fp);

    // Close the socket
    close(sockfd);

    // Print a success message
    printf("File received successfully!\n");

    return 0;
}