//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <fcntl.h>

#define IMAP_SERVER "imap.example.com"
#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("Sent: %s", buffer);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);
        
        if (strstr(buffer, "OK") || strstr(buffer, "BYE")) {
            break;
        }
    }
}

int connect_imap_server(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;

    if ((host = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(host->h_addr, &server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to IMAP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void login(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, buffer);
    read_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    read_response(sockfd);
}

void fetch_email(int sockfd, const char *mailbox) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "A003 SELECT \"%s\"", mailbox);
    send_command(sockfd, buffer);
    read_response(sockfd);

    send_command(sockfd, "A004 FETCH 1 BODY[]");
    read_response(sockfd);
}

void logout(int sockfd) {
    send_command(sockfd, "A005 LOGOUT");
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <username> <password> <mailbox>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *username = argv[1];
    const char *password = argv[2];
    const char *mailbox = argv[3];

    int sockfd = connect_imap_server(IMAP_SERVER, IMAP_PORT);
    printf("Connected to IMAP server at %s:%d\n", IMAP_SERVER, IMAP_PORT);
    
    login(sockfd, username, password);
    list_mailboxes(sockfd);
    fetch_email(sockfd, mailbox);
    logout(sockfd);

    close(sockfd);
    printf("Connection closed.\n");

    return 0;
}