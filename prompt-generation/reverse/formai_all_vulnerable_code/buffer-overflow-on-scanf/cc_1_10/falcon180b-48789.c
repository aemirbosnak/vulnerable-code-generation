//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in remote;
    char hostname[1024];
    int port;
    int result;
    char buffer[1024];
    time_t start_time, end_time;
    double total_time;

    printf("Enter a hostname or IP address: ");
    scanf("%s", hostname);

    printf("Enter a port number: ");
    scanf("%d", &port);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    remote.sin_family = AF_INET;
    remote.sin_port = htons(port);
    remote.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&remote, sizeof(remote)) == -1) {
        printf("Error connecting to %s:%d: %s\n", hostname, port, strerror(errno));
        close(sock);
        exit(1);
    }

    time(&start_time);
    result = send(sock, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);
    if (result == -1) {
        printf("Error sending request: %s\n", strerror(errno));
        close(sock);
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    result = recv(sock, buffer, sizeof(buffer), 0);
    if (result == -1) {
        printf("Error receiving response: %s\n", strerror(errno));
        close(sock);
        exit(1);
    }

    printf("Response:\n%s", buffer);

    time(&end_time);
    total_time = difftime(end_time, start_time);

    printf("Total time: %.2f seconds\n", total_time);

    close(sock);
    return 0;
}