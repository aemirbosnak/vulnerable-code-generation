//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
    printf("Hello there! I am a networking bot, ready to connect you to the world!\n");
    printf("So, where do you want to go? Enter the IP address and port number of your destination:\n");

    char dest_ip[16];
    int dest_port;
    scanf("%s %d", dest_ip, &dest_port);

    printf("\nConnecting to %s:%d...\n", dest_ip, dest_port);

    int network_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(network_socket == -1){
        printf("Oops! Something went wrong! Could not create socket.\n");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(dest_port);
    inet_aton(dest_ip, &server_address.sin_addr);

    int connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if(connection_status == -1){
        printf("Uh oh! Could not establish connection!\n");
        return 1;
    }

    printf("\nConnection successful! You are now connected to %s:%d\n", dest_ip, dest_port);

    printf("\nNow, what do you want to say to them? Type your message below and press Enter:\n");

    char message[1024];
    scanf("%s", message);

    int send_status = send(network_socket, message, sizeof(message), 0);
    if(send_status == -1){
        printf("Oops! Error in sending message. :(\n");
        return 1;
    }

    printf("\nSent successfully! Waiting for a response...\n");

    char response[1024];
    int response_size = recv(network_socket, response, sizeof(response), 0);

    if(response_size == -1){
        printf("Uh oh! Error in receiving response.\n");
        return 1;
    }

    printf("\nReceived a response: \"%s\". Haha, they said that! :D\n", response);

    printf("\nDisconnecting from %s:%d...\n", dest_ip, dest_port);

    close(network_socket);

    printf("\nBye bye! Hope you had a good chat. Come back again!\n");

    return 0;
}