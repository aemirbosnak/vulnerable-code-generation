//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 110 // POP3 Port Number
#define IP "127.0.0.1" // Localhost IP Address

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[1024],user[50],pass[50];
    char buf[1024],*p,*q;
    int n;

    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        error("Could not create socket");
    }

    // Set server attributes
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(IP);

    // Connect to server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) == -1) {
        error("Could not connect to server");
    }
    
    // Receive welcome message from server
    n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        error("Error receiving message from server");
    }
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send username to server
    printf("\nEnter username: ");
    scanf("%s", user);
    snprintf(buf, sizeof(buf), "USER %s\r\n", user);
    n = send(sock, buf, strlen(buf), 0);
    if (n < 0) {
        error("Error sending username to server");
    }
    
    // Receive response from server
    n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        error("Error receiving response from server");
    }
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send password to server
    printf("\nEnter password: ");
    scanf("%s", pass);
    snprintf(buf, sizeof(buf), "PASS %s\r\n", pass);
    n = send(sock, buf, strlen(buf), 0);
    if (n < 0) {
        error("Error sending password to server");
    }
    
    // Receive response from server
    n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        error("Error receiving response from server");
    }
    
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Send command to list emails
    n = send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    if (n < 0) {
        error("Error sending command to server");
    }
    
    // Receive response from server
    n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        error("Error receiving response from server");
    }
    
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Parse email list
    p = strstr(buffer, "\r\n");
    if (p == NULL) {
        error("Error parsing email list");
    }
    p += 2;
    q = strstr(p, "\r\n.\r\n");
    if (q == NULL) {
        error("Error parsing email list");
    }
    *q = '\0';
    printf("Email list:\n%s\n", p);
    
    // Quit session
    n = send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    if (n < 0) {
        error("Error sending command to server");
    }
    
    // Receive goodbye message from server
    n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        error("Error receiving message from server");
    }
    
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Close socket
    close(sock);
    
    return 0;
}