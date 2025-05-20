//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server>\n", argv[0]);
        exit(1);
    }

    int sockfd, port;
    struct sockaddr_in server;
    char buf[256];
    char command[256];
    int result;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(5000); // default port
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // default server

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) error("ERROR connecting");

    printf("Connected to %s on port %d\n", argv[1], ntohs(server.sin_port));

    // prompt user for command
    printf("Enter command (help, exit): ");
    fgets(command, sizeof(command), stdin);

    // handle commands
    if (strcasecmp(command, "help") == 0) {
        printf("Available commands:\n");
        printf("  -ls <dir>\tlist files in directory\n");
        printf("  -get <file>\tdownload file\n");
        printf("  -put <file>\tupload file\n");
        printf("  -exit\tquit\n");
    } else if (strcasecmp(command, "exit") == 0) {
        close(sockfd);
        exit(0);
    } else if (strstr(command, "-ls")!= NULL) {
        if (sscanf(command, "-ls %s", buf) == 1) {
            printf("Listing directory '%s':\n", buf);
            // code to list files in directory
        } else {
            printf("Invalid command format\n");
        }
    } else if (strstr(command, "-get")!= NULL) {
        if (sscanf(command, "-get %s", buf) == 1) {
            printf("Downloading file '%s':\n", buf);
            // code to download file
        } else {
            printf("Invalid command format\n");
        }
    } else if (strstr(command, "-put")!= NULL) {
        if (sscanf(command, "-put %s", buf) == 1) {
            printf("Uploading file '%s':\n", buf);
            // code to upload file
        } else {
            printf("Invalid command format\n");
        }
    } else {
        printf("Invalid command\n");
    }

    return 0;
}