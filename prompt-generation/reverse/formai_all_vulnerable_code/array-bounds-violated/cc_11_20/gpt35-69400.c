//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

void print_error(const char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s [pop3_server] [username] [password]\n", argv[0]);
        return 1;
    }

    char* pop3_server = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; // IPv4 only
    hints.ai_socktype = SOCK_STREAM; // TCP
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(pop3_server, "pop3", &hints, &result);
    if (status != 0) {
        print_error("getaddrinfo() failed");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        print_error("socket() failed");
    }

    status = connect(sockfd, result->ai_addr, result->ai_addrlen);
    if (status == -1) {
        print_error("connect() failed");
    }

    char buf[BUF_SIZE];
    int n_bytes = recv(sockfd, buf, BUF_SIZE-1, 0);
    if (n_bytes == -1) {
        print_error("recv() failed");
    }
    buf[n_bytes] = '\0';
    printf("Received: %s", buf);

    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Error: expected +OK but got %s\n", buf);
        close(sockfd);
        return 1;
    }

    const char* user_cmd = "USER %s\r\n";
    char command[BUF_SIZE];
    snprintf(command, BUF_SIZE, user_cmd, username);

    status = send(sockfd, command, strlen(command), 0);
    if (status == -1) {
        print_error("send() failed");
    }

    n_bytes = recv(sockfd, buf, BUF_SIZE-1, 0);
    if (n_bytes == -1) {
        print_error("recv() failed");
    }
    buf[n_bytes] = '\0';
    printf("Received: %s", buf);

    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Error: expected +OK but got %s\n", buf);
        close(sockfd);
        return 1;
    }

    const char* pass_cmd = "PASS %s\r\n";
    snprintf(command, BUF_SIZE, pass_cmd, password);

    status = send(sockfd, command, strlen(command), 0);
    if (status == -1) {
        print_error("send() failed");
    }

    n_bytes = recv(sockfd, buf, BUF_SIZE-1, 0);
    if (n_bytes == -1) {
        print_error("recv() failed");
    }
    buf[n_bytes] = '\0';
    printf("Received: %s", buf);

    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Error: expected +OK but got %s\n", buf);
        close(sockfd);
        return 1;
    }

    const char* list_cmd = "LIST\r\n";
    snprintf(command, BUF_SIZE, list_cmd);

    status = send(sockfd, command, strlen(command), 0);
    if (status == -1) {
        print_error("send() failed");
    }

    int msg_count = 0;

    while (1) {
        n_bytes = recv(sockfd, buf, BUF_SIZE-1, 0);
        if (n_bytes == -1) {
            print_error("recv() failed");
        }
        buf[n_bytes] = '\0';
        printf("Received: %s", buf);

        if (strcmp(buf, ".\r\n") == 0) {
            break;
        }

        int msg_num, msg_size;
        sscanf(buf, "%d %d", &msg_num, &msg_size);
        printf("Message %d has size %d bytes\n", msg_num, msg_size);
        msg_count++;
    }

    if (msg_count == 0) {
        printf("No messages.\n");
        close(sockfd);
        return 0;
    }

    printf("Enter the message number to retrieve: ");
    int selected_num;
    scanf("%d", &selected_num);

    const char* retr_cmd = "RETR %d\r\n";
    snprintf(command, BUF_SIZE, retr_cmd, selected_num);

    status = send(sockfd, command, strlen(command), 0);
    if (status == -1) {
        print_error("send() failed");
    }

    while (1) {
        n_bytes = recv(sockfd, buf, BUF_SIZE-1, 0);
        if (n_bytes == -1) {
            print_error("recv() failed");
        }
        buf[n_bytes] = '\0';
        printf("%s", buf);

        if (strcmp(buf, ".\r\n") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}