//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 10
#define MAX_ID_LEN 20

typedef struct player {
    char id[MAX_ID_LEN];
    struct in_addr ip;
} player;

int main(void) {
    int num_players;
    player players[MAX_PLAYERS];
    
    printf("Welcome to the Subnet Calculator!\n");
    printf("Please enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // consume newline character
    
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }
    
    // get player information
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's ID: ", i+1);
        fgets(players[i].id, MAX_ID_LEN, stdin);
        players[i].id[strcspn(players[i].id, "\n")] = '\0'; // remove newline character
        printf("Enter player %d's IP address: ", i+1);
        scanf("%s", inet_ntoa(players[i].ip));
        getchar(); // consume newline character
    }
    
    // print player information
    printf("\nPlayer Information:\n");
    for (int i = 0; i < num_players; i++) {
        printf("ID: %s\nIP Address: %s\n", players[i].id, inet_ntoa(players[i].ip));
    }
    
    // calculate subnet mask
    char subnet_mask[INET_ADDRSTRLEN];
    int subnet_bits;
    printf("\nEnter the number of subnet bits (1-30): ");
    scanf("%d", &subnet_bits);
    getchar(); // consume newline character
    
    if (subnet_bits < 1 || subnet_bits > 30) {
        printf("Invalid number of subnet bits.\n");
        return 1;
    }
    
    struct in_addr mask;
    if (inet_pton(AF_INET, "255.255.255.255", &mask) != 1) {
        perror("inet_pton");
        return 1;
    }
    mask.s_addr <<= subnet_bits;
    if (inet_ntop(AF_INET, &mask, subnet_mask, sizeof(subnet_mask)) == NULL) {
        perror("inet_ntop");
        return 1;
    }
    
    printf("Subnet Mask: %s\n", subnet_mask);
    
    // assign subnet to players
    printf("\nAssigning subnets to players...\n");
    struct in_addr subnet;
    if (inet_pton(AF_INET, inet_ntoa(players[0].ip), &subnet) != 1) {
        perror("inet_pton");
        return 1;
    }
    subnet.s_addr &= mask.s_addr;
    for (int i = 0; i < num_players; i++) {
        players[i].ip.s_addr = subnet.s_addr | ((i+1) << (32-subnet_bits));
        printf("%s's Subnet: %s\n", players[i].id, inet_ntoa(players[i].ip));
    }
    
    return 0;
}