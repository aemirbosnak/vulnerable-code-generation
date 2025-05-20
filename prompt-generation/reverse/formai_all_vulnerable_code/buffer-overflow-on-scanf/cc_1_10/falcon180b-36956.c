//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_IP_LEN 16

struct subnet {
    char ip[MAX_IP_LEN];
    struct subnet *next;
};

struct subnet *head = NULL;

void add_subnet(char *ip) {
    struct subnet *new_subnet = malloc(sizeof(struct subnet));
    strcpy(new_subnet->ip, ip);
    new_subnet->next = NULL;

    if (head == NULL) {
        head = new_subnet;
    } else {
        struct subnet *temp = head;
        while (temp->next!= NULL && count_subnets() < MAX_SUBNETS) {
            temp = temp->next;
        }
        temp->next = new_subnet;
    }
}

int count_subnets() {
    int count = 0;
    struct subnet *temp = head;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void print_subnets() {
    struct subnet *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->ip);
        temp = temp->next;
    }
}

int main() {
    char ip[MAX_IP_LEN];
    int i = 0;

    while (i < MAX_SUBNETS) {
        printf("Enter IP address %d (or enter to finish): ", i+1);
        scanf("%s", ip);

        if (strcmp(ip, "")!= 0) {
            add_subnet(ip);
            i++;
        }
    }

    printf("\nSubnets:\n");
    print_subnets();

    return 0;
}