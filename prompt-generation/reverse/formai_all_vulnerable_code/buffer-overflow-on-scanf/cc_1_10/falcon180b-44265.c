//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char date[10];
    int steps;
};

void add_entry(struct entry *entries, int index, char *date, int steps) {
    strncpy(entries[index].date, date, 9);
    entries[index].steps = steps;
}

void print_entries(struct entry *entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s - %d steps\n", entries[i].date, entries[i].steps);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int entry_count = 0;
    char input[50];

    printf("Welcome to the Cyberpunk Fitness Tracker\n");
    printf("Enter your name: ");
    scanf("%s", input);

    printf("Hello, %s. Let's get started!\n", input);

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", input);
        time_t timestamp = time(NULL);
        struct tm *date_time = localtime(&timestamp);
        strftime(input, 50, "%Y-%m-%d", date_time);

        printf("Enter steps taken today: ");
        scanf("%d", &entries[entry_count].steps);
        add_entry(entries, entry_count++, input, entries[entry_count-1].steps);

        if (entry_count >= MAX_ENTRIES) {
            printf("Maximum entries reached. Exiting.\n");
            break;
        }
    }

    printf("\nYour fitness data:\n");
    print_entries(entries, entry_count);

    return 0;
}