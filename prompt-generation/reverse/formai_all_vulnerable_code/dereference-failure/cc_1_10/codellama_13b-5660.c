//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: portable
/*
 * Building a FTP Client example program in a portable style
 *
 * Author: [Your Name]
 * Date:   [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function prototypes
void usage(char *prog_name);
int send_ftp_command(int sock_fd, char *cmd);
int recv_ftp_response(int sock_fd);

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    // Parse command line arguments
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return 1;
    }

    // Set up address struct
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send FTP command
    send_ftp_command(sock_fd, "USER anonymous");
    send_ftp_command(sock_fd, "PASS anonymous@example.com");
    send_ftp_command(sock_fd, "PASV");

    // Receive FTP response
    int response = recv_ftp_response(sock_fd);
    if (response < 0) {
        perror("recv_ftp_response");
        return 1;
    }

    // Print FTP response
    printf("FTP response: %d\n", response);

    // Close socket
    close(sock_fd);

    return 0;
}

void usage(char *prog_name) {
    printf("Usage: %s <host> <port>\n", prog_name);
}

int send_ftp_command(int sock_fd, char *cmd) {
    // Send FTP command
    int len = strlen(cmd);
    if (send(sock_fd, cmd, len, 0) < 0) {
        perror("send");
        return -1;
    }

    return 0;
}

int recv_ftp_response(int sock_fd) {
    // Receive FTP response
    char response[1024];
    int len = recv(sock_fd, response, sizeof(response), 0);
    if (len < 0) {
        perror("recv");
        return -1;
    }

    // Parse FTP response
    int code = atoi(response);

    return code;
}