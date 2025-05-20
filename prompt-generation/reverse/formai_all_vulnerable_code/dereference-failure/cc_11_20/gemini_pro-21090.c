//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: Could not create socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: Could not connect to server");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive the welcome message
    char buf[1024];
    int n = recv(sock, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("Error: Could not receive welcome message");
        close(sock);
        return EXIT_FAILURE;
    }

    // Send the USER command
    sprintf(buf, "USER %s\r\n", argv[2]);
    n = send(sock, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: Could not send USER command");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive the USER response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("Error: Could not receive USER response");
        close(sock);
        return EXIT_FAILURE;
    }

    // Send the PASS command
    sprintf(buf, "PASS %s\r\n", argv[3]);
    n = send(sock, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: Could not send PASS command");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive the PASS response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("Error: Could not receive PASS response");
        close(sock);
        return EXIT_FAILURE;
    }

    // Send the STAT command
    sprintf(buf, "STAT\r\n");
    n = send(sock, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: Could not send STAT command");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive the STAT response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("Error: Could not receive STAT response");
        close(sock);
        return EXIT_FAILURE;
    }

    // Parse the STAT response
    int num_messages, total_size;
    sscanf(buf, "+OK %d %d", &num_messages, &total_size);

    // Send the LIST command
    sprintf(buf, "LIST\r\n");
    n = send(sock, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: Could not send LIST command");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive the LIST response
    FILE *fp = fopen("messages.txt", "w");
    if (fp == NULL) {
        perror("Error: Could not open file messages.txt");
        close(sock);
        return EXIT_FAILURE;
    }
    while (1) {
        n = recv(sock, buf, sizeof(buf), 0);
        if (n == -1) {
            perror("Error: Could not receive LIST response");
            close(sock);
            fclose(fp);
            return EXIT_FAILURE;
        }
        if (strncmp(buf, ".", 1) == 0) {
            break;
        }
        fprintf(fp, "%s", buf);
    }
    fclose(fp);

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    n = send(sock, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: Could not send QUIT command");
        close(sock);
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}