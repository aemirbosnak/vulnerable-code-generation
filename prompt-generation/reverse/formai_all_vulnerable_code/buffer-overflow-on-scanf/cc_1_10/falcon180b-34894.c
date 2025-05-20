//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry entries[], int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);

    printf("Enter phone number: ");
    scanf("%s", entries[count].phone);

    count++;
}

void display_entries(struct entry entries[], int count) {
    printf("Phone Book:\n");
    printf("================\n");

    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].phone);
    }
}

void search_entry(struct entry entries[], int count) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].phone);
        }
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        printf("\nWhat would you like to do?\n1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
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
                search_entry(entries, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}