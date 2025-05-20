//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char username[50], password[50];
    char command[100];
    char buffer[BUFFER_SIZE];
    int n;

    printf("Enter the FTP server address: ");
    scanf("%s", argv[1]);

    host = gethostbyname(argv[1]);

    if (host == NULL) {
        printf("Host not found.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Socket creation failed.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed.\n");
        exit(1);
    }

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the password: ");
    scanf("%s", password);

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        buffer[n] = '\0';
        printf("%s", buffer);

        if (strstr(buffer, "220")!= NULL) {
            break;
        }
    }

    printf("Connected to the FTP server.\n");

    while (1) {
        printf("Enter the command (type 'quit' to exit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            sprintf(command, "QUIT\r\n");
            send(sockfd, command, strlen(command), 0);
            break;
        } else {
            send(sockfd, command, strlen(command), 0);
        }

        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}