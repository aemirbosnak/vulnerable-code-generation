//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_LOG 100
#define MAX_INPUT 50

typedef enum {
    ALLOW,
    BLOCK
} Action;

typedef struct {
    int port;
    Action action;
} Rule;

typedef struct {
    char message[MAX_INPUT];
} LogEntry;

Rule rules[MAX_RULES];
LogEntry logs[MAX_LOG];
int rule_count = 0;
int log_count = 0;

void add_rule(int port, Action action) {
    if (rule_count < MAX_RULES) {
        rules[rule_count].port = port;
        rules[rule_count].action = action;
        rule_count++;
        printf("Rule added: %s on port %d\n", action == ALLOW ? "ALLOW" : "BLOCK", port);
    } else {
        printf("Max rule limit reached!\n");
    }
}

void log_event(const char *message) {
    if (log_count < MAX_LOG) {
        strncpy(logs[log_count].message, message, MAX_INPUT - 1);
        logs[log_count].message[MAX_INPUT - 1] = '\0';
        log_count++;
    } else {
        printf("Log capacity full!\n");
    }
}

void check_port(int port) {
    for (int i = 0; i < rule_count; i++) {
        if (rules[i].port == port) {
            if (rules[i].action == BLOCK) {
                log_event("Blocked access attempt!");
                printf("Access to port %d is BLOCKED.\n", port);
                return;
            } else {
                log_event("Allowed access.");
                printf("Access to port %d is ALLOWED.\n", port);
                return;
            }
        }
    }
    log_event("No rule found; allowing access.");
    printf("No rules apply, access to port %d is ALLOWED.\n", port);
}

void display_logs() {
    printf("\n--- Log Entries ---\n");
    for (int i = 0; i < log_count; i++) {
        printf("%s\n", logs[i].message);
    }
}

int main() {
    int choice, port;
    Action action;

    printf("********* Retro C Firewall *********\n");
    while (1) {
        printf("\n1. Add Rule\n2. Check Port\n3. Display Logs\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter port number: ");
                scanf("%d", &port);
                printf("Action (1 for ALLOW, 2 for BLOCK): ");
                scanf("%d", &action);
                add_rule(port, action - 1);
                break;
            case 2:
                printf("Enter port number to check: ");
                scanf("%d", &port);
                check_port(port);
                break;
            case 3:
                display_logs();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}