//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define MAX_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[MAX_SIZE];
    char *user, *password, *filename;
    FILE *file;
    int bytes, sent_bytes, received_bytes, total_bytes;

    if(argc < 4) {
        printf("Usage: ./ftpclient <hostname> <username> <password> <filename>\n");
        exit(1);
    }

    user = argv[2];
    password = argv[3];
    filename = argv[4];

    host = gethostbyname(argv[1]);
    if(host == NULL) {
        printf("Error: Could not resolve host.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr*)host->h_addr);

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    received_bytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if(received_bytes < 0) {
        printf("Error: Could not receive data from server.\n");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "USER %s\r\n", user);
    sent_bytes = send(sockfd, buffer, strlen(buffer), 0);
    if(sent_bytes < 0) {
        printf("Error: Could not send data to server.\n");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    received_bytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if(received_bytes < 0) {
        printf("Error: Could not receive data from server.\n");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "PASS %s\r\n", password);
    sent_bytes = send(sockfd, buffer, strlen(buffer), 0);
    if(sent_bytes < 0) {
        printf("Error: Could not send data to server.\n");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    received_bytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if(received_bytes < 0) {
        printf("Error: Could not receive data from server.\n");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "TYPE I\r\n");
    sent_bytes = send(sockfd, buffer, strlen(buffer), 0);
    if(sent_bytes < 0) {
        printf("Error: Could not send data to server.\n");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    received_bytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if(received_bytes < 0) {
        printf("Error: Could not receive data from server.\n");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "SIZE %s\r\n", filename);
    sent_bytes = send(sockfd, buffer, strlen(buffer), 0);
    if(sent_bytes < 0) {
        printf("Error: Could not send data to server.\n");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    received_bytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if(received_bytes < 0) {
        printf("Error: Could not receive data from server.\n");
        exit(1);
    }

    printf("%s", buffer);

    sscanf(buffer, "%*s %d", &total_bytes);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "RETR %s\r\n", filename);
    sent_bytes = send(sockfd, buffer, strlen(buffer), 0);
    if(sent_bytes < 0) {
        printf("Error: Could not send data to server.\n");
        exit(1);
    }

    file = fopen(filename, "wb");
    if(file == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    received_bytes = 0;
    while(received_bytes < total_bytes) {
        memset(buffer, 0, sizeof(buffer));
        bytes = recv(sockfd, buffer, sizeof(buffer), 0);
        if(bytes < 0) {
            printf("Error: Could not receive data from server.\n");
            exit(1);
        }
        if(bytes == 0) {
            break;
        }
        fwrite(buffer, 1, bytes, file);
        received_bytes += bytes;
    }

    fclose(file);
    close(sockfd);
    printf("File downloaded successfully.\n");
    return 0;
}