//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char date[MAX_ENTRY_LENGTH];
    char activity[MAX_ENTRY_LENGTH];
    int duration;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* activity, int duration) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].activity, activity);
    entries[num_entries].duration = duration;
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s (%d minutes)\n", entries[i].date, entries[i].activity, entries[i].duration);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    while (1) {
        printf("Enter an activity (e.g. running, cycling): ");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "quit") == 0) {
            break;
        }
        char date[MAX_ENTRY_LENGTH];
        printf("Enter a date (YYYY-MM-DD): ");
        fgets(date, MAX_ENTRY_LENGTH, stdin);
        date[strcspn(date, "\n")] = '\0';
        int duration;
        printf("Enter a duration in minutes: ");
        scanf("%d", &duration);
        add_entry(date, input, duration);
    }
    printf("Fitness tracker entries:\n");
    print_entries();
    return 0;
}