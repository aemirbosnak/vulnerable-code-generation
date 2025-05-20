//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

void add_entry(entry_t *entries, int count, char *name, char *number) {
    if (count >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(entries[count].name, name);
    strcpy(entries[count].number, number);

    count++;
}

void search_entry(entry_t *entries, int count, char *name) {
    int i = 0;

    while (i < count) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }

        i++;
    }

    printf("Entry not found.\n");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        int choice;

        if (scanf("%d", &choice)!= 1) {
            printf("Error: Invalid input.\n");
            continue;
        }

        switch (choice) {
        case 1:
            {
                char name[MAX_NAME_LENGTH];
                char number[MAX_NUMBER_LENGTH];

                printf("Enter name: ");
                if (scanf("%s", name)!= 1) {
                    printf("Error: Invalid input.\n");
                    break;
                }

                printf("Enter number: ");
                if (scanf("%s", number)!= 1) {
                    printf("Error: Invalid input.\n");
                    break;
                }

                add_entry(entries, count, name, number);
                count++;
                break;
            }

        case 2:
            {
                char name[MAX_NAME_LENGTH];

                printf("Enter name: ");
                if (scanf("%s", name)!= 1) {
                    printf("Error: Invalid input.\n");
                    break;
                }

                search_entry(entries, count, name);
                break;
            }

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}