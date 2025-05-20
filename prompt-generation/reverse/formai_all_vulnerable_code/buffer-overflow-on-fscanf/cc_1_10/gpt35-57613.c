//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 30

char username[MAX_USERNAME_LENGTH];
char password[MAX_PASSWORD_LENGTH];

void read_username_and_password_from_file() {
    FILE *file = fopen("credentials.txt", "r");
    if (file == NULL) {
        printf("Error opening credentials file\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%s", username);
    fscanf(file, "%s", password);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <ftp_server_name>\n", argv[0]);
        return EXIT_FAILURE;
    }
    read_username_and_password_from_file();

    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    const int true_flag = 1;
    int status;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    status = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &true_flag, sizeof(int));
    if (status < 0) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);

    status = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    if (status <= 0) {
        printf("Error: Invalid address\n");
        exit(EXIT_FAILURE);
    }

    status = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (status < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    char message[BUFFER_SIZE];
    sprintf(message, "USER %s\r\n", username);
    write(sockfd, message, strlen(message));
    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    sprintf(message, "PASS %s\r\n", password);
    write(sockfd, message, strlen(message));
    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    sprintf(message, "SYST\r\n");
    write(sockfd, message, strlen(message));
    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    sprintf(message, "PWD\r\n");
    write(sockfd, message, strlen(message));
    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    sprintf(message, "QUIT\r\n");
    write(sockfd, message, strlen(message));
    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    close(sockfd);

    return EXIT_SUCCESS;
}