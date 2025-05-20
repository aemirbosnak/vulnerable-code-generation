//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <unistd.h>

    int main() {
        // Create a socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Failed to create socket");
            return 1;
        }

        // Connect to the SMTP server
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(25);
        if (inet_pton(AF_INET, "smtp.gmail.com", &server.sin_addr) <= 0) {
            perror("Invalid address");
            return 1;
        }
        if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
            perror("Failed to connect to server");
            return 1;
        }

        // Send the HELO command
        char cmd[256];
        sprintf(cmd, "HELO %s\r\n", "localhost");
        if (send(sock, cmd, strlen(cmd), 0) < 0) {
            perror("Failed to send HELO command");
            return 1;
        }

        // Send the MAIL FROM command
        sprintf(cmd, "MAIL FROM:<%s>\r\n", "sender@gmail.com");
        if (send(sock, cmd, strlen(cmd), 0) < 0) {
            perror("Failed to send MAIL FROM command");
            return 1;
        }

        // Send the RCPT TO command
        sprintf(cmd, "RCPT TO:<%s>\r\n", "recipient@gmail.com");
        if (send(sock, cmd, strlen(cmd), 0) < 0) {
            perror("Failed to send RCPT TO command");
            return 1;
        }

        // Send the DATA command
        sprintf(cmd, "DATA\r\n");
        if (send(sock, cmd, strlen(cmd), 0) < 0) {
            perror("Failed to send DATA command");
            return 1;
        }

        // Send the message body
        sprintf(cmd, "Subject: Hello from C\r\n\r\nHello, World!\r\n.\r\n");
        if (send(sock, cmd, strlen(cmd), 0) < 0) {
            perror("Failed to send message body");
            return 1;
        }

        // Send the QUIT command
        sprintf(cmd, "QUIT\r\n");
        if (send(sock, cmd, strlen(cmd), 0) < 0) {
            perror("Failed to send QUIT command");
            return 1;
        }

        // Close the socket
        close(sock);

        return 0;
    }