//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: phone book is full.\n");
        return;
    }

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Error: entry already exists.\n");
            return;
        }
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
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(entry_t) * (num_entries - i - 1));
            num_entries--;
            return;
        }
    }

    printf("Error: entry not found.\n");
}

void list_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    char command[100];
    while (1) {
        printf("Phone book commands: add, search, delete, list, quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LENGTH];
            char number[MAX_NUMBER_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            add_entry(name, number);
        } else if (strcmp(command, "search") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            search_entry(name);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            delete_entry(name);
        } else if (strcmp(command, "list") == 0) {
            list_entries();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Error: invalid command.\n");
        }
    }

    return 0;
}