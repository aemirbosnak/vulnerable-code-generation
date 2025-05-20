//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[15];
} entry;

void add_entry(entry entries[], int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[count].number);
    count++;
}

void display_entry(entry entry) {
    printf("Name: %s\n", entry.name);
    printf("Phone Number: %s\n", entry.number);
}

void search_entry(entry entries[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            display_entry(entries[i]);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    entry entries[MAX_ENTRIES];
    int count = 0;

    printf("Sherlock Holmes' Phone Book\n");

    while (count < MAX_ENTRIES) {
        printf("1. Add Entry\n2. Search Entry\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, count);
                break;
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(entries, count, name);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}