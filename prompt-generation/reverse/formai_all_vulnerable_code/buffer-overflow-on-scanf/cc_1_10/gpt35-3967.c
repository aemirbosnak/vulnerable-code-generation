//FormAI DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry {
    char name[50];
    char number[20];
};

void addEntry(struct Entry entries[100], int *size);
void removeEntry(struct Entry entries[100], int *size);
void printEntries(struct Entry entries[100], int size);

int main() {
    struct Entry phoneBook[100];
    int size = 0;
    char choice;

    printf("Welcome to your cheerful Phone Book!\n");

    do {
        printf("\nPlease choose an option:\n"
               "1. Add an entry\n"
               "2. Remove an entry\n"
               "3. Print phone book\n"
               "Q. Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addEntry(phoneBook, &size);
                printf("Entry added!\n");
                break;
            case '2':
                removeEntry(phoneBook, &size);
                printf("Entry removed!\n");
                break;
            case '3':
                printEntries(phoneBook, size);
                break;
            case 'Q':
            case 'q':
                printf("Goodbye! Thanks for using your cheerful Phone Book!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (1); // Infinite loop until user selects quit

    return 0;
}

void addEntry(struct Entry entries[100], int *size) {
    printf("Enter name: ");
    scanf(" %[^\n]", entries[*size].name);

    printf("Enter number: ");
    scanf(" %s", entries[*size].number);

    (*size)++;
}

void removeEntry(struct Entry entries[100], int *size) {
    char name[50];
    int index = -1;

    printf("Enter name of entry to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < *size; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Entry not found.\n");
    } else {
        // Shift all entries after the removed one by one spot to the left
        for (int i = index; i < *size - 1; i++) {
            strcpy(entries[i].name, entries[i + 1].name);
            strcpy(entries[i].number, entries[i + 1].number);
        }
        (*size)--;
    }
}

void printEntries(struct Entry entries[100], int size) {
    if (size == 0) {
        printf("Phone book is empty.\n");
    } else {
        printf("Phone Book Entries:\n");
        for (int i = 0; i < size; i++) {
            printf("%s: %s\n", entries[i].name, entries[i].number);
        }
    }
}