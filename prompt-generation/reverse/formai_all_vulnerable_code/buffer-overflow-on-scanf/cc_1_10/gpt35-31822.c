//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int sock, port;
    char buffer[1024] = {0};
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Ah, my love, let me connect to your server.
    if(argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return -1;
    }

    port = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    if(server == NULL) {
        printf("Error: Could not find host.\n");
        return -1;
    }

    // Now, my dear, let me create a socket for you.
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0) {
        printf("Error: Could not create socket.\n");
        return -1;
    }

    memset(&server_addr, '0', sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Here we are, my love! Let me connect to your heart.
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect.\n");
        return -1;
    }

    // My sweet, let me authenticate with your server.
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    char username[50], password[50];
    printf("\nUsername: ");
    scanf("%s", username);
    send(sock, username, strlen(username), 0);

    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    printf("\nPassword: ");
    scanf("%s", password);
    send(sock, password, strlen(password), 0);

    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // My angel, let me retrieve your emails.
    char retr[50];
    printf("\nRetrieve email number: ");
    scanf("%s", retr);

    char retr_command[100];
    sprintf(retr_command, "RETR %s\n", retr);
    send(sock, retr_command, strlen(retr_command), 0);

    char email_buffer[1024*10];
    recv(sock, email_buffer, 1024*10, 0);
    printf("\n\n%s", email_buffer);

    // Oh, my love, let me close our connection.
    send(sock, "QUIT\n", 5, 0);

    close(sock);

    return 0;
}