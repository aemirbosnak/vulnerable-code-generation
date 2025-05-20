//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[15];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;
}

void display_entry(int index) {
    printf("Name: %s\nNumber: %s\n", phonebook[index].name, phonebook[index].number);
}

void display_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        display_entry(i);
    }
}

int main() {
    printf("Welcome to the Happy Phonebook!\n");
    char choice;

    while (true) {
        printf("What would you like to do?\n");
        printf("A. Add entry\n");
        printf("B. Display entry\n");
        printf("C. Display all entries\n");
        printf("D. Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case 'A':
            printf("Enter name: ");
            char name[50];
            scanf("%s", name);
            printf("Enter number: ");
            char number[15];
            scanf("%s", number);
            add_entry(name, number);
            printf("Entry added successfully!\n");
            break;
        case 'B':
            printf("Enter index of entry to display: ");
            int index;
            scanf("%d", &index);
            display_entry(index);
            break;
        case 'C':
            display_all_entries();
            break;
        case 'D':
            printf("Goodbye! :)\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}