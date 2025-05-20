//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 30
#define MAX_DISTANCE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char distance[MAX_DISTANCE_LEN];
    int time;
} entry;

void add_entry(entry* entries, int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    printf("Enter distance: ");
    scanf("%s", entries[count].distance);
    printf("Enter time: ");
    scanf("%d", &entries[count].time);
    count++;
}

void print_entries(entry* entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s - %s - %d\n", entries[i].name, entries[i].distance, entries[i].time);
    }
}

int main() {
    entry entries[MAX_ENTRIES];
    int count = 0;
    char choice;

    do {
        printf("Fitness Tracker\n");
        printf("A. Add Entry\n");
        printf("B. Print Entries\n");
        printf("C. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                add_entry(entries, count);
                break;
            case 'B':
                print_entries(entries, count);
                break;
            case 'C':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice!= 'C');

    return 0;
}