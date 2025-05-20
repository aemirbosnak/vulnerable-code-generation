//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open()
#include <unistd.h> // for close()

#define MAXDATASIZE 100 // max number of bytes we can get at once

int main(int argc, char *argv[]) {
    int sockfd;
    int numbytes;
    char buf[MAXDATASIZE];
    struct sockaddr_in server_addr;
    struct hostent *host;
    FILE *fp;

    if (argc != 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // get the host information
    if ((host = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    // initialize the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // get the file name from the user
    printf("Enter the file name you want to download: ");
    scanf("%s", buf);

    // send the file name to the server
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // open a file to store the downloaded data
    fp = fopen("downloaded_file", "wb");

    // receive the file data from the server
    while ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) > 0) {
        fwrite(buf, 1, numbytes, fp);
    }

    // close the file
    fclose(fp);

    // close the socket
    close(sockfd);

    return 0;
}