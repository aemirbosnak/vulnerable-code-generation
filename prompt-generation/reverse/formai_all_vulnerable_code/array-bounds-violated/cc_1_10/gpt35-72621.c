//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int sockid;
    struct sockaddr_in ftp_server;
    char buffer[MAXSIZE];
    int read_size;
    char command[MAXSIZE];

    // Create socket
    sockid = socket(AF_INET, SOCK_STREAM, 0);
    if (sockid == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Configure server information
    ftp_server.sin_addr.s_addr = inet_addr("127.0.0.1");
    ftp_server.sin_family = AF_INET;
    ftp_server.sin_port = htons(21);

    // Connect to the server
    if (connect(sockid, (struct sockaddr *)&ftp_server, sizeof(ftp_server)) < 0) {
        printf("Failed to connect to server");
        return 1;
    }

    // Read server welcome message
    read_size = recv(sockid, buffer, MAXSIZE, 0);
    buffer[read_size] = '\0';
    printf("%s", buffer);

    // Login with username
    printf("Username: ");
    fgets(command, MAXSIZE, stdin);
    command[strlen(command) - 1] = '\0';
    sprintf(buffer, "USER %s\r\n", command);
    send(sockid, buffer, strlen(buffer), 0);
    read_size = recv(sockid, buffer, MAXSIZE, 0);
    buffer[read_size] = '\0';
    printf("%s", buffer);

    // Login with password
    printf("%s", "Password: ");
    fgets(command, MAXSIZE, stdin);
    command[strlen(command) - 1] = '\0';
    sprintf(buffer, "PASS %s\r\n", command);
    send(sockid, buffer, strlen(buffer), 0);
    read_size = recv(sockid, buffer, MAXSIZE, 0);
    buffer[read_size] = '\0';
    printf("%s", buffer);

    // Send command to change to binary mode
    send(sockid, "TYPE I\r\n", strlen("TYPE I\r\n"), 0);
    read_size = recv(sockid, buffer, MAXSIZE, 0);
    buffer[read_size] = '\0';
    printf("%s", buffer);

    // Send command to change to passive mode
    send(sockid, "PASV\r\n", strlen("PASV\r\n"), 0);
    read_size = recv(sockid, buffer, MAXSIZE, 0);
    buffer[read_size] = '\0';
    printf("%s", buffer);

    // Split server address and port from passive mode response
    char *p1, *p2;
    p1 = strchr(buffer, '(');
    p2 = strchr(buffer, ')');
    char addr_port[MAXSIZE];
    strncpy(addr_port, p1+1, p2-p1-1);
    addr_port[p2-p1-1] = '\0';
    int parts[6];
    sscanf(addr_port, "%d,%d,%d,%d,%d,%d", &parts[0], &parts[1], &parts[2], &parts[3], &parts[4], &parts[5]);
    char addr[25];
    sprintf(addr, "%d.%d.%d.%d", parts[0], parts[1], parts[2], parts[3]);
    int port = parts[4] * 256 + parts[5];

    // Connect to data port
    struct sockaddr_in ftp_data;
    ftp_data.sin_family = AF_INET;
    ftp_data.sin_port = htons(port);
    ftp_data.sin_addr.s_addr = inet_addr(addr);
    int sockid_data = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sockid_data, (struct sockaddr *)&ftp_data, sizeof(ftp_data)) < 0) {
        printf("Failed to connect to data port");
        return 1;
    }

    // Retrieve directory listing
    sprintf(buffer, "LIST\r\n");
    send(sockid, buffer, strlen(buffer), 0);

    // Read data from data port
    char data_buffer[MAXSIZE];
    read_size = recv(sockid_data, data_buffer, MAXSIZE, 0);
    while (read_size > 0) {
        printf("%s", data_buffer);
        read_size = recv(sockid_data, data_buffer, MAXSIZE, 0);
    }

    // Close data port
    close(sockid_data);

    // Logout from server
    send(sockid, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    return 0;
}