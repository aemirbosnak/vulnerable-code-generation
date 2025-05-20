//Falcon-180B DATASET v1.0 Category: Networking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT "80"
#define SERVER "www.example.com"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int n;
    char *filename = "index.html";
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        send(sockfd, line, read, 0);
    }

    fclose(fp);
    free(line);

    exit(EXIT_SUCCESS);
}