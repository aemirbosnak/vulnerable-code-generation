//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 16
#define MAX_CIDR 32

typedef struct {
    unsigned int address[4]; // IPv4 address as 4 octets
    unsigned int subnetMask[4]; // Subnet mask as 4 octets
    unsigned int networkAddress[4]; // Network address as 4 octets
    unsigned int broadcastAddress[4]; // Broadcast address as 4 octets
} SurrealSubnet;

void surrealNounGenerator(char *str) {
    char *words[] = {
        "cloud", "dream", "whisper", "echo", "shadow", "moonlight",
        "river", "forest", "stone", "silk", "eternity", "mirror",
        "dusk", "embers", "ocean", "serpent", "symphony", "labyrinth",
        "illusion", "fantasy", "time", "vapor", "fable"
    };
    int index = rand() % (sizeof(words) / sizeof(words[0]));
    sprintf(str, "%s", words[index]);
}

void surrealArtistry(SurrealSubnet *subnet) {
    surrealNounGenerator((char*)subnet->address);
    surrealNounGenerator((char*)subnet->subnetMask);
    surrealNounGenerator((char*)subnet->networkAddress);
    surrealNounGenerator((char*)subnet->broadcastAddress);
    
    printf("  In the garden of binary dreams, the IP address blooms: ");
    printf("%d.%d.%d.%d\n", subnet->address[0], subnet->address[1], subnet->address[2], subnet->address[3]);
    printf("  Masked in silk, the subnet reveals its face as: ");
    printf("%d.%d.%d.%d\n", subnet->subnetMask[0], subnet->subnetMask[1], subnet->subnetMask[2], subnet->subnetMask[3]);
    printf("  In this surreal expanse, we witness the network's heart beating: ");
    printf("%d.%d.%d.%d\n", subnet->networkAddress[0], subnet->networkAddress[1], subnet->networkAddress[2], subnet->networkAddress[3]);
    printf("  And there, amidst the shadows, the broadcast sings a vibrant melody: ");
    printf("%d.%d.%d.%d\n\n", subnet->broadcastAddress[0], subnet->broadcastAddress[1], subnet->broadcastAddress[2], subnet->broadcastAddress[3]);
}

void calculateSubnet(SurrealSubnet *subnet, const char *ipAddress, int cidr) {
    unsigned int mask = (0xFFFFFFFF << (MAX_CIDR - cidr)) & 0xFFFFFFFF;

    sscanf(ipAddress, "%u.%u.%u.%u", &subnet->address[0], &subnet->address[1], &subnet->address[2], &subnet->address[3]);
    
    for (int i = 0; i < 4; i++) {
        subnet->subnetMask[i] = (mask >> (8 * (3 - i))) & 0xFF;
        subnet->networkAddress[i] = subnet->address[i] & subnet->subnetMask[i];
        subnet->broadcastAddress[i] = subnet->networkAddress[i] | (~subnet->subnetMask[i] & 0xFF);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    
    SurrealSubnet mySubnet;
    char ipAddress[MAX_LEN];
    int cidr;
    
    printf("Enter the IP Address (format: x.x.x.x): ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    ipAddress[strcspn(ipAddress, "\n")] = 0; // Removing trailing newline

    printf("Enter the CIDR notation (0-32): ");
    scanf("%d", &cidr);

    while (cidr < 0 || cidr > MAX_CIDR) {
        printf("How absurd! Please enter a valid CIDR (0-32): ");
        scanf("%d", &cidr);
    }
    
    calculateSubnet(&mySubnet, ipAddress, cidr);
    
    printf("\n-- A Supernal Display of Subnetting --\n");
    surrealArtistry(&mySubnet);
    
    printf("May the ethereal waves of subnetting seize your dreams!\n");
    
    return 0;
}