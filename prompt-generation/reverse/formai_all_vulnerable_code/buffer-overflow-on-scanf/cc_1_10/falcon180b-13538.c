//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char server_ip[16];
    char username[32];
    char password[32];
    char command[1024];
    char response[BUFFER_SIZE];
    int n;
    
    printf("Enter FTP server IP address: ");
    scanf("%s", server_ip);
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }
    
    printf("Connected to server\n");
    
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);
    
    n = recv(sock, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);
    
    while (1) {
        printf("Enter command (quit to exit): ");
        fgets(command, sizeof(command), stdin);
        
        if (strcmp(command, "quit") == 0) {
            break;
        }
        
        send(sock, command, strlen(command), 0);
        
        n = recv(sock, response, BUFFER_SIZE, 0);
        response[n] = '\0';
        printf("Server response: %s\n", response);
    }
    
    close(sock);
    return 0;
}