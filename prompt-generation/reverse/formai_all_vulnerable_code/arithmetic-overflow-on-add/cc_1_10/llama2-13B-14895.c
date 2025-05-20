//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct email email;
    email.from = "john@example.com";
    email.to = "jane@example.com";
    email.subject = "Hello from C!";
    email.message = "This is the first email sent from C.";

    char buffer[MAX_MESSAGE_LENGTH];
    strcpy(buffer, email.message);

    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Sent email successfully. Waiting for response...\n");

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);

    select(sock + 1, &read_fds, NULL, NULL, NULL);

    char buffer2[MAX_MESSAGE_LENGTH];
    read(sock, buffer2, MAX_MESSAGE_LENGTH);

    printf("Received email: %s\n", buffer2);

    close(sock);
    return 0;
}