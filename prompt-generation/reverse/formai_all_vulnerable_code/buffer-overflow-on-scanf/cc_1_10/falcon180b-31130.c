//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a phone book entry
typedef struct {
    char name[50];
    char phone[15];
} phonebook_entry;

// Function to add a new entry to the phone book
void add_entry(phonebook_entry *entries, int *entry_count) {
    char name[50];
    char phone[15];
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the phone number: ");
    scanf("%s", phone);
    strcpy(entries[*entry_count].name, name);
    strcpy(entries[*entry_count].phone, phone);
    (*entry_count)++;
}

// Function to search for an entry in the phone book
int search_entry(phonebook_entry *entries, int entry_count, char *name) {
    int i;
    for (i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Found entry: %s - %s\n", entries[i].name, entries[i].phone);
            return i;
        }
    }
    printf("Entry not found.\n");
    return -1;
}

// Function to display all entries in the phone book
void display_entries(phonebook_entry *entries, int entry_count) {
    int i;
    for (i = 0; i < entry_count; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    phonebook_entry entries[100];
    int entry_count = 0;
    char choice;
    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                add_entry(entries, &entry_count);
                break;
            case '2':
                printf("Enter the name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(entries, entry_count, name);
                break;
            case '3':
                display_entries(entries, entry_count);
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