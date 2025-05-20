//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store a mailing list entry
typedef struct MailEntry {
    char name[50];
    char address[100];
    char city[50];
    char state[2];
    char zip[10];
    struct MailEntry* next;
} MailEntry;

// Define a function to insert a new entry into the mailing list
void insertEntry(MailEntry** head) {
    // Allocate memory for the new entry
    MailEntry* newEntry = (MailEntry*)malloc(sizeof(MailEntry));

    // Get the user's input
    printf("Enter name: ");
    scanf("%s", newEntry->name);

    printf("Enter address: ");
    scanf("%s", newEntry->address);

    printf("Enter city: ");
    scanf("%s", newEntry->city);

    printf("Enter state: ");
    scanf("%s", newEntry->state);

    printf("Enter zip: ");
    scanf("%s", newEntry->zip);

    // Insert the new entry into the list
    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }

    // Print a confirmation message
    printf("Entry inserted successfully.\n");
}

// Define a function to print the mailing list
void printList(MailEntry* head) {
    // Traverse the list and print each entry
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Address: %s\n", head->address);
        printf("City: %s\n", head->city);
        printf("State: %s\n", head->state);
        printf("Zip: %s\n", head->zip);
        printf("\n");
        head = head->next;
    }
}

int main() {
    // Create a new mailing list
    MailEntry* head = NULL;

    // Insert some entries
    insertEntry(&head);
    insertEntry(&head);
    insertEntry(&head);

    // Print the list
    printList(head);

    return 0;
}