//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21
#define MAX_COMMAND_LENGTH 256
#define MAX_RESPONSE_LENGTH 512

void handle_response(int sockfd);
void send_command(int sockfd, const char *command);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    if ((host = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Unable to connect to FTP server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    handle_response(sockfd);

    char command[MAX_COMMAND_LENGTH];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);

    // Get current directory
    send_command(sockfd, "PWD\r\n");

    // List files in the current directory
    send_command(sockfd, "LIST\r\n");

    // Disconnect from the server
    send_command(sockfd, "QUIT\r\n");

    close(sockfd);
    return 0;
}

void handle_response(int sockfd) {
    char response[MAX_RESPONSE_LENGTH];
    ssize_t n;

    n = recv(sockfd, response, sizeof(response) - 1, 0);
    if (n > 0) {
        response[n] = '\0';
        printf("%s", response);
    } else {
        perror("Error: Unable to receive response");
    }
}

void send_command(int sockfd, const char *command) {
    ssize_t n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        perror("Error: Unable to send command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    handle_response(sockfd);
}