//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct email email;
    printf("Enter from address: ");
    scanf("%s", email.from);
    printf("Enter to address: ");
    scanf("%s", email.to);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    // Send email
    if (sendmail(sock, email.from, email.to, email.subject, email.message) < 0) {
        perror("Sendmail failed");
        exit(EXIT_FAILURE);
    }

    // Receive response
    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("Received response: %s\n", buffer);

    close(sock);
    return 0;
}

int sendmail(int sock, char *from, char *to, char *subject, char *message) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    char *message_buffer = malloc(strlen(message) + 1);
    strcpy(message_buffer, message);

    int len = sendto(sock, message_buffer, strlen(message), 0,
                     (struct sockaddr *)&server_addr, sizeof(server_addr));
    free(message_buffer);

    if (len < 0) {
        perror("Sendto failed");
        exit(EXIT_FAILURE);
    }

    return len;
}