//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server ip address> <server port>\n", argv[0]);
        return 1;
    }

    // Step 1: Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: socket creation failed");
        return 1;
    }

    // Step 2: Bind socket
    struct sockaddr_in clientaddr;
    memset(&clientaddr, 0, sizeof(clientaddr));
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_addr.s_addr = htonl(INADDR_ANY); // let the system choose a local address
    clientaddr.sin_port = htons(0); // let the system choose a random port number

    if (bind(sockfd, (struct sockaddr *)&clientaddr, sizeof(clientaddr)) < 0) {
        perror("Error: socket binding failed");
        return 1;
    }

    // Step 3: Connect to server
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error: connection failed");
        return 1;
    }

    // Step 4: Send HELO message
    char helo_msg[BUFSIZE];
    sprintf(helo_msg, "HELO %s\r\n", argv[1]);
    write(sockfd, helo_msg, strlen(helo_msg));

    // Step 5: Receive server response
    char response[BUFSIZE];
    ssize_t n = read(sockfd, response, BUFSIZE);
    if (n <= 0) {
        printf("Error: failed to receive response from server\n");
        return 1;
    }

    // Step 6: Send MAIL FROM message
    char mail_from_msg[BUFSIZE];
    sprintf(mail_from_msg, "MAIL FROM:<%s>\r\n", "sender@example.com");
    write(sockfd, mail_from_msg, strlen(mail_from_msg));

    // Step 7: Receive server response
    n = read(sockfd, response, BUFSIZE);
    if (n <= 0) {
        printf("Error: failed to receive response from server\n");
        return 1;
    }

    // Step 8: Send RCPT TO message
    char rcpt_to_msg[BUFSIZE];
    sprintf(rcpt_to_msg, "RCPT TO:<%s>\r\n", "recipient@example.com");
    write(sockfd, rcpt_to_msg, strlen(rcpt_to_msg));

    // Step 9: Receive server response
    n = read(sockfd, response, BUFSIZE);
    if (n <= 0) {
        printf("Error: failed to receive response from server\n");
        return 1;
    }

    // Step 10: Send DATA message
    char data_msg[] = "DATA\r\n";
    write(sockfd, data_msg, strlen(data_msg));

    // Step 11: Receive server response
    n = read(sockfd, response, BUFSIZE);
    if (n <= 0) {
        printf("Error: failed to receive response from server\n");
        return 1;
    }

    // Step 12: Send message body
    char message[BUFSIZE];
    sprintf(message, "From: <%s>\r\nTo: <%s>\r\nSubject: Test Message\r\n\r\nThis is a test message.\r\n.\r\n", "sender@example.com", "recipient@example.com");
    write(sockfd, message, strlen(message));

    // Step 13: Receive server response
    n = read(sockfd, response, BUFSIZE);
    if (n <= 0) {
        printf("Error: failed to receive response from server\n");
        return 1;
    }

    // Step 14: Send QUIT message
    char quit_msg[] = "QUIT\r\n";
    write(sockfd, quit_msg, strlen(quit_msg));

    // Step 15: Receive server response
    n = read(sockfd, response, BUFSIZE);
    if (n <= 0) {
        printf("Error: failed to receive response from server\n");
        return 1;
    }

    // Step 16: Close socket
    close(sockfd);

    return 0;
}