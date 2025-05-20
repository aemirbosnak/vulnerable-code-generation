//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define PORT 21

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket.\n");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connect error\n");
        return 1;
    }

    char buffer[1024];
    int bytes = recv(sock, buffer, 1024, 0);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Send User
    char user[100] = "USER ";
    strcat(user, username);
    send(sock, user, strlen(user), 0);

    // Receive reply from server
    recv(sock, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Send Password
    char pass[100] = "PASS ";
    strcat(pass, password);
    send(sock, pass, strlen(pass), 0);

    // Receive reply from server
    recv(sock, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Open Passive Mode
    send(sock, "PASV\n", 5, 0);

    // Receive reply from server
    memset(buffer, 0, strlen(buffer));
    recv(sock, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Extract IP address and port number from PASV response
    char* start_ptr = strchr(buffer, '(');
    int array[6];
    sscanf(start_ptr, "(%d,%d,%d,%d,%d,%d)", &array[0],&array[1],&array[2],&array[3],&array[4],&array[5]);
    char ip[100];
    sprintf(ip, "%d.%d.%d.%d", array[0], array[1], array[2], array[3]);
    int port = array[4] * 256 + array[5];

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    // Connect to server
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Data socket connection failed\n");
        return 1;
    }

    // Request directory listing
    char list[6] = "LIST\r\n";
    send(sock, list, strlen(list), 0);

    // Receive reply from server
    memset(buffer, 0, strlen(buffer));
    recv(sock, buffer, 1024, 0);

    // Receive directory listing from server
    while ((bytes = recv(data_sock, buffer, 1024, 0)) > 0) {
        write(STDOUT_FILENO, buffer, bytes);
    }
    close(data_sock);

    // Quit
    send(sock, "QUIT\r\n", 6, 0);
    recv(sock, buffer, 1024, 0);
    printf("%s\n", buffer);

    close(sock);
    return 0;
}