//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define USER_LEN 100
#define PASS_LEN 100
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char username[USER_LEN], password[PASS_LEN], buffer[BUF_SIZE];
    int success = 0;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Get server information */
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    /* Assign values for server address struct */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    /* Attempt to connect to server */
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Receive welcome message */
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    /* Send username */
    bzero(username, USER_LEN);
    printf("Username: ");
    fgets(username, USER_LEN-1, stdin);
    n = send(sockfd, username, strlen(username), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Send password */
    bzero(password, PASS_LEN);
    printf("Password: ");
    fgets(password, PASS_LEN-1, stdin);
    n = send(sockfd, password, strlen(password), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Check for success */
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    if (strstr(buffer, "+OK login successful")) {
        printf("Successfully logged in as %s", username);
        success = 1;
    } else {
        printf("Invalid username or password\n");
        close(sockfd);
        exit(0);
    }

    /* List messages */
    printf("Getting message list...\n");
    n = send(sockfd, "LIST\n", 5, 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Message List:\n");
    printf("%s", buffer);

    /* Logout */
    n = send(sockfd, "QUIT\n", 5, 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    close(sockfd);
    printf("Logged out.\n");
    exit(0);

    return 0;
}