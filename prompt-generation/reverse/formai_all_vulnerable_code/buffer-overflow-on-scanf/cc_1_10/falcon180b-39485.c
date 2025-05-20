//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void delete_entry() {
    int i;
    printf("Enter name to delete: ");
    scanf("%s", phonebook[0].name);
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, phonebook[0].name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            break;
        }
    }
}

void search_entry() {
    int i;
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
        }
    }
}

int main() {
    int choice;
    while (1) {
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
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}