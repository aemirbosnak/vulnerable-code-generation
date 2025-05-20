//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_LENGTH 15
#define SUBNET_LENGTH 5

typedef struct {
    char ip[IP_LENGTH];
    char subnet[SUBNET_LENGTH];
    int num_hosts;
} Subnet;

void print_subnet(Subnet *s) {
    printf("IP: %s\n", s->ip);
    printf("Subnet: %s\n", s->subnet);
    printf("Number of hosts: %d\n", s->num_hosts);
}

int main() {
    int num_subnets;
    char input[IP_LENGTH];
    Subnet subnets[MAX_SUBNETS];
    int i, j, k;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the IP address: ");
    scanf("%s", input);

    for (i = 0; i < num_subnets; i++) {
        subnets[i].num_hosts = 0;
        strcpy(subnets[i].ip, input);
    }

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < IP_LENGTH - 3; j++) {
            if (subnets[i].ip[j] == '.') {
                for (k = j + 1; k < IP_LENGTH - 2; k++) {
                    subnets[i].ip[k] = '0';
                }
                break;
            }
        }
        strcpy(subnets[i].subnet, subnets[i].ip);
        subnets[i].num_hosts = 0;
    }

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < IP_LENGTH - 3; j++) {
            if (subnets[i].ip[j] == '.') {
                for (k = j + 1; k < IP_LENGTH - 2; k++) {
                    if (subnets[i].ip[k] == '0' && subnets[i].num_hosts < 254) {
                        subnets[i].ip[k]++;
                        subnets[i].num_hosts++;
                    } else if (subnets[i].ip[k] == '9' && subnets[i].num_hosts < 254) {
                        subnets[i].ip[k] = '0';
                        subnets[i].num_hosts++;
                    } else {
                        break;
                    }
                }
                break;
            }
        }
    }

    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}