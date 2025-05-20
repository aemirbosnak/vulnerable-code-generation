//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void read_server(int sockfd, char *buffer) {
    // Read message from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error in receiving data from server");
        exit(1);
    }
}

void send_command(int sockfd, char *buffer) {
    // Send command to server
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error in sending command to server");
        exit(1);
    }
}

void print_response(char *buffer) {
    // Print response from server
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s server port [filename]\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int port = atoi(argv[2]);
    char buffer[BUFFER_SIZE];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in creating socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        perror("Error in converting address to binary form");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error in connecting");
        exit(1);
    }

    // Read welcome message from server
    read_server(sockfd, buffer);
    print_response(buffer);

    // Send username and password
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("Username: ");
    scanf("%s", username);
    send_command(sockfd, username);
    read_server(sockfd, buffer);
    print_response(buffer);

    printf("Password: ");
    scanf("%s", password);
    send_command(sockfd, password);
    read_server(sockfd, buffer);
    print_response(buffer);

    // If a filename is given, open the file and send it to the server
    if (argc == 4) {
        FILE *fp = fopen(argv[3], "rb");
        if (fp == NULL) {
            perror("Error in opening file");
            exit(1);
        }

        // Send STOR command and filename to server
        char stor_cmd[BUFFER_SIZE];
        sprintf(stor_cmd, "STOR %s", argv[3]);
        send_command(sockfd, stor_cmd);
        read_server(sockfd, buffer);
        print_response(buffer);

        // Send file to server
        int bytes_read;
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
            if (send(sockfd, buffer, bytes_read, 0) < 0) {
                perror("Error in sending data to server");
                exit(1);
            }
        }

        // Close file and read response from server
        fclose(fp);
        read_server(sockfd, buffer);
        print_response(buffer);
    }

    // Receive list of files from server
    send_command(sockfd, "LIST");
    read_server(sockfd, buffer);
    print_response(buffer);

    while (1) {
        read_server(sockfd, buffer);
        if (strcmp(buffer, "done") == 0) {
            break;
        }
        printf("%s", buffer);
    }

    // Send QUIT command to server
    send_command(sockfd, "QUIT");
    read_server(sockfd, buffer);
    print_response(buffer);

    // Close socket
    close(sockfd);
    return 0;
}