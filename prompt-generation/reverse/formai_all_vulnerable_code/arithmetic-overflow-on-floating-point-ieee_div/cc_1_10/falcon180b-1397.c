//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in server_addr;
    char *host = "speedtest.net";
    char *port = "80";
    char buf[1024];
    int len;
    int timeout = 5;
    double start_time, end_time;
    double total_time;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        printf("Error: Invalid hostname.\n");
        close(sock);
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server.\n");
        close(sock);
        return 1;
    }

    // Send request
    sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
    len = strlen(buf);
    if (send(sock, buf, len, 0) == -1) {
        printf("Error: Could not send request.\n");
        close(sock);
        return 1;
    }

    // Receive response
    start_time = time(NULL);
    while (1) {
        len = recv(sock, buf, sizeof(buf), 0);
        if (len <= 0) {
            break;
        }
        buf[len] = '\0';
        printf("%s", buf);
    }
    end_time = time(NULL);
    close(sock);

    // Calculate total time
    total_time = difftime(end_time, start_time);

    // Calculate speed
    double speed = (double)len / total_time;

    // Print results
    printf("\nTotal time: %.2f seconds\n", total_time);
    printf("Speed: %.2f bytes/second\n", speed);

    return 0;
}