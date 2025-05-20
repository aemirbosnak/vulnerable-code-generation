//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

// Define a struct to hold the phone book entries
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} PhoneBookEntry;

// Define the phone book itself
PhoneBookEntry phoneBook[MAX_ENTRIES];
int numEntries = 0;

// Helper function to add a new entry to the phone book
void addEntry() {
    printf("Enter name: ");
    scanf("%s", phoneBook[numEntries].name);
    printf("Enter number: ");
    scanf("%s", phoneBook[numEntries].number);
    numEntries++;
}

// Helper function to display all entries in the phone book
void displayEntries() {
    printf("Phone book entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

// Helper function to search for an entry by name
bool searchByName(char *name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found entry for %s:\n", name);
            printf("Name: %s\n", phoneBook[i].name);
            printf("Number: %s\n", phoneBook[i].number);
            return true;
        }
    }
    printf("No entry found for %s\n", name);
    return false;
}

// Helper function to search for an entry by number
bool searchByNumber(char *number) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].number, number) == 0) {
            printf("Found entry for %s:\n", number);
            printf("Name: %s\n", phoneBook[i].name);
            printf("Number: %s\n", phoneBook[i].number);
            return true;
        }
    }
    printf("No entry found for %s\n", number);
    return false;
}

int main() {
    addEntry();
    addEntry();
    addEntry();
    displayEntries();
    searchByName("John");
    searchByNumber("555-1234");
    return 0;
}