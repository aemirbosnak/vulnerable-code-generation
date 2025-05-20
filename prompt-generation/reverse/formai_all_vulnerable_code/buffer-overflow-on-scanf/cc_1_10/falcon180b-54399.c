//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
    printf("Entry added.\n");
}

void search_entry() {
    printf("Enter name to search: ");
    char search_name[MAX_NAME_LEN];
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    printf("Enter name to delete: ");
    char delete_name[MAX_NAME_LEN];
    scanf("%s", delete_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
            num_entries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    printf("Romeo and Juliet's Phonebook\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}