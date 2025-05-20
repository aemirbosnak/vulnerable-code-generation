//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_AGE 150

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

int compare_entries(const void* a, const void* b) {
    const entry_t* entry_a = (const entry_t*)a;
    const entry_t* entry_b = (const entry_t*)b;

    if (entry_a->age < entry_b->age) {
        return -1;
    } else if (entry_a->age > entry_b->age) {
        return 1;
    } else {
        return 0;
    }
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Cannot add more entries.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter age: ");
    scanf("%d", &entries[num_entries].age);

    num_entries++;
}

void search_entries() {
    int target_age;

    printf("Enter target age: ");
    scanf("%d", &target_age);

    qsort(entries, num_entries, sizeof(entry_t), compare_entries);

    printf("Results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (entries[i].age >= target_age) {
            printf("%s (%d years old)\n", entries[i].name, entries[i].age);
        }
    }
}

int main() {
    printf("Welcome to the C Database Indexing System!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add entry\n");
        printf("2. Search entries\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;

        case 2:
            search_entries();
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}