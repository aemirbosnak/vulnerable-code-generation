//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: satisfied
/*
 * C Port Scanner Example Program
 *
 * Usage:
 *  -s <target>   target IP address or hostname
 *  -p <port>     port to scan (default: 1-1000)
 *  -t <time>     scan timeout in seconds (default: 10)
 *
 * Example:
 *  ./portscan -s 192.168.1.1 -p 22 -t 5
 *
 * This program scans the target IP address or hostname for open ports in the
 * specified range and with the specified timeout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define DEFAULT_PORT 1-1000
#define DEFAULT_TIMEOUT 10

int main(int argc, char *argv[]) {
    int sockfd, n;
    char *target, *port_str, *timeout_str;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct timeval tv;

    /* Parse command line arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s -s <target> -p <port> -t <time>\n", argv[0]);
        return 1;
    }

    target = NULL;
    port_str = NULL;
    timeout_str = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
            target = argv[i + 1];
        } else if (strcmp(argv[i], "-p") == 0) {
            port_str = argv[i + 1];
        } else if (strcmp(argv[i], "-t") == 0) {
            timeout_str = argv[i + 1];
        }
    }

    if (target == NULL) {
        fprintf(stderr, "No target specified\n");
        return 1;
    }

    if (port_str == NULL) {
        port_str = DEFAULT_PORT;
    }

    if (timeout_str == NULL) {
        timeout_str = DEFAULT_TIMEOUT;
    }

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    /* Look up target IP address */
    server = gethostbyname(target);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", target);
        return 1;
    }

    /* Set socket timeout */
    tv.tv_sec = atoi(timeout_str);
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        return 1;
    }

    /* Scan ports */
    for (int port = atoi(port_str); port <= 1000; port++) {
        /* Set up socket address structure */
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = server->h_addr;
        serv_addr.sin_port = htons(port);

        /* Connect to socket */
        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect");
            continue;
        }

        /* Print port number if connection successful */
        printf("Port %d is open\n", port);

        /* Close socket */
        close(sockfd);
    }

    return 0;
}