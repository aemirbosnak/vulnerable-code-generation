//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 143
#define MAX_RECV_SIZE 1024

int main() {
    int sockfd, n, i, recv_size, port = PORT;
    char buf[MAX_RECV_SIZE], email[256], username[256];
    struct sockaddr_in server_addr;
    struct hostent *server_host;

    printf("Enter email username: ");
    scanf("%s", username);

    printf("Enter email password: ");
    scanf("%s", email);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    server_host = gethostbyname("localhost");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)server_host->h_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    sprintf(buf, "USER %s\r\n", username);
    write(sockfd, buf, strlen(buf));

    sprintf(buf, "PASS %s\r\n", email);
    write(sockfd, buf, strlen(buf));

    sprintf(buf, "RETR\r\n");
    write(sockfd, buf, strlen(buf));

    recv_size = recv(sockfd, buf, MAX_RECV_SIZE, 0);
    printf("Received mail:\n");
    for (i = 0; i < recv_size; i++) {
        printf("%c", buf[i]);
    }

    close(sockfd);

    return 0;
}