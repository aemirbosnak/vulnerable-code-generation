//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h> 

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 21

void sendCommand(char* command, char* reply, int sock);

int main() {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    printf("Socket created\n");

    // Connect to server
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to the server");
        return 1;
    }

    char reply[2000];
    int rcode;

    // Send user name
    sendCommand("USER anonymous\r\n", reply, sock);
    sscanf(reply, "%d", &rcode);
    if (rcode != 331) {
        printf("Error: username command failed\n");
        return 1;
    }

    // Send password
    sendCommand("PASS password\r\n", reply, sock);
    sscanf(reply, "%d", &rcode);
    if (rcode != 230) {
        printf("Error: password command failed\n");
        return 1;
    }

    // Download file
    sendCommand("TYPE I\r\n", reply, sock);
    sscanf(reply, "%d", &rcode);
    if (rcode != 200) {
        printf("Error: type command failed\n");
        return 1;
    }

    sendCommand("PASV\r\n", reply, sock);
    sscanf(reply, "%d", &rcode);
    if (rcode != 227) {
        printf("Error: passive command failed\n");
        return 1;
    }

    // get the IP and port for passive mode
    int port1, port2, i1, i2, i3, i4;
    sscanf(reply, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &i1, &i2, &i3, &i4, &port1, &port2);
    char ip[20];
    snprintf(ip, sizeof(ip), "%d.%d.%d.%d", i1, i2, i3, i4);
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons((port1 * 256) + port2);
    addr.sin_addr.s_addr = inet_addr(ip);

    if(connect(data_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Failed to connect to the data socket");
        return 1;
    }

    sendCommand("RETR file1.txt\r\n", reply, sock);
    sscanf(reply, "%d", &rcode);
    if (rcode != 150) {
        printf("Error: retr command failed\n");
        return 1;
    }

    // Download file contents
    FILE* fp = fopen("file1.txt", "w+");
    if (fp == NULL) {
        printf("Error: could not create file\n");
        return 1;
    }

    char buffer[1024];
    int read_size;
    while((read_size = recv(data_sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, read_size, 1, fp);
    }

    fclose(fp);
    close(data_sock);
    printf("Download complete!\n");

    // Quit
    sendCommand("QUIT\r\n", reply, sock);
    sscanf(reply, "%d", &rcode);
    if (rcode != 221) {
        printf("Error: quit command failed\n");
        return 1;
    }

    close(sock);
    return 0;
}

// Function to send command and read response
void sendCommand(char* command, char* reply, int sock) {
    if(send(sock, command, strlen(command), 0) < 0) {
        printf("Error: could not send command\n");
        exit(1);
    }

    if(recv(sock, reply, sizeof(reply), 0) < 0) {
        printf("Error: could not receive reply\n");
        exit(1);
    }
}