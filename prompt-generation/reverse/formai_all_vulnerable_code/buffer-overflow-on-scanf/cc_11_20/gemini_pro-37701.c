//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[1024];
    char command[1024];
    char filename[1024];
    char file_size[1024];
    int bytes_received;
    int bytes_sent;

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("connect");
        exit(1);
    }

    // Receive the welcome message from the server
    bytes_received = recv(client_socket, buffer, 1024, 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send the USER command to the server
    strcpy(command, "USER anonymous\n");
    bytes_sent = send(client_socket, command, strlen(command), 0);
    if (bytes_sent == -1)
    {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    bytes_received = recv(client_socket, buffer, 1024, 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send the PASS command to the server
    strcpy(command, "PASS anonymous@\n");
    bytes_sent = send(client_socket, command, strlen(command), 0);
    if (bytes_sent == -1)
    {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    bytes_received = recv(client_socket, buffer, 1024, 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send the LIST command to the server
    strcpy(command, "LIST\n");
    bytes_sent = send(client_socket, command, strlen(command), 0);
    if (bytes_sent == -1)
    {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    bytes_received = recv(client_socket, buffer, 1024, 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send the RETR command to the server
    printf("Enter the filename to download: ");
    scanf("%s", filename);
    strcpy(command, "RETR ");
    strcat(command, filename);
    strcat(command, "\n");
    bytes_sent = send(client_socket, command, strlen(command), 0);
    if (bytes_sent == -1)
    {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    bytes_received = recv(client_socket, buffer, 1024, 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Receive the file size from the server
    bytes_received = recv(client_socket, file_size, 1024, 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }

    // Open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("fopen");
        exit(1);
    }

    // Receive the file data from the server
    while ((bytes_received = recv(client_socket, buffer, 1024, 0)) > 0)
    {
        fwrite(buffer, 1, bytes_received, fp);
    }

    // Close the file
    fclose(fp);

    // Send the QUIT command to the server
    strcpy(command, "QUIT\n");
    bytes_sent = send(client_socket, command, strlen(command), 0);
    if (bytes_sent == -1)
    {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(client_socket);

    return 0;
}