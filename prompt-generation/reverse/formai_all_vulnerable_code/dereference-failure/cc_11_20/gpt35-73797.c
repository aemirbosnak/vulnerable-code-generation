//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to FTP server.\n");

    bzero(buffer,BUFFER_SIZE);

    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    buffer[n] = '\0';

    printf("%s", buffer);

    bool loggedIn = false;

    while (true) {
        bzero(buffer,BUFFER_SIZE);
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE - 1, stdin);

        char *command = strtok(buffer, " \t\r\n");

        if (command == NULL) {
            continue;
        }

        if (strcasecmp(command, "QUIT") == 0) {
            n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
            if (n < 0) {
                error("ERROR writing to socket");
            }

            bzero(buffer,BUFFER_SIZE);

            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            buffer[n] = '\0';

            printf("%s", buffer);

            close(sockfd);

            return 0;
        }

        if (strcasecmp(command, "USER") == 0) {
            char *username = strtok(NULL, " \t\r\n");

            if (username == NULL) {
                printf("Username not specified.\n");
                continue;
            }

            char userBuff[BUFFER_SIZE];
            snprintf(userBuff, BUFFER_SIZE - 1, "USER %s\r\n", username);

            n = write(sockfd, userBuff, strlen(userBuff));
            if (n < 0) {
                error("ERROR writing to socket");
            }

            bzero(buffer,BUFFER_SIZE);

            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            buffer[n] = '\0';

            printf("%s", buffer);

            loggedIn = true;
        }

        if (strcasecmp(command, "PASS") == 0) {
            if (!loggedIn) {
                printf("You need to login first.\n");
                continue;
            }

            char *password = strtok(NULL, " \t\r\n");

            if (password == NULL) {
                printf("Password not specified.\n");
                continue;
            }

            char passBuff[BUFFER_SIZE];
            snprintf(passBuff, BUFFER_SIZE - 1, "PASS %s\r\n", password);

            n = write(sockfd, passBuff, strlen(passBuff));
            if (n < 0) {
                error("ERROR writing to socket");
            }

            bzero(buffer,BUFFER_SIZE);

            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            buffer[n] = '\0';

            printf("%s", buffer);

            if (buffer[0] != '2') {
                loggedIn = false;
            }
        }

        if (strcasecmp(command, "LIST") == 0) {
            if (!loggedIn) {
                printf("You need to login first.\n");
                continue;
            }

            n = write(sockfd, "PASV\r\n", strlen("PASV\r\n"));
            if (n < 0) {
                error("ERROR writing to socket");
            }

            bzero(buffer,BUFFER_SIZE);

            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            buffer[n] = '\0';

            if (buffer[0] != '2') {
                printf("%s", buffer);
                continue;
            }

            printf("%s", buffer);

            int a,b,c,d,p1,p2;
            sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &a, &b, &c, &d, &p1, &p2);

            struct sockaddr_in dataSockAddr;
            bzero((char *) &dataSockAddr, sizeof(dataSockAddr));
            dataSockAddr.sin_family = AF_INET;
            dataSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(serv_addr.sin_addr));
            dataSockAddr.sin_port = htons(p1 * 256 + p2);

            int dataSock = socket(AF_INET, SOCK_STREAM, 0);

            if (connect(dataSock, (struct sockaddr*)&dataSockAddr, sizeof(dataSockAddr)) < 0) {
                error("ERROR connecting data socket");
            }

            n = write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
            if (n < 0) {
                error("ERROR writing to socket");
            }

            bzero(buffer,BUFFER_SIZE);

            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            buffer[n] = '\0';

            printf("%s", buffer);

            n = read(dataSock, buffer, BUFFER_SIZE - 1);
            while (n > 0) {
                buffer[n] = '\0';
                printf("%s", buffer);
                n = read(dataSock, buffer, BUFFER_SIZE - 1);
            }

            close(dataSock);

            bzero(buffer,BUFFER_SIZE);

            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            buffer[n] = '\0';

            printf("%s", buffer);
        }
    }

    close(sockfd);

    return 0;
}