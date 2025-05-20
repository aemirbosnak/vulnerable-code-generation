//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_USERNAME_LENGTH 64
#define MAX_PASSWORD_LENGTH 64

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char hostname[256];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char response[MAX_LINE_LENGTH];
    int response_length;
    int auth_state = 0;
    int ret;
    
    // Get hostname from user
    printf("Enter hostname: ");
    scanf("%s", hostname);
    
    // Get username from user
    printf("Enter username: ");
    scanf("%s", username);
    
    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);
    
    // Connect to server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    
    // Connect to server
    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error: Failed to connect to server.\n");
        return 1;
    }
    
    // Send username and password to server
    ret = send(sock, username, strlen(username), 0);
    if (ret == -1) {
        printf("Error: Failed to send username to server.\n");
        return 1;
    }
    
    ret = send(sock, password, strlen(password), 0);
    if (ret == -1) {
        printf("Error: Failed to send password to server.\n");
        return 1;
    }
    
    // Read server response
    response_length = recv(sock, response, MAX_LINE_LENGTH, 0);
    if (response_length <= 0) {
        printf("Error: Failed to receive server response.\n");
        return 1;
    }
    
    response[response_length] = '\0';
    printf("Server response: %s\n", response);
    
    close(sock);
    return 0;
}