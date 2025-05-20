//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char* keyword;
    int action;
};

int main() {
    FILE* rules_file;
    char line[MAX_RULE_LENGTH];
    struct rule rules[MAX_RULES];
    int num_rules = 0;
    char input_buffer[MAX_RULE_LENGTH];

    // Load rules from file
    rules_file = fopen("firewall_rules.txt", "r");
    if (rules_file == NULL) {
        printf("Error: Could not open rules file.\n");
        exit(1);
    }

    while (fgets(line, MAX_RULE_LENGTH, rules_file)!= NULL) {
        strcpy(input_buffer, line);
        char* token = strtok(input_buffer, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "BLOCK") == 0) {
            rules[num_rules].action = 0;
        } else if (strcmp(token, "ALLOW") == 0) {
            rules[num_rules].action = 1;
        } else {
            printf("Error: Invalid action in rule.\n");
            exit(1);
        }

        while ((token = strtok(NULL, " "))!= NULL) {
            if (num_rules >= MAX_RULES) {
                printf("Error: Maximum number of rules exceeded.\n");
                exit(1);
            }

            rules[num_rules].keyword = malloc(strlen(token) + 1);
            strcpy(rules[num_rules].keyword, token);

            num_rules++;
        }
    }

    fclose(rules_file);

    // Romeo and Juliet style firewall
    char* message = "My bounty is as boundless as the sea, "
                    "My love as deep; the more I give to thee, "
                    "The more I have, for both are infinite. ";

    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char keyword[MAX_RULE_LENGTH];
            strncpy(keyword, &message[i], 1);

            int j;
            for (j = 0; j < num_rules; j++) {
                if (strcmp(keyword, rules[j].keyword) == 0) {
                    if (rules[j].action == 0) {
                        printf("Firewall: Message blocked due to keyword '%s'.\n", keyword);
                        exit(1);
                    }
                }
            }
        }
    }

    printf("Firewall: Message allowed.\n");

    return 0;
}