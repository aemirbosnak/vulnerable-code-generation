//Falcon-180B DATASET v1.0 Category: Firewall ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

typedef struct {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int allow;
} rule_t;

int main() {
    FILE *f;
    char filename[100];
    int num_rules = 0;
    rule_t rules[MAX_RULES];

    printf("Enter the name of the rules file: ");
    scanf("%s", filename);

    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(f, "%s %s %d\n", rules[num_rules].ip, rules[num_rules].port, &rules[num_rules].allow) == 3) {
        num_rules++;
        if (num_rules == MAX_RULES) {
            printf("Error: too many rules.\n");
            exit(1);
        }
    }

    fclose(f);

    char input_ip[MAX_IP_LENGTH];
    char input_port[MAX_PORT_LENGTH];

    while (1) {
        printf("Enter an IP address and port number to check (e.g. 192.168.1.1 80): ");
        scanf("%s %s", input_ip, input_port);

        if (strlen(input_ip)!= 4 || strlen(input_port)!= 5) {
            printf("Error: invalid input.\n");
            continue;
        }

        for (int i = 0; i < num_rules; i++) {
            if (strcmp(input_ip, rules[i].ip) == 0 && strcmp(input_port, rules[i].port) == 0) {
                if (rules[i].allow) {
                    printf("Access allowed.\n");
                } else {
                    printf("Access denied.\n");
                }
                break;
            }
        }
    }

    return 0;
}