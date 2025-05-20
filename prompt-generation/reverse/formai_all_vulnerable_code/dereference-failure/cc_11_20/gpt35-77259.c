//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    // check number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server-ip> <port>\n", argv[0]);
        exit(1);
    }

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in creating socket");
        exit(1);
    }

    // get hostname from IP address
    struct hostent *he;
    if ((he = gethostbyaddr((const char *) &argv[1], sizeof(argv[1]), AF_INET)) == NULL) {
        herror("Error in gethostbyaddr");
        exit(1);
    }

    // set server address
    struct sockaddr_in serveraddr;
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    memcpy(&serveraddr.sin_addr, he->h_addr_list[0], he->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error in connecting to server");
        exit(1);
    }

    // receive welcome message from server
    char buffer[MAXSIZE];
    bzero(buffer, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error in receiving message from server");
        exit(1);
    }
    printf("%s", buffer);

    // login to server
    char username[MAXSIZE], password[MAXSIZE];
    bzero(username, sizeof(username));
    bzero(password, sizeof(password));
    printf("Username: ");
    fgets(username, MAXSIZE, stdin);
    printf("Password: ");
    fgets(password, MAXSIZE, stdin);
    strcat(username, password);

    if (send(sockfd, username, strlen(username), 0) < 0) {
        perror("Error in sending username and password");
        exit(1);
    }

    // receive login status from server
    bzero(buffer, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error in receiving message from server");
        exit(1);
    }
    if (strcmp(buffer, "Login Successful\n") != 0) {
        printf("%s", buffer);
        exit(1);
    }
    printf("%s", buffer);

    // send commands to server
    char command[MAXSIZE];
    bzero(command, sizeof(command));
    while (1) {
        printf("ftp> ");
        fgets(command, MAXSIZE, stdin);
        if (send(sockfd, command, strlen(command), 0) < 0) {
            perror("Error in sending command to server");
            exit(1);
        }

        // receive response from server
        bzero(buffer, sizeof(buffer));
        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("Error in receiving message from server");
            exit(1);
        }
        printf("%s", buffer);

        // quit if command is quit or exit
        if (strcmp(command, "quit\n") == 0 || strcmp(command, "exit\n") == 0)
            break;
    }

    // close socket
    close(sockfd);
    return 0;
}