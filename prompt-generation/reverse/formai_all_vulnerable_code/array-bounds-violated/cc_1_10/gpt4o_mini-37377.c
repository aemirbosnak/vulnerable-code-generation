//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int open_connection(const char *hostname) {
    struct sockaddr_in server;
    struct hostent *host;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);
    server.sin_port = htons(FTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
   
    if (bytes_received < 0) {
        error("ERROR receiving response");
    }

    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV");
    receive_response(sockfd);

    // Here, you would typically parse the response to get the data connection details 
    // For simplicity, we assume the connection is set up here.

    send_command(sockfd, "LIST");
    receive_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    send_command(sockfd, "RETR");
    send_command(sockfd, filename);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <command>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *command = argv[2];

    int sockfd = open_connection(hostname);

    receive_response(sockfd); // Get initial server response

    if (strcmp(command, "list") == 0) {
        list_files(sockfd);
    } else if (strcmp(command, "get") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: %s %s <filename>\n", argv[0], command);
            exit(1);
        }
        download_file(sockfd, argv[3]);
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
    }

    close(sockfd);
    return 0;
}