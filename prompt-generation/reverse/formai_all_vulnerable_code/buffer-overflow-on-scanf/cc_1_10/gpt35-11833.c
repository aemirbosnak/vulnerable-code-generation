//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h>

#define MAXBUFFER 1024

int main(int argc, char const *argv[])
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAXBUFFER] = {0};

    //Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\nSocket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //Connecting to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    //Reading message from server
    if (recv(sock, buffer, MAXBUFFER, 0) < 0)
    {
        printf("\nFailed to receive message from server \n");
        return -1;
    }

    //Printing message from server
    printf("\nMessage from Server: \n%s\n", buffer);

    //Sending email username and password
    char username[MAXBUFFER];
    char password[MAXBUFFER];

    printf("Enter Email username: ");
    scanf("%s", username);
    strcat(username, "\r\n");

    if (send(sock, username, strlen(username), 0) < 0)
    {
        printf("\nFailed to send username \n");
        return -1;
    }

    printf("Enter Email password: ");
    scanf("%s", password);
    strcat(password, "\r\n");

    if (send(sock, password, strlen(password), 0) < 0)
    {
        printf("\nFailed to send password \n");
        return -1;
    }

    //Reading message from server
    if (recv(sock, buffer, MAXBUFFER, 0) < 0)
    {
        printf("\nFailed to receive message from server \n");
        return -1;
    }

    //Printing message from server
    printf("\nMessage from Server: \n%s\n", buffer);

    //Sending command to retrieve emails
    char command[MAXBUFFER];
    strcpy(command, "RETR 1\r\n");

    if (send(sock, command, strlen(command), 0) < 0)
    {
        printf("\nFailed to send command \n");
        return -1;
    }

    //Reading message from server
    if (recv(sock, buffer, MAXBUFFER, 0) < 0)
    {
        printf("\nFailed to receive message from server \n");
        return -1;
    }

    //Printing message from server
    printf("\nMessage from Server: \n%s\n", buffer);

    //Closing socket
    close(sock);

    return 0;
}