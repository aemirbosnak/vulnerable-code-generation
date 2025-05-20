//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF 2048

int main(int argc , char *argv[]) {
    int sock;
    struct sockaddr_in server; // Struct to hold server details
    char message[MAX_BUFF];
    char server_reply[MAX_BUFF];

    // Create a socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        puts("Could not create socket");
    }

    // Set up server details
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    // Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    // Send HELLO command to server
    if (send(sock , "HELLO" , strlen("HELLO") , 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive server response
    if (recv(sock , server_reply , MAX_BUFF , 0) < 0) {
        puts("recv failed");
        return 1;
    }

    puts("Server reply :");
    puts(server_reply);

    // Send USER command to server
    memset(message, 0, MAX_BUFF);
    snprintf(message, MAX_BUFF-1, "USER %s", argv[3]);
    if (send(sock , message , strlen(message) , 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive server response
    memset(server_reply, 0, MAX_BUFF);
    if (recv(sock , server_reply , MAX_BUFF , 0) < 0) {
        puts("recv failed");
        return 1;
    }

    puts("Server reply :");
    puts(server_reply);

    // Send PASS command to server
    memset(message, 0, MAX_BUFF);
    snprintf(message, MAX_BUFF-1, "PASS %s", argv[4]);
    if (send(sock , message , strlen(message) , 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive server response
    memset(server_reply, 0, MAX_BUFF);
    if (recv(sock , server_reply , MAX_BUFF , 0) < 0) {
        puts("recv failed");
        return 1;
    }

    puts("Server reply :");
    puts(server_reply);

    // Send TYPE command to server
    if (send(sock , "TYPE I" , strlen("TYPE I") , 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive server response
    memset(server_reply, 0, MAX_BUFF);
    if (recv(sock , server_reply , MAX_BUFF , 0) < 0) {
        puts("recv failed");
        return 1;
    }

    puts("Server reply :");
    puts(server_reply);

    // Send PASV command to server
    if (send(sock , "PASV" , strlen("PASV") , 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive server response
    memset(server_reply, 0, MAX_BUFF);
    if (recv(sock , server_reply , MAX_BUFF , 0) < 0) {
        puts("recv failed");
        return 1;
    }

    puts("Server reply :");
    puts(server_reply);

    // Parse response to get data port
    int i1, i2, i3, i4, p1, p2;
    sscanf(server_reply, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
           &i1, &i2, &i3, &i4, &p1, &p2);
    int data_port = p1*256 + p2;

    // Connect to data port on server
    int data_sock;
    struct sockaddr_in data_server;
    data_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (data_sock == -1) {
        puts("Could not create socket");
    }
    data_server.sin_addr.s_addr = inet_addr(argv[1]);
    data_server.sin_family = AF_INET;
    data_server.sin_port = htons(data_port);
    if (connect(data_sock , (struct sockaddr *)&data_server , sizeof(data_server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    // Send RETR command to server
    memset(message, 0, MAX_BUFF);
    snprintf(message, MAX_BUFF-1, "RETR %s", argv[5]);
    if (send(sock , message , strlen(message) , 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive server response
    memset(server_reply, 0, MAX_BUFF);
    if (recv(sock , server_reply , MAX_BUFF , 0) < 0) {
        puts("recv failed");
        return 1;
    }

    puts("Server reply :");
    puts(server_reply);

    // Receive file from data port
    FILE* file;
    file = fopen(argv[6], "w");
    char buf[MAX_BUFF];
    int nbytes;
    while ((nbytes = recv(data_sock, buf, MAX_BUFF, 0)) > 0) {
        fwrite(buf, nbytes, 1, file);
    }
    fclose(file);

    // Send QUIT command to server
    if (send(sock , "QUIT" , strlen("QUIT") , 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive server response
    memset(server_reply, 0, MAX_BUFF);
    if (recv(sock , server_reply , MAX_BUFF , 0) < 0) {
        puts("recv failed");
        return 1;
    }

    puts("Server reply :");
    puts(server_reply);

    close(sock);
    close(data_sock);
    return 0;
}