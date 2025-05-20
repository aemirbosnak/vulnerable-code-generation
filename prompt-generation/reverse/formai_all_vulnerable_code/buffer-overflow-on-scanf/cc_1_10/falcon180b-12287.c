//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 50
#define MAX_DURATION_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int duration;
} Entry;

void add_entry(Entry entries[], int count) {
    if (count >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    printf("Enter the name of the exercise: ");
    scanf("%s", entries[count].name);

    printf("Enter the type of exercise (e.g. cardio, strength): ");
    scanf("%s", entries[count].type);

    printf("Enter the duration of the exercise in minutes: ");
    scanf("%d", &entries[count].duration);

    count++;
}

void display_entries(Entry entries[], int count) {
    printf("\nFitness Tracker\n");
    printf("=================\n");

    for (int i = 0; i < count; i++) {
        printf("Entry %d:\n", i+1);
        printf("Name: %s\n", entries[i].name);
        printf("Type: %s\n", entries[i].type);
        printf("Duration: %d minutes\n\n", entries[i].duration);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("\nFitness Tracker Menu\n");
        printf("=====================\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, count);
                break;
            case 2:
                display_entries(entries, count);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}