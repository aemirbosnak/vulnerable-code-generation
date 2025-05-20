//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    pthread_t thread_id;
    int sock;
    struct sockaddr_in server_addr;
    char hostname[20] = "localhost";
    char username[20] = "username";
    char password[20] = "password";
    char *response;
    char *line;
    int num_lines;
    char buffer[MAX_LINE];
    FILE *fp;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    response = (char *)malloc(MAX_LINE * sizeof(char));
    num_lines = 0;

    while ((line = fgets(buffer, MAX_LINE, stdin))!= NULL) {
        strcat(response, line);
        strcat(response, "\r\n");
        num_lines++;
    }

    strcat(response, ".\r\n");

    send(sock, response, strlen(response), 0);

    free(response);

    close(sock);

    return 0;
}