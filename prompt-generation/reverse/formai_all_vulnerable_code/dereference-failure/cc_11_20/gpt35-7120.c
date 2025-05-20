//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
// SMTP client example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096
#define PORT_NUM "25" // SMTP uses port 25

int main(int argc, char *argv[]) {
    int sockfd, ret, bytes;
    char buf[BUF_SIZE];
    struct addrinfo hints, *servinfo, *p;
    char s[INET_ADDRSTRLEN];
    char *server_address, *from_address, *to_address, *subject, *body;

    if (argc < 6) { // Check if all required arguments are provided
        fprintf(stderr, "Usage: ./smtp_client <server_address> <from_address> <to_address> <subject> <body>\n");
        exit(1);
    }

    server_address = argv[1];
    from_address = argv[2];
    to_address = argv[3];
    subject = argv[4];
    body = argv[5];

    // Set up hints structure for getaddrinfo()
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Call getaddrinfo() to get the server address info
    if ((ret = getaddrinfo(server_address, PORT_NUM, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    // Loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        // Create a socket for this result
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        // Connect to the server
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        // Successfully connected to the server
        break;
    }

    if (p == NULL) { // Failed to connect to the server
        fprintf(stderr, "Failed to connect\n");
        exit(2);
    }

    // Convert the server IP address to a string
    inet_ntop(p->ai_family, &(((struct sockaddr_in*)p->ai_addr)->sin_addr), s, sizeof s);
    printf("Connected to %s\n", s);

    freeaddrinfo(servinfo); // Done with the address info

    // Read the server greeting
    bytes = recv(sockfd, buf, sizeof buf, 0);
    if (bytes == -1) {
        perror("recv");
        exit(3);
    }
    buf[bytes] = '\0';
    printf("Server: %s", buf);

    // Send the HELO command
    sprintf(buf, "HELO mydomain.com\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(4);
    }
    printf("Client: %s", buf);

    // Read the server response
    bytes = recv(sockfd, buf, sizeof buf, 0);
    if (bytes == -1) {
        perror("recv");
        exit(5);
    }
    buf[bytes] = '\0';
    printf("Server: %s", buf);

    // Send the MAIL FROM command
    sprintf(buf, "MAIL FROM:<%s>\r\n", from_address);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(6);
    }
    printf("Client: %s", buf);

    // Read the server response
    bytes = recv(sockfd, buf, sizeof buf, 0);
    if (bytes == -1) {
        perror("recv");
        exit(7);
    }
    buf[bytes] = '\0';
    printf("Server: %s", buf);

    // Send the RCPT TO command
    sprintf(buf, "RCPT TO:<%s>\r\n", to_address);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(8);
    }
    printf("Client: %s", buf);

    // Read the server response
    bytes = recv(sockfd, buf, sizeof buf, 0);
    if (bytes == -1) {
        perror("recv");
        exit(9);
    }
    buf[bytes] = '\0';
    printf("Server: %s", buf);

    // Send the DATA command
    sprintf(buf, "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(10);
    }
    printf("Client: %s", buf);

    // Read the server response
    bytes = recv(sockfd, buf, sizeof buf, 0);
    if (bytes == -1) {
        perror("recv");
        exit(11);
    }
    buf[bytes] = '\0';
    printf("Server: %s", buf);

    // Send the email content
    sprintf(buf, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n",
        from_address, to_address, subject, body);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(12);
    }
    printf("Client: %s", buf);

    // Read the server response
    bytes = recv(sockfd, buf, sizeof buf, 0);
    if (bytes == -1) {
        perror("recv");
        exit(13);
    }
    buf[bytes] = '\0';
    printf("Server: %s", buf);

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(14);
    }
    printf("Client: %s", buf);

    // Read the server response
    bytes = recv(sockfd, buf, sizeof buf, 0);
    if (bytes == -1) {
        perror("recv");
        exit(15);
    }
    buf[bytes] = '\0';
    printf("Server: %s", buf);

    // Close the connection
    close(sockfd);

    return 0;
}