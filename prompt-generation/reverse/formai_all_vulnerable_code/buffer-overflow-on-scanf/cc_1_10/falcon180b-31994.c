//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // Maximum number of entries in the phone book
#define MAX_NAME_LEN 50 // Maximum length of a name
#define MAX_NUM_LEN 15 // Maximum length of a phone number

// Structure to store an entry in the phone book
typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} entry_t;

// Function to add an entry to the phone book
void add_entry(entry_t *book, int num_entries, char *name, char *number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full. Cannot add more entries.\n");
        return;
    }

    strcpy(book[num_entries].name, name);
    strcpy(book[num_entries].number, number);

    num_entries++;
}

// Function to search for an entry in the phone book
int search_entry(entry_t *book, int num_entries, char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(book[i].name, name) == 0) {
            return i;
        }
    }

    return -1; // Entry not found
}

// Function to display the phone book
void display_phonebook(entry_t *book, int num_entries) {
    int i;

    printf("Phone Book:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%d. %s - %s\n", i+1, book[i].name, book[i].number);
    }
}

int main() {
    entry_t phonebook[MAX_ENTRIES];
    int num_entries = 0;

    add_entry(phonebook, num_entries, "John Doe", "555-1234");
    add_entry(phonebook, num_entries, "Jane Smith", "555-5678");

    display_phonebook(phonebook, num_entries);

    char search_name[MAX_NAME_LEN];
    printf("Enter a name to search: ");
    scanf("%s", search_name);

    int index = search_entry(phonebook, num_entries, search_name);

    if (index!= -1) {
        printf("Found entry for %s:\n", search_name);
        printf("%s - %s\n", phonebook[index].name, phonebook[index].number);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}