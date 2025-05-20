//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    char phone[15];
} entry;

void add_entry(entry entries[], int *count) {
    printf("Enter name: ");
    scanf("%s", entries[*count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[*count].phone);
    (*count)++;
}

void search_entry(entry entries[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(entry entries[], int *count) {
    char name[30];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(entry) * (*count - i - 1));
            (*count)--;
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;
    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_entry(entries, &count);
            break;
        case 2:
            printf("Enter name to search: ");
            char name[30];
            scanf("%s", name);
            search_entry(entries, count, name);
            break;
        case 3:
            delete_entry(entries, &count);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 4);
    return 0;
}