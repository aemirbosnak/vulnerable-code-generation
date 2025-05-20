//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);
    num_entries++;
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

void delete_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            strcpy(entries[i].name, "");
            strcpy(entries[i].number, "");
            num_entries--;
            return;
        }
    }
}

int main() {
    char choice;
    do {
        printf("Phone Book Menu:\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter number: ");
                char number[MAX_NUMBER_LENGTH];
                scanf("%s", number);
                add_entry(name, number);
                break;
            case '2':
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LENGTH];
                scanf("%s", search_name);
                search_entry(search_name);
                break;
            case '3':
                printf("Enter name to delete: ");
                char del_name[MAX_NAME_LENGTH];
                scanf("%s", del_name);
                delete_entry(del_name);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}