//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

void add_entry(Entry entries[], int num_entries) {
    printf("Enter name (or 'list' to view entries): ");
    scanf("%s", entries[num_entries].name);

    if (strcmp(entries[num_entries].name, "list") == 0) {
        for (int i = 0; i < num_entries; i++) {
            printf("%s: %s\n", entries[i].name, entries[i].number);
        }
    } else {
        printf("Enter phone number: ");
        scanf("%s", entries[num_entries].number);
        num_entries++;
    }
}

void search_entry(Entry entries[], int num_entries) {
    printf("Enter name to search for: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("%s: %s\n", entries[i].name, entries[i].number);
        }
    }
}

void delete_entry(Entry entries[], int num_entries) {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(entries[j].name, entries[j+1].name);
                strcpy(entries[j].number, entries[j+1].number);
            }
            num_entries--;
            break;
        }
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to the Medieval Phone Book!\n");

    while (num_entries < MAX_ENTRIES) {
        printf("Enter command (add, search, delete, or quit): ");
        char command[MAX_NAME_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            add_entry(entries, num_entries);
        } else if (strcmp(command, "search") == 0) {
            search_entry(entries, num_entries);
        } else if (strcmp(command, "delete") == 0) {
            delete_entry(entries, num_entries);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}