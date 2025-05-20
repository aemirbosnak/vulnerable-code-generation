//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} entry_t;

int num_entries = 0;
entry_t phonebook[MAX_ENTRIES];

int add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return 1;
    }
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
    printf("Entry added successfully.\n");
    return 0;
}

int delete_entry() {
    if (num_entries == 0) {
        printf("Phonebook is empty.\n");
        return 1;
    }
    printf("Enter name to delete: ");
    scanf("%s", phonebook[num_entries - 1].name);
    for (int i = 0; i < num_entries - 1; i++) {
        strcpy(phonebook[i].name, phonebook[i + 1].name);
        strcpy(phonebook[i].number, phonebook[i + 1].number);
    }
    num_entries--;
    printf("Entry deleted successfully.\n");
    return 0;
}

int search_entry() {
    printf("Enter name to search: ");
    scanf("%s", phonebook[0].name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, phonebook[0].name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return 0;
        }
    }
    printf("Entry not found.\n");
    return 1;
}

int main() {
    int choice;
    do {
        printf("\nPhonebook\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}