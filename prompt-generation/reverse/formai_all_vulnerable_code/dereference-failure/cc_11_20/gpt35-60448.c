//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 21
#define PASS_LENGTH 100
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servadd;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host exists\n");
        exit(1);
    }

    bzero(&servadd, sizeof(servadd));
    servadd.sin_family = AF_INET;
    servadd.sin_port = htons(PORT);
    memcpy(&servadd.sin_addr.s_addr, server->h_addr, server->h_length);

    if ((connect(sockfd, (struct sockaddr *) &servadd, sizeof(servadd))) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to server successfully!\n");

    char username[50], password[50], command[50], filename[50];
    char buffer[BUFFER_SIZE];

    // Enter credentials to login into the FTP server
    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    // Send login credentials to the server
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    printf("Logged into the FTP server successfully!\n");

    // Loop to handle user commands
    while (1) {
        printf("Enter command (get, put, ls, cd, pwd, quit): ");
        scanf("%s", command);

        // Handle get command
        if (!strcmp(command, "get")) {
            printf("Enter filename to retrieve: ");
            scanf("%s", filename);

            sprintf(buffer, "RETR %s\r\n", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, BUFFER_SIZE, 0);

            FILE *fp;
            fp = fopen(filename, "w");

            while (1) {
                recv(sockfd, buffer, BUFFER_SIZE, 0);
                if (strncmp(buffer, "226", 3) == 0) {
                    printf("File transfer complete!\n");
                    break;
                }
                fprintf(fp, "%s", buffer);
            }
            fclose(fp);
        }

        // Handle put command
        else if (!strcmp(command, "put")) {
            printf("Enter filename to upload: ");
            scanf("%s", filename);

            sprintf(buffer, "STOR %s\r\n", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, BUFFER_SIZE, 0);

            FILE *fp;
            fp = fopen(filename, "r");

            while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
                send(sockfd, buffer, strlen(buffer), 0);
            }
            fclose(fp);

            send(sockfd, "EOF", strlen("EOF"), 0);
            recv(sockfd, buffer, BUFFER_SIZE, 0);
            printf("File transfer complete!\n");
        }

        // Handle ls command
        else if (!strcmp(command, "ls")) {
            sprintf(buffer, "LIST\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, BUFFER_SIZE, 0);

            while (1) {
                recv(sockfd, buffer, BUFFER_SIZE, 0);
                if (strncmp(buffer, "226", 3) == 0) break;
                printf("%s", buffer);
            }
        }

        // Handle cd command
        else if (!strcmp(command, "cd")) {
            printf("Enter the directory to change to: ");
            scanf("%s", filename);

            sprintf(buffer, "CWD %s\r\n", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, BUFFER_SIZE, 0);
            printf("%s\n", buffer);
        }

        // Handle pwd command
        else if (!strcmp(command, "pwd")) {
            sprintf(buffer, "PWD\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, BUFFER_SIZE, 0);
            printf("%s\n", buffer);
        }

        // Handle quit command
        else if (!strcmp(command, "quit")) {
            sprintf(buffer, "QUIT\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, BUFFER_SIZE, 0);
            printf("%s\n", buffer);
            break;
        }

        // Handle invalid command
        else {
            printf("Invalid command, please try again\n");
        }
    }

    printf("Closing connection...\n");
    close(sockfd);
    return 0;
}