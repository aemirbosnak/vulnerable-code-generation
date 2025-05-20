//FormAI DATASET v1.0 Category: Firewall ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LENGTH 15
#define MAX_RULES 10

struct Rule {
    char ip[MAX_IP_LENGTH];
    bool allowed;
};

struct Firewall {
    struct Rule rules[MAX_RULES];
    int count;
};

void addRule(struct Firewall *firewall, char *ip, bool allowed) {
    if (firewall->count >= MAX_RULES) {
        printf("Firewall rule limit reached, cannot add new rule\n");
        return;
    }

    strcpy(firewall->rules[firewall->count].ip, ip);
    firewall->rules[firewall->count].allowed = allowed;
    firewall->count++;
}

bool isAllowed(struct Firewall firewall, char *ip) {
    for (int i = 0; i < firewall.count; i++) {
        if (strcmp(firewall.rules[i].ip, ip) == 0) {
            return firewall.rules[i].allowed;
        }
    }

    return false;
}

int main(void) {
    struct Firewall firewall = { .rules = {}, .count = 0 };
    addRule(&firewall, "192.168.0.1", true);
    addRule(&firewall, "192.168.1.1", true);
    addRule(&firewall, "10.0.0.1", false);

    char ip[MAX_IP_LENGTH];
    printf("Enter IP Address: ");
    scanf("%s", ip);

    if (isAllowed(firewall, ip)) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }

    return 0;
}