//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define FTP_PORT 21      // default FTP port
#define MAX_COMMAND 1024 // maximum command length
#define MAX_REPLY 1024   // maximum server reply length

int main(int argc, char **argv) {
    // check for correct number of command-line arguments
    if (argc != 3) {
        printf("Usage: %s hostname username\n", argv[0]);
        exit(1);
    }

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(errno);
    }

    // specify server address
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Invalid address: %s\n", argv[1]);
        exit(1);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(errno);
    }

    // read initial greeting from server
    char reply[MAX_REPLY];
    if (read(sockfd, reply, MAX_REPLY) < 0) {
        perror("read");
        exit(errno);
    }
    printf("%s", reply);

    // send username
    char command[MAX_COMMAND];
    snprintf(command, MAX_COMMAND, "USER %s\r\n", argv[2]);
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("write");
        exit(errno);
    }
    if (read(sockfd, reply, MAX_REPLY) < 0) {
        perror("read");
        exit(errno);
    }
    printf("%s", reply);

    // send password
    char password[MAX_COMMAND];
    printf("Enter password: ");
    fgets(password, MAX_COMMAND, stdin);
    password[strlen(password)-1] = '\0';  // remove newline character
    snprintf(command, MAX_COMMAND, "PASS %s\r\n", password);
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("write");
        exit(errno);
    }
    if (read(sockfd, reply, MAX_REPLY) < 0) {
        perror("read");
        exit(errno);
    }
    printf("%s", reply);

    // send PASV command to enter passive mode
    snprintf(command, MAX_COMMAND, "PASV\r\n");
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("write");
        exit(errno);
    }
    if (read(sockfd, reply, MAX_REPLY) < 0) {
        perror("read");
        exit(errno);
    }
    printf("%s", reply);
    // extract server's IP address and port number from PASV reply
    unsigned int a1, a2, a3, a4, p1, p2;
    sscanf(reply, "227 Entering Passive Mode (%u,%u,%u,%u,%u,%u)\r\n", 
           &a1, &a2, &a3, &a4, &p1, &p2);
    char data_ip_address[MAX_COMMAND];
    snprintf(data_ip_address, MAX_COMMAND, "%u.%u.%u.%u", a1, a2, a3, a4);
    int data_port = p1 * 256 + p2;

    // connect to data port using new socket
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        perror("socket");
        exit(errno);
    }
    struct sockaddr_in data_servaddr;
    memset(&data_servaddr, 0, sizeof(data_servaddr));
    data_servaddr.sin_family = AF_INET;
    data_servaddr.sin_port = htons(data_port);
    if (inet_pton(AF_INET, data_ip_address, &data_servaddr.sin_addr) <= 0) {
        printf("Invalid address: %s\n", argv[1]);
        exit(1);
    }
    if (connect(data_sockfd, (struct sockaddr *) &data_servaddr, sizeof(data_servaddr)) < 0) {
        perror("connect");
        exit(errno);
    }

    // send LIST command to obtain data from server
    snprintf(command, MAX_COMMAND, "LIST\r\n");
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("write");
        exit(errno);
    }
    if (read(sockfd, reply, MAX_REPLY) < 0) {
        perror("read");
        exit(errno);
    }
    printf("%s", reply);

    // read data from data port and output to stdout
    char data[MAX_REPLY];
    int num_bytes = read(data_sockfd, data, MAX_REPLY);
    while (num_bytes > 0) {
        for (int i = 0; i < num_bytes; i++) {
            printf("%c", data[i]);
        }
        num_bytes = read(data_sockfd, data, MAX_REPLY);
    }
    if (num_bytes < 0) {
        perror("read");
        exit(errno);
    }

    // close sockets and exit
    close(sockfd);
    close(data_sockfd);
    exit(0);
}