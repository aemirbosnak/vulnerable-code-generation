//FormAI DATASET v1.0 Category: Client Server Application ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 8080

int main(){
    int server_socket, new_socket, client_len;
    struct sockaddr_in server_address, client_address;

    char *buffer = malloc(sizeof(char)*256);
    char *response = malloc(sizeof(char)*256);

    srand(time(NULL));
    int r = rand()%10;

    printf("\n\nWelcome to the game of Ping-Pong. Let's begin!\n\n");

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket<0){
        fprintf(stderr, "\nERROR: Could not create socket.\n");
        exit(1);
    }

    printf("\nServer socket created successfully.\n");

    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address))<0){
        fprintf(stderr, "\nERROR: Could not bind socket to address.\n");
        exit(1);
    }

    printf("\nServer socket bound to address successfully.\n");

    listen(server_socket, 5);

    printf("\nWaiting for client to connect.....\n");

    client_len = sizeof(client_address);

    new_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_len);

    if(new_socket<0){
        fprintf(stderr, "\nERROR: Could not accept client connection.\n");
        exit(1);
    }

    printf("\nClient connected successfully.\n");

    int count = 0;
    do{
        memset(buffer, 0, sizeof(buffer));
        memset(response, 0, sizeof(response));
        count++;
        read(new_socket, buffer, sizeof(buffer));
        if(buffer[0]=='i' && buffer[1]=='\0'){
            printf("Client: I\n");
            printf("Server: %d\n", r);
            sprintf(response, "%d", r);
            write(new_socket, response, sizeof(response));
        }else if(buffer[0] == 'p' && buffer[1]=='\0'){
            printf("Client: P\n");
            r++;
            write(new_socket, buffer, sizeof(buffer));
        }else if(buffer[0] == 'n' && buffer[1]=='\0'){
            printf("Client: N\n");
            r--;
            write(new_socket, buffer, sizeof(buffer));
        }

    }while(count<=5);

    printf("\nGame over!\n");

    close(new_socket);
    close(server_socket);

    printf("\nSockets closed\n");

    free(buffer);
    free(response);

    return 0;
}