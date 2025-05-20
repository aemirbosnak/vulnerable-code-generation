//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to send data to server
int send_data(int sockfd, char *msg) {
    int n = send(sockfd, msg, strlen(msg), 0);
    if (n < 0) {
        perror("send error");
        exit(1);
    }
    return n;
}

// Function to receive data from server
int receive_data(int sockfd, char *buf, int len) {
    int n = recv(sockfd, buf, len, 0);
    if (n < 0) {
        perror("recv error");
        exit(1);
    }
    return n;
}

// Function to connect to server
int connect_to_server(char *server_ip, int server_port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    int connect_result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_result < 0) {
        perror("connect error");
        exit(1);
    }

    return sockfd;
}

// Function to list files on server
void list_files(int sockfd) {
    char buffer[1024];
    int n = receive_data(sockfd, buffer, sizeof(buffer));
    printf("Files on server:\n%s\n", buffer);
}

// Function to download file from server
void download_file(int sockfd, char *file_name) {
    char buffer[1024];
    int n = receive_data(sockfd, buffer, sizeof(buffer));
    printf("File %s downloaded successfully.\n", file_name);
}

int main() {
    char server_ip[50];
    int server_port = 21;

    printf("Enter server IP address: ");
    scanf("%s", server_ip);

    int sockfd = connect_to_server(server_ip, server_port);

    char file_name[50];
    printf("Enter file name to download: ");
    scanf("%s", file_name);

    list_files(sockfd);
    download_file(sockfd, file_name);

    close(sockfd);
    return 0;
}