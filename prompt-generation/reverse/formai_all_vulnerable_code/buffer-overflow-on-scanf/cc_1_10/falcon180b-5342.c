//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // maximum number of entries in phone book
#define MAX_NAME_LEN 50 // maximum length of name
#define MAX_NUM_LEN 20 // maximum length of phone number

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES]; // the phone book array
int num_entries = 0; // number of entries in phone book

void add_entry() {
    num_entries++;
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries-1].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries-1].number);
}

void delete_entry() {
    int i, found = 0;
    char name[MAX_NAME_LEN];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        num_entries--;
        while (i < num_entries) {
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].number, phonebook[i+1].number);
            i++;
        }
    } else {
        printf("Entry not found.\n");
    }
}

void search_entry() {
    int i;
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice = 0;
    while (choice!= 4) {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                delete_entry();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}