//FormAI DATASET v1.0 Category: Client Server Application ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define SERVER_PORT 8888

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    struct sockaddr_in server_addr;
    char buffer[255];
    int client_socket;

    printf("\n\n\tWelcome to Unauthorized Access Program!\n\n");
    printf("\tEnter server IP Address:\t");
    char server_ip[20];
    scanf("%s", server_ip);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0)
        error("Error in creating socket");

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    while(1){
        if(connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
            error("Unable to connect to server. Retry.");

        printf("\n\tEnter Command:\t");
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);

        if(write(client_socket, buffer, strlen(buffer)) < 0)
            printf("\n\tError in sending command");

        bzero(buffer, 255);
        if(read(client_socket, buffer, 255) < 0)
            printf("\n\tError in receiving data");

        printf("\n\tServer Response:\t%s\n", buffer);
        close(client_socket);
    }
    return 0;
}