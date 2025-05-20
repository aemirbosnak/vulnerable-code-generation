//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_IP_SIZE 16
#define MAX_SUBNET_SIZE 4

typedef struct {
    char ip[MAX_IP_SIZE];
    int subnet_size;
} SubnetData;

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    char ip_str[MAX_IP_SIZE];
    int ip[4];
    int subnet_mask[4];
    int broadcast[4];
    int i;
    SubnetData data;

    printf("\n===============\n");
    printf("| SUBNET CALCULATOR |\n");
    printf("|__________________|\n");
    printf("===============\n");
    printf("\nEnter IP address (dd.dd.dd.dd): ");
    fgets(ip_str, MAX_IP_SIZE, stdin);
    sscanf(ip_str, "%[^:]:%n", data.ip, &i);
    sscanf(ip_str + i, "%d", &data.subnet_size);

    if (inet_pton(AF_INET, data.ip, ip) <= 0) {
        fprintf(stderr, "Invalid IP address.\n");
        error("Usage: ./subnet_calculator IP_ADDRESS SUBNET_SIZE\n");
    }

    memset(subnet_mask, 0xFF, sizeof(subnet_mask));
    for (i = 0; i < data.subnet_size; i++) {
        subnet_mask[3 - i / 8] <<= (8 - i % 8);
    }

    for (i = 0; i < 4; i++) {
        broadcast[i] = ip[i] | subnet_mask[i];
    }

    printf("\nSubnet Mask: ");
    for (i = 0; i < 4; i++) {
        printf("%d.", subnet_mask[i]);
    }
    printf("\nBroadcast Address: ");
    for (i = 0; i < 4; i++) {
        printf("%d.", broadcast[i]);
    }
    printf("\n\n");

    return 0;
}