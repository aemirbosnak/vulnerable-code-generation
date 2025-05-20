//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    char phone[15];
} entry_t;

void add_entry(entry_t entries[], int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[count].phone);
}

void display_entries(entry_t entries[], int count) {
    printf("\nPhone Book:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, entries[i].name, entries[i].phone);
    }
}

void search_entry(entry_t entries[], int count) {
    char name[30];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("\nName: %s\nPhone Number: %s\n", entries[i].name, entries[i].phone);
            break;
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    printf("\nWelcome to the Phone Book!\n");

    while (count < MAX_ENTRIES) {
        int choice;
        printf("\n1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, count);
                count++;
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