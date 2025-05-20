//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Entry not found.\n");
    }
}

void delete_entry() {
    char delete_name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j + 1].name);
                strcpy(phonebook[j].number, phonebook[j + 1].number);
            }
            num_entries--;
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Entry not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}