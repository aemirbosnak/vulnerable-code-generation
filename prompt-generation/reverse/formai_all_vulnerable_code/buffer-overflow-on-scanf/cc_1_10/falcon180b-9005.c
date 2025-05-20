//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

// Define the structure for each phone book entry
typedef struct {
    char name[50];
    char phone[15];
} Entry;

// Function to compare two entries based on name
int compareEntries(const void* a, const void* b) {
    const Entry* entryA = (const Entry*)a;
    const Entry* entryB = (const Entry*)b;
    return strcmp(entryA->name, entryB->name);
}

// Function to print the phone book in alphabetical order
void printPhoneBook(Entry* entries, int numEntries) {
    qsort(entries, numEntries, sizeof(Entry), compareEntries);
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    // Initialize the phone book with empty entries
    Entry entries[MAX_ENTRIES] = {{"", ""}};
    int numEntries = 0;

    // Main menu loop
    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Print Phone Book\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Add entry
            if (numEntries >= MAX_ENTRIES) {
                printf("Phone book is full!\n");
            } else {
                printf("Enter name: ");
                scanf("%s", entries[numEntries].name);
                printf("Enter phone number: ");
                scanf("%s", entries[numEntries].phone);
                numEntries++;
            }
            break;

        case 2: // Search entry
            printf("Enter name to search: ");
            char searchName[50];
            scanf("%s", searchName);
            int index = -1;

            for (int i = 0; i < numEntries; i++) {
                if (strcmp(entries[i].name, searchName) == 0) {
                    index = i;
                    break;
                }
            }

            if (index!= -1) {
                printf("Found entry:\n");
                printf("Name: %s\n", entries[index].name);
                printf("Phone number: %s\n", entries[index].phone);
            } else {
                printf("Entry not found.\n");
            }
            break;

        case 3: // Print phone book
            printPhoneBook(entries, numEntries);
            break;

        case 4: // Quit
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}