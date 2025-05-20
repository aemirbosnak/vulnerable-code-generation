//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

void add_entry(entry_t entries[], int count) {
    char name[50];
    char phone[15];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(entries[count].name, name);
    strcpy(entries[count].phone, phone);

    count++;
}

void search_entry(entry_t entries[], int count) {
    char name[50];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].phone);
        }
    }
}

void delete_entry(entry_t entries[], int count) {
    char name[50];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(entries[j].name, entries[j + 1].name);
                strcpy(entries[j].phone, entries[j + 1].phone);
            }
            count--;
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    printf("Welcome to the Phone Book!\n");

    while (count < MAX_ENTRIES) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, count);
            break;
        case 2:
            search_entry(entries, count);
            break;
        case 3:
            delete_entry(entries, count);
            break;
        case 4:
            printf("Thank you for using the Phone Book!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}