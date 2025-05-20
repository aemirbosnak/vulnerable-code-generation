//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LEN 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in server_addr;
    char username[20];
    char password[20];
    char buffer[MAX_LINE_LEN];
    int n;

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error Opening Socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);

    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error Connecting to Server\n");
        exit(1);
    }

    printf("Connected to Server\n");

    do {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter Command: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            printf("Error Sending Command\n");
            exit(1);
        }

        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);

        if (n <= 0) {
            printf("Error Receiving Response\n");
            exit(1);
        }

        printf("Server Response:\n%s", buffer);

    } while (1);

    close(sockfd);

    return 0;
}