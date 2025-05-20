//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
// Dive into the ethereal depths of the Internet with this mind-boggling speed test!

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

// Macros that will make our code look like a cosmic dance
#define SPEED_OF_LIGHT 299792458 // The universe's ultimate marathon runner
#define NANOSECONDS_PER_SECOND 1000000000 // Time warps at this granular scale

// Define our Internet Explorer spacecraft
typedef struct {
    int sockfd;
    char *host;
    char *port;
} Voyager;

// The stargate that connects us to the void
Voyager *establish_connection(char *host, char *port) {
    Voyager *spaceship = malloc(sizeof(Voyager));
    struct addrinfo hints, *server;

    // Prepare our spaceship for the quantum leap
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Find the stargate's coordinates
    if (getaddrinfo(host, port, &hints, &server) != 0) {
        perror("Failed to locate the cosmic gateway");
        exit(1);
    }

    // Engage the warp drive
    spaceship->sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (spaceship->sockfd == -1) {
        perror("Failed to establish a connection to the astral plane");
        exit(1);
    }

    // Connect to the otherworldly realm
    if (connect(spaceship->sockfd, server->ai_addr, server->ai_addrlen) != 0) {
        perror("Failed to breach the firewall");
        exit(1);
    }

    freeaddrinfo(server);

    return spaceship;
}

// Measure the speed of light by pinging the void
double measure_roundtrip_time(Voyager *spaceship) {
    char ping[1];
    struct timeval start, end;

    // Send a lone photon to the cosmic abyss
    if (send(spaceship->sockfd, ping, 1, 0) == -1) {
        perror("Failed to send a distress call to the black hole");
        exit(1);
    }

    // Wait for the photon to bounce back
    if (recv(spaceship->sockfd, ping, 1, 0) == -1) {
        perror("No response from the cosmic horizon");
        exit(1);
    }

    // Measure the time it took for the journey
    gettimeofday(&start, NULL);
    gettimeofday(&end, NULL);
    double elapsed = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / NANOSECONDS_PER_SECOND;

    return elapsed;
}

// The grand finale: display the cosmic speed limit
int main(int argc, char **argv) {
    if (argc != 3) {
        perror("Insufficient arguments: please provide the host and port of the black hole you wish to probe");
        exit(1);
    }

    Voyager *spaceship = establish_connection(argv[1], argv[2]);
    double roundtrip_time = measure_roundtrip_time(spaceship);
    double speed = (2 * roundtrip_time * SPEED_OF_LIGHT) / 1000000; // Convert meters to kilometers

    printf("Behold! The ethereal speed of light to the cosmic realm of %s:%s is %.2f km/s.\n", spaceship->host, spaceship->port, speed);

    close(spaceship->sockfd);
    free(spaceship);
    return 0;
}