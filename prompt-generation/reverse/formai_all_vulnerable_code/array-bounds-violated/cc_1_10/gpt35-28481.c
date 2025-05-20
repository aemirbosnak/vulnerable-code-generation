//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_fd == -1)
    {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) == -1)
    {
        perror("IP address parsing failed");
        exit(1);
    }

    if(connect(client_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        perror("Connection failed");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    while(1)
    {
        printf("Enter a message to send to the server: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        int bytes_sent = send(client_fd, buffer, sizeof(buffer), 0);
        if(bytes_sent == -1)
        {
            perror("Message sending failed");
            exit(1);
        }

        if(strcmp(buffer, "exit\n") == 0)
        {
            printf("Exiting...\n");
            close(client_fd);
            exit(0);
        }

        int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
        if(bytes_received == -1)
        {
            perror("Message receiving failed");
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("Server response: %s", buffer);
    }

    return 0;
}