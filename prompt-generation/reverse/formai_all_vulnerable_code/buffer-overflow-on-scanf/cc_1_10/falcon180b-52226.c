//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 20
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;
}

void remove_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], sizeof(entry_t) * (num_entries - i - 1));
            num_entries--;
            return;
        }
    }
    printf("Entry not found.\n");
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
    char choice;
    int i;

    printf("Welcome to the Claude Shannon Phonebook!\n");

    while (1) {
        printf("\n");
        printf("A - Add an entry\n");
        printf("S - Search for an entry\n");
        printf("R - Remove an entry\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(name, number);
                break;
            case 'S':
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(name);
                break;
            case 'R':
                printf("Enter name to remove: ");
                scanf("%s", name);
                remove_entry(name);
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}