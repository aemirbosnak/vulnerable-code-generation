//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int num_entries = 0;
Entry phonebook[MAX_ENTRIES];

void add_entry() {
    num_entries++;
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries-1].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_entries-1].number);
}

void delete_entry() {
    int index;
    printf("Enter index of entry to delete: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_entries) {
        num_entries--;
        for (int i = index; i < num_entries; i++) {
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].number, phonebook[i+1].number);
        }
    }
}

void search_entry() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

void display_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;
    do {
        printf("Phone Book Menu:\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Display entries\n5. Exit\n");
        printf("Enter your choice: ");
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
                display_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
    return 0;
}