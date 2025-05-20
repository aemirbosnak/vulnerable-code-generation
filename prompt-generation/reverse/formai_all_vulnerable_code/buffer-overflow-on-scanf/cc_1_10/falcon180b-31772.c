//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a phone book entry
typedef struct {
    char name[50];
    char phone[15];
} PhoneBookEntry;

// Define the function to compare two strings
int compare(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

// Define the function to print a phone book entry
void printEntry(PhoneBookEntry* entry) {
    printf("%s: %s\n", entry->name, entry->phone);
}

// Define the function to add a new entry to the phone book
void addEntry(PhoneBookEntry* entries, int* count) {
    char name[50];
    char phone[15];

    // Prompt the user for the name and phone number
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the phone number: ");
    scanf("%s", phone);

    // Copy the name and phone number into the entry
    strcpy(entries[*count].name, name);
    strcpy(entries[*count].phone, phone);

    // Increment the count of entries
    (*count)++;
}

// Define the function to search for an entry in the phone book
PhoneBookEntry* searchEntry(PhoneBookEntry* entries, int count, char* name) {
    // Define the search key
    char* key = name;

    // Sort the entries by name
    qsort(entries, count, sizeof(PhoneBookEntry), compare);

    // Search for the entry with the given name
    PhoneBookEntry* result = NULL;
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, key) == 0) {
            result = &entries[i];
            break;
        }
    }

    return result;
}

// Define the main function
int main() {
    // Define the phone book entries
    PhoneBookEntry entries[100];
    int count = 0;

    // Prompt the user to add entries to the phone book
    while (count < 100) {
        printf("Enter 'a' to add an entry,'s' to search for an entry, or 'q' to quit: ");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
        case 'a':
            addEntry(entries, &count);
            break;
        case's':
            printf("Enter the name to search for: ");
            char name[50];
            scanf("%s", name);
            PhoneBookEntry* result = searchEntry(entries, count, name);

            if (result!= NULL) {
                printEntry(result);
            } else {
                printf("Entry not found.\n");
            }
            break;
        case 'q':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}