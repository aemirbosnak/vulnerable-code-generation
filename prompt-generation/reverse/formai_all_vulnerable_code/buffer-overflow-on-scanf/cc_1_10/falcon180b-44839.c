//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry* entries, int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[count].phone);
    count++;
}

void display_entry(struct entry entry) {
    printf("Name: %s\nPhone number: %s\n", entry.name, entry.phone);
}

void search_entry(struct entry* entries, int count, char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            display_entry(entries[i]);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    printf("Phone book\n");
    printf("==========\n");

    while (count < MAX_ENTRIES) {
        int choice;
        printf("1. Add entry\n2. Display entry\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, count);
            break;
        case 2:
            printf("Enter name: ");
            char name[50];
            scanf("%s", name);
            search_entry(entries, count, name);
            break;
        case 3:
            printf("Enter name: ");
            char name2[50];
            scanf("%s", name2);
            search_entry(entries, count, name2);
            break;
        case 4:
            printf("Goodbye.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}