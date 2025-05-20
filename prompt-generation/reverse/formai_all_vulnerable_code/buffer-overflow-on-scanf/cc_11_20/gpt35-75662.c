//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    // check for correct usage
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // get host information
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "Error resolving hostname\n");
        exit(1);
    }

    // setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // authenticate user (username + password)
    char username[BUF_SIZE], password[BUF_SIZE];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    char auth_msg[BUF_SIZE];
    sprintf(auth_msg, "USER %s\r\nPASS %s\r\n", username, password);

    if (send(sockfd, auth_msg, strlen(auth_msg), 0) < 0) {
        perror("Error sending authentication message");
        exit(1);
    }

    // receive response from server
    char buf[BUF_SIZE];
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        exit(1);
    }

    printf("%s", buf);

    // enter FTP command loop
    printf("Enter FTP command (QUIT to exit): ");
    while (1) {
        char cmd[BUF_SIZE];
        scanf("%s", cmd);

        char ftp_cmd[BUF_SIZE];
        sprintf(ftp_cmd, "%s\r\n", cmd);

        if (send(sockfd, ftp_cmd, strlen(ftp_cmd), 0) < 0) {
            perror("Error sending FTP command");
            exit(1);
        }

        // receive response from server
        if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
            perror("Error receiving message from server");
            exit(1);
        }

        printf("%s", buf);

        if (strcmp(cmd, "QUIT") == 0)
            break;

        printf("Enter FTP command (QUIT to exit): ");
    }

    // close socket
    close(sockfd);

    return 0;
}