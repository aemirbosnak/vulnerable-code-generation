//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PHONEBOOK_SIZE 100

// Define a structure for a phonebook entry
struct phonebook_entry {
    char name[50];
    char phone[20];
};

// Declare a phonebook as a global array
struct phonebook_entry phonebook[MAX_PHONEBOOK_SIZE];

// Define function prototypes
void add_entry();
void remove_entry();
void search_phonebook();
void display_phonebook();

int main() {
    int user_choice;

    // Print menu options and get user choice
    do {
        printf("\nC Phonebook Program\n\n");
        printf("1. Add a phonebook entry\n");
        printf("2. Remove a phonebook entry\n");
        printf("3. Search the phonebook\n");
        printf("4. Display the phonebook\n");
        printf("5. Exit\n");

        printf("\nEnter your choice (1-5): ");
        scanf("%d", &user_choice);

        switch(user_choice) {
            case 1: add_entry(); break;
            case 2: remove_entry(); break;
            case 3: search_phonebook(); break;
            case 4: display_phonebook(); break;
            case 5: printf("\nGoodbye!"); break;
            default: printf("\nInvalid choice. Please try again.\n"); break;
        }
    } while (user_choice != 5);

    return 0;
}

// Function to add a new entry to the phonebook
void add_entry() {
    int index = -1;
    struct phonebook_entry new_entry;

    // Prompt the user for name and phone number
    printf("\nEnter a name: ");
    scanf("%s", new_entry.name);
    printf("Enter a phone number: ");
    scanf("%s", new_entry.phone);

    // Scan for the first empty slot in the phonebook
    for (int i = 0; i < MAX_PHONEBOOK_SIZE; i++) {
        if (phonebook[i].name[0] == '\0') {
            index = i;
            break;
        }
    }

    // If an empty slot was found, add the new entry to the phonebook
    if (index != -1) {
        phonebook[index] = new_entry;
        printf("\nPhonebook entry added successfully.\n");
    } else {
        printf("\nThe phonebook is full. Cannot add entry.\n");
    }
}

// Function to remove an existing entry from the phonebook
void remove_entry() {
    char search_name[50];
    int found_index = -1;

    // Prompt the user for the name to be removed
    printf("\nEnter the name to be removed: ");
    scanf("%s", search_name);

    // Search for the entry in the phonebook
    for (int i = 0; i < MAX_PHONEBOOK_SIZE; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            found_index = i;
            break;
        }
    }

    // If the entry was found, remove it from the phonebook by shifting all
    // entries after it one slot to the left
    if (found_index != -1) {
        for (int i = found_index + 1; i < MAX_PHONEBOOK_SIZE; i++) {
            phonebook[i - 1] = phonebook[i];
        }
        phonebook[MAX_PHONEBOOK_SIZE - 1].name[0] = '\0';  // clear the last slot
        printf("\nPhonebook entry removed successfully.\n");
    } else {
        printf("\nEntry not found in the phonebook.\n");
    }
}

// Function to search for a name or phone number in the phonebook
void search_phonebook() {
    char search_string[50];
    int found = 0;

    // Prompt the user for the search string
    printf("\nEnter a name or phone number to search for: ");
    scanf("%s", search_string);

    // Search for the search string in the phonebook
    for (int i = 0; i < MAX_PHONEBOOK_SIZE; i++) {
        if (strcmp(phonebook[i].name, search_string) == 0 ||
            strcmp(phonebook[i].phone, search_string) == 0) {
            printf("\n%-20s %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
        }
    }

    // If no results were found, print a message to the user
    if (found == 0) {
        printf("\nNo results found.\n");
    }
}

// Function to display the contents of the phonebook
void display_phonebook() {
    printf("\n%-20s %s\n", "Name", "Phone Number");
    printf("----------------------------------------\n");

    // Print each entry in the phonebook
    for (int i = 0; i < MAX_PHONEBOOK_SIZE; i++) {
        if (phonebook[i].name[0] != '\0') {
            printf("%-20s %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}