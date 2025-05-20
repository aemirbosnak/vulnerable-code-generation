//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    while ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (buffer[0] == '2') // OK response
            break;
    }
    if (n < 0)
        error("Error receiving from server");
}

void send_command(int sockfd, const char *command) {
    int n = send(sockfd, command, strlen(command), 0);
    if (n < 0)
        error("Error writing to socket");

    // Receive server response
    receive_response(sockfd);
}

void connect_ftp_server(int sockfd) {
    receive_response(sockfd);
    send_command(sockfd, "USER anonymous\r\n");
    send_command(sockfd, "PASS anonymous@\r\n");
}

void list_files(int sockfd) {
    int data_sock;
    struct sockaddr_in data_addr;
    socklen_t addr_len = sizeof(data_addr);
    char command[BUFFER_SIZE];

    // Prepare the PASV command to retrieve the IP and Port for data transfer
    send_command(sockfd, "PASV\r\n");

    char response[BUFFER_SIZE];
    int n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';

    // Parsing response for the data port
    int p1, p2;
    if (sscanf(response, "%*d %*d %*d %*d %d,%d", &p1, &p2) == 2) {
        int data_port = p1 * 256 + p2;
        printf("Using data port: %d\n", data_port);

        // Set up a socket for data connection
        if ((data_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            error("Error opening data socket");

        data_addr.sin_family = AF_INET;
        data_addr.sin_port = htons(data_port);
        data_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to the server's IP if different

        if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0)
            error("Error connecting to data port");

        // Send LIST command
        send_command(sockfd, "LIST\r\n");

        // Display the file list received from the data socket
        char file_buffer[BUFFER_SIZE];
        int bytes_received;
        while ((bytes_received = recv(data_sock, file_buffer, BUFFER_SIZE - 1, 0)) > 0) {
            file_buffer[bytes_received] = '\0';
            printf("%s", file_buffer);
        }

        close(data_sock);
        receive_response(sockfd); // Receive final response to LIST command
    } else {
        printf("Could not parse PASV response\n");
    }
}

void close_ftp_connection(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    close(sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("Error opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your FTP server IP

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error connecting to server");

    connect_ftp_server(sockfd);
    list_files(sockfd);
    close_ftp_connection(sockfd);

    return 0;
}