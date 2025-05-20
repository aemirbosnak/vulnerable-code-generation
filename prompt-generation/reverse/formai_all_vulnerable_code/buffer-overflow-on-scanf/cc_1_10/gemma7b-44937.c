//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store phone book data
struct PhoneBook {
    char name[20];
    char number[20];
    struct PhoneBook *next;
};

// Create a function to insert a new phone book entry
void insert(struct PhoneBook **head) {
    // Allocate memory for a new phone book entry
    struct PhoneBook *newEntry = (struct PhoneBook *)malloc(sizeof(struct PhoneBook));

    // Get the name and number of the new entry
    printf("Enter name: ");
    scanf("%s", newEntry->name);

    printf("Enter number: ");
    scanf("%s", newEntry->number);

    // Insert the new entry into the phone book
    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }

    // Print a confirmation message
    printf("Entry inserted.\n");
}

// Create a function to search for a phone book entry
void search(struct PhoneBook *head) {
    // Get the name of the entry to search for
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);

    // Search for the entry
    struct PhoneBook *current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            // Print the phone number of the entry
            printf("Phone number: %s\n", current->number);
            break;
        }
        current = current->next;
    }

    // If the entry is not found, print an error message
    if (current == NULL) {
        printf("Entry not found.\n");
    }
}

// Main function
int main() {
    // Create a head of the phone book
    struct PhoneBook *head = NULL;

    // Insert some phone book entries
    insert(&head);
    insert(&head);
    insert(&head);

    // Search for a phone book entry
    search(head);

    return 0;
}