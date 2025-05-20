//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024], command[128];
    int cnt = 0;
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Welcome to FTP client!\n");
    while (1) {
        printf("Enter command: ");
        fgets(command, 128, stdin);
        cnt = send(sockfd, command, strlen(command), 0);
        if (cnt < 0) {
            perror("ERROR sending command");
            exit(1);
        }

        if (strcmp(command, "quit") == 0) {
            printf("Bye!\n");
            break;
        } else if (strcmp(command, "ls") == 0) {
            bzero(buffer, sizeof(buffer));
            n = recv(sockfd, buffer, sizeof(buffer), 0);
            if (n < 0) {
                perror("ERROR receiving response");
                exit(1);
            }
            printf("%s\n", buffer);
        } else if (strcmp(command, "get") == 0) {
            bzero(buffer, sizeof(buffer));
            bzero(command, sizeof(command));
            sprintf(command, "RETR %s", command);
            n = send(sockfd, command, strlen(command), 0);
            if (n < 0) {
                perror("ERROR sending command");
                exit(1);
            }
            fp = fopen("out.txt", "w");
            bzero(buffer, sizeof(buffer));
            n = recv(sockfd, buffer, sizeof(buffer), 0);
            if (n < 0) {
                perror("ERROR receiving response");
                exit(1);
            }
            fwrite(buffer, 1, n, fp);
            fclose(fp);
            printf("File downloaded successfully!\n");
        } else if (strcmp(command, "put") == 0) {
            bzero(buffer, sizeof(buffer));
            bzero(command, sizeof(command));
            sprintf(command, "STOR %s", command);
            n = send(sockfd, command, strlen(command), 0);
            if (n < 0) {
                perror("ERROR sending command");
                exit(1);
            }
            fp = fopen("in.txt", "r");
            bzero(buffer, sizeof(buffer));
            n = recv(sockfd, buffer, sizeof(buffer), 0);
            if (n < 0) {
                perror("ERROR receiving response");
                exit(1);
            }
            fwrite(buffer, 1, n, fp);
            fclose(fp);
            printf("File uploaded successfully!\n");
        } else {
            printf("Invalid command!\n");
        }
    }

    close(sockfd);
    return 0;
}