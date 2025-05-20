//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 21

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a USER command
    char user_cmd[256];
    sprintf(user_cmd, "USER anonymous\r\n");
    if (send(sock, user_cmd, strlen(user_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char recv_buf[256];
    int recv_len = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check the response code
    if (strncmp(recv_buf, "331", 3) != 0) {
        fprintf(stderr, "Error: Invalid response from server: %s\n", recv_buf);
        return EXIT_FAILURE;
    }

    // Send a PASS command
    char pass_cmd[256];
    sprintf(pass_cmd, "PASS anonymous@example.com\r\n");
    if (send(sock, pass_cmd, strlen(pass_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    recv_len = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check the response code
    if (strncmp(recv_buf, "230", 3) != 0) {
        fprintf(stderr, "Error: Invalid response from server: %s\n", recv_buf);
        return EXIT_FAILURE;
    }

    // Send a LIST command
    char list_cmd[256];
    sprintf(list_cmd, "LIST\r\n");
    if (send(sock, list_cmd, strlen(list_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    recv_len = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response to the console
    printf("%s", recv_buf);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}