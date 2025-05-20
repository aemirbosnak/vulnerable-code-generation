//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];
    char* file_path = "/downloads/romeo_and_juliet.txt";
    FILE* file;

    if (sockfd < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
    {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // FTP login
    printf("Enter FTP username: ");
    scanf("%s", buffer);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    printf("Enter FTP password: ");
    scanf("%s", buffer);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Change to passive mode
    send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0);

    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Connect to data channel
    int port = 0;
    int first_octet = 0;
    int second_octet = 0;
    int third_octet = 0;
    int fourth_octet = 0;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
        &first_octet, &second_octet, &third_octet, &fourth_octet,
        &port, &port);
    sprintf(buffer, "%d.%d.%d.%d", first_octet, second_octet, third_octet, fourth_octet);

    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_address;

    memset(&data_address, 0, sizeof(data_address));
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(port);

    if (inet_pton(AF_INET, buffer, &data_address.sin_addr) <= 0)
    {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(data_sockfd, (struct sockaddr*)&data_address, sizeof(data_address)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Retrieve file
    sprintf(buffer, "RETR %s\r\n", file_path);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    file = fopen("romeo_and_juliet.txt", "w");

    while (recv(data_sockfd, buffer, MAX_BUFFER_SIZE, 0) > 0)
    {
        fwrite(buffer, 1, strlen(buffer), file);
    }

    fclose(file);
    close(sockfd);
    close(data_sockfd);

    printf("\nSuccess! Romeo and Juliet has been downloaded!\n");
    return 0;
}