//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

int main() {
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Display Entries\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries == MAX_ENTRIES) {
                printf("Phone book is full.\n");
            } else {
                printf("Enter name: ");
                scanf("%s", entries[num_entries].name);
                printf("Enter phone number: ");
                scanf("%s", entries[num_entries].phone);
                num_entries++;
                printf("Entry added.\n");
            }
            break;

        case 2:
            printf("Enter name to search: ");
            char name[50];
            scanf("%s", name);

            int found = 0;
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].name, name) == 0) {
                    printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Entry not found.\n");
            }
            break;

        case 3:
            if (num_entries == 0) {
                printf("No entries in phone book.\n");
            } else {
                printf("Phone Book\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
                }
            }
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}