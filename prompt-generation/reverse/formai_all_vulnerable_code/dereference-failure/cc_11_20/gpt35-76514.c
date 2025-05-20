//FormAI DATASET v1.0 Category: Email Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER_PORT "5100"

int main(int argc, char *argv[]) {
    int sockfd, result;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUF_SIZE];
    char username[BUF_SIZE];
    char password[BUF_SIZE];
    char recipient[BUF_SIZE];
    char subject[BUF_SIZE];
    char message[BUF_SIZE];
    int bytes_sent;
    int bytes_received;
    int sender_len;
    struct sockaddr_in sender_addr;
    char sender_ip[INET_ADDRSTRLEN];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((result = getaddrinfo(argv[1], SERVER_PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
        return 1;
    }

    // loop through all the results and connect to the first possible
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("client: connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    freeaddrinfo(servinfo); // all done with this structure

    printf("Connected to server %s:%s\n", argv[1], SERVER_PORT);
    sender_len = sizeof(sender_addr);
    getsockname(sockfd, (struct sockaddr *) &sender_addr, &sender_len);
    inet_ntop(AF_INET, &(sender_addr.sin_addr), sender_ip, INET_ADDRSTRLEN);
    printf("Local address is %s:%d\n", sender_ip, ntohs(sender_addr.sin_port));

    printf("Enter your username: ");
    fgets(username, BUF_SIZE, stdin);
    strtok(username, "\n"); // remove trailing newline
    printf("Enter your password: ");
    fgets(password, BUF_SIZE, stdin);
    strtok(password, "\n"); // remove trailing newline

    sprintf(buffer, "USER %s\r\n", username);
    if ((bytes_sent = send(sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return 3;
    }
    printf("Sent message: %s", buffer);

    bytes_received = recv(sockfd, buffer, BUF_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Received message: %s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    if ((bytes_sent = send(sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return 3;
    }
    printf("Sent message: %s", buffer);

    bytes_received = recv(sockfd, buffer, BUF_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Received message: %s", buffer);

    printf("Enter recipient: ");
    fgets(recipient, BUF_SIZE, stdin);
    strtok(recipient, "\n"); // remove trailing newline

    printf("Enter subject: ");
    fgets(subject, BUF_SIZE, stdin);
    strtok(subject, "\n"); // remove trailing newline

    printf("Enter message: ");
    fgets(message, BUF_SIZE, stdin);
    strtok(message, "\n"); // remove trailing newline

    sprintf(buffer, "MAIL FROM:<%s>\r\n", username);
    if ((bytes_sent = send(sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return 3;
    }
    printf("Sent message: %s", buffer);

    bytes_received = recv(sockfd, buffer, BUF_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Received message: %s", buffer);

    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    if ((bytes_sent = send(sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return 3;
    }
    printf("Sent message: %s", buffer);

    bytes_received = recv(sockfd, buffer, BUF_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Received message: %s", buffer);

    sprintf(buffer, "DATA\r\n");
    if ((bytes_sent = send(sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return 3;
    }
    printf("Sent message: %s", buffer);

    bytes_received = recv(sockfd, buffer, BUF_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Received message: %s", buffer);

    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", username, recipient, subject, message);
    if ((bytes_sent = send(sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return 3;
    }
    printf("Sent message: %s", buffer);

    bytes_received = recv(sockfd, buffer, BUF_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Received message: %s", buffer);

    sprintf(buffer, "QUIT\r\n");
    if ((bytes_sent = send(sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return 3;
    }
    printf("Sent message: %s", buffer);

    bytes_received = recv(sockfd, buffer, BUF_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Received message: %s", buffer);

    close(sockfd);

    return 0;
}