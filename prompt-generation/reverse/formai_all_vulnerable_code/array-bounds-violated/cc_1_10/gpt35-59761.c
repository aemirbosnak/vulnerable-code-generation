//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESPONSE_SIZE 1024

/* Function to establish a connection to the POP3 server */
int connect_to_server(char* hostname, int port){
    int sockfd;
    struct hostent *he;
    struct sockaddr_in their_addr;

    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(port);
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

/* Function to send a command to the POP3 server */
void send_command(int sockfd, char* command, char* response){
    char buffer[MAX_RESPONSE_SIZE];
    int numbytes;

    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        exit(1);
    }

    if ((numbytes = recv(sockfd, buffer, MAX_RESPONSE_SIZE-1, 0)) == -1) {
        perror("recv");
        exit(1);
    }
    buffer[numbytes] = '\0';
    strcpy(response, buffer);
}

int main(int argc, char** argv) {
    /* Establish a connection to the POP3 server */
    int sockfd = connect_to_server("pop3.example.com", 110);

    /* Receive the server greeting */
    char response[MAX_RESPONSE_SIZE];
    send_command(sockfd, "", response);
    printf("%s", response);

    /* Log in to the server */
    send_command(sockfd, "USER username", response);
    printf("%s", response);
    send_command(sockfd, "PASS password", response);
    printf("%s", response);

    /* Retrieve a list of messages */
    send_command(sockfd, "LIST", response);
    printf("%s", response);

    /* Retrieve the first message */
    send_command(sockfd, "RETR 1", response);
    printf("%s", response);

    /* Close the connection to the server */
    send_command(sockfd, "QUIT", response);
    printf("%s", response);
    close(sockfd);

    return 0;
}