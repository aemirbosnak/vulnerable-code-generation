//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure of a phone book entry
typedef struct {
    char name[50];
    char phone[15];
} phonebook_entry;

// Function to compare two entries alphabetically by name
int compare_entries(const void *a, const void *b) {
    const phonebook_entry *entry_a = (const phonebook_entry *)a;
    const phonebook_entry *entry_b = (const phonebook_entry *)b;
    return strcmp(entry_a->name, entry_b->name);
}

// Function to print the phone book
void print_phonebook(phonebook_entry *entries, int num_entries) {
    printf("Phone Book:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].phone);
    }
}

// Function to search for an entry in the phone book
int search_phonebook(phonebook_entry *entries, int num_entries, const char *name) {
    phonebook_entry entry = {.name = name };
    phonebook_entry *result = bsearch(&entry, entries, num_entries, sizeof(phonebook_entry), compare_entries);
    return result!= NULL;
}

// Function to add an entry to the phone book
void add_entry(phonebook_entry *entries, int *num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[*num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[*num_entries].phone);
    (*num_entries)++;
}

int main() {
    int num_entries = 0;
    phonebook_entry entries[100];

    // Initialize the phone book with some entries
    entries[num_entries++] = (phonebook_entry) {.name = "Alice",.phone = "123-4567" };
    entries[num_entries++] = (phonebook_entry) {.name = "Bob",.phone = "234-5678" };
    entries[num_entries++] = (phonebook_entry) {.name = "Charlie",.phone = "345-6789" };

    // Print the initial phone book
    print_phonebook(entries, num_entries);

    // Add an entry
    add_entry(entries, &num_entries);

    // Print the updated phone book
    print_phonebook(entries, num_entries);

    // Search for an entry
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    if (search_phonebook(entries, num_entries, search_name)) {
        printf("Found entry for %s\n", search_name);
    } else {
        printf("No entry found for %s\n", search_name);
    }

    return 0;
}