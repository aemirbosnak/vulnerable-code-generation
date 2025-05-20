//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: ultraprecise
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

int num_entries = 0;
Entry phonebook[MAX_ENTRIES];

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phonebook is full.\n");
        return;
    }
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;
    printf("Entry added successfully.\n");
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

void delete_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void print_phonebook() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    char choice;
    while (1) {
        printf("Phonebook Menu:\n");
        printf("A - Add entry\n");
        printf("S - Search entry\n");
        printf("D - Delete entry\n");
        printf("P - Print phonebook\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case 'A':
                printf("Enter name: ");
                scanf("%s", phonebook[num_entries].name);
                printf("Enter number: ");
                scanf("%s", phonebook[num_entries].number);
                add_entry(phonebook[num_entries].name, phonebook[num_entries].number);
                break;
            case 'S':
                printf("Enter name to search: ");
                scanf("%s", phonebook[num_entries].name);
                search_entry(phonebook[num_entries].name);
                break;
            case 'D':
                printf("Enter name to delete: ");
                scanf("%s", phonebook[num_entries].name);
                delete_entry(phonebook[num_entries].name);
                break;
            case 'P':
                print_phonebook();
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}