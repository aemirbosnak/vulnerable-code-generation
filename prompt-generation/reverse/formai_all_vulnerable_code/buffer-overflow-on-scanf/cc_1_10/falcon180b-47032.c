//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 30
#define MAX_NUM_LEN 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char phone_number[MAX_NUM_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *phone_number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].phone_number, phone_number);
    num_entries++;
    printf("Entry added successfully.\n");
}

void delete_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memset(entries[i].name, 0, MAX_NAME_LEN);
            memset(entries[i].phone_number, 0, MAX_NUM_LEN);
            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void search_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].phone_number);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    char choice;
    do {
        printf("Phone book menu:\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf(" %[^\n]", entries[num_entries-1].name);
            printf("Enter phone number: ");
            scanf(" %[^\n]", entries[num_entries-1].phone_number);
            break;
        case '2':
            printf("Enter name to delete: ");
            scanf(" %[^\n]", entries[num_entries-1].name);
            delete_entry(entries[num_entries-1].name);
            break;
        case '3':
            printf("Enter name to search: ");
            scanf(" %[^\n]", entries[num_entries-1].name);
            search_entry(entries[num_entries-1].name);
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}