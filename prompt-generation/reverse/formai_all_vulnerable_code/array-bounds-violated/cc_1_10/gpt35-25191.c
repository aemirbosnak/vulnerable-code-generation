//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: brave
// POP3 Client Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    // Establish connection with server
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = inet_addr("YOUR_SERVER_IP_ADDRESS");
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection error\n");
        exit(1);
    }
    char buffer[MAXSIZE];
    int size = recv(sock, buffer, sizeof(buffer), 0);
    buffer[size] = 0;
    printf("%s", buffer);
    
    // Send username
    char user[MAXSIZE];
    printf("Enter username: ");
    scanf("%s", user);
    sprintf(buffer, "USER %s\r\n", user);
    send(sock, buffer, strlen(buffer), 0);
    size = recv(sock, buffer, sizeof(buffer), 0);
    buffer[size] = 0;
    printf("%s", buffer);
    
    // Send password
    char pass[MAXSIZE];
    printf("Enter password: ");
    scanf("%s", pass);
    sprintf(buffer, "PASS %s\r\n", pass);
    send(sock, buffer, strlen(buffer), 0);
    size = recv(sock, buffer, sizeof(buffer), 0);
    buffer[size] = 0;
    printf("%s", buffer);
    
    // List messages
    sprintf(buffer, "LIST\r\n");
    send(sock, buffer, strlen(buffer), 0);
    size = recv(sock, buffer, sizeof(buffer), 0);
    buffer[size] = 0;
    printf("%s", buffer);
    
    // Select message
    int message;
    printf("Enter message number: ");
    scanf("%d", &message);
    sprintf(buffer, "RETR %d\r\n", message);
    send(sock, buffer, strlen(buffer), 0);
    size = recv(sock, buffer, sizeof(buffer), 0);
    buffer[size] = 0;
    printf("%s", buffer);
    
    // Delete message
    printf("Delete message? (y/n): ");
    char del;
    scanf(" %c", &del);
    if (del == 'y' || del == 'Y') {
        sprintf(buffer, "DELE %d\r\n", message);
        send(sock, buffer, strlen(buffer), 0);
        size = recv(sock, buffer, sizeof(buffer), 0);
        buffer[size] = 0;
        printf("%s", buffer);
    }
    
    // Quit
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    size = recv(sock, buffer, sizeof(buffer), 0);
    buffer[size] = 0;
    printf("%s", buffer);
    
    // Close connection
    close(sock);
    return 0;
}