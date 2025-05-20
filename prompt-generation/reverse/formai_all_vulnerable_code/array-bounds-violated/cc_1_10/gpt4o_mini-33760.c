//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void pop3_send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
}

void pop3_receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving data from the server");
    }
    buffer[bytes_received] = '\0';
    printf("Received: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or Address not supported\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    pop3_receive_response(sockfd);

    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    pop3_send_command(sockfd, command);
    pop3_receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    pop3_send_command(sockfd, command);
    pop3_receive_response(sockfd);

    pop3_send_command(sockfd, "LIST\r\n");
    pop3_receive_response(sockfd);

    pop3_send_command(sockfd, "RETR 1\r\n");
    pop3_receive_response(sockfd);

    pop3_send_command(sockfd, "QUIT\r\n");
    pop3_receive_response(sockfd);

    close(sockfd);
    return 0;
}