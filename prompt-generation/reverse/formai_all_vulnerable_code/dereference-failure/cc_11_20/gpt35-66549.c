//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send HTTP request to server
    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s:%d\r\n\r\n", argv[1], portno);

    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response from server
    int content_length = 0; // keep track of content length
    int header_end = 0; // flag to mark end of header
    int i = 0; // counter for buffer
    while ((n = read(sockfd, &buffer[i], 1)) > 0) {
        // check if end of header is reached
        if (i > 3 && buffer[i] == '\n' && buffer[i-1] == '\r' && buffer[i-2] == '\n' && buffer[i-3] == '\r') {
            header_end = 1;
            // extract content length from header
            char* content_length_str = strstr(buffer, "Content-Length: ");
            if (content_length_str != NULL) {
                content_length_str += strlen("Content-Length: ");
                content_length = atoi(content_length_str);
            }
        }
        // check if end of response is reached
        if (header_end && i >= content_length+4) { // add 4 to account for the header bytes
            break;
        }
        i++;
    }

    // Print response from server
    printf("%s", &buffer[strlen(buffer)-(content_length+4)]);

    close(sockfd);
    return 0;
}