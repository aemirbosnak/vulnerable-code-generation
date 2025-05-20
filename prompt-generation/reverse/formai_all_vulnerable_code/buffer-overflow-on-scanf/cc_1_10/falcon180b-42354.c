//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
    double duration;
} fitness_entry;

void add_entry(fitness_entry* entries, int* num_entries) {
    printf("Enter the name of the activity: ");
    scanf("%s", entries[*num_entries].name);
    printf("Enter a description of the activity (optional): ");
    scanf("%s", entries[*num_entries].description);
    entries[*num_entries].start_time = time(NULL);
}

void end_entry(fitness_entry* entries, int* num_entries) {
    entries[*num_entries].end_time = time(NULL);
    entries[*num_entries].duration = difftime(entries[*num_entries].end_time, entries[*num_entries].start_time);
}

void print_entries(fitness_entry* entries, int num_entries) {
    printf("Activity\tDuration\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%.2lf\n", entries[i].name, entries[i].duration);
    }
}

int main() {
    fitness_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char repeat = 'y';

    while (repeat == 'y') {
        printf("Welcome to the Fitness Tracker!\n");
        printf("Enter 'a' to add an entry, 'p' to print entries, or 'q' to quit.\n");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
        case 'a':
            if (num_entries >= MAX_ENTRIES) {
                printf("Sorry, you have reached the maximum number of entries.\n");
            } else {
                add_entry(entries, &num_entries);
            }
            break;
        case 'p':
            print_entries(entries, num_entries);
            break;
        case 'q':
            repeat = 'n';
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}