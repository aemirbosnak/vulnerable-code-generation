//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sock, connfd, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    
    printf("Welcome to my immersive C Socket Programming example!\n");
    printf("Enter an IP address and port number to connect to below:\n");
    
    char ip_address[16];
    int port;
    
    printf("IP Address: ");
    scanf("%s", ip_address);
    printf("Port Number: ");
    scanf("%d", &port);
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }
    
    printf("You are now connected!\n");
    printf("Type 'quit' to disconnect.\n\n");
    
    while (1) {
        printf("> ");
        fflush(stdout);
        char message[1024];
        scanf("%s", message);
        
        send(sock, message, strlen(message), 0);
        
        if (strcmp(message, "quit") == 0) {
            printf("\nDisconnected from server.\n");
            break;
        }
        
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);
        memset(buffer, 0, 1024);
    }
    
    close(sock);
    return 0;
}