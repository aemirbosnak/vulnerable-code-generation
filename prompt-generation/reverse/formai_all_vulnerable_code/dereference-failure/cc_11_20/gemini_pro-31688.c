//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define PORT 110
#define MAXRECV 1024

int main()
{
    int sockfd, bytes_recv;
    char recvbuf[MAXRECV], sendbuf[MAXRECV];
    struct sockaddr_in serv_addr;

    // Welcome Message
    printf("Greetings, Agent! Welcome to the POP3 Extraction Nexus.\n");

    // Hostname Prompt
    printf("Enter the synaptic coordinates of the mail server (e.g., mail.example.com): ");
    char hostname[100];
    scanf("%s", hostname);

    // Socket Initialization
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Socket initialization failed. Mission aborted.\n");
        return 1;
    }

    // Server Address Retrieval
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL)
    {
        printf("Unknown synaptic coordinates. Please verify and retry.\n");
        return 1;
    }

    // Server Address Setup
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Server Connection
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection to server failed. Please check your targeting system.\n");
        return 1;
    }

    // Server Greeting
    bytes_recv = recv(sockfd, recvbuf, MAXRECV, 0);
    if (bytes_recv < 0)
    {
        printf("Error receiving server greeting. Mission compromised.\n");
        return 1;
    }
    printf("%s\n", recvbuf);

    // Username Authentication
    printf("Enter your username, Agent: ");
    scanf("%s", sendbuf);
    send(sockfd, "USER ", 5, 0);
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    send(sockfd, "\r\n", 2, 0);

    bytes_recv = recv(sockfd, recvbuf, MAXRECV, 0);
    if (bytes_recv < 0)
    {
        printf("Error receiving username authentication response. Your cover may be blown.\n");
        return 1;
    }
    printf("%s\n", recvbuf);

    // Password Authentication
    printf("Transmit your password, Agent: ");
    scanf("%s", sendbuf);
    send(sockfd, "PASS ", 5, 0);
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    send(sockfd, "\r\n", 2, 0);

    bytes_recv = recv(sockfd, recvbuf, MAXRECV, 0);
    if (bytes_recv < 0)
    {
        printf("Error receiving password authentication response. Protocol violation detected.\n");
        return 1;
    }
    printf("%s\n", recvbuf);

    // Mailbox Status
    send(sockfd, "STAT\r\n", 6, 0);
    bytes_recv = recv(sockfd, recvbuf, MAXRECV, 0);
    if (bytes_recv < 0)
    {
        printf("Error receiving mailbox status. Target may be out of range.\n");
        return 1;
    }
    printf("%s\n", recvbuf);

    // Mail Retrieval Loop
    int msg_num, msg_size;
    bool quit = false;
    while (!quit)
    {
        printf("Enter message number to retrieve (or 'QUIT' to terminate): ");
        scanf("%s", sendbuf);
        if (strcmp(sendbuf, "QUIT") == 0)
        {
            quit = true;
            break;
        }
        msg_num = atoi(sendbuf);

        // Mail Retrieval Command
        sprintf(sendbuf, "RETR %d\r\n", msg_num);
        send(sockfd, sendbuf, strlen(sendbuf), 0);

        // Mail Header
        bytes_recv = recv(sockfd, recvbuf, MAXRECV, 0);
        if (bytes_recv < 0)
        {
            printf("Error retrieving message header. Transmission intercepted.\n");
            return 1;
        }
        printf("Message %d Header:\n%s", msg_num, recvbuf);

        // Mail Body
        msg_size = atoi(recvbuf + 2);
        bytes_recv = recv(sockfd, recvbuf, msg_size, 0);
        if (bytes_recv < 0)
        {
            printf("Error retrieving message body. Transmission distorted.\n");
            return 1;
        }
        printf("Message %d Body:\n%s", msg_num, recvbuf);
    }

    // Logout
    printf("Transmitting \"QUIT\" command to terminate connection.\n");
    send(sockfd, "QUIT\r\n", 6, 0);

    // Server Response
    bytes_recv = recv(sockfd, recvbuf, MAXRECV, 0);
    if (bytes_recv < 0)
    {
        printf("Error receiving logout response. Connection termination compromised.\n");
        return 1;
    }
    printf("%s\n", recvbuf);

    // Socket Close
    close(sockfd);

    printf("Connection terminated. Return to base.\n");
    return 0;
}