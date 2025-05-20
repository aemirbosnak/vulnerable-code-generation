//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_THREADS 5

void* ftpClient(void* arg) {
    // create client socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    // get server address
    struct hostent *server = gethostbyname((char*)arg);
    if (server == NULL) {
        perror("Error getting server address");
        exit(1);
    }
    // set up server address structure
    struct sockaddr_in serv_addr;
    memset((char*) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21); // FTP port
    memcpy((char*) &serv_addr.sin_addr.s_addr, (char*) server->h_addr, server->h_length);
    // connect to the server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }
    // receive welcome message from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE-1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    // send user login
    char user[50];
    printf("Enter username: ");
    scanf("%s", user);
    char user_cmd[50];
    memset(user_cmd, 0, 50);
    sprintf(user_cmd, "USER %s\r\n", user);
    if (write(sockfd, user_cmd, strlen(user_cmd)) < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE-1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    // send password login
    char passwd[50];
    printf("Enter password: ");
    scanf("%s", passwd);
    char passwd_cmd[50];
    memset(passwd_cmd, 0, 50);
    sprintf(passwd_cmd, "PASS %s\r\n", passwd);
    if (write(sockfd, passwd_cmd, strlen(passwd_cmd)) < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE-1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    // send type command to set type to binary
    if (write(sockfd, "TYPE I\r\n", strlen("TYPE I\r\n")) < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE-1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    // send PASV command to enter passive mode
    if (write(sockfd, "PASV\r\n", strlen("PASV\r\n")) < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE-1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    // parse server response to get passive mode connection details
    char *ptr = strstr(buffer, "(");
    int numbers[6], i;
    sscanf(ptr, "(%d,%d,%d,%d,%d,%d)", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5]);
    // set up socket for passive mode connection
    int pasv_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (pasv_sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in serv_addr_pasv;
    memset((char*) &serv_addr_pasv, 0, sizeof(serv_addr_pasv));
    serv_addr_pasv.sin_family = AF_INET;
    serv_addr_pasv.sin_port = htons(numbers[4]*256 + numbers[5]); // port from server response
    memcpy((char*) &serv_addr_pasv.sin_addr.s_addr, (char*) server->h_addr, server->h_length);
    // connect to passive mode server
    if (connect(pasv_sockfd, (struct sockaddr*) &serv_addr_pasv, sizeof(serv_addr_pasv)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }
    // send LIST command to get file list from server
    if (write(sockfd, "LIST\r\n", strlen("LIST\r\n")) < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE-1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    // receive file list from passive mode connection
    memset(buffer, 0, BUFFER_SIZE);
    if (read(pasv_sockfd, buffer, BUFFER_SIZE-1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    // close passive mode connection socket
    close(pasv_sockfd);
    // send QUIT command to exit connection
    if (write(sockfd, "QUIT\r\n", strlen("QUIT\r\n")) < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE-1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    // close client socket
    close(sockfd);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./ftpClient hostname\n");
        return 1;
    }
    pthread_t threads[MAX_THREADS];
    int rc, t;
    for (t=0; t<MAX_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, ftpClient, argv[1]);
        if (rc) {
            printf("Error: unable to create thread\n");
            exit(1);
        }
    }
    pthread_exit(NULL);
    return 0;
}