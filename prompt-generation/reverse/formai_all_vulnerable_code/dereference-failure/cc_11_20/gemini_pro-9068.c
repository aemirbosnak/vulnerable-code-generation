//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <message>\n", argv[0]);
        exit(1);
    }

    const char *server = argv[1];
    int port = atoi(argv[2]);
    const char *message = argv[3];

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = inet_addr(server),
        },
    };

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buffer[4096];
    int bytes_received;

    // SMTP client loop
    while (1) {
        // Read response from server
        bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("recv");
            break;
        }

        // Print response from server
        printf("%s", buffer);

        // Check for server greeting
        if (strstr(buffer, "220") != NULL) {
            // Send HELO command
            sprintf(buffer, "HELO %s\r\n", "client");
            if (send(sock, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                break;
            }
        } else if (strstr(buffer, "250") != NULL) {
            // Send MAIL FROM command
            sprintf(buffer, "MAIL FROM: <sender@example.com>\r\n");
            if (send(sock, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                break;
            }
        } else if (strstr(buffer, "250") != NULL) {
            // Send RCPT TO command
            sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
            if (send(sock, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                break;
            }
        } else if (strstr(buffer, "250") != NULL) {
            // Send DATA command
            sprintf(buffer, "DATA\r\n");
            if (send(sock, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                break;
            }
        } else if (strstr(buffer, "354") != NULL) {
            // Send email message
            sprintf(buffer, "%s\r\n.\r\n", message);
            if (send(sock, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                break;
            }
        } else if (strstr(buffer, "250") != NULL) {
            // Send QUIT command
            sprintf(buffer, "QUIT\r\n");
            if (send(sock, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                break;
            }
            break;
        }

        // Clear buffer
        memset(buffer, 0, sizeof(buffer));
    }

    close(sock);

    return 0;
}