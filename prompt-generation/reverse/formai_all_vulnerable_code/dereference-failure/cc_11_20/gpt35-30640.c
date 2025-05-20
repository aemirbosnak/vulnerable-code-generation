//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERV_PORT 21 // FTP server port number
#define BUF_SIZE 256 // buffer size

int main(int argc, char *argv[]) {
    int sock; // socket descriptor
    struct sockaddr_in ser_addr; // server address struct
    char buf[BUF_SIZE]; // buffer to receive server response
    char filename[BUF_SIZE]; // filename to retrieve from FTP server
    
    // clear the buffer and server address struct
    memset(buf, 0, sizeof(buf));
    memset(&ser_addr, 0, sizeof(ser_addr));
    
    // create socket
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    // set server address struct
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(SERV_PORT);
    if (inet_pton(AF_INET, argv[1], &ser_addr.sin_addr) <= 0) {
        printf("Invalid server IP address\n");
        exit(1);
    }

    // connect to server
    if (connect(sock, (struct sockaddr *)&ser_addr, sizeof(ser_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    // receive server welcome message
    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("Error receiving welcome message");
        exit(1);
    }
    printf("%s\n", buf);
    
    // send username
    printf("Enter username: ");
    fgets(buf, BUF_SIZE, stdin);
    sprintf(buf, "USER %s", buf); // format username command
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Error sending username");
        exit(1);
    }
    
    // receive response
    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }
    printf("%s\n", buf);

    // send password
    printf("Enter password: ");
    fgets(buf, BUF_SIZE, stdin);
    sprintf(buf, "PASS %s", buf); // format password command
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Error sending password");
        exit(1);
    }
    
    // receive response
    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }
    printf("%s\n", buf);
    
    // send PASV command to get data port
    if (send(sock, "PASV\r\n", strlen("PASV\r\n"), 0) < 0) {
        perror("Error sending PASV command");
        exit(1);
    }

    // receive response
    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }
    printf("%s\n", buf);

    // extract data port from response
    char *port_start = strchr(buf, '(') + 1;
    char *port_end = strchr(port_start, ')');
    *port_end = '\0';
    char *port_str = strrchr(port_start, ',') + 1;
    int port = atoi(port_str) << 8;
    *port_str = '\0';
    port += atoi(port_start);

    // create data socket
    int data_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (data_sock < 0) {
        perror("Error creating data socket");
        exit(1);
    }

    // set data socket address struct
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, argv[1], &data_addr.sin_addr) <= 0) {
        printf("Invalid server IP address\n");
        exit(1);
    }

    // connect to data socket
    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Error connecting to data socket");
        exit(1);
    }

    // send RETR command to retrieve file
    printf("Enter filename to retrieve: ");
    fgets(filename, BUF_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // remove newline character
    sprintf(buf, "RETR %s\r\n", filename);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Error sending RETR command");
        exit(1);
    }

    // receive response
    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }
    printf("%s\n", buf);

    // receive file from data socket
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(1);
    }
    char file_buf[BUF_SIZE];
    int bytes_read;
    while ((bytes_read = recv(data_sock, file_buf, BUF_SIZE, 0)) > 0) {
        fwrite(file_buf, 1, bytes_read, file);
    }
    fclose(file);
    printf("File retrieved successfully\n");
    
    // close sockets
    close(data_sock);
    close(sock);

    return 0;
}