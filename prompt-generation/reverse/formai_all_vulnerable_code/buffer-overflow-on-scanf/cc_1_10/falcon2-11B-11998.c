//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float weight;
    float height;
    int age;
} Entry;

void add_entry(Entry* entry) {
    // TODO: Add entry to database
    printf("Added entry: %s, %.2f kg, %.2f cm, %d years old\n", entry->name, entry->weight, entry->height, entry->age);
}

int main() {
    Entry entry;
    int choice;

    do {
        printf("1. Add entry\n");
        printf("2. List entries\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", entry.name);

                printf("Enter weight: ");
                scanf("%f", &entry.weight);

                printf("Enter height: ");
                scanf("%f", &entry.height);

                printf("Enter age: ");
                scanf("%d", &entry.age);

                add_entry(&entry);
                break;

            case 2:
                printf("Entries:\n");
                Entry* entries = NULL;
                int num_entries = 0;

                // TODO: Retrieve entries from database and print them

                break;

            case 3:
                return 0;
        }
    } while (choice!= 3);

    return 0;
}