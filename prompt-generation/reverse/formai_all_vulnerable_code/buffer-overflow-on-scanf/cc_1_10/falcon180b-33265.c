//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_IP_LIMIT 100

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
    int num_ips;
    char ips[MAX_IP_LIMIT][15];
} Subnet;

void add_ip(Subnet* subnet, char* ip) {
    int i = 0;
    while(i < subnet->num_ips && strcmp(subnet->ips[i], ip)!= 0) {
        i++;
    }
    if(i == subnet->num_ips) {
        strcpy(subnet->ips[i], ip);
        subnet->num_ips++;
    }
}

int main() {
    int num_subnets, i, j, k;
    char input[100];
    Subnet subnets[MAX_SUBNETS];

    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    for(i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);
        printf("Enter subnet %d size: ", i+1);
        scanf("%d", &subnets[i].size);

        subnets[i].num_ips = 0;
        strcpy(subnets[i].ips[0], "0.0.0.0");
        for(j = 1; j < subnets[i].size; j++) {
            sprintf(input, "%d.%d.%d.%d", i+1, j, 0, 0);
            strcpy(subnets[i].ips[j], input);
        }
    }

    printf("Enter IPs to add:\n");
    while(1) {
        scanf("%s", input);
        if(strcmp(input, "done") == 0) {
            break;
        }
        for(i = 0; i < num_subnets; i++) {
            if(strstr(input, subnets[i].name)!= NULL) {
                k = atoi(input+strlen(subnets[i].name)+1);
                if(k >= 1 && k <= subnets[i].size) {
                    add_ip(&subnets[i], input);
                }
            }
        }
    }

    printf("Subnets:\n");
    for(i = 0; i < num_subnets; i++) {
        printf("Subnet %s:\n", subnets[i].name);
        for(j = 0; j < subnets[i].num_ips; j++) {
            printf("%s\n", subnets[i].ips[j]);
        }
    }

    return 0;
}