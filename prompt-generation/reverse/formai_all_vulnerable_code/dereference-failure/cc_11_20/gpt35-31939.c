//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>   
#include <string.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portnum, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];

    if (argc < 3) {
       fprintf(stderr,"usage: %s hostname port\n", argv[0]);
       exit(0);
    }

    portnum = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr,"Error opening socket\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"Error finding host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(portnum);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"Error connecting\n");
        exit(0);
    }

    printf("\nConnected to SMTP server successfully!\n\n");
    printf("Enter 'QUIT' to exit\n");

    while(1) {
        printf("Enter message : ");

        bzero(buffer,1024);
        fgets(buffer,1024,stdin);
        n = strlen(buffer);

        if (n > 0 && buffer[n - 1] == '\n') {
            buffer[n - 1] = '\0';
        }

        if(strcmp(buffer, "QUIT") == 0) {
            printf("\nDisconnected from SMTP server\n\n");
            break;
        }

        n = write(sockfd,buffer,strlen(buffer));

        if (n < 0) {
            fprintf(stderr,"Error writing to socket\n");
            exit(0);
        }

        bzero(buffer,1024);
        n = read(sockfd,buffer,1024);

        if (n < 0) {
            fprintf(stderr,"Error reading from socket\n");
            exit(0);
        }

        printf("\nServer Response: %s\n\n",buffer);
    }

    close(sockfd);
    return 0;
}