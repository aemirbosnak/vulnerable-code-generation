//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define PORT 21

struct ftp_data {
    char host[100];
    char user[100];
    char pass[100];
    int port;
};

void *ftp_thread(void *param) {
    struct ftp_data *ftp = (struct ftp_data *) param;
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname(ftp->host);
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(ftp->port);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    char username[100] = "USER ";
    strcat(username, ftp->user);
    send(sockfd, username, strlen(username), 0);

    char password[100] = "PASS ";
    strcat(password, ftp->pass);
    send(sockfd, password, strlen(password), 0);

    char command[100] = "PWD\r\n";
    send(sockfd, command, strlen(command), 0);

    char buffer[BUF_SIZE];
    while (1) {
        bzero(buffer, BUF_SIZE);
        n = read(sockfd, buffer, BUF_SIZE);
        if (n <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return NULL;
}

int main() {
    struct ftp_data ftp;

    printf("Enter hostname: ");
    scanf("%s", ftp.host);

    printf("Enter username: ");
    scanf("%s", ftp.user);

    printf("Enter password: ");
    scanf("%s", ftp.pass);

    ftp.port = PORT;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, ftp_thread, (void *)&ftp);

    pthread_join(thread_id, NULL);

    return 0;
}