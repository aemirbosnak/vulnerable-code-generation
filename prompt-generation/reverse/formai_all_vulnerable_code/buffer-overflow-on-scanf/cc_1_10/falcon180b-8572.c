//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#define PORT 21
#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char username[32], password[32];
    char command[MAX_COMMAND_LENGTH];
    char response[BUFFER_SIZE];
    int datalen;
    FILE *fp;

    // prompt for username and password
    printf("Enter your FTP username: ");
    scanf("%s", username);
    printf("Enter your FTP password: ");
    scanf("%s", password);

    // connect to FTP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: failed to create socket\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1) {
        printf("Error: failed to connect to server\n");
        return 1;
    }

    // send USER command
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    // send PASS command
    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    // send SYST command
    sprintf(command, "SYST\r\n");
    send(sockfd, command, strlen(command), 0);

    // receive response
    memset(response, 0, BUFFER_SIZE);
    datalen = recv(sockfd, response, BUFFER_SIZE, 0);
    if (datalen <= 0) {
        printf("Error: failed to receive response\n");
        return 1;
    }

    // print response
    printf("Response: %s", response);

    // close socket
    close(sockfd);

    return 0;
}