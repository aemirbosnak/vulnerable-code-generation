//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <latitude> <longitude> <date>\n", argv[0]);
        exit(1);
    }

    double lat = atof(argv[1]);
    double lon = atof(argv[2]);
    char *date = argv[3];

    srand(time(NULL));

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) die("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1337);

    int ip[4];
    for (int i = 0; i < 4; i++) {
        ip[i] = rand() % 256;
        server_addr.sin_addr.s_addr = htonl(ip[0] << 24 | ip[1] << 16 | ip[2] << 8 | ip[3]);
    }

    if (connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) die("connect");

    char request[1024];
    snprintf(request, sizeof(request), "GET /calculate?lat=%f&lon=%f&date=%s HTTP/1.1\r\n", lat, lon, date);
    write(fd, request, strlen(request));

    char response[1024];
    memset(response, 0, sizeof(response));
    int n = recv(fd, response, sizeof(response) - 1, 0);
    if (n < 0) die("recv");

    response[n] = '\0';

    double probability = strtod(strtok(strchr(response, '\n'), " "), NULL);

    printf("Probability of alien invasion on %s, %f %%\n", date, probability * 100.0);

    close(fd);
    exit(0);
}