//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    printf("Welcome to the Sherlock Holmes FTP Client Program\n"); // the game is afoot!

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // set up server address structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(21);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(server.sin_zero, '\0', sizeof server.sin_zero);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // authenticate with server
    char buffer[1024];
    recv(sock, buffer, 1024, 0); // receive "220 Welcome to FTP Server"
    printf("%s", buffer);

    memset(buffer, '\0', sizeof buffer);
    printf("Enter username: ");
    scanf("%s", buffer);
    send(sock, buffer, strlen(buffer), 0); // send username
    recv(sock, buffer, 1024, 0); // receive "331 Password required"
    printf("%s", buffer);

    memset(buffer, '\0', sizeof buffer);
    printf("Enter password: ");
    scanf("%s", buffer);
    send(sock, buffer, strlen(buffer), 0); // send password
    recv(sock, buffer, 1024, 0); // receive "230 User logged in"
    printf("%s", buffer);

    // enter passive mode
    send(sock, "PASV\r\n", strlen("PASV\r\n"), 0);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // parse server response to get data port
    char *port_start = strchr(buffer, '(') + 1;
    char *port_end = strchr(buffer, ')');
    *port_end = '\0';
    char *port_string = strdup(port_start);
    char *ip_string = strtok(port_string, ",");
    char ip_address[16];
    sprintf(ip_address, "%s.%s.%s.%s", ip_string, strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","));
    int port_number = atoi(strtok(NULL, ",")) * 256 + atoi(strtok(NULL, ","));

    // create data socket
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock == -1) {
        perror("Error creating data socket");
        exit(1);
    }

    // set up data server address structure
    struct sockaddr_in data_server;
    data_server.sin_family = AF_INET;
    data_server.sin_port = htons(port_number);
    data_server.sin_addr.s_addr = inet_addr(ip_address);
    memset(data_server.sin_zero, '\0', sizeof data_server.sin_zero);

    // connect to data server
    if (connect(data_sock, (struct sockaddr *)&data_server, sizeof(data_server)) < 0) {
        perror("Error connecting to data server");
        exit(1);
    }

    // receive welcome message from server
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    printf("Enter command: ");
    memset(buffer, '\0', sizeof buffer);
    scanf("%s", buffer);
    send(sock, buffer, strlen(buffer), 0); // send command
    recv(sock, buffer, 1024, 0); // receive server response
    printf("%s", buffer);

    // retrieve file from server
    if (strncmp(buffer, "150", 3) == 0) {
        // file available, retrieve it
        FILE *fp = fopen("file.txt", "wb");
        if (fp == NULL) {
            perror("Error creating file");
            exit(1);
        }

        while (recv(data_sock, buffer, 1024, 0) > 0) {
            fwrite(buffer, sizeof(char), strlen(buffer), fp);
            memset(buffer, '\0', sizeof buffer);
        }

        fclose(fp);
    }

    // close sockets
    close(sock);
    close(data_sock);

    printf("Farewell! Till we meet again, dear user.\n"); // the game is over
    return 0;
}