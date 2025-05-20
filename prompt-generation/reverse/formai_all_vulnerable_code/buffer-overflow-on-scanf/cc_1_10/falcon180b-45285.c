//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

void add_entry(entry* phonebook, int num_entries, char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;
}

void search_entry(entry* phonebook, int num_entries, char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(entry* phonebook, int num_entries, char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memset(&phonebook[i], 0, sizeof(entry));
            num_entries--;
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    entry phonebook[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            printf("Enter name (max %d characters): ", MAX_NAME_LENGTH - 1);
            scanf("%s", phonebook[num_entries].name);
            printf("Enter number (max %d characters): ", MAX_NUMBER_LENGTH - 1);
            scanf("%s", phonebook[num_entries].number);
            add_entry(phonebook, num_entries, phonebook[num_entries].name, phonebook[num_entries].number);
            break;
        case '2':
            printf("Enter name to search: ");
            scanf("%s", phonebook[num_entries].name);
            search_entry(phonebook, num_entries, phonebook[num_entries].name);
            break;
        case '3':
            printf("Enter name to delete: ");
            scanf("%s", phonebook[num_entries].name);
            delete_entry(phonebook, num_entries, phonebook[num_entries].name);
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}