//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define FTP_PORT 21

int main(int argc, char *argv[]) {
    int control_sock, data_sock;
    struct sockaddr_in ctrl_addr, data_addr;
    char buffer[BUF_SIZE];

    // Create a socket for the control connection
    control_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (control_sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up the control address and port
    memset(&ctrl_addr, 0, sizeof(ctrl_addr));
    ctrl_addr.sin_family = AF_INET;
    ctrl_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, argv[1], &ctrl_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to the FTP server control port
    if (connect(control_sock, (struct sockaddr *) &ctrl_addr, sizeof(ctrl_addr)) < 0) {
        perror("Error connecting to control port");
        exit(EXIT_FAILURE);
    }

    // Send login information
    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(control_sock, buffer, strlen(buffer), 0);
    recv(control_sock, buffer, BUF_SIZE, 0);
    sprintf(buffer, "PASS %s\r\n", argv[3]);
    send(control_sock, buffer, strlen(buffer), 0);
    recv(control_sock, buffer, BUF_SIZE, 0);

    // Send PASV command to enter passive mode
    sprintf(buffer, "PASV\r\n");
    send(control_sock, buffer, strlen(buffer), 0);
    recv(control_sock, buffer, BUF_SIZE, 0);

    // Parse the IP address and port from the PASV response
    char *ip_start = strchr(buffer, '(') + 1;
    char *ip_end = strchr(ip_start, ')');
    char *port_start = ip_end + 1;
    int ip1, ip2, ip3, ip4, port1, port2;
    sscanf(ip_start, "%d,%d,%d,%d,%d,%d", &ip1, &ip2, &ip3, &ip4, &port1, &port2);
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    char data_ip[16];
    sprintf(data_ip, "%d.%d.%d.%d", ip1, ip2, ip3, ip4);
    data_addr.sin_addr.s_addr = inet_addr(data_ip);
    data_addr.sin_port = htons(port1 * 256 + port2);

    // Connect to the FTP server data port
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        perror("Error creating data socket");
        exit(EXIT_FAILURE);
    }
    if (connect(data_sock, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) {
        perror("Error connecting to data port");
        exit(EXIT_FAILURE);
    }

    // Send LIST command to retrieve directory information
    sprintf(buffer, "LIST\r\n");
    send(control_sock, buffer, strlen(buffer), 0);
    recv(control_sock, buffer, BUF_SIZE, 0);

    // Receive and display the directory information
    int num_bytes_recv;
    while ((num_bytes_recv = recv(data_sock, buffer, BUF_SIZE, 0)) > 0) {
        write(STDOUT_FILENO, buffer, num_bytes_recv);
    }

    // Close the control and data sockets
    close(data_sock);
    close(control_sock);

    return 0;
}