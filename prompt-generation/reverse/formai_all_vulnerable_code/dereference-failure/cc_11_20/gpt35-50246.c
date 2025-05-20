//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define PORT 8888

// Constants for defining the types of packets
#define TYPE_AUDIO 1
#define TYPE_VIDEO 2

// A struct to hold information about a packet
typedef struct {
    int type;
    int data;
} Packet;

// A flag to indicate whether the program should exit
int shouldExit = 0;

// A mutex to protect the socket
pthread_mutex_t socketMutex;

// The thread to handle incoming packets
void *packetThread(void *arg) {
    int sockfd = *(int *)arg;
    Packet packet;

    printf("Packet thread started\n");

    while (!shouldExit) {
        // Lock the socket while we read from it
        pthread_mutex_lock(&socketMutex);

        if (recv(sockfd, &packet, sizeof(Packet), 0) == -1) {
            if (errno == EINTR) {
                printf("recv() interrupted\n");
            } else {
                printf("recv() failed: %s\n", strerror(errno));
                shouldExit = 1;
            }
        } else {
            // We've received a packet, handle it appropriately
            switch (packet.type) {
                case TYPE_AUDIO:
                    printf("Received audio packet with data %d\n", packet.data);
                    break;
                case TYPE_VIDEO:
                    printf("Received video packet with data %d\n", packet.data);
                    break;
                default:
                    printf("Received unknown packet type %d\n", packet.type);
                    break;
            }
        }

        // Unlock the socket
        pthread_mutex_unlock(&socketMutex);
    }

    printf("Packet thread exiting\n");

    return NULL;
}

int main() {
    int sockfd, clientfd, opt = 1;
    struct sockaddr_in address;
    pthread_t packetThreadId;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Set the socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt() failed");
        return EXIT_FAILURE;
    }

    // Bind the socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind() failed");
        return EXIT_FAILURE;
    }

    // Wait for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen() failed");
        return EXIT_FAILURE;
    }

    // Start the packet thread to handle incoming packets
    if (pthread_create(&packetThreadId, NULL, packetThread, &sockfd) != 0) {
        perror("pthread_create() failed");
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d\n", PORT);

    while (!shouldExit) {
        // Wait for incoming connections
        clientfd = accept(sockfd, NULL, NULL);

        // Lock the socket while we read from it
        pthread_mutex_lock(&socketMutex);

        if (clientfd == -1) {
            if (errno == EINTR) {
                printf("accept() interrupted\n");
            } else {
                printf("accept() failed: %s\n", strerror(errno));
                shouldExit = 1;
            }
        } else {
            // Read a packet from the client
            Packet packet;
            if (recv(clientfd, &packet, sizeof(Packet), 0) == -1) {
                if (errno == EINTR) {
                    printf("recv() interrupted\n");
                } else {
                    printf("recv() failed: %s\n", strerror(errno));
                    shouldExit = 1;
                }
            } else {
                // We've received a packet, handle it appropriately
                switch (packet.type) {
                    case TYPE_AUDIO:
                        printf("Received audio packet with data %d\n", packet.data);
                        break;
                    case TYPE_VIDEO:
                        printf("Received video packet with data %d\n", packet.data);
                        break;
                    default:
                        printf("Received unknown packet type %d\n", packet.type);
                        break;
                }
            }

            // Send a response packet back to the client
            Packet response;
            response.type = packet.type;
            response.data = packet.data + 1;
            if (send(clientfd, &response, sizeof(Packet), 0) == -1) {
                if (errno == EINTR) {
                    printf("send() interrupted\n");
                } else {
                    printf("send() failed: %s\n", strerror(errno));
                    shouldExit = 1;
                }
            }
        }

        // Unlock the socket
        pthread_mutex_unlock(&socketMutex);

        // Close the client socket
        close(clientfd);
    }

    // Set the flag to exit the packet thread
    shouldExit = 1;

    // Wait for the packet thread to exit
    if (pthread_join(packetThreadId, NULL) != 0) {
        perror("pthread_join() failed");
        return EXIT_FAILURE;
    }

    printf("Server exiting\n");

    return EXIT_SUCCESS;
}