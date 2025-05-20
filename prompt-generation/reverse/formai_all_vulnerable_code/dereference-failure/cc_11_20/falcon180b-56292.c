//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    char name[64];
    char address[64];
    int port;
    int protocol;
} service_t;

int main(int argc, char *argv[]) {
    int sock, res;
    struct sockaddr_in server;
    char *address = "127.0.0.1";
    int port = 0;
    service_t *services = NULL;
    int num_services = 0;

    if (argc > 1) {
        address = argv[1];
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, address, &server.sin_addr);

    res = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (res == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    while (1) {
        res = read(sock, &num_services, sizeof(int));
        if (res == -1) {
            perror("read");
            close(sock);
            return 1;
        }
        if (num_services == 0) {
            break;
        }
        services = realloc(services, num_services * sizeof(service_t));
        for (int i = 0; i < num_services; i++) {
            res = read(sock, &services[i], sizeof(service_t));
            if (res == -1) {
                perror("read");
                close(sock);
                return 1;
            }
        }
    }

    for (int i = 0; i < num_services; i++) {
        printf("%s:%d (%s)\n", services[i].name, services[i].port, services[i].protocol == SOCK_STREAM? "TCP" : "UDP");
    }

    close(sock);
    return 0;
}