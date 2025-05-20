//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 21

int main(int argc, char **argv) {

    int sockfd, rc;
    char buf[BUF_SIZE];

    if(argc != 4) {
        perror("USAGE: ftpclient [server_address] [username] [password]");
        exit(-1);
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check for errors
    if(sockfd < 0) {
        perror("Unable to create socket");
        exit(-1);
    }

    // Declare the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    rc = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    // Check for errors
    if(rc < 0) {
        perror("Unable to connect to server");
        exit(-1);
    }

    // Receive the welcome message from the server
    read(sockfd, buf, BUF_SIZE);

    // Send the username to the server
    sprintf(buf, "USER %s\r\n", argv[2]);
    write(sockfd, buf, strlen(buf));

    // Receive the response from the server
    read(sockfd, buf, BUF_SIZE);

    // Send the password to the server
    sprintf(buf, "PASS %s\r\n", argv[3]);
    write(sockfd, buf, strlen(buf));

    // Receive the response from the server
    read(sockfd, buf, BUF_SIZE);
    
    // Enter passive mode for data transfer
    write(sockfd, "PASV\r\n", strlen("PASV\r\n"));
    read(sockfd, buf, BUF_SIZE);

    // Parse the server's passive mode response
    int ip1, ip2, ip3, ip4, port1, port2;
    sscanf(buf, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &ip1, &ip2, &ip3, &ip4, &port1, &port2);

    // Create the data socket
    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    memset(&data_addr, '\0', sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(argv[1]);
    data_addr.sin_port = htons((256 * port1) + port2);
    rc = connect(data_socket, (struct sockaddr *) &data_addr, sizeof(data_addr));
    if(rc < 0) {
        perror("Unable to connect to server");
        exit(-1);
    }

    // Send the list command to the server
    write(sockfd, "LIST\r\n", strlen("LIST\r\n"));

    // Receive the directory listing from the server
    read(sockfd, buf, BUF_SIZE);
    read(data_socket, buf, BUF_SIZE);

    // Print the directory listing to the console
    printf("%s", buf);

    // Close the sockets and exit
    close(data_socket);
    close(sockfd);
    return 0;
}