//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program simulates an intrusion detection system that monitors network traffic */
/* The program reads packets from a file and keeps track of network activity */
/* If there are more than a specified number of packets within a certain time window, an alert is raised */

#define MAX_PACKETS 1000
#define WINDOW_SIZE 10 // seconds
#define THRESHOLD 50

typedef struct packet {
    int time;       // in seconds
    char source[16];
    char destination[16];
} Packet;

int current_time = 0;
int packet_count = 0;
Packet packets[MAX_PACKETS];

void log_packet(int time, char* source, char* destination) {
    if (packet_count == MAX_PACKETS) {
        printf("\nMaximum number of packets has been reached!\n");
        exit(1);
    }

    Packet p = {.time = time};
    strcpy(p.source, source);
    strcpy(p.destination, destination);

    packets[packet_count++] = p;
    printf("\nPacket logged - %d seconds: %s -> %s\n", time, source, destination);
}

int num_packets_in_window(int start, int end) {
    int count = 0;
    for (int i = 0; i < packet_count; i++) {
        if (packets[i].time >= start && packets[i].time <= end) {
            count++;
        }
    }
    return count;
}

int main() {
    int time = 0;
    char source[16];
    char destination[16];
    int count_in_window;

    printf("\nStarting intrusion detection system...\n");

    FILE* fp;
    fp = fopen("packets.txt", "r");
    if (fp == NULL){
        printf("Error: Could not open file.\n");
        exit(1);
    }

    /* Read packets from file */
    while (fscanf(fp, "%d %15s %15s", &time, source, destination) != EOF) {
        log_packet(time, source, destination);

        /* Check if packet threshold has been exceeded in current window */
        count_in_window = num_packets_in_window(current_time - WINDOW_SIZE, current_time);
        if (count_in_window > THRESHOLD) {
            printf("\nALERT: Too many packets within %d seconds! (%d packets)\n", WINDOW_SIZE, count_in_window);
        }

        /* Update current time */
        current_time = time;
    }

    fclose(fp);
    printf("\nStopping intrusion detection system...\n");

    return 0;
}