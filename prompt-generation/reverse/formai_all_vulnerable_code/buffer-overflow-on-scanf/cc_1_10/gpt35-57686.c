//FormAI DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct PhoneEntry {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    struct PhoneEntry *next;
} PhoneEntry;

void addEntry(PhoneEntry **list, char *name, char *phone) {
    // Create new entry and set its properties
    PhoneEntry *newEntry = (PhoneEntry*) malloc(sizeof(PhoneEntry));
    strncpy(newEntry->name, name, MAX_NAME_LENGTH);
    strncpy(newEntry->phone, phone, MAX_PHONE_LENGTH);
    newEntry->next = NULL;
    
    // Find the end of the list and append the new entry
    PhoneEntry *current = *list;
    if (current == NULL) {
        *list = newEntry;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEntry;
    }
}

void printList(PhoneEntry *list) {
    PhoneEntry *current = list;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

int main() {
    PhoneEntry *phoneBook = NULL;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int running = 1;
    
    printf("Welcome to the phone book!\n");
    while (running) {
        // Ask the user for input
        printf("Enter a name (or 'exit' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            running = 0;
        } else {
            printf("Enter a phone number: ");
            scanf("%s", phone);
            
            // Add the entry to the phone book
            addEntry(&phoneBook, name, phone);
            printf("Entry added!\n\n");
        }
    }
    
    printf("\n\nPhone Book:\n\n");
    printList(phoneBook);
    
    // Clean up memory
    PhoneEntry *current = phoneBook;
    while (current != NULL) {
        PhoneEntry *next = current->next;
        free(current);
        current = next;
    }
    
    printf("\n\nGoodbye!\n");
    return 0;
}