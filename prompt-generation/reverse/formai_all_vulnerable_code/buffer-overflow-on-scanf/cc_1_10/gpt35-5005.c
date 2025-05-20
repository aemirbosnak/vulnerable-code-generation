//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "pop3.server.com"
#define SERVER_PORT 110

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0); // create socket

    if (sock == -1)
    {
        printf("Failed to create socket.\n");
        return -1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Connection failed.\n");
        return -1;
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer)); // clear buffer

    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer); // print server greeting message

    // send username to the server
    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);

    char user_cmd[100];
    sprintf(user_cmd, "USER %s\r\n", username);

    send(sock, user_cmd, strlen(user_cmd), 0);
    memset(buffer, 0, sizeof(buffer)); // clear buffer

    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer); // print server response to username command

    // send password to the server
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);

    char pass_cmd[100];
    sprintf(pass_cmd, "PASS %s\r\n", password);

    send(sock, pass_cmd, strlen(pass_cmd), 0);
    memset(buffer, 0, sizeof(buffer)); // clear buffer

    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer); // print server response to password command

    // send LIST command to the server
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    memset(buffer, 0, sizeof(buffer)); // clear buffer

    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer); // print server response to LIST command

    // send RETR command to the server to get an email
    int email_number;
    printf("Enter the email number you want to retrieve: ");
    scanf("%d", &email_number);

    char retr_cmd[100];
    sprintf(retr_cmd, "RETR %d\r\n", email_number);

    send(sock, retr_cmd, strlen(retr_cmd), 0);
    memset(buffer, 0, sizeof(buffer)); // clear buffer

    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer); // print server response to RETR command

    // close the socket
    close(sock);

    return 0;
}