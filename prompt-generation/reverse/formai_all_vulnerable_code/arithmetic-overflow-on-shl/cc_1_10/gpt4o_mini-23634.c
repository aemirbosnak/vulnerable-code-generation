//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OCTETS 4
#define MAX_CIDR 32
#define MAX_INPUT_LEN 18
#define MAX_OUTPUT_LEN 128

typedef struct {
    unsigned char octets[MAX_OCTETS];
    int cidr;
} Subnet;

void display_banner() {
    printf("###############################\n");
    printf("#  Welcome to the Subnet Lab   #\n");
    printf("#  Post-Apocalyptic Edition    #\n");
    printf("###############################\n");
    printf("Survivors, let's calculate the subnet.\n\n");
}

void read_subnet(Subnet *subnet) {
    char input[MAX_INPUT_LEN];
    printf("Enter your network address (e.g., 192.168.1.0/24): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Failed to read input!\n");
        exit(EXIT_FAILURE);
    }
    
    char *slash = strchr(input, '/');
    if (slash == NULL || sscanf(input, "%hhu.%hhu.%hhu.%hhu", &subnet->octets[0], 
        &subnet->octets[1], &subnet->octets[2], &subnet->octets[3]) != MAX_OCTETS 
        || sscanf(slash + 1, "%d", &subnet->cidr) != 1) {
        fprintf(stderr, "Invalid subnet format!\n");
        exit(EXIT_FAILURE);
    }
    
    if (subnet->cidr < 0 || subnet->cidr > MAX_CIDR) {
        fprintf(stderr, "CIDR must be between 0 and 32!\n");
        exit(EXIT_FAILURE);
    }
}

unsigned int calculate_subnet_mask(int cidr) {
    return (cidr == 0) ? 0 : ~((1 << (MAX_CIDR - cidr)) - 1);
}

void calculate_and_display_details(Subnet subnet) {
    unsigned int mask = calculate_subnet_mask(subnet.cidr);
    
    printf("\nSubnet Details:\n");
    printf("Network Address: %d.%d.%d.%d/%d\n", subnet.octets[0], subnet.octets[1], 
           subnet.octets[2], subnet.octets[3], subnet.cidr);
    
    printf("Subnet Mask: %d.%d.%d.%d\n", 
           (mask >> 24) & 0xFF, (mask >> 16) & 0xFF, 
           (mask >> 8) & 0xFF, mask & 0xFF);
    
    unsigned int total_hosts = (1 << (MAX_CIDR - subnet.cidr)) - 2;
    printf("Total Usable Hosts: %u\n", total_hosts);
}

void display_survival_tips() {
    printf("\n--- Survival Tips ---\n");
    printf("1. Always stay aware of your surroundings.\n");
    printf("2. Gather resources whenever possible.\n");
    printf("3. Trust cautiously in the new world order.\n");
    printf("4. Exchange knowledge to survive.\n");
    printf("---------------------\n\n");
}

int main() {
    display_banner();

    Subnet subnet;
    read_subnet(&subnet);
    calculate_and_display_details(subnet);
    display_survival_tips();

    printf("May your networks be stable in this chaotic world. Stay safe, Survivor!\n");

    return 0;
}