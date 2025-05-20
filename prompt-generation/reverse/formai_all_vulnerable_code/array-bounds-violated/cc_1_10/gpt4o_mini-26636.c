//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("ERROR invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
}

void list_messages(int sockfd) {
    send_command(sockfd, "USER user"); // Enter your username here
    read_response(sockfd);

    send_command(sockfd, "PASS password"); // Enter your password here
    read_response(sockfd);

    send_command(sockfd, "LIST");
    read_response(sockfd);

    send_command(sockfd, "QUIT");
    read_response(sockfd);
}

void retrieve_message(int sockfd, int message_number) {
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "RETR %d", message_number);
    send_command(sockfd, cmd);
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <POP3 server address>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    int sockfd = connect_to_server(hostname);
    printf("Connected to POP3 server: %s\n", hostname);
    
    read_response(sockfd); // Read the initial server greeting

    list_messages(sockfd); // List messages in the mailbox

    int message_number = 1; // Change this to retrieve different messages
    retrieve_message(sockfd, message_number);

    close(sockfd);
    return 0;
}