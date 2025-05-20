//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct hostent *host = NULL;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int sock, len, result, value;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);

    if (host == NULL) {
        fprintf(stderr, "Unknown host: %s\n", argv[1]);
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr = *((struct in_addr *) host->h_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Cannot create socket");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Cannot connect to server");
        exit(1);
    }

    printf("Connected to server %s:%s\n", argv[1], argv[2]);

    while (1) {
        printf("\nEnter a value to send to server (0 to exit): ");
        scanf("%d", &value);

        if (value == 0) {
            break;
        }

        sprintf(buffer, "%d\n", value);

        len = strlen(buffer);

        result = send(sock, buffer, len, 0);

        if (result != len) {
            perror("Cannot send data to server");
            exit(1);
        }

        len = recv(sock, buffer, BUFFER_SIZE, 0);

        if (len < 0) {
            perror("Cannot receive data from server");
            exit(1);
        }

        buffer[len] = '\0';

        printf("Received response from server: %s\n", buffer);
    }

    close(sock);

    return 0;
}