//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define BUFFER_SIZE 4096
 
int main(int argc, char *argv[]) {
    char *pop3_server_ip;
    int pop3_server_port;
    char *username;
    char *password;
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
 
    if (argc != 5) {
        printf("Usage: pop3_client <pop3_server_ip> <pop3_server_port> <username> <password>\n");
        return 0;
    }
 
    pop3_server_ip = argv[1];
    pop3_server_port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];
 
    // create a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: could not create socket\n");
        return 1;
    }
 
    // prepare the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(pop3_server_ip);
    server_addr.sin_port = htons(pop3_server_port);
 
    // connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: could not connect to server\n");
        return 1;
    }
 
    // receive the welcome message
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
 
    // send the username
    sprintf(buffer, "USER %s\r\n", username);
    send(socket_fd, buffer, strlen(buffer), 0);
 
    // receive the response
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
 
    // send the password
    sprintf(buffer, "PASS %s\r\n", password);
    send(socket_fd, buffer, strlen(buffer), 0);
 
    // receive the response
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
 
    // send the STAT command
    sprintf(buffer, "STAT\r\n");
    send(socket_fd, buffer, strlen(buffer), 0);
 
    // receive the response
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
 
    // print the response
    printf("%s", buffer);
 
    // close the socket
    close(socket_fd);
 
    return 0;
}