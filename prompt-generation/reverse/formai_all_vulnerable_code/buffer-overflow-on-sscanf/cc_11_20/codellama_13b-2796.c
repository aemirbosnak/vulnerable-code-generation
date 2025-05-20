//Code Llama-13B DATASET v1.0 Category: Intrusion detection system ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256
#define MAX_PATTERNS 100
#define MAX_ACTIONS 10

typedef struct {
    char pattern[MAX_LINE_LENGTH];
    char action[MAX_LINE_LENGTH];
} rule_t;

rule_t rules[MAX_PATTERNS];

int main(void) {
    int i, j, k;
    char line[MAX_LINE_LENGTH];
    char command[MAX_LINE_LENGTH];
    char arguments[MAX_LINE_LENGTH];
    char output[MAX_LINE_LENGTH];
    int num_rules = 0;

    while (1) {
        printf("Enter a command: ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        sscanf(line, "%s %s", command, arguments);

        if (strcmp(command, "add_rule") == 0) {
            sscanf(arguments, "%s %s", rules[num_rules].pattern, rules[num_rules].action);
            num_rules++;
        } else if (strcmp(command, "del_rule") == 0) {
            sscanf(arguments, "%d", &i);
            if (i >= 0 && i < num_rules) {
                for (j = i; j < num_rules - 1; j++) {
                    rules[j] = rules[j + 1];
                }
                num_rules--;
            }
        } else if (strcmp(command, "check") == 0) {
            sscanf(arguments, "%s", output);
            for (i = 0; i < num_rules; i++) {
                if (strstr(output, rules[i].pattern) != NULL) {
                    system(rules[i].action);
                    break;
                }
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}