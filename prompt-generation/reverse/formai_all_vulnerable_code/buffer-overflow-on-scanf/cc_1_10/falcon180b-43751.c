//Falcon-180B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 1000
#define PORT 1234

int main() {
    
    char username[MAX];
    char password[MAX];
    char server_ip[MAX];
    char email_subject[MAX];
    char email_body[MAX];
    int server_socket, client_socket, valread;
    struct sockaddr_in server, client;
    int opt = 1;
    int addrlen = sizeof(client);

    // Get user input for server IP, username, and password
    printf("Enter server IP: ");
    scanf("%[^\n]", server_ip);
    printf("Enter username: ");
    scanf("%[^\n]", username);
    printf("Enter password: ");
    scanf("%[^\n]", password);

    // Connect to server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket.\n");
        exit(0);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option.\n");
        exit(0);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server.\n");
        exit(0);
    }

    // Authenticate with server
    send(server_socket, username, strlen(username), 0);
    send(server_socket, password, strlen(password), 0);

    // Receive server response
    recv(server_socket, &valread, sizeof(valread), 0);

    if (valread == 1) {
        printf("Authentication successful.\n");
    } else {
        printf("Authentication failed.\n");
        exit(0);
    }

    // Send email
    printf("Enter email subject: ");
    scanf("%[^\n]", email_subject);
    printf("Enter email body: ");
    scanf("%[^\n]", email_body);

    send(server_socket, email_subject, strlen(email_subject), 0);
    send(server_socket, email_body, strlen(email_body), 0);

    // Close connection
    close(server_socket);

    return 0;
}