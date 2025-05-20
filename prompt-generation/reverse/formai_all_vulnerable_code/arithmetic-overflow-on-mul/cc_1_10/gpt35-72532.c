//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <SERVER IP ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { // create socket
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    memset(&(server_addr.sin_zero), '\0', 8);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) { // establish connection
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, 1024, 0); // receive welcome message from server
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    char username[256];
    printf("Username: ");
    fgets(username, 256, stdin);
    username[strcspn(username, "\n")] = '\0'; // remove newline character from input

    char password[256];
    printf("Password: ");
    fgets(password, 256, stdin);
    password[strcspn(password, "\n")] = '\0'; // remove newline character from input

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0); // send username

    bytes_received = recv(sockfd, buffer, 1024, 0); // receive response
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0); // send password

    bytes_received = recv(sockfd, buffer, 1024, 0); // receive response
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "PASV\r\n");
    send(sockfd, buffer, strlen(buffer), 0); // send passive command to initiate passive mode

    bytes_received = recv(sockfd, buffer, 1024, 0); // receive response
    buffer[bytes_received] = '\0';

    int address[6];
    int matched = sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
                            &address[0], &address[1], &address[2], &address[3], &address[4], &address[5]);

    if(matched != 6) {
        fprintf(stderr, "Parse error\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(address[4] * 256 + address[5]);
    char data_addr_str[256];
    sprintf(data_addr_str, "%d.%d.%d.%d", address[0], address[1], address[2], address[3]);
    inet_pton(AF_INET, data_addr_str, &data_addr.sin_addr);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { // create data socket
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr *)&data_addr, sizeof(struct sockaddr)) == -1) { // establish data connection
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0); // send list command

    bytes_received = recv(sockfd, buffer, 1024, 0); // receive response
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    close(sockfd); // close data socket

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0); // send quit command to terminate session

    bytes_received = recv(sockfd, buffer, 1024, 0); // receive response
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    close(sockfd); // close control socket

    return 0;
}