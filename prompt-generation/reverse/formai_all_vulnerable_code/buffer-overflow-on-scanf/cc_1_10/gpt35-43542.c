//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0); //create socket
    if (sock == -1) {
        perror("Error opening socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]); //IP address
    server.sin_family = AF_INET; //IPv4 address family
    server.sin_port = htons(21); //FTP port number

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting");
        return 1;
    }

    char response[1024];
    int count = recv(sock, response, 1024, 0); //receive connection message
    if (count < 0) {
        perror("Error receiving");
        return 1;
    }
    response[count] = '\0';
    printf("Server response: %s\n", response);

    //login credentials
    char username[50];
    char password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    char login[100];
    sprintf(login, "USER %s\r\n", username);
    send(sock, login, strlen(login), 0); //send username
    count = recv(sock, response, 1024, 0); //receive response
    if (count < 0) {
        perror("Error receiving");
        return 1;
    }
    response[count] = '\0';
    printf("Server response: %s\n", response);

    char password_cmd[100];
    sprintf(password_cmd, "PASS %s\r\n", password);
    send(sock, password_cmd, strlen(password_cmd), 0); //send password
    count = recv(sock, response, 1024, 0); //receive response
    if (count < 0) {
        perror("Error receiving");
        return 1;
    }
    response[count] = '\0';
    printf("Server response: %s\n", response);

    //command loop
    while (1) {
        char command[100];
        printf("Enter command: ");
        scanf("%s", command);
        strcat(command, "\r\n"); //add FTP command delimiter

        //exit FTP client
        if (strcmp(command, "QUIT\r\n") == 0) {
            send(sock, command, strlen(command), 0);
            count = recv(sock, response, 1024, 0);
            if (count < 0) {
                perror("Error receiving");
                return 1;
            }
            response[count] = '\0';
            printf("Server response: %s\n", response);
            close(sock); //close socket
            break;
        }

        send(sock, command, strlen(command), 0); //send command
        count = recv(sock, response, 1024, 0); //receive response
        if (count < 0) {
            perror("Error receiving");
            return 1;
        }
        response[count] = '\0';
        printf("Server response: %s\n", response);
    }
    return 0;
}