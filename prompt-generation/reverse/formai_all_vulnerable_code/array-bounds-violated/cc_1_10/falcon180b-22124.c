//Falcon-180B DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_NAME 64
#define MAX_ADDRESS 1024

struct sockaddr_in server_addr;
int sock;

void main()
{
    char hostname[MAX_NAME];
    char address[MAX_ADDRESS];
    char line[MAX_LINE];
    char *ptr;
    int port;
    int result;

    printf("Enter the hostname: ");
    fgets(hostname, MAX_NAME, stdin);
    hostname[strcspn(hostname, "\r\n")] = '\0';

    printf("Enter the port number: ");
    fgets(line, MAX_LINE, stdin);
    port = atoi(line);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    result = inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    if (result == 0)
    {
        printf("Invalid hostname\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1)
    {
        memset(line, 0, MAX_LINE);
        printf("Enter a message: ");
        fgets(line, MAX_LINE, stdin);
        line[strcspn(line, "\r\n")] = '\0';

        send(sock, line, strlen(line), 0);

        memset(line, 0, MAX_LINE);
        result = recv(sock, line, MAX_LINE, 0);
        if (result <= 0)
        {
            printf("Disconnected from server\n");
            break;
        }
        line[result] = '\0';
        printf("Received message: %s\n", line);
    }

    close(sock);
}