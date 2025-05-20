//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 // range of ports to scan
#define MAX_HOSTS 1000 // maximum number of hosts to scan

int main(int argc, char *argv[]) {
    int sock, port, host, i;
    struct sockaddr_in server;
    char hostname[100];

    if (argc < 2) {
        printf("Usage: %s <ip_range>\n", argv[0]);
        return 0;
    }

    // parse IP range from command line argument
    char *ip_range = argv[1];
    char *token = strtok(ip_range, ",");
    char *end;
    long ip_start = strtol(token, &end, 10);
    long ip_end = strtol(end, NULL, 10);

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // set up server structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(0); // any available port
    server.sin_addr.s_addr = ip_start; // start IP address

    // bind socket to port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    // loop through hosts and ports
    for (host = ip_start; host <= ip_end; host++) {
        for (port = 1; port < PORT_RANGE; port++) {
            // construct hostname and port
            sprintf(hostname, "%d.%d.%d.%d", host, port);

            // connect to host and port
            if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
                perror("connect failed");
                continue;
            }

            // send and receive data
            char buffer[1024];
            recv(sock, buffer, 1024, 0);
            send(sock, "Hello, world!", 13, 0);

            // close connection and print results
            close(sock);
            printf("Host: %s, Port: %d\n", hostname, port);
        }
    }

    // close socket
    close(sock);

    return 0;
}