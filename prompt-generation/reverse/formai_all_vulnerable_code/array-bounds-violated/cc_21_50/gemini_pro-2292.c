//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdbool.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd;
    struct sockaddr_in addr;
    struct hostent *host;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(server);
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(110);
    addr.sin_addr = **((struct in_addr **) host->h_addr_list);

    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char buffer[MAXLINE];
    int n;

    // Retrieve welcome message
    n = recv(sockfd, buffer, MAXLINE - 1, 0);
    if (n < 0) {
        perror("Error receiving welcome message");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send username
    sprintf(buffer, "USER %s\r\n", username);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending username");
        exit(EXIT_FAILURE);
    }

    // Retrieve response
    n = recv(sockfd, buffer, MAXLINE - 1, 0);
    if (n < 0) {
        perror("Error receiving username response");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send password
    sprintf(buffer, "PASS %s\r\n", password);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending password");
        exit(EXIT_FAILURE);
    }

    // Retrieve response
    n = recv(sockfd, buffer, MAXLINE - 1, 0);
    if (n < 0) {
        perror("Error receiving password response");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Get list of emails
    bool listing_emails = false;
    int num_emails = 0;
    while (true) {
        n = recv(sockfd, buffer, MAXLINE - 1, 0);
        if (n < 0) {
            perror("Error receiving emails");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';
        printf("%s", buffer);

        if (strstr(buffer, "OK") != NULL) {
            if (listing_emails) {
                break;
            }
            sprintf(buffer, "LIST\r\n");
            n = send(sockfd, buffer, strlen(buffer), 0);
            if (n < 0) {
                perror("Error sending LIST command");
                exit(EXIT_FAILURE);
            }
            listing_emails = true;
        } else if (strstr(buffer, "+OK") != NULL) {
            sscanf(buffer, "+OK %d messages", &num_emails);
        } else if (strstr(buffer, "-ERR") != NULL) {
            break;
        }
    }

    if (num_emails > 0) {
        printf("Found %d emails:\n", num_emails);
        for (int i = 1; i <= num_emails; i++) {
            sprintf(buffer, "RETR %d\r\n", i);
            n = send(sockfd, buffer, strlen(buffer), 0);
            if (n < 0) {
                perror("Error sending RETR command");
                exit(EXIT_FAILURE);
            }

            // Retrieve email
            listing_emails = false;
            while (true) {
                n = recv(sockfd, buffer, MAXLINE - 1, 0);
                if (n < 0) {
                    perror("Error receiving email");
                    exit(EXIT_FAILURE);
                }
                buffer[n] = '\0';
                printf("%s", buffer);

                if (strstr(buffer, "OK") != NULL) {
                    break;
                }
            }
        }
    }

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending QUIT command");
        exit(EXIT_FAILURE);
    }

    // Close connection
    close(sockfd);

    return EXIT_SUCCESS;
}