//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_BUFFER 1024

char* receiveMessage(int socket)
{
    char* message = (char*)malloc(MAX_BUFFER * sizeof(char));
    memset(message, '\0', MAX_BUFFER);

    int bytesReceived = recv(socket, message, MAX_BUFFER - 1, 0);
    if (bytesReceived == -1)
    {
        perror("Error receiving message");
        exit(1);
    }
    else if (bytesReceived == 0)
    {
        printf("Connection closed by server.\n");
        exit(1);
    }
    message[bytesReceived] = '\0';

    if (message[0] == '-')
    {
        printf("%s", message);
        exit(1);
    }

    return message;
}

void sendMessage(int socket, char* message)
{
    int bytesSent = send(socket, message, strlen(message), 0);
    if (bytesSent == -1)
    {
        perror("Error sending message");
        exit(1);
    }
}

void login(int socket)
{
    char username[MAX_BUFFER];
    char password[MAX_BUFFER];

    printf("Username: ");
    fgets(username, MAX_BUFFER, stdin);
    username[strlen(username) - 1] = '\0';

    printf("Password: ");
    fgets(password, MAX_BUFFER, stdin);
    password[strlen(password) - 1] = '\0';

    char loginMessage[MAX_BUFFER];  
    sprintf(loginMessage, "USER %s\r\n", username);
    sendMessage(socket, loginMessage);
    printf("%s", receiveMessage(socket));

    sprintf(loginMessage, "PASS %s\r\n", password);
    sendMessage(socket, loginMessage);
    printf("%s", receiveMessage(socket));
}

void list(int socket)
{
    sendMessage(socket, "LIST\r\n");
    char* response = receiveMessage(socket);
    printf("%s", response);

    char* token = strtok(response, "\n");
    while (token != NULL)
    {
        if (token[0] >= '0' && token[0] <= '9')
            printf("%s\n", token);
        token = strtok(NULL, "\n");
    }
}

void quit(int socket)
{
    sendMessage(socket, "QUIT\r\n");
    printf("%s", receiveMessage(socket));

    close(socket);
    exit(0);
}

void handleCommand(int socket, char command)
{
    switch(command)
    {
        case 'l':
        {
            list(socket);
            break;
        }
        case 'q':
        {
            quit(socket);
            break;
        }
        default:
        {
            printf("Invalid command\n");
            break;
        }
    }
}

void recursivePrompt(int socket)
{
    printf("Enter Command: ");
    char command = getchar();
    getchar(); // Consume new line character

    handleCommand(socket, command);

    recursivePrompt(socket);
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <server-address> <port>\n", argv[0]);
        exit(1);
    }

    char* serverAddress = argv[1];
    int port = atoi(argv[2]);

    struct hostent* serverInfo = gethostbyname(serverAddress);
    if (serverInfo == NULL)
    {
        printf("Error: no such host %s.\n", serverAddress);
        exit(1);
    }

    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1)
    {
        perror("Error opening socket");
        exit(1);
    }

    struct sockaddr_in serverAddressInfo;
    serverAddressInfo.sin_family = AF_INET;
    serverAddressInfo.sin_port = htons(port);
    bcopy((char*)serverInfo->h_addr, (char*)&serverAddressInfo.sin_addr.s_addr, serverInfo->h_length);

    if (connect(socketFD, (struct sockaddr*)&serverAddressInfo, sizeof(serverAddressInfo)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("%s", receiveMessage(socketFD));
    login(socketFD);

    recursivePrompt(socketFD);
}