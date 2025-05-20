//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#define PORT "80"
#define MAX_SEGMENT_SIZE 1500

volatile sig_atomic_t stop;

typedef struct {
    int socket;
    int packet_loss;
    int latency;
} Connection;

void sigint_handler(int sig) {
    stop = 1;
}

void usage(char *progname) {
    fprintf(stderr, "Usage: %s <hostname>\n", progname);
}

void die(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, sigint_handler);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    if (getaddrinfo(argv[1], PORT, &hints, &res)) {
        fprintf(stderr, "Couldn't resolve hostname %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char ipstr[INET6_ADDRSTRLEN];
    void *addr;
    if (res->ai_family == AF_INET) {
        struct sockaddr_in *ipv4 = (struct sockaddr_in *) res->ai_addr;
        addr = &(ipv4->sin_addr);
    } else {
        struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *) res->ai_addr;
        addr = &(ipv6->sin6_addr);
    }
    inet_ntop(res->ai_family, addr, ipstr, sizeof ipstr);
    printf("Connecting to %s (%s)\n\n", res->ai_canonname, ipstr);
    freeaddrinfo(res);

    Connection connection;
    connection.latency = -1;
    connection.packet_loss = -1;

    while (!stop) {
        // create socket
        connection.socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (connection.socket == -1) {
            perror("socket");
            continue;
        }

        // connect to host and start measuring
        struct timeval start, end;
        gettimeofday(&start, NULL);
        int rc = connect(connection.socket, res->ai_addr, res->ai_addrlen);
        gettimeofday(&end, NULL);
        if (rc == -1) {
            perror("connect");
            close(connection.socket);
            sleep(1);
            continue;
        }

        // measure connection latency
        connection.latency = (int) (end.tv_usec - start.tv_usec);
        printf("Latency: %d microseconds\n", connection.latency);

        // create packet
        char packet[MAX_SEGMENT_SIZE];
        memset(packet, 'A', MAX_SEGMENT_SIZE);

        // send packet
        ssize_t bytes_sent = send(connection.socket, packet, MAX_SEGMENT_SIZE, 0);
        if (bytes_sent == -1) {
            perror("send");
            connection.packet_loss = 100;
        } else {
            printf("Packet sent: %ld bytes\n", bytes_sent);
            // wait for response
            char response[MAX_SEGMENT_SIZE];
            memset(response, 0, sizeof(response));
            ssize_t bytes_received = recv(connection.socket, response, MAX_SEGMENT_SIZE, 0);
            if (bytes_received == -1) {
                perror("recv");
                connection.packet_loss = 100;
            } else {
                printf("Packet received: %ld bytes\n", bytes_received);
                // check for packet loss
                if (bytes_sent != bytes_received) {
                    connection.packet_loss = 100 * ((bytes_sent - bytes_received) * 1.0 / bytes_sent);
                    printf("Packet loss: %d%%\n", connection.packet_loss);
                } else {
                    printf("Packet loss: 0%%\n");
                }
            }
        }
        // close connection
        close(connection.socket);
        sleep(1);
    }
    return EXIT_SUCCESS;
}