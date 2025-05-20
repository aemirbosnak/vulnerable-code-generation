//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_BUF_SIZE 1024

void print_usage() {
    printf("Usage: pop3_client <server_ip> <username> <password>\n");
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        print_usage();
    }

    // Get command line arguments
    char *server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Receive welcome message
    char buf[MAX_BUF_SIZE];
    int len = recv(sock, buf, MAX_BUF_SIZE, 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buf);

    // Send USER command
    char user_cmd[MAX_BUF_SIZE];
    snprintf(user_cmd, MAX_BUF_SIZE, "USER %s\r\n", username);
    len = send(sock, user_cmd, strlen(user_cmd), 0);
    if (len < 0) {
        perror("send");
        exit(1);
    }
    len = recv(sock, buf, MAX_BUF_SIZE, 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buf);

    // Send PASS command
    char pass_cmd[MAX_BUF_SIZE];
    snprintf(pass_cmd, MAX_BUF_SIZE, "PASS %s\r\n", password);
    len = send(sock, pass_cmd, strlen(pass_cmd), 0);
    if (len < 0) {
        perror("send");
        exit(1);
    }
    len = recv(sock, buf, MAX_BUF_SIZE, 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buf);

    // Send STAT command
    char stat_cmd[] = "STAT\r\n";
    len = send(sock, stat_cmd, strlen(stat_cmd), 0);
    if (len < 0) {
        perror("send");
        exit(1);
    }
    len = recv(sock, buf, MAX_BUF_SIZE, 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buf);

    // Send LIST command
    char list_cmd[] = "LIST\r\n";
    len = send(sock, list_cmd, strlen(list_cmd), 0);
    if (len < 0) {
        perror("send");
        exit(1);
    }
    while (1) {
        len = recv(sock, buf, MAX_BUF_SIZE, 0);
        if (len < 0) {
            perror("recv");
            exit(1);
        }
        if (strcmp(buf, ".\r\n") == 0) {
            break;
        }
        printf("%s", buf);
    }

    // Send RETR command
    char retr_cmd[MAX_BUF_SIZE];
    snprintf(retr_cmd, MAX_BUF_SIZE, "RETR 1\r\n");
    len = send(sock, retr_cmd, strlen(retr_cmd), 0);
    if (len < 0) {
        perror("send");
        exit(1);
    }
    FILE *fp = fopen("message.txt", "w");
    while (1) {
        len = recv(sock, buf, MAX_BUF_SIZE, 0);
        if (len < 0) {
            perror("recv");
            exit(1);
        }
        if (strcmp(buf, ".\r\n") == 0) {
            break;
        }
        fwrite(buf, 1, len, fp);
    }
    fclose(fp);

    // Send QUIT command
    char quit_cmd[] = "QUIT\r\n";
    len = send(sock, quit_cmd, strlen(quit_cmd), 0);
    if (len < 0) {
        perror("send");
        exit(1);
    }
    len = recv(sock, buf, MAX_BUF_SIZE, 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}