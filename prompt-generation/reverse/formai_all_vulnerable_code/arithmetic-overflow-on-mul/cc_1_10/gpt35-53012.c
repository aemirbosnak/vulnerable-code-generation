//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to store information about network packets */
typedef struct {
    int src_ip;
    int dest_ip;
    int protocol;
    char payload[1024];
} Packet;

/* Define a function to detect network intrusions */
void detect_intrusion(Packet packet) {
    /* Convert IP addresses to strings */
    char src_ip[16], dest_ip[16];
    sprintf(src_ip, "%d.%d.%d.%d", (packet.src_ip >> 24) & 0xff, (packet.src_ip >> 16) & 0xff, (packet.src_ip >> 8) & 0xff, packet.src_ip & 0xff);
    sprintf(dest_ip, "%d.%d.%d.%d", (packet.dest_ip >> 24) & 0xff, (packet.dest_ip >> 16) & 0xff, (packet.dest_ip >> 8) & 0xff, packet.dest_ip & 0xff);
    
    /* Check for protocol violations */
    if (packet.protocol != 6 && packet.protocol != 17) {
        printf("Intrusion detected: invalid protocol (src=%s, dest=%s)\n", src_ip, dest_ip);
        return;
    }
    
    /* Check for well-known attack signatures */
    if (strstr(packet.payload, "SQL injection") != NULL) {
        printf("Intrusion detected: SQL injection (src=%s, dest=%s)\n", src_ip, dest_ip);
    }
    else if (strstr(packet.payload, "buffer overflow") != NULL) {
        printf("Intrusion detected: buffer overflow (src=%s, dest=%s)\n", src_ip, dest_ip);
    }
}

int main() {
    /* Simulate network traffic by generating random packets */
    srand(12345);
    for (int i = 0; i < 100; i++) {
        Packet packet;
        packet.src_ip = rand() % 256 * (1 << 24) + rand() % 256 * (1 << 16) + rand() % 256 * (1 << 8) + rand() % 256;
        packet.dest_ip = rand() % 256 * (1 << 24) + rand() % 256 * (1 << 16) + rand() % 256 * (1 << 8) + rand() % 256;
        packet.protocol = (rand() % 2 == 0) ? 6 : 17;
        memset(packet.payload, 0, sizeof(packet.payload));
        if (rand() % 2 == 0) {
            strcat(packet.payload, "SELECT * FROM users; DROP TABLE users;");
        }
        else {
            strcat(packet.payload, "A");
            for (int j = 0; j < rand() % 1020 + 1; j++) {
                strcat(packet.payload, "B");
            }
            strcat(packet.payload, "C");
        }
        detect_intrusion(packet);
    }
    return 0;
}