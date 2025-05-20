//FormAI DATASET v1.0 Category: Firewall ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_IP 100
#define RULES_FILE "rules.txt"

typedef struct {
    int ip[4];
    int mask;
    int action; // 0 - allow, 1 - deny
} rule;

int read_rules(rule **rules) {
    FILE *fp;
    fp = fopen(RULES_FILE, "r");
    if (fp == NULL) {
        printf("Error opening rules file\n");
        return -1;
    }
    int n, i;
    fscanf(fp, "%d", &n);
    *rules = (rule*)malloc(sizeof(rule)*n);
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d.%d.%d.%d/%d %d", &((*rules)[i].ip[0]), &((*rules)[i].ip[1]), &((*rules)[i].ip[2]), &((*rules)[i].ip[3]), &((*rules)[i].mask), &((*rules)[i].action));
    }
    fclose(fp);
    return n;
}

int match_ip(int ip1[], int ip2[], int mask) {
    int i;
    for (i = 0; i < 4; i++) {
        if ((ip1[i] & mask) != (ip2[i] & mask)) {
            return 0;
        }
    }
    return 1;
}

int process_packet(rule *rules, int n, int packet[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (match_ip(rules[i].ip, packet, (0xffffffff << (32 - rules[i].mask)))) {
            return rules[i].action;
        }
    }
    return 0; // default allow
}

int main() {
    srand(time(0));
    int i, n;
    rule *rules;
    n = read_rules(&rules);
    if (n == -1) {
        return -1;
    }
    for (i = 0; i < 10; i++) {
        int packet[4];
        packet[0] = rand() % MAX_IP;
        packet[1] = rand() % MAX_IP;
        packet[2] = rand() % MAX_IP;
        packet[3] = rand() % MAX_IP;
        printf("Packet: %d.%d.%d.%d ", packet[0], packet[1], packet[2], packet[3]);
        if (process_packet(rules, n, packet)) {
            printf("DENIED\n");
        }
        else {
            printf("ALLOWED\n");
        }
    }
    free(rules);
    return 0;
}