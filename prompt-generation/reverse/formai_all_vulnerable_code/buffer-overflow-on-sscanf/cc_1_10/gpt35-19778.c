//FormAI DATASET v1.0 Category: System process viewer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Struct for holding process information
struct Process {
    int pid;
    char name[256];
    char status[256];
};

// Function to fetch all running processes on the system
void getProcesses(struct Process *processList, int *count) {
    FILE *fp;
    char output[1024], procName[256], procStatus[256];
    int pid, i = 0;

    fp = popen("ps -eo pid,comm,state", "r");

    while(fgets(output, sizeof(output), fp) != NULL) {
        sscanf(output, "%d %s %s", &pid, procName, procStatus);
        processList[i].pid = pid;
        strcpy(processList[i].name, procName);
        strcpy(processList[i].status, procStatus);
        i++;
    }

    *count = i;

    pclose(fp);
}

int main() {
    int sockfd, addrlen, new_socket, i, opt = 1;
    struct sockaddr_in addr;
    struct Process processList[100];
    int count = 0;

    // Fetch all processes running on the system
    getProcesses(processList, &count);

    // Create TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Allow socket reuse
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Failed to bind socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // Accept incoming connections
        if ((new_socket = accept(sockfd, (struct sockaddr *)&addr, (socklen_t*)&addrlen)) < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

        // Send process list to client
        send(new_socket, &count, sizeof(count), 0);
        for (i = 0; i < count; i++) {
            send(new_socket, &processList[i], sizeof(struct Process), 0);
        }

        // Close connection with client
        close(new_socket);
    }

    return 0;
}