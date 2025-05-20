//Falcon-180B DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char source_ip[16];
    char dest_ip[16];
    char action;
};

int main() {
    int num_rules = 0;
    struct rule rules[MAX_RULES];

    FILE *file = fopen("firewall_rules.txt", "r");
    if (file == NULL) {
        printf("Error: could not open firewall rules file.\n");
        return 1;
    }

    char line[MAX_RULE_LENGTH];
    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        num_rules++;
        if (num_rules > MAX_RULES) {
            printf("Error: too many firewall rules.\n");
            fclose(file);
            return 1;
        }

        char *token = strtok(line, " ");
        strcpy(rules[num_rules - 1].source_ip, token);

        token = strtok(NULL, " ");
        strcpy(rules[num_rules - 1].dest_ip, token);

        token = strtok(NULL, " ");
        rules[num_rules - 1].action = toupper(token[0]);
    }

    fclose(file);

    char source_ip[16];
    char dest_ip[16];

    printf("Enter source IP address: ");
    scanf("%s", source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", dest_ip);

    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 && strcmp(rules[i].dest_ip, dest_ip) == 0) {
            switch (rules[i].action) {
                case 'A':
                    printf("Access granted.\n");
                    break;
                case 'D':
                    printf("Access denied.\n");
                    break;
                default:
                    printf("Invalid action.\n");
                    break;
            }
            return 0;
        }
    }

    printf("No matching firewall rule found.\n");
    return 0;
}