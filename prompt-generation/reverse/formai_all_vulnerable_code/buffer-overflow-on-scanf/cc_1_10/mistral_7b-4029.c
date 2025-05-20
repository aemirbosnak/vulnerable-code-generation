//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define ENTRY_SIZE 100

typedef struct {
    char title[50];
    char description[50];
} Entry;

Entry entries[MAX_ENTRIES];
int count = 0;

void add_entry(const char *title, const char *description) {
    if (count >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[count].title, title);
    strcpy(entries[count].description, description);
    count++;
}

void view_entries() {
    if (count == 0) {
        printf("Error: No entries found.\n");
        return;
    }

    printf("\nDigital Diary Entries\n");
    printf("----------------------\n");

    for (int i = 0; i < count; i++) {
        printf("\nEntry %d:\n", i + 1);
        printf("Title: %s\n", entries[i].title);
        printf("Description: %s\n", entries[i].description);
    }
}

void delete_entry(int index) {
    if (index < 0 || index > count) {
        printf("Error: Invalid index.\n");
        return;
    }

    memmove(&entries[index], &entries[index + 1], sizeof(Entry) * (count - index - 1));
    count--;
}

int main() {
    char title[50];
    char description[50];
    int choice, index;

    while (1) {
        printf("\nDigital Diary\n");
        printf("-------------\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter description: ");
                scanf("%s", description);
                add_entry(title, description);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Enter index of entry to delete: ");
                scanf("%d", &index);
                delete_entry(index);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}