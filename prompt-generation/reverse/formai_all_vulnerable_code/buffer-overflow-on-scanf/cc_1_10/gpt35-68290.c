//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

int main(void) {
    int sock_fd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    int n;
    
    // create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }
    
    // set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // connect to server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(EXIT_FAILURE);
    }
    
    // receive welcome message
    memset(buffer, 0, sizeof(buffer));
    n = recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    // login
    printf("User: ");
    scanf("%s", command);
    strcat(command, "\r\n");
    send(sock_fd, command, strlen(command), 0);
    memset(command, 0, sizeof(command));
    n = recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    printf("Password: ");
    scanf("%s", command);
    strcat(command, "\r\n");
    send(sock_fd, command, strlen(command), 0);
    memset(command, 0, sizeof(command));
    n = recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    // enter passive mode
    strcpy(command, "PASV\r\n");
    send(sock_fd, command, strlen(command), 0);
    memset(command, 0, sizeof(command));
    n = recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    // extract IP and port number from response
    char *first_comma = strchr(buffer, ',');
    char *second_comma = strchr(first_comma+1, ',');
    char *third_comma = strchr(second_comma+1, ',');
    char *fourth_comma = strchr(third_comma+1, ',');
    char *ip_arr = strtok(buffer+27, ",");
    char ip[15];
    sprintf(ip, "%s.%s.%s.%s", ip_arr, strtok(NULL, ","),
            strtok(NULL, ","), strtok(NULL, ","));
    int port = atoi(third_comma+1) * 256 + atoi(fourth_comma+1);
    
    // connect to passive mode
    struct sockaddr_in pasv_addr;
    int pasv_sock_fd;
    if ((pasv_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }
    pasv_addr.sin_family = AF_INET;
    pasv_addr.sin_port = htons(port);
    pasv_addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(pasv_sock_fd, (struct sockaddr *)&pasv_addr, sizeof(pasv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(EXIT_FAILURE);
    }
    
    // list files
    strcpy(command, "LIST\r\n");
    send(sock_fd, command, strlen(command), 0);
    memset(command, 0, sizeof(command));
    n = recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    // receive file list
    memset(buffer, 0, sizeof(buffer));
    n = recv(pasv_sock_fd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    close(pasv_sock_fd);
    close(sock_fd);
    return 0;
}