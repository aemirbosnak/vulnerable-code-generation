//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <string.h>

#define MAX_PACKETS 100

// Structure to hold player information (for simulating "multiplayer" interaction)
typedef struct {
    char name[50];
    pcap_t *handle;
} Player;

// A global array to hold players
Player players[MAX_PACKETS];
int player_count = 0;

// Packet handler function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct iphdr *ip_header = (struct iphdr *)(packet + 14); // Ethernet header is 14 bytes
    struct sockaddr_in source, dest;

    source.sin_addr.s_addr = ip_header->saddr;
    dest.sin_addr.s_addr = ip_header->daddr;

    printf("Packet captured! Source: %s, Destination: %s\n",
           inet_ntoa(source.sin_addr), inet_ntoa(dest.sin_addr));
}

// Function to initialize a player and start capturing packets
void start_capture(Player *player, char *interface) {
    char errbuf[PCAP_ERRBUF_SIZE];
    player->handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (player->handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", interface, errbuf);
        exit(EXIT_FAILURE);
    }
    pcap_loop(player->handle, 0, packet_handler, (u_char *)player);
}

// Function to create a new player
void create_player() {
    if (player_count >= MAX_PACKETS) {
        printf("Max players reached. Cannot add more players.\n");
        return;
    }

    printf("Enter player name: ");
    scanf("%s", players[player_count].name);
    
    printf("Starting capture for %s...\n", players[player_count].name);
    char interface[10];
    printf("Enter the network interface to capture from (e.g. eth0): ");
    scanf("%s", interface);
    start_capture(&players[player_count], interface);
    player_count++;
}

int main() {
    int num_players;
    printf("How many players will be capturing packets? ");
    scanf("%d", &num_players);
    
    for (int i = 0; i < num_players; i++) {
        create_player();
    }

    printf("Press Ctrl+C to stop capturing\n");

    while (1) {
        // Keep the program running to capture packets; actual capturing is done in separate threads
        sleep(100);
    }
    
    return 0;
}