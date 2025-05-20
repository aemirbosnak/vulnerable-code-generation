//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char buffer[1024];
    int n;

    printf("Enter POP3 server address: ");
    scanf("%s", inet_ntoa(server_addr.sin_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        exit(0);
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}