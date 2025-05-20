//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, phone book is full.\n");
        return;
    }
    strncpy(entries[num_entries].name, name, MAX_NAME_LEN);
    strncpy(entries[num_entries].number, number, MAX_NUMBER_LEN);
    num_entries++;
    printf("Entry added successfully.\n");
}

void delete_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memset(&entries[i], 0, sizeof(entries[i]));
            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    char command[20];
    while (1) {
        printf("Enter command (add/delete/search/exit): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LEN];
            char number[MAX_NUMBER_LEN];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            add_entry(name, number);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_NAME_LEN];
            printf("Enter name: ");
            scanf("%s", name);
            delete_entry(name);
        } else if (strcmp(command, "search") == 0) {
            char name[MAX_NAME_LEN];
            printf("Enter name: ");
            scanf("%s", name);
            search_entry(name);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}