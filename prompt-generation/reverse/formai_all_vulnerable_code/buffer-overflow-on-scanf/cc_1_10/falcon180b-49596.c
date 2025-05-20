//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

// Struct to hold phone book entries
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} phone_entry;

// Function to add a new entry to the phone book
void add_entry(phone_entry entries[], int num_entries) {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

// Function to search for an entry in the phone book
int search_entry(phone_entry entries[], int num_entries, char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Phone number for %s: %s\n", entries[i].name, entries[i].number);
            return i;
        }
    }
    printf("Entry not found.\n");
    return -1;
}

// Function to display all entries in the phone book
void display_entries(phone_entry entries[], int num_entries) {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    phone_entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Initialize phone book
    memset(entries, 0, sizeof(entries));

    // Add some entries
    add_entry(entries, num_entries);
    add_entry(entries, num_entries);
    add_entry(entries, num_entries);

    // Search for an entry
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", name);
    int result = search_entry(entries, num_entries, name);
    if (result!= -1) {
        printf("Entry found at index %d.\n", result);
    }

    // Display all entries
    printf("All entries:\n");
    display_entries(entries, num_entries);

    return 0;
}