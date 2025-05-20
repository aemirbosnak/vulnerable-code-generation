//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_EMAIL_SIZE 1000
#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_BUFF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket: %s\n", strerror(errno));
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to server\n");

    char user_input[MAX_BUFF_SIZE];
    char email[MAX_EMAIL_SIZE];

    while(1) {
        printf("Enter command: ");
        memset(user_input, 0, MAX_BUFF_SIZE);
        fgets(user_input, MAX_BUFF_SIZE - 1, stdin);

        if (strncmp(user_input, "QUIT", 4) == 0) {
            printf("Quitting...\n");
            break;
        }

        if (strncmp(user_input, "USER", 4) == 0) {
            printf("Enter username: ");
            memset(user_input, 0, MAX_BUFF_SIZE);
            fgets(user_input, MAX_BUFF_SIZE - 1, stdin);

            // Send USER command to server
            sprintf(buffer, "USER %s", user_input);
            write(sockfd, buffer, strlen(buffer));

            // Read response from server
            memset(buffer, 0, MAX_BUFF_SIZE);
            read(sockfd, buffer, MAX_BUFF_SIZE - 1);
            printf("%s", buffer);
        }

        if (strncmp(user_input, "PASS", 4) == 0) {
            printf("Enter password: ");
            memset(user_input, 0, MAX_BUFF_SIZE);
            fgets(user_input, MAX_BUFF_SIZE - 1, stdin);

            // Send PASS command to server
            sprintf(buffer, "PASS %s", user_input);
            write(sockfd, buffer, strlen(buffer));

            // Read response from server
            memset(buffer, 0, MAX_BUFF_SIZE);
            read(sockfd, buffer, MAX_BUFF_SIZE - 1);
            printf("%s", buffer);
        }

        if (strncmp(user_input, "LIST", 4) == 0) {
            // Send LIST command to server
            write(sockfd, "LIST", 4);

            // Read response from server
            memset(buffer, 0, MAX_BUFF_SIZE);
            read(sockfd, buffer, MAX_BUFF_SIZE - 1);

            if (strncmp(buffer, "+OK", 3) == 0) {
                printf("%s", buffer);

                while (1) {
                    memset(buffer, 0, MAX_BUFF_SIZE);
                    read(sockfd, buffer, MAX_BUFF_SIZE - 1);

                    if (strncmp(buffer, ".", 1) == 0) {
                        break;
                    }

                    printf("%s", buffer);
                }
            } else {
                printf("%s", buffer);
            }
        }

        if (strncmp(user_input, "RETR", 4) == 0) {
            printf("Enter email number: ");
            memset(user_input, 0, MAX_BUFF_SIZE);
            fgets(user_input, MAX_BUFF_SIZE - 1, stdin);

            // Send RETR command to server
            sprintf(buffer, "RETR %s", user_input);
            write(sockfd, buffer, strlen(buffer));

            // Read response from server
            memset(buffer, 0, MAX_BUFF_SIZE);
            read(sockfd, buffer, MAX_BUFF_SIZE - 1);

            if (strncmp(buffer, "+OK", 3) == 0) {
                printf("%s", buffer);

                // Read email content from server
                memset(email, 0, MAX_EMAIL_SIZE);
                while (1) {
                    memset(buffer, 0, MAX_BUFF_SIZE);
                    read(sockfd, buffer, MAX_BUFF_SIZE - 1);

                    if (strncmp(buffer, ".", 1) == 0) {
                        break;
                    }

                    strcat(email, buffer);
                }

                printf("%s", email);
            } else {
                printf("%s", buffer);
            }
        }

        if (strncmp(user_input, "DELE", 4) == 0) {
            printf("Enter email number: ");
            memset(user_input, 0, MAX_BUFF_SIZE);
            fgets(user_input, MAX_BUFF_SIZE - 1, stdin);

            // Send DELE command to server
            sprintf(buffer, "DELE %s", user_input);
            write(sockfd, buffer, strlen(buffer));

            // Read response from server
            memset(buffer, 0, MAX_BUFF_SIZE);
            read(sockfd, buffer, MAX_BUFF_SIZE - 1);
            printf("%s", buffer);
        }
    }

    close(sockfd);

    return 0;
}