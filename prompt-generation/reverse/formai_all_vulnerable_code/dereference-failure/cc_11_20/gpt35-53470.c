//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server_name;
    char buffer[1024];

    // Step 1: Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Step 2: Resolve server name
    server_name = gethostbyname(argv[1]);
    if (server_name == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    // Step 3: Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, server_name->h_addr_list[0], server_name->h_length);

    // Step 4: Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Step 5: Send EHLO message to server
    sprintf(buffer, "EHLO %s\r\n", argv[1]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("EHLO message sent: %s", buffer);

    // Step 6: Receive reply from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("EHLO reply received: %s", buffer);

    // Step 7: Send MAIL FROM message to server
    sprintf(buffer, "MAIL FROM: <%s>\r\n", argv[2]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("MAIL FROM message sent: %s", buffer);

    // Step 8: Receive reply from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("MAIL FROM reply received: %s", buffer);

    // Step 9: Send RCPT TO message to server
    sprintf(buffer, "RCPT TO: <%s>\r\n", argv[3]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("RCPT TO message sent: %s", buffer);

    // Step 10: Receive reply from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("RCPT TO reply received: %s", buffer);

    // Step 11: Send DATA message to server
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("DATA message sent: %s", buffer);

    // Step 12: Receive reply from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("DATA reply received: %s", buffer);

    // Step 13: Send mail body to server
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", argv[2], argv[3], argv[4], argv[5]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("Mail body sent: %s\n", buffer);

    // Step 14: Receive reply from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("Mail body reply received: %s", buffer);

    // Step 15: Send QUIT message to server
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("QUIT message sent: %s", buffer);

    // Step 16: Receive reply from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("QUIT reply received: %s", buffer);

    // Step 17: Close socket
    close(sockfd);

    return 0;
}