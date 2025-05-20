//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
} entry_t;

void add_entry(entry_t entries[], int count, char name[], char phone[]) {
    if (count >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(entries[count].name, name);
    strcpy(entries[count].phone, phone);

    count++;
}

void search_entry(entry_t entries[], int count, char name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }

    printf("Entry not found!\n");
}

void delete_entry(entry_t entries[], int count, char name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], (count-i-1)*sizeof(entry_t));
            count--;
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    printf("Phone book initialized!\n");

    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], phone[20];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                add_entry(entries, count, name, phone);
                break;
            }
            case 2: {
                char name[50];
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(entries, count, name);
                break;
            }
            case 3: {
                char name[50];
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_entry(entries, count, name);
                break;
            }
            case 4: {
                printf("Exiting phone book...\n");
                return 0;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}