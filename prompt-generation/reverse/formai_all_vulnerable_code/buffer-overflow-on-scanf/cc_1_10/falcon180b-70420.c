//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full!\n");
        return;
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;
    printf("Entry added successfully!\n");
}

void delete_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            num_entries--;

            for (int j = i; j < num_entries; j++) {
                strcpy(phonebook[j].name, phonebook[j+1].name);
                strcpy(phonebook[j].number, phonebook[j+1].number);
            }

            printf("Entry deleted successfully!\n");
            return;
        }
    }

    printf("Entry not found!\n");
}

void search_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];

    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(name, number);
                break;

            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_entry(name);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(name);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}