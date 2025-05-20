//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define DEFAULT_PORT 8080

struct configuration {
    char *server_address;
    int port;
    int timeout;
} config;

void load_configuration(const char *filename) {
    FILE *f;
    char line[256];
    int n;

    if ((f = fopen(filename, "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), f) != NULL) {
        n = strlen(line);
        if (line[n - 1] == '\n') {
            line[n - 1] = '\0';
        }

        if (strncmp(line, "server_address=", strlen("server_address=")) == 0) {
            config.server_address = strdup(line + strlen("server_address="));
        } else if (strncmp(line, "port=", strlen("port=")) == 0) {
            config.port = atoi(line + strlen("port="));
        } else if (strncmp(line, "timeout=", strlen("timeout=")) == 0) {
            config.timeout = atoi(line + strlen("timeout="));
        }
    }

    fclose(f);
}

int connect_to_server() {
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if ((server = gethostbyname(config.server_address)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(config.port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

void send_message(int sockfd, const char *message) {
    int n;

    if ((n = write(sockfd, message, strlen(message))) < 0) {
        perror("write");
        exit(1);
    }
}

char *receive_message(int sockfd) {
    char buffer[256];
    int n;

    if ((n = read(sockfd, buffer, sizeof(buffer) - 1)) < 0) {
        perror("read");
        exit(1);
    }

    buffer[n] = '\0';

    return strdup(buffer);
}

void close_connection(int sockfd) {
    close(sockfd);
}

int main(int argc, char **argv) {
    int sockfd;
    char *message;

    if (argc > 1) {
        load_configuration(argv[1]);
    } else {
        config.server_address = "localhost";
        config.port = DEFAULT_PORT;
        config.timeout = 30;
    }

    sockfd = connect_to_server();

    send_message(sockfd, "Hello from client!");

    message = receive_message(sockfd);

    printf("Received message: %s\n", message);

    close_connection(sockfd);

    return 0;
}