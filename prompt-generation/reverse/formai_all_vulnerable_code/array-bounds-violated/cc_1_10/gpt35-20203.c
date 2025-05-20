//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
/*
Mathematical FTP Client Program
Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_SIZE 1024

void printMenu();
void connectToFtpServer(int *sock, struct sockaddr_in *server_addr, char *ip_address);
int sendCommand(int sock, char *command);
int receiveResponse(int sock, char *response);
void parseResponse(char *response, char *code, char *message);
void ftpHandler(int sock, struct sockaddr_in server_addr, char *ip_address);

int main()
{
    int sock;
    struct sockaddr_in server_addr;
    char ip_address[MAX_SIZE];

    printf("Enter FTP server IP address: ");
    fgets(ip_address, MAX_SIZE, stdin);
    if (ip_address[strlen(ip_address)-1] == '\n')
        ip_address[strlen(ip_address)-1] = '\0';

    connectToFtpServer(&sock, &server_addr, ip_address);
    ftpHandler(sock, server_addr, ip_address);

    return 0;
}

void printMenu()
{
    printf("\n");
    printf("FTP Command Menu:\n");
    printf("1. List files in current directory (ls)\n");
    printf("2. Change current directory (cd <directory>)\n");
    printf("3. Download file (get <filename>)\n");
    printf("4. Exit FTP client (quit)\n");
    printf("Enter command: ");
}

void connectToFtpServer(int *sock, struct sockaddr_in *server_addr, char *ip_address)
{
    if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, ip_address, &server_addr->sin_addr) <= 0)
    {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(*sock, (struct sockaddr *) server_addr, sizeof(*server_addr)) < 0)
    {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char response[MAX_SIZE];
    if (receiveResponse(*sock, response) < 0)
    {
        perror("failed to receive response from server");
        exit(EXIT_FAILURE);
    }
    printf("Response from server: %s\n", response);
}

int sendCommand(int sock, char *command)
{
    if (send(sock, command, strlen(command), 0) < 0)
    {
        perror("failed to send command");
        return -1;
    }
    return 0;
}

int receiveResponse(int sock, char *response)
{
    int bytes_received;
    if ((bytes_received = recv(sock, response, MAX_SIZE, 0)) < 0)
    {
        perror("failed to receive response");
        return -1;
    }
    response[bytes_received] = '\0';
    return 0;
}

void parseResponse(char *response, char *code, char *message)
{
    strncpy(code, response, 3);
    code[3] = '\0';
    strncpy(message, response + 4, MAX_SIZE - 4);
}

void ftpHandler(int sock, struct sockaddr_in server_addr, char *ip_address)
{
    char command[MAX_SIZE];
    char response[MAX_SIZE];
    char code[4];
    char message[MAX_SIZE - 4];

    while (1)
    {
        printMenu();

        fgets(command, MAX_SIZE, stdin);
        if (command[strlen(command)-1] == '\n')
            command[strlen(command)-1] = '\0';

        if (sendCommand(sock, command) < 0)
        {
            perror("failed to send command");
            continue;
        }

        if (receiveResponse(sock, response) < 0)
        {
            perror("failed to receive response");
            continue;
        }

        parseResponse(response, code, message);
        printf("Response from server: %s\n", response);

        if (strcmp(code, "221") == 0)
        {
            printf("Closing connection with FTP server.\n");
            break;
        }
    }
}