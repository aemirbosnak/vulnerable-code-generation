//Falcon-180B DATASET v1.0 Category: Firewall ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT 8080
#define WHITE_LIST_FILE "whitelist.txt"

struct whitelist {
    char *ip;
    int port;
};

int is_whitelisted(char *ip, int port) {
    FILE *fp;
    struct whitelist *wl;

    fp = fopen(WHITE_LIST_FILE, "r");
    if (fp == NULL) {
        return 0;
    }

    while ((wl = (struct whitelist *)malloc(sizeof(struct whitelist)))!= NULL) {
        fscanf(fp, "%s %d", wl->ip, &wl->port);

        if (strcmp(ip, wl->ip) == 0 && wl->port == port) {
            free(wl);
            fclose(fp);
            return 1;
        }

        free(wl);
    }

    fclose(fp);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    int bytes_received;
    char *ip;
    int port;

    bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
    if (bytes_received <= 0) {
        close(client_socket);
        return;
    }

    buffer[bytes_received] = '\0';
    ip = strtok(buffer, " ");
    port = atoi(strtok(NULL, " "));

    if (is_whitelisted(ip, port)) {
        printf("Connection from %s:%d allowed\n", ip, port);
    } else {
        printf("Connection from %s:%d denied\n", ip, port);
        close(client_socket);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, NULL)) == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}