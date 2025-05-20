//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

typedef struct {
    char name[20];
    char ip[20];
    char mask[20];
    char gateway[20];
} subnet;

void read_subnets(subnet* subnets) {
    FILE* file = fopen("subnets.txt", "r");
    if (!file) {
        printf("Error: file not found.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %s %s\n", subnets[count].name, subnets[count].ip, subnets[count].mask, subnets[count].gateway)!= EOF) {
        count++;
        if (count >= MAX_SUBNETS) {
            printf("Error: too many subnets.\n");
            exit(1);
        }
    }
    fclose(file);
}

void print_subnets(subnet* subnets) {
    printf("Subnet\tIP\tMask\tGateway\n");
    for (int i = 0; i < MAX_SUBNETS; i++) {
        if (subnets[i].name[0]!= '\0') {
            printf("%s\t%s\t%s\t%s\n", subnets[i].name, subnets[i].ip, subnets[i].mask, subnets[i].gateway);
        }
    }
}

void calculate_subnets(subnet* subnets) {
    for (int i = 0; i < MAX_SUBNETS; i++) {
        if (subnets[i].name[0]!= '\0') {
            char* ip = strtok(subnets[i].ip, ".");
            char* mask = strtok(subnets[i].mask, ".");
            char* gateway = strtok(subnets[i].gateway, ".");

            char subnet_ip[20];
            char broadcast_ip[20];

            int subnet_octet = atoi(mask);
            int broadcast_octet = 255;

            sprintf(subnet_ip, "%s.%s.%s.%d", ip, ip, ip, subnet_octet);
            sprintf(broadcast_ip, "%s.%s.%s.%d", ip, ip, ip, broadcast_octet);

            printf("Subnet IP: %s\n", subnet_ip);
            printf("Broadcast IP: %s\n", broadcast_ip);
        }
    }
}

int main() {
    subnet subnets[MAX_SUBNETS];
    read_subnets(subnets);
    print_subnets(subnets);
    calculate_subnets(subnets);
    return 0;
}