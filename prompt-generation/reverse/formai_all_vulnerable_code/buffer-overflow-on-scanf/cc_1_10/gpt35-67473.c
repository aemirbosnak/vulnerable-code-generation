//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 10
#define MAX_IP_LEN 16
#define MAX_SUBNET_MASK 32

struct client {
    char ip[MAX_IP_LEN];
    int subnet_mask;
};

int get_subnet_mask() {
    int subnet_mask;
    printf("Enter subnet mask (0-32): ");
    scanf("%d", &subnet_mask);
    while (subnet_mask < 0 || subnet_mask > MAX_SUBNET_MASK) {
        printf("Invalid subnet mask, please enter a value between 0 and 32: ");
        scanf("%d", &subnet_mask);
    }
    return subnet_mask;
}

void calculate_network_address(char ip[MAX_IP_LEN], int subnet_mask, char network_address[MAX_IP_LEN]) {
    int ip_address[4];
    int subnet_bits = subnet_mask % 8;
    int octet_index = subnet_mask / 8;
    
    sscanf(ip, "%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);
    
    for (int i = 0; i < octet_index; i++) {
        sprintf(&network_address[strlen(network_address)], "%d.", ip_address[i]);
    }
    
    if (subnet_bits > 0) {
        int mask = 0xFF - (1 << (8 - subnet_bits));
        ip_address[octet_index] = ip_address[octet_index] & mask;
        sprintf(&network_address[strlen(network_address)], "%d.", ip_address[octet_index]);
    } else {
        sprintf(&network_address[strlen(network_address)], "0.");
    }
    
    for (int i = octet_index + 1; i < 4; i++) {
        sprintf(&network_address[strlen(network_address)], "0.");
    }
    
    network_address[strlen(network_address) - 1] = '\0'; // remove trailing .
}

int main() {
    struct client clients[MAX_CLIENTS];
    
    printf("Welcome to the C Subnet Calculator multiplayer game!\n");
    printf("To start, enter your IP address and subnet mask:\n");
    
    char my_ip[MAX_IP_LEN];
    int my_subnet_mask;
    
    printf("Your IP address: ");
    scanf("%s", my_ip);
    my_subnet_mask = get_subnet_mask();
    
    char my_network_address[MAX_IP_LEN];
    calculate_network_address(my_ip, my_subnet_mask, my_network_address);
    
    printf("Your network address is: %s/%d\n", my_network_address, my_subnet_mask);
    printf("Waiting for other players to join...\n");
    
    int num_clients = 1;
    
    while (num_clients < MAX_CLIENTS) {
        struct client new_client;
        printf("\nNew client joining:\n");
        printf("IP address: ");
        scanf("%s", new_client.ip);
        new_client.subnet_mask = get_subnet_mask();
        
        char new_client_network_address[MAX_IP_LEN];
        calculate_network_address(new_client.ip, new_client.subnet_mask, new_client_network_address);
        printf("Network address: %s/%d\n", new_client_network_address, new_client.subnet_mask);
        
        int num_same_network = 0;
        for (int i = 0; i < num_clients; i++) {
            if (strcmp(clients[i].ip, new_client.ip) == 0 || clients[i].subnet_mask != new_client.subnet_mask) {
                continue;
            }
            char existing_client_network_address[MAX_IP_LEN];
            calculate_network_address(clients[i].ip, clients[i].subnet_mask, existing_client_network_address);
            if (strcmp(new_client_network_address, existing_client_network_address) == 0) {
                num_same_network++;
            }
        }
        
        if (num_same_network == 0) {
            printf("New client added to the game!\n");
            clients[num_clients] = new_client;
            num_clients++;
        } else {
            printf("Sorry, the client could not be added to the game because they are on the same network as %d other players.\n", num_same_network);
        }
        
        printf("Current players in the game:\n");
        for (int i = 0; i < num_clients; i++) {
            char network_address[MAX_IP_LEN];
            calculate_network_address(clients[i].ip, clients[i].subnet_mask, network_address);
            printf("%s/%d (%s)\n", clients[i].ip, clients[i].subnet_mask, network_address);
        }
    }
    
    printf("\nGame is full, starting calculations...\n");
    
    for (int i = 0; i < num_clients; i++) {
        char network_address[MAX_IP_LEN];
        calculate_network_address(clients[i].ip, clients[i].subnet_mask, network_address);
        printf("%s/%d (%s)\n", clients[i].ip, clients[i].subnet_mask, network_address);
        
        if (strcmp(my_network_address, network_address) == 0) {
            printf("You are on the same network as %s/%d!\n", clients[i].ip, clients[i].subnet_mask);
        }
    }
    
    printf("\nThe game is now over!");
    return 0;
}