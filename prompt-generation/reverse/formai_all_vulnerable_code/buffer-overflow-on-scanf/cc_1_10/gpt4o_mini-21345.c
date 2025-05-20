//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_USERS 10
#define IP_LENGTH 16
#define MASK_LENGTH 3
#define MAX_USER_INPUT 100

typedef struct {
    char ip[IP_LENGTH];
    char mask[MASK_LENGTH];
    char subnet[IP_LENGTH];
    char broadcast[IP_LENGTH];
    char first_ip[IP_LENGTH];
    char last_ip[IP_LENGTH];
} UserNetwork;

void calculate_subnet(UserNetwork *user);
void print_results(UserNetwork user);

int main() {
    UserNetwork users[MAX_USERS];
    int num_users = 0;
    char continue_input;

    printf("Welcome to the Multiplayer Subnet Calculator!\n");

    do {
        if (num_users >= MAX_USERS) {
            printf("Maximum number of users reached.\n");
            break;
        }

        printf("User %d, enter your IP Address (e.g., 192.168.0.1): ", num_users + 1);
        scanf("%s", users[num_users].ip);
        printf("Enter your Subnet Mask (e.g., 24 for 255.255.255.0): ");
        scanf("%s", users[num_users].mask);

        calculate_subnet(&users[num_users]);
        print_results(users[num_users]);

        num_users++;
        printf("Would you like another user to enter data? (y/n): ");
        getchar(); // to consume newline left by previous input
        continue_input = getchar();
    } while (continue_input == 'y' || continue_input == 'Y');

    printf("Thank you for using the Multiplayer Subnet Calculator!\n");
    return 0;
}

void calculate_subnet(UserNetwork *user) {
    struct sockaddr_in ip_addr;
    struct sockaddr_in mask_addr;
    struct sockaddr_in subnet_addr;
    struct sockaddr_in broadcast_addr;

    // Convert IP and Subnet Mask
    inet_pton(AF_INET, user->ip, &ip_addr.sin_addr);
    int mask_length = atoi(user->mask);
    unsigned long mask = ~0UL >> (32 - mask_length);
    mask_addr.sin_addr.s_addr = htonl(mask);

    // Calculate subnet and broadcast addresses
    subnet_addr.sin_addr.s_addr = ip_addr.sin_addr.s_addr & mask_addr.sin_addr.s_addr;
    broadcast_addr.sin_addr.s_addr = subnet_addr.sin_addr.s_addr | ~mask_addr.sin_addr.s_addr;

    // Set calculated values to user struct
    inet_ntop(AF_INET, &subnet_addr.sin_addr, user->subnet, sizeof(user->subnet));
    inet_ntop(AF_INET, &broadcast_addr.sin_addr, user->broadcast, sizeof(user->broadcast));

    // Calculate first and last usable IP
    snprintf(user->first_ip, IP_LENGTH, "%d.%d.%d.%d", 
             ((uint8_t *)&subnet_addr.sin_addr)[0],
             ((uint8_t *)&subnet_addr.sin_addr)[1],
             ((uint8_t *)&subnet_addr.sin_addr)[2],
             ((uint8_t *)&subnet_addr.sin_addr)[3] + 1); // First usable IP

    snprintf(user->last_ip, IP_LENGTH, "%d.%d.%d.%d", 
             ((uint8_t *)&broadcast_addr.sin_addr)[0],
             ((uint8_t *)&broadcast_addr.sin_addr)[1],
             ((uint8_t *)&broadcast_addr.sin_addr)[2],
             ((uint8_t *)&broadcast_addr.sin_addr)[3] - 1); // Last usable IP
}

void print_results(UserNetwork user) {
    printf("Results for IP: %s / Mask: %s\n", user.ip, user.mask);
    printf("Subnet Address: %s\n", user.subnet);
    printf("Broadcast Address: %s\n", user.broadcast);
    printf("First Usable IP: %s\n", user.first_ip);
    printf("Last Usable IP: %s\n", user.last_ip);
    printf("----------------------------------\n");
}