//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]){
    int clientSocket;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    if(argc < 3){
        printf("USAGE : %s <Server IP Address> <Username>\n", argv[0]);
        exit(1);
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, argv[1], &serverAddr.sin_addr);

    addr_size = sizeof(serverAddr);
    if(connect(clientSocket, (struct sockaddr*)&serverAddr, addr_size) == -1){
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }
    printf("Connected to POP3 Server\n");

    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Server : %s", buffer);
    bzero(buffer, BUFFER_SIZE);

    // username
    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(clientSocket, buffer, strlen(buffer), 0);
    printf("Sent to Server : %s", buffer);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Server : %s", buffer);
    bzero(buffer, BUFFER_SIZE);

    //password
    char *password = getpass("Enter Password");
    sprintf(buffer, "PASS %s\r\n", password);
    send(clientSocket, buffer, strlen(buffer), 0);
    printf("Sent to Server : %s", buffer);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Server : %s", buffer);
    bzero(buffer, BUFFER_SIZE);

    // Stat
    sprintf(buffer, "STAT\r\n");
    send(clientSocket, buffer, strlen(buffer), 0);
    printf("Sent to Server : %s", buffer);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Server : %s", buffer);
    bzero(buffer, BUFFER_SIZE);


    // Set Message
    printf("Enter message number to read : ");
    int msgNo;
    scanf("%d", &msgNo);
    sprintf(buffer, "RETR %d\r\n", msgNo);
    send(clientSocket, buffer, strlen(buffer), 0);
    printf("Sent to Server : %s", buffer);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Server : %s", buffer);
    bzero(buffer, BUFFER_SIZE);
    while(recv(clientSocket, buffer, BUFFER_SIZE, 0) > 0){
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    // Delete Message
    printf("Do you want to delete message (Y/N) :");
    char ans;
    scanf(" %c", &ans);
    if(ans == 'Y' || ans == 'y'){
        sprintf(buffer, "DELE %d\r\n", msgNo);
        send(clientSocket, buffer, strlen(buffer), 0);
        printf("Sent to Server : %s", buffer);
        recv(clientSocket, buffer, BUFFER_SIZE, 0);
        printf("Server : %s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    // Quit
    sprintf(buffer, "QUIT\r\n");
    send(clientSocket, buffer, strlen(buffer), 0);
    printf("Sent to Server : %s", buffer);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Server : %s", buffer);

    close(clientSocket);
    return 0;
}