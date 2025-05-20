//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

int sock = 0;

// A function that handles the incoming messages from the server
void *server_handler(void *arg){

    char buffer[1024] = {0};

    while (1){

        // Receive messages
        if (recv(sock, buffer, 1024, 0) < 0){
            printf("Connection lost");
            exit(0);
        }

        // Display the incoming messages
        printf("Server: %s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
}

int main(){

    char username[20];

    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <=0 ){
        printf("Invalid address/ Address not supported");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("Connection failed");
        return -1;
    }

    printf("Enter your username: ");
    scanf("%s", username);

    // Login confirmation
    char login_message[50];
    sprintf(login_message, "%s has joined the chat.\n", username);
    send(sock, login_message, strlen(login_message), 0);

    pthread_t server_thread;

    // A thread for the server_handler function
    if (pthread_create(&server_thread, NULL, server_handler, (void*) &sock) != 0){
        printf("Thread creation error");
        return -1;
    }

    // A loop for sending messages
    while (1){

        char message[1000];

        // Taking user input
        fgets(message, 1000, stdin);
        if (strlen(message) == 1){
            continue;
        }

        // Concating the username with the message
        char temp[1024];
        sprintf(temp, "%s: %s", username, message);

        // Send messages
        send(sock, temp, strlen(temp), 0);
    }

    close(sock);

    return 0;
}