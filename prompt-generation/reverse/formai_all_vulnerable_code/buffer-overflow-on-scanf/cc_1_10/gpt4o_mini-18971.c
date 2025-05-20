//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_EVENTS 100
#define MAX_STRING_LENGTH 256

typedef struct {
    char action[MAX_STRING_LENGTH];
    char item[MAX_STRING_LENGTH];
    char description[MAX_STRING_LENGTH];
} Event;

Event event_log[MAX_EVENTS];
int log_index = 0;

void record_event(const char *action, const char *item, const char *description) {
    if (log_index < MAX_EVENTS) {
        strcpy(event_log[log_index].action, action);
        strcpy(event_log[log_index].item, item);
        strcpy(event_log[log_index].description, description);
        log_index++;
    } else {
        printf("Whoa! The event log is too full! Someone call the space janitor!\n");
    }
}

void display_events() {
    printf("\n----- Intrusion Detection Event Log -----\n");
    for (int i = 0; i < log_index; i++) {
        printf("Event %d: %s %s - %s\n", i + 1, event_log[i].action, event_log[i].item, event_log[i].description);
    }
    printf("------------------------------------------\n");
}

int detect_intrusion(const char *input_action, const char *input_item) {
    if (strcmp(input_action, "hack") == 0 && strcmp(input_item, "database") == 0) {
        return 1; // Hacking detected
    }
    if (strcmp(input_action, "steal") == 0 && strcmp(input_item, "cupcake") == 0) {
        return 1; // Cupcake theft detected!
    }
    return 0; // No intrusion detected
}

void handle_intrusion(const char *input_action, const char *input_item) {
    if (detect_intrusion(input_action, input_item)) {
        record_event(input_action, input_item, "Alert! Potential intruder detected!");
        printf("ALERT: Intruder detected trying to %s the %s! Send in the cupcakes and alarms!\n", input_action, input_item);
    } else {
        printf("No intrusions detected, just a harmless user doing harmless things! Phew!\n");
    }
}

void simulate_intrusion_detection() {
    char action[MAX_STRING_LENGTH];
    char item[MAX_STRING_LENGTH];

    while (1) {
        printf("Enter action (e.g., hack, steal, sit): ");
        scanf("%s", action);
        printf("Enter item (e.g., database, cupcake, chair): ");
        scanf("%s", item);

        handle_intrusion(action, item);
        display_events();
        
        printf("Do you want to continue? (yes/no): ");
        char response[MAX_STRING_LENGTH];
        scanf("%s", response);
        if (strcmp(response, "no") == 0) {
            printf("Exiting the fabulous world of Intrusion Detection! Until next time! 🎉\n");
            break;
        }
    }
}

int main() {
    printf("Welcome to the Great and Powerful C Intrusion Detection System! 🕵️‍♂️\n");
    simulate_intrusion_detection();
    return 0;
}