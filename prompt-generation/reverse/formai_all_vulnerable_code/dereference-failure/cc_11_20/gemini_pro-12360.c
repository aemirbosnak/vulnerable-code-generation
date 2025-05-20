//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multiplayer
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 10

struct player {
    int id;
    char *name;
    struct sockaddr_in addr;
};

struct packet {
    int player_id;
    char *data;
};

int main() {
    // Initialize the pcap library
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live("en0", 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening live capture: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Initialize the players
    struct player players[MAX_PLAYERS];
    memset(players, 0, sizeof(players));

    // Initialize the packet buffer
    struct packet buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Main loop
    while (1) {
        // Check for new packets
        struct pcap_pkthdr *header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        }

        // Parse the packet
        struct packet packet;
        memcpy(&packet, data, sizeof(packet));

        // Find the player associated with the packet
        struct player *player = NULL;
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].id == packet.player_id) {
                player = &players[i];
                break;
            }
        }

        // If the player is not found, create a new one
        if (player == NULL) {
            player = &players[0];
            while (player->id != 0) {
                player++;
            }
            player->id = packet.player_id;
            player->name = strdup("Player");
            player->addr = *(struct sockaddr_in *) &data[sizeof(packet)];
        }

        // Add the packet to the buffer
        buffer[player->id] = packet;

        // Send the packet to the other players
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].id != player->id && players[i].id != 0) {
                sendto(socket, &packet, sizeof(packet), 0, (struct sockaddr *) &players[i].addr, sizeof(players[i].addr));
            }
        }
    }

    // Cleanup
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].name != NULL) {
            free(players[i].name);
        }
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}