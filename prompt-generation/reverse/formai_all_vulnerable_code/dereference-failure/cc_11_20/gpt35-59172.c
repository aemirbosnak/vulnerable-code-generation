//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_HOSTS 100
#define MAX_IP_LENGTH 19
#define MAX_PORT_LENGTH 6

int main(int argc, char *argv[]) {
    char *ipList[MAX_HOSTS];
    char *portList[MAX_HOSTS];
    int hostCount = 0;

    // Parse host and port input arguments
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        // Split host and port arguments
        char *host = strtok(arg, ":");
        char *port = strtok(NULL, ":");

        // Validate host and port input
        if (host == NULL || port == NULL) {
            printf("Invalid host or port argument: %s\n", arg);
            exit(1);
        }

        if (strlen(host) > MAX_IP_LENGTH || strlen(port) > MAX_PORT_LENGTH) {
            printf("Host or port argument is too long: %s\n", arg);
            exit(1);
        }

        // Add host and port to respective lists
        ipList[hostCount] = host;
        portList[hostCount] = port;
        hostCount++;
    }

    printf("Starting network topology mapping...\n");

    // Create array of sockets for each host
    int sockfdList[MAX_HOSTS];
    memset(sockfdList, 0, sizeof(sockfdList));

    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;

    const char *msg = "Hello, world!\n";

    // Asynchronous approach using non-blocking sockets
    for (int i = 0; i < hostCount; i++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Error creating socket for host %s:%s\n", ipList[i], portList[i]);
            continue;
        }

        // Set socket to non-blocking
        fcntl(sockfd, F_SETFL, O_NONBLOCK);

        // Connect to host
        servAddr.sin_port = htons(atoi(portList[i]));
        inet_pton(AF_INET, ipList[i], &servAddr.sin_addr);

        int rc = connect(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr));
        if (rc < 0 && errno != EINPROGRESS) {
            printf("Error connecting to host %s:%s\n", ipList[i], portList[i]);
            close(sockfd);
            continue;
        }

        sockfdList[i] = sockfd;
    }

    // Wait for a specified timeout before checking for connection success
    int timeoutSecs = 5;
    sleep(timeoutSecs);

    // Check for success / failure of socket connections
    for (int i = 0; i < hostCount; i++) {
        int sockfd = sockfdList[i];

        // Check if connection was successful
        int err = 0;
        socklen_t len = sizeof(err);
        int rc = getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);

        if (rc < 0 || err != 0) {
            printf("Could not connect to host %s:%s\n", ipList[i], portList[i]);
        } else {
            printf("Successfully connected to host %s:%s\n", ipList[i], portList[i]);

            // Send message to host
            rc = send(sockfd, msg, strlen(msg), 0);
            if (rc < 0) {
                printf("Error sending message to host %s:%s\n", ipList[i], portList[i]);
            } else {
                printf("Message sent successfully to host %s:%s\n", ipList[i], portList[i]);
            }
        }

        // Close socket
        close(sockfd);
    }

    printf("Network topology mapping complete.\n");

    return 0;
}