//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LEN 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
    char command[MAX_LEN];

    // get the server name and port number from the user
    printf("Enter server name: ");
    scanf("%s", buffer);
    server = gethostbyname(buffer);
    printf("Enter server port number: ");
    scanf("%d", &portno);

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // set up the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to the server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    // read the welcome message
    bzero(buffer, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send the username to the server
    bzero(username, MAX_LEN);
    printf("Username: ");
    scanf("%s", username);
    sprintf(command, "USER %s\r\n", username);
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // read the response from the server
    bzero(buffer, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send the password to the server
    bzero(password, MAX_LEN);
    printf("Password: ");
    scanf("%s", password);
    sprintf(command, "PASS %s\r\n", password);
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // read the response from the server
    bzero(buffer, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send the LIST command to the server
    sprintf(command, "LIST\r\n");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // read the response from the server
    bzero(buffer, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send the QUIT command to the server
    sprintf(command, "QUIT\r\n");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // read the response from the server
    bzero(buffer, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // close the socket
    close(sockfd);

    return 0;
}