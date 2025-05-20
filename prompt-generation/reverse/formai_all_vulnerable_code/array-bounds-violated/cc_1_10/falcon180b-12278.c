//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_PORT 25

struct sockaddr_in server_addr;
int sockfd;
char message[1024];
char input_buffer[1024];

void process_response(char *response) {
    printf("Server response: %s\n", response);
}

int main() {
    char hostname[64];
    printf("Enter SMTP server hostname or IP address: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter message to send (END to quit): ");
        fgets(message, sizeof(message), stdin);

        if (strcmp(message, "END\n") == 0) {
            break;
        }

        send(sockfd, message, strlen(message), 0);

        while (1) {
            memset(input_buffer, 0, sizeof(input_buffer));
            int bytes_received = recv(sockfd, input_buffer, sizeof(input_buffer), 0);

            if (bytes_received <= 0) {
                printf("Error receiving data\n");
                exit(1);
            }

            printf("%s", input_buffer);

            if (input_buffer[strlen(input_buffer) - 1] == '.') {
                break;
            }
        }
    }

    close(sockfd);
    return 0;
}