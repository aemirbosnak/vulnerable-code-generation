//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;
}

void delete_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memset(phonebook[i].name, 0, strlen(phonebook[i].name));
            memset(phonebook[i].number, 0, strlen(phonebook[i].number));
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
    char choice;
    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", phonebook[num_entries].name);
                printf("Enter number: ");
                scanf("%s", phonebook[num_entries].number);
                break;
            case '2':
                printf("Enter name to delete: ");
                scanf("%s", phonebook[num_entries].name);
                delete_entry(phonebook[num_entries].name);
                break;
            case '3':
                printf("Enter name to search: ");
                scanf("%s", phonebook[num_entries].name);
                search_entry(phonebook[num_entries].name);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}