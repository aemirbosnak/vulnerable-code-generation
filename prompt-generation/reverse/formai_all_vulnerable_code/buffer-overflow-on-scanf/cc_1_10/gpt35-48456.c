//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: intelligent
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
  
#define PORTNUM 9000  
  
int main(int argc, char** argv) {  
    int s;  
    char* server_name;  
    struct sockaddr_in servaddr;  
    char buffer[1024];  
    int n;  
  
    if (argc < 2) {  
        printf("Enter IP address of server: ");  
        scanf("%s", server_name);  
    } else {  
        server_name = argv[1];  
    }  
  
    // Create socket  
    s = socket(AF_INET, SOCK_STREAM, 0);  
    if (s < 0) {  
        printf("Socket creation failed\n");  
        exit(1);  
    }  
  
    // Initialize server details  
    bzero(&servaddr, sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_port = htons(PORTNUM);  
    inet_pton(AF_INET, server_name, &servaddr.sin_addr);  
  
    // Connect to server  
    if (connect(s, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {  
        printf("Connection failed\n");  
        exit(1);  
    }  
  
    // Now connected to server  
    printf("Connected to server %s...\n", server_name);  
  
    while (1) {  
        printf("Enter message: ");  
        bzero(buffer, sizeof(buffer));  
        fgets(buffer, sizeof(buffer), stdin);  
        n = write(s, buffer, strlen(buffer));  
        if (n < 0) {  
            printf("Error writing to socket\n");  
            exit(1);  
        }  
  
        bzero(buffer, sizeof(buffer));  
        n = read(s, buffer, sizeof(buffer));  
        if (n < 0) {  
            printf("Error reading from socket\n");  
            exit(1);  
        }  
        printf("Received from server: %s\n", buffer);  
    }  
      
    return 0;  
}