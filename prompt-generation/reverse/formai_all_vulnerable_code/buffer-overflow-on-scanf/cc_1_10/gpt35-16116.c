//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024
#define MAX_LOG_SIZE 100

/* Structure to store packet information */
typedef struct {
    int source_port;
    int dest_port;
    char payload[MAX_PACKET_SIZE];
} Packet;

/* Function to process incoming packets */
void process_packet(Packet packet) {
    printf("New packet received from port %d to port %d\n", packet.source_port, packet.dest_port);
    /* implement intrusion detection rules/checks here */
}

int main() {
    Packet incoming_packet;
    char log[MAX_LOG_SIZE][MAX_PACKET_SIZE]; // array to store log of incoming packets

    while (1) {
        /* read incoming packet */
        printf("Enter source port number: ");
        scanf("%d", &incoming_packet.source_port);
        printf("Enter destination port number: ");
        scanf("%d", &incoming_packet.dest_port);
        printf("Enter payload (max %d characters): ", MAX_PACKET_SIZE);
        getchar(); // clear input buffer
        fgets(incoming_packet.payload, MAX_PACKET_SIZE, stdin);
        incoming_packet.payload[strcspn(incoming_packet.payload, "\n")] = '\0';

        /* add packet to log */
        int i;
        for (i = 0; i < MAX_LOG_SIZE; i++) {
            if (strlen(log[i]) == 0) {
                strcpy(log[i], incoming_packet.payload);
                break;
            }
        }

        /* process incoming packet */
        process_packet(incoming_packet);

        /* check log for suspicious activity */
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(log[j], incoming_packet.payload) == 0) {
                printf("Intrusion detected: repeated payload detected from port %d\n", incoming_packet.source_port);
                /* take necessary action */
            }
        }
    }

    return 0;
}