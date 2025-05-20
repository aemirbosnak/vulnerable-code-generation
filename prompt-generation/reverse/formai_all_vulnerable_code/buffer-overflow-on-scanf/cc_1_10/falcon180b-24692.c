//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 50

typedef struct {
    char date[20];
    char activity[MAX_ENTRY_LENGTH];
    int duration;
} Entry;

void add_entry(Entry* entries, int num_entries, char* date, char* activity, int duration) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Cannot add more entries.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].activity, activity);
    entries[num_entries].duration = duration;

    num_entries++;
}

void print_entries(Entry* entries, int num_entries) {
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s (%d minutes)\n", entries[i].date, entries[i].activity, entries[i].duration);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char input[MAX_ENTRY_LENGTH];
    while (1) {
        printf("Enter an activity (or 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        time_t now = time(NULL);
        char date[20];
        strftime(date, 20, "%Y-%m-%d", localtime(&now));

        add_entry(entries, num_entries, date, input, 0);
    }

    print_entries(entries, num_entries);

    return 0;
}