//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h> 

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd = 0, port = 0, n = 0, file_fd = 0, len = 0;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        printf("\nUsage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[2]);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        perror("Error: Could not create socket");
        return 1;
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("\nError: Could not resolve host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Could not connect to server");
        return 1;
    }

    printf("Connected to server\n");

    bzero(buffer, sizeof(buffer));
    // Read response from server
    n = read(socket_fd, buffer, sizeof(buffer));

    if (n < 0) {
        perror("Error: Failed to read from server");
        return 1;
    }

    printf("%s", buffer);

    // Prompt the user to enter filename
    printf("Enter filename: ");
    bzero(buffer, sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);

    // Remove newline character from input
    len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    // Open file for writing
    file_fd = open(buffer, O_CREAT | O_WRONLY, 0644);

    if (file_fd < 0) {
        perror("Error: Could not create file");
        return 1;
    }

    // Send filename to server
    n = write(socket_fd, buffer, strlen(buffer));

    if (n < 0) {
        perror("Error: Failed to write to server");
        return 1;
    }

    // Read response from server
    bzero(buffer, sizeof(buffer));
    n = read(socket_fd, buffer, sizeof(buffer));

    if (n < 0) {
        perror("Error: Failed to read from server");
        return 1;
    }

    if (strcmp(buffer, "Error") == 0) {
        printf("Error: File not found on server\n");
        return 1;
    }

    // Read data from server and write to file
    while ((n = read(socket_fd, buffer, sizeof(buffer))) > 0) {
        write(file_fd, buffer, n);
    }

    if (n < 0) {
        perror("Error: Failed to read from server");
        return 1;
    }

    printf("File transfer complete\n");

    close(file_fd);
    close(socket_fd);

    return 0;
}