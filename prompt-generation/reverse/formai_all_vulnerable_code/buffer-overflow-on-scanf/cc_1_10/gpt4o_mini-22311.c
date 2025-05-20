//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PACKETS 1000
#define SUSPICIOUS_THRESHOLD 5
#define PACKET_SIZE 256

typedef struct {
    char source[PACKET_SIZE];
    char destination[PACKET_SIZE];
    char payload[PACKET_SIZE];
    time_t timestamp;
} Packet;

typedef struct {
    Packet packets[MAX_PACKETS];
    int count;
} PacketDatabase;

void log_packet(PacketDatabase *db, const char *src, const char *dst, const char *payload) {
    if (db->count < MAX_PACKETS) {
        Packet *new_packet = &db->packets[db->count++];
        strcpy(new_packet->source, src);
        strcpy(new_packet->destination, dst);
        strcpy(new_packet->payload, payload);
        new_packet->timestamp = time(NULL);
        printf("Packet logged from %s to %s: %s\n", src, dst, payload);
    } else {
        printf("Packet database full. Cannot log new packet.\n");
    }
}

bool detect_intrusion(PacketDatabase *db) {
    int suspicious_count = 0;
    // Analyze logged packets for suspicious activity
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->packets[i].payload, "malicious action") == 0) {
            suspicious_count++;
        }
    }
    return suspicious_count > SUSPICIOUS_THRESHOLD;
}

void show_alert() {
    printf("ALERT: Intrusion detected in the network.\n");
    printf("Strengthening firewall protocols...\n");
}

void simulate_network_activity(PacketDatabase *db) {
    const char *sources[] = {"192.168.1.1", "192.168.1.2", "192.168.1.3"};
    const char *destinations[] = {"192.168.1.10", "192.168.1.20", "192.168.1.30"};
    const char *payloads[] = {"normal action", "malicious action", "data request"};

    for (int i = 0; i < 20; i++) {
        int src_index = rand() % 3;
        int dst_index = rand() % 3;
        int payload_index = rand() % 3;

        log_packet(db, sources[src_index], destinations[dst_index], payloads[payload_index]);
        if (detect_intrusion(db)) {
            show_alert();
        }
        sleep(1); // Simulate the time delay between packets
    }
}

void display_packets(PacketDatabase *db) {
    printf("Current Packet Log:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Packet %d: From %s To %s - [%s] at %s", 
               i + 1, db->packets[i].source, db->packets[i].destination, 
               db->packets[i].payload, ctime(&db->packets[i].timestamp));
    }
}

int main() {
    srand(time(NULL));
    PacketDatabase db = { .count = 0 };

    while (true) {
        int choice;
        printf("\n==========================\n");
        printf("Futuristic Intrusion Detection System\n");
        printf("1. Simulate Network Activity\n");
        printf("2. Display Logged Packets\n");
        printf("3. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                simulate_network_activity(&db);
                break;
            case 2:
                display_packets(&db);
                break;
            case 3:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}