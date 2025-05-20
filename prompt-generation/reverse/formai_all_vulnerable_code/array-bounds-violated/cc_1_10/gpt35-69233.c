//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    char* domainName = "www.example.com";
    struct in_addr destIP;
    struct sockaddr_in serv_addr;
    if (inet_pton(AF_INET, domainName, &destIP) != 1) {
        printf("Invalid Address");
        return 1;
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = destIP.s_addr;
    serv_addr.sin_port = htons(80);

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Could not connect to server");
        return 1;
    }

    char* message = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (send(sock, message, strlen(message), 0) == -1) {
        printf("Could not send request");
        return 1;
    }

    char response[MAX_SIZE];
    int recv_size = 0;
    while ((recv_size = recv(sock, response, MAX_SIZE-1, 0)) > 0) {
        response[recv_size] = '\0';
        printf("%s", response);
    }
    printf("\n");

    close(sock);
    return 0;
}