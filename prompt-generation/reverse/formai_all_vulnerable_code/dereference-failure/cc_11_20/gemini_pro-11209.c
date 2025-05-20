//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <host> <port> <file>\n", argv[0]);
        return 1;
    }

    // Get the host name and port number
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Get the file name
    char *file = argv[3];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the FTP server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        perror("gethostbyname");
        return 1;
    }
    memcpy(&serv_addr.sin_addr, host_info->h_addr, host_info->h_length);
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the RETR command to the FTP server
    char retr_cmd[MAX_LINE];
    snprintf(retr_cmd, MAX_LINE, "RETR %s\r\n", file);
    if (send(sock, retr_cmd, strlen(retr_cmd), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response from the FTP server
    char resp[MAX_LINE];
    if (recv(sock, resp, MAX_LINE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Check the response code
    if (resp[0] != '1' && resp[1] != '5') {
        printf("Error: %s\n", resp);
        return 1;
    }

    // Receive the file data from the FTP server
    FILE *fp = fopen(file, "w");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    while (1) {
        char data[MAX_LINE];
        int n = recv(sock, data, MAX_LINE, 0);
        if (n <= 0) {
            break;
        }
        fwrite(data, 1, n, fp);
    }
    fclose(fp);

    // Send the QUIT command to the FTP server
    char quit_cmd[MAX_LINE];
    snprintf(quit_cmd, MAX_LINE, "QUIT\r\n");
    if (send(sock, quit_cmd, strlen(quit_cmd), 0) == -1) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}