//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int create_socket(char* url){

    struct hostent* host = gethostbyname(url);
    if (host == NULL){
        perror("Error resolving hostname");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = *((unsigned long *)host->h_addr);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1){
        perror("Error creating socket");
        return -1;
    }

    if (connect(client_socket , (struct sockaddr *)&addr , sizeof(addr)) < 0){
        perror("Connection failed");
        return -1;
    }

    return client_socket;
}

bool send_request(int client_socket, char* request){

    char buffer[BUFFER_SIZE];
    int request_length = strlen(request);
    if (send(client_socket, request, request_length, 0) != request_length){
        perror("Error sending request");
        return false;
    }

    return true;
}

bool receive_response(int client_socket){

    char response[BUFFER_SIZE];
    int response_length;
    if ((response_length = recv(client_socket, response, BUFFER_SIZE, 0)) == -1){
        perror("Error receiving response");
        return false;
    }

    response[response_length] = '\0';
    printf("%s\n", response);

    return true;
}

int main(int argc, char* argv[]){

    if (argc < 2){
        printf("Usage: %s [url]\n", argv[0]);
        return -1;
    }

    char* url = argv[1];
    char request[BUFFER_SIZE];

    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url);

    int client_socket;
    if ((client_socket = create_socket(url)) == -1){
        return -1;
    }

    if (!send_request(client_socket, request)){
        return -1;
    }

    if (!receive_response(client_socket)){
        return -1;
    }

    close(client_socket);

    return 0;
}