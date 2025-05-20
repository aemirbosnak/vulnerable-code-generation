//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char hostname[100];
    char username[100];
    char password[100];
    char response[BUFFER_SIZE];

    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);

    printf("Enter POP3 username: ");
    scanf("%s", username);

    printf("Enter POP3 password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char auth_response[BUFFER_SIZE];
    sprintf(response, "USER %s\r\n", username);
    send(sock, response, strlen(response), 0);

    recv(sock, auth_response, BUFFER_SIZE, 0);
    printf("Server response: %s", auth_response);

    sprintf(response, "PASS %s\r\n", password);
    send(sock, response, strlen(response), 0);

    recv(sock, auth_response, BUFFER_SIZE, 0);
    printf("Server response: %s", auth_response);

    char list_response[BUFFER_SIZE];
    sprintf(response, "LIST\r\n");
    send(sock, response, strlen(response), 0);

    recv(sock, list_response, BUFFER_SIZE, 0);
    printf("Server response: %s", list_response);

    close(sock);

    return 0;
}