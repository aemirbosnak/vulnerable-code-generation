//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    // Define the client socket
    int sockfd;
    struct sockaddr_in server_addr;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    // Connect to the server
    server_addr.sin_port = htons(SERVER_PORT);
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send file information
    char filename[256];
    printf("Enter file name: ");
    scanf("%s", filename);

    // Send the file name to the server
    send(sockfd, filename, strlen(filename), 0);

    // Receive file data
    char buffer[BUFFER_SIZE];
    int read_size;

    // Create a file to store the data
    FILE *file = fopen(filename, "w");

    // Loop to receive file data until the file is complete
    while ((read_size = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, read_size, 1, file);
    }

    // Close the file
    fclose(file);

    // Close the socket
    close(sockfd);

    return 0;
}