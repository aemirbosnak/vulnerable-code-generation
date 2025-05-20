//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

bool is_valid_number(const char *number) {
    for (int i = 0; i < strlen(number); i++) {
        if (!isdigit(number[i])) {
            return false;
        }
    }
    return true;
}

void add_entry(entry_t entries[], int num_entries, const char *name, const char *number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }
    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);
    num_entries++;
}

void delete_entry(entry_t entries[], int num_entries, const char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            num_entries--;
            break;
        }
    }
    for (int j = i; j < num_entries - 1; j++) {
        strcpy(entries[j].name, entries[j + 1].name);
        strcpy(entries[j].number, entries[j + 1].number);
    }
}

void search_entry(const entry_t entries[], int num_entries, const char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    while (1) {
        printf("Phone Book\n");
        printf("A - Add entry\n");
        printf("D - Delete entry\n");
        printf("S - Search entry\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);
        switch (choice) {
        case 'A':
            printf("Enter name: ");
            scanf(" %[^\n]", entries[num_entries].name);
            printf("Enter number: ");
            scanf(" %[^\n]", entries[num_entries].number);
            if (!is_valid_number(entries[num_entries].number)) {
                printf("Error: Invalid number.\n");
                break;
            }
            num_entries++;
            break;
        case 'D':
            printf("Enter name to delete: ");
            scanf(" %[^\n]", entries[num_entries - 1].name);
            delete_entry(entries, num_entries, entries[num_entries - 1].name);
            break;
        case 'S':
            printf("Enter name to search: ");
            scanf(" %[^\n]", entries[num_entries - 1].name);
            search_entry(entries, num_entries, entries[num_entries - 1].name);
            break;
        case 'Q':
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Error: Invalid choice.\n");
        }
    }
    return 0;
}