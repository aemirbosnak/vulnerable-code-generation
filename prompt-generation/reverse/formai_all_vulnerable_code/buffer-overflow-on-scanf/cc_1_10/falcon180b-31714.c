//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX];
    int n;

    if(argc!= 3){
        printf("Usage:./client <IP Address> <Message>\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1){
        printf("Socket creation failed\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1){
        printf("Connection failed\n");
        exit(1);
    }

    printf("Enter the message to be sent to the server: ");
    scanf("%[^\n]", buffer);

    n = send(sock, buffer, strlen(buffer), 0);

    if(n == -1){
        printf("Message sending failed\n");
        exit(1);
    }

    close(sock);

    printf("Message sent successfully\n");

    return 0;
}