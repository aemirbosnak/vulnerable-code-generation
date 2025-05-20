//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

int num_entries = 0;
entry_t entries[MAX_ENTRIES];

void add_entry() {
    printf("Enter name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number (max %d characters): ", MAX_NUMBER_LEN - 1);
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void search_entry() {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    tolower(search_name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(tolower(entries[i].name), search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    tolower(name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(tolower(entries[i].name), name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(entries[j].name, entries[j + 1].name);
                strcpy(entries[j].number, entries[j + 1].number);
            }
            num_entries--;
            break;
        }
    }
}

int main() {
    printf("Phone book\n");
    printf("Commands:\n");
    printf("a - Add entry\n");
    printf("s - Search entry\n");
    printf("d - Delete entry\n");
    printf("q - Quit\n");

    while (1) {
        char command[3];
        printf("Enter command: ");
        scanf("%s", command);
        tolower(command[0]);

        switch (command[0]) {
            case 'a':
                add_entry();
                break;
            case's':
                search_entry();
                break;
            case 'd':
                delete_entry();
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}