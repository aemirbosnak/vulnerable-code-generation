//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

int add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
    return 0;
}

int delete_entry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            strcpy(entries[i].name, "");
            strcpy(entries[i].number, "");
            num_entries--;
            return 0;
        }
    }
    printf("Entry not found.\n");
    return 1;
}

int search_entry() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
            return 0;
        }
    }
    printf("Entry not found.\n");
    return 1;
}

int main() {
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}