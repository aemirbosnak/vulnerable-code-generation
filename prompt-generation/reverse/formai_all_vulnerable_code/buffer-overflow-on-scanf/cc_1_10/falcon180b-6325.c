//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char name[MAX_ENTRY_LENGTH];
    int calories;
    int steps;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    char name[MAX_ENTRY_LENGTH];
    printf("Enter name: ");
    scanf("%s", name);

    int calories, steps;
    printf("Enter calories burned: ");
    scanf("%d", &calories);

    printf("Enter steps taken: ");
    scanf("%d", &steps);

    strcpy(entries[num_entries].name, name);
    entries[num_entries].calories = calories;
    entries[num_entries].steps = steps;

    num_entries++;

    printf("Entry added successfully.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries yet.\n");
        return;
    }

    printf("Name\tCalories\tSteps\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%d\n", entries[i].name, entries[i].calories, entries[i].steps);
    }
}

void delete_entry() {
    if (num_entries == 0) {
        printf("No entries yet.\n");
        return;
    }

    int index;
    printf("Enter index of entry to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    num_entries--;

    for (int i = index; i < num_entries; i++) {
        strcpy(entries[i].name, entries[i+1].name);
        entries[i].calories = entries[i+1].calories;
        entries[i].steps = entries[i+1].steps;
    }

    printf("Entry deleted successfully.\n");
}

int main() {
    while (1) {
        printf("Fitness Tracker\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}