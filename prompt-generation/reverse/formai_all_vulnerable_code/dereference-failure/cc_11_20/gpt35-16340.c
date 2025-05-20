//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 587

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not open socket");
        return -1;
    }

    server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        printf("Error: No such host");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect");
        return -1;
    }

    char buffer[256];
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
        printf("Error: Could not read");
        return -1;
    }
    printf("%s\n",buffer);

    char *hello = "EHLO example.com\n";
    n = write(sockfd,hello,strlen(hello));
    if (n < 0) {
        printf("Error: Could not write");
        return -1;
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
        printf("Error: Could not read");
        return -1;
    }
    printf("%s\n",buffer);

    char *from = "MAIL FROM: <cyberpunk@example.com>\n";
    n = write(sockfd,from,strlen(from));
    if (n < 0) {
        printf("Error: Could not write");
        return -1;
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
        printf("Error: Could not read");
        return -1;
    }
    printf("%s\n",buffer);

    char *to = "RCPT TO: <recipient@example.com>\n";
    n = write(sockfd,to,strlen(to));
    if (n < 0) {
        printf("Error: Could not write");
        return -1;
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
        printf("Error: Could not read");
        return -1;
    }
    printf("%s\n",buffer);

    char *data = "DATA\n";
    n = write(sockfd,data,strlen(data));
    if (n < 0) {
        printf("Error: Could not write");
        return -1;
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
        printf("Error: Could not read");
        return -1;
    }
    printf("%s\n",buffer);

    char *message = "Subject: Cyberpunk SMTP Client\nThis is a test message from the Cyberpunk SMTP client.\n.\n";
    n = write(sockfd,message,strlen(message));
    if (n < 0) {
        printf("Error: Could not write");
        return -1;
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
        printf("Error: Could not read");
        return -1;
    }
    printf("%s\n",buffer);

    char *quit = "QUIT\n";
    n = write(sockfd,quit,strlen(quit));
    if (n < 0) {
        printf("Error: Could not write");
        return -1;
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
        printf("Error: Could not read");
        return -1;
    }
    printf("%s\n",buffer);

    close(sockfd);
    
    return 0;
}