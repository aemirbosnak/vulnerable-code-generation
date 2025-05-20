//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        exit(1);
    }
    
    char *server = argv[1];
    char *username = argv[2];
    
    char password[BUF_SIZE];
    printf("Enter password: ");
    fflush(stdout);
    int i = 0;
    char c;
    while (i < BUF_SIZE-1 && (c = getchar()) != '\n') {
        password[i++] = c;
    }
    password[i] = '\0';
    
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        printf("Error: Unable to resolve host \"%s\".\n", server);
        exit(1);
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr*) host->h_addr);
    server_addr.sin_port = htons(110);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Unable to create socket.\n");
        exit(1);
    }
    
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Unable to connect to server \"%s\".\n", server);
        exit(1);
    }
    
    char buffer[BUF_SIZE];
    int n;
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        printf("Error: Unable to receive data from server \"%s\".\n", server);
        exit(1);
    }
    buffer[n] = '\0';
    if (strstr(buffer, "+OK") == NULL) {
        printf("Error: Server \"%s\" responded with \"%s\".\n", server, buffer);
        exit(1);
    }
    
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server \"%s\".\n", server);
        exit(1);
    }
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        printf("Error: Unable to receive data from server \"%s\".\n", server);
        exit(1);
    }
    buffer[n] = '\0';
    if (strstr(buffer, "+OK") == NULL) {
        printf("Error: Server \"%s\" responded with \"%s\".\n", server, buffer);
        exit(1);
    }
    
    sprintf(buffer, "PASS %s\r\n", password);
    memset(password, 0, BUF_SIZE);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server \"%s\".\n", server);
        exit(1);
    }
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        printf("Error: Unable to receive data from server \"%s\".\n", server);
        exit(1);
    }
    buffer[n] = '\0';
    if (strstr(buffer, "+OK") == NULL) {
        printf("Error: Server \"%s\" responded with \"%s\".\n", server, buffer);
        exit(1);
    }
    
    sprintf(buffer, "STAT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server \"%s\".\n", server);
        exit(1);
    }
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        printf("Error: Unable to receive data from server \"%s\".\n", server);
        exit(1);
    }
    buffer[n] = '\0';
    if (strstr(buffer, "+OK") == NULL) {
        printf("Error: Server \"%s\" responded with \"%s\".\n", server, buffer);
        exit(1);
    }
    int num_messages, total_size;
    sscanf(buffer, "+OK %d %d", &num_messages, &total_size);
    printf("You have %d messages (%d bytes) in total.\n", num_messages, total_size);
    
    for (int i = 1; i <= num_messages; i++) {
        sprintf(buffer, "RETR %d\r\n", i);
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            printf("Error: Unable to send data to server \"%s\".\n", server);
            exit(1);
        }
        n = recv(sockfd, buffer, BUF_SIZE-1, 0);
        if (n < 0) {
            printf("Error: Unable to receive data from server \"%s\".\n", server);
            exit(1);
        }
        buffer[n] = '\0';
        if (strstr(buffer, "+OK") == NULL) {
            printf("Error: Server \"%s\" responded with \"%s\".\n", server, buffer);
            exit(1);
        }
        
        memset(buffer, 0, BUF_SIZE);
        int size = 0;
        while (recv(sockfd, &c, 1, 0) > 0) {
            if (c == '\n' && buffer[size-1] == '\r') break;
            buffer[size++] = c;
            if (size >= BUF_SIZE-1) {
                printf("Error: Message too large.\n");
                exit(1);
            }
        }
        buffer[size] = '\0';
        if (strstr(buffer, "+OK") == NULL) {
            printf("Error: Server \"%s\" responded with \"%s\".\n", server, buffer);
            exit(1);
        }
        
        FILE *fp;
        char filename[BUF_SIZE];
        sprintf(filename, "%d.eml", i);
        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Error: Unable to open file \"%s\".\n", filename);
            exit(1);
        }
        
        int bytes_left = size + 1;
        int bytes_written = fwrite(buffer, 1, size, fp);
        while (bytes_written < size && bytes_written >= 0) {
            bytes_left = size - bytes_written;
            bytes_written = fwrite(buffer+bytes_written, 1, bytes_left, fp);
        }
        if (bytes_written < 0) {
            printf("Error: Unable to write to file \"%s\".\n", filename);
            exit(1);
        }
        fclose(fp);
    }
    
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server \"%s\".\n", server);
        exit(1);
    }
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        printf("Error: Unable to receive data from server \"%s\".\n", server);
        exit(1);
    }
    buffer[n] = '\0';
    if (strstr(buffer, "+OK") == NULL) {
        printf("Error: Server \"%s\" responded with \"%s\".\n", server, buffer);
        exit(1);
    }
    
    close(sockfd);
    printf("Disconnected from server \"%s\".\n", server);
    return 0;
}