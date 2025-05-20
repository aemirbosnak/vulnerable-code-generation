//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum length of names and phone numbers
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 12

// Define the structure for a phone book entry
struct PhoneBookEntry {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

// Define the function to add a new entry to a phone book
void addPhoneBookEntry(struct PhoneBookEntry* phoneBook, int* numberOfEntries) {
    // Check if the phone book is full
    if (*numberOfEntries >= 100) {
        printf("The phone book is full. Cannot add more entries.\n");
        return;
    }
    // Ask the user to enter the name
    printf("Enter the name: ");
    scanf("%s", phoneBook[*numberOfEntries].name);
    // Ask the user to enter the phone number
    printf("Enter the phone number: ");
    scanf("%s", phoneBook[*numberOfEntries].phone);
    // Increment the number of entries
    (*numberOfEntries)++;
    // Display a message to indicate success
    printf("New entry added to the phone book.\n");
}

// Define the function to search for an entry in a phone book
void searchPhoneBookEntry(struct PhoneBookEntry* phoneBook, int numberOfEntries) {
    // Ask the user to enter the name to be searched
    printf("Enter the name to be searched: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);
    // Find the entry with the matching name
    int foundIndex = -1;
    for (int i = 0; i < numberOfEntries; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            foundIndex = i;
            break;
        }
    }
    // Display the search result
    if (foundIndex >= 0) {
        printf("Name: %s\nPhone: %s\n", phoneBook[foundIndex].name, phoneBook[foundIndex].phone);
    } else {
        printf("Entry not found in the phone book.\n");
    }
}

int main() {
    // Initialize the phone book
    struct PhoneBookEntry phoneBook[100];
    int numberOfEntries = 0;
    // Display the menu
    int choice = 0;
    while (choice != 3) {
        printf("Select an option:\n");
        printf("1. Add a new entry\n");
        printf("2. Search for an entry\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        // Process the user's choice
        switch (choice) {
            case 1:
                addPhoneBookEntry(phoneBook, &numberOfEntries);
                break;
            case 2:
                searchPhoneBookEntry(phoneBook, numberOfEntries);
                break;
            case 3:
                printf("Exiting the phone book program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}