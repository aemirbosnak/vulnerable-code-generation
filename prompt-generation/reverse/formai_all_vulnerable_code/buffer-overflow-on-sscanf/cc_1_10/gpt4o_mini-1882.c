//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 10
#define MAX_SUBNETS 5

typedef struct {
    char ip[16];
    char subnet_mask[16];
} Player;

typedef struct {
    char subnet[16];
    int player_count;
    Player players[MAX_PLAYERS];
} Subnet;

Subnet subnets[MAX_SUBNETS];
int total_subnets = 0;

void clear_buffer() {
    while (getchar() != '\n');
}

void add_subnet() {
    if (total_subnets >= MAX_SUBNETS) {
        printf("Maximum subnets reached.\n");
        return;
    }

    printf("Enter subnet (e.g., 192.168.1.0/24): ");
    scanf("%s", subnets[total_subnets].subnet);
    subnets[total_subnets].player_count = 0;
    total_subnets++;
    printf("Subnet added successfully!\n");
}

void add_player() {
    char subnet[16];
    printf("Enter subnet to which you want to add a player: ");
    scanf("%s", subnet);

    for (int i = 0; i < total_subnets; i++) {
        if (strcmp(subnets[i].subnet, subnet) == 0) {
            if (subnets[i].player_count >= MAX_PLAYERS) {
                printf("Maximum players for this subnet reached.\n");
                return;
            }

            Player new_player;
            printf("Enter player's IP address: ");
            scanf("%s", new_player.ip);
            strcpy(new_player.subnet_mask, subnets[i].subnet);
            
            subnets[i].players[subnets[i].player_count] = new_player;
            subnets[i].player_count++;
            printf("Player added successfully!\n");
            return;
        }
    }
    printf("Subnet not found.\n");
}

void display_subnets() {
    printf("\nList of Subnets and Players:\n");
    for (int i = 0; i < total_subnets; i++) {
        printf("Subnet: %s\n", subnets[i].subnet);
        printf("Players:\n");
        for (int j = 0; j < subnets[i].player_count; j++) {
            printf("\tPlayer %d: %s (Subnet Mask: %s)\n", j + 1, subnets[i].players[j].ip, subnets[i].players[j].subnet_mask);
        }
        if (subnets[i].player_count == 0) {
            printf("\tNo players in this subnet.\n");
        }
    }
}

void calculate_subnets() {
    char subnet[16];
    printf("Enter subnet to calculate (e.g., 192.168.1.0/24): ");
    scanf("%s", subnet);

    struct sockaddr_in sa;
    int prefix_length;
    sscanf(strchr(subnet, '/') + 1, "%d", &prefix_length);
    
    if (inet_pton(AF_INET, strtok(subnet, "/"), &(sa.sin_addr)) != 1) {
        printf("Invalid IP address format.\n");
        return;
    }

    unsigned long subnet_mask = (0xFFFFFFFF << (32 - prefix_length)) & 0xFFFFFFFF;
    unsigned long subnet_ip = ntohl(sa.sin_addr.s_addr) & subnet_mask;

    printf("Subnet Address: %d.%d.%d.%d\n", (subnet_ip >> 24) & 0xFF, (subnet_ip >> 16) & 0xFF, (subnet_ip >> 8) & 0xFF, subnet_ip & 0xFF);
}

void exit_program() {
    printf("Exiting the program.\n");
    exit(0);
}

int main() {
    int choice;
    while (1) {
        printf("\nMultiplayer Subnet Calculator\n");
        printf("1. Add Subnet\n");
        printf("2. Add Player\n");
        printf("3. Display Subnets\n");
        printf("4. Calculate Subnet\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                add_subnet();
                break;
            case 2:
                add_player();
                break;
            case 3:
                display_subnets();
                break;
            case 4:
                calculate_subnets();
                break;
            case 5:
                exit_program();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        clear_buffer(); // Clear the input buffer
    }

    return 0;
}