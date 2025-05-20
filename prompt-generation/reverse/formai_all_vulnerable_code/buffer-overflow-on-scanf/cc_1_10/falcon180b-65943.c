//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // Maximum number of entries in the phone book

// Define structure for a phone book entry
typedef struct {
    char name[50];
    char number[15];
} entry;

// Function to add an entry to the phone book
void add_entry(entry entries[], int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[count].number);
    count++;
}

// Function to search for an entry in the phone book
int search_entry(entry entries[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
            return 1;
        }
    }
    printf("Entry not found.\n");
    return 0;
}

// Function to delete an entry from the phone book
void delete_entry(entry entries[], int count) {
    printf("Enter name to delete: ");
    char name[50];
    scanf("%s", name);
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            entries[i] = entries[count - 1];
            count--;
            break;
        }
    }
}

// Function to display the phone book
void display_phonebook(entry entries[], int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    entry phonebook[MAX_ENTRIES];
    int count = 0;

    // Initialize the phone book
    while (count < MAX_ENTRIES) {
        add_entry(phonebook, count);
        count++;
    }

    // Display the phone book
    printf("Phone book:\n");
    display_phonebook(phonebook, count);

    // Search for an entry
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int result = search_entry(phonebook, count, name);

    // Delete an entry
    if (result == 1) {
        delete_entry(phonebook, count);
        printf("Entry deleted.\n");
        count--;
    }

    return 0;
}