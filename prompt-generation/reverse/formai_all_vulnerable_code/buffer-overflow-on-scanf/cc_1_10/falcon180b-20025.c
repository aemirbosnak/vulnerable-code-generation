//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} entry;

void add_entry(entry entries[], int num_entries) {
    char name[50];
    char phone[15];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].phone, phone);

    num_entries++;
}

void display_entries(entry entries[], int num_entries) {
    printf("\nPhone Book:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].phone);
    }
}

void search_entry(entry entries[], int num_entries) {
    char name[50];

    printf("\nEnter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("\n%s - %s\n", entries[i].name, entries[i].phone);
        }
    }
}

int main() {
    entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        printf("\n1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        int choice;

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, num_entries);
                break;
            case 2:
                display_entries(entries, num_entries);
                break;
            case 3:
                search_entry(entries, num_entries);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}