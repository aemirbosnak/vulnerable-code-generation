//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a phone book entry
typedef struct {
    char name[50];
    char phone[20];
} phone_entry;

// Function to compare two phone book entries by name
int compare_entries(const void* a, const void* b) {
    const phone_entry* entry_a = (const phone_entry*)a;
    const phone_entry* entry_b = (const phone_entry*)b;

    return strcmp(entry_a->name, entry_b->name);
}

// Function to display the phone book entries
void display_entries(phone_entry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].phone);
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_entry* entries, int* num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[*num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[*num_entries].phone);

    (*num_entries)++;
}

// Function to search for a phone book entry by name
int search_entry(phone_entry* entries, int num_entries, const char* name) {
    phone_entry entry = {.name = name };
    return bsearch(&entry, entries, num_entries, sizeof(phone_entry), compare_entries);
}

int main() {
    phone_entry entries[100];
    int num_entries = 0;

    // Initialize the phone book with some entries
    add_entry(entries, &num_entries);
    add_entry(entries, &num_entries);

    // Display the phone book entries
    printf("Phone book:\n");
    display_entries(entries, num_entries);

    // Search for an entry by name
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int entry_index = search_entry(entries, num_entries, search_name);

    if (entry_index!= -1) {
        printf("Found entry for %s:\n", search_name);
        display_entries(entries, num_entries);
    } else {
        printf("No entry found for %s.\n", search_name);
    }

    return 0;
}