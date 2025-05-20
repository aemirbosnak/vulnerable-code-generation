//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LEN);
    strncpy(entries[num_entries].number, number, MAX_NUMBER_LEN);

    num_entries++;
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
    char choice;
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    printf("Cyberpunk Phone Book\n");

    while(1) {
        printf("\n");
        printf("A - Add entry\n");
        printf("S - Search entry\n");
        printf("Q - Quit\n");
        printf("\n");
        scanf("%c", &choice);

        switch(choice) {
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

            case 'Q':
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}