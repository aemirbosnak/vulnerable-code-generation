//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The structure of a heart - it holds a name and a number
typedef struct Contact {
    char name[100];
    char number[15];
    struct Contact* next; // The next heart in the garden
} Contact;

// The garden of memories - the head of the linked list
Contact* head = NULL;

// Function prototypes
void addContact();
void searchContact();
void displayContacts();
void freeMemory();

// A monologue of adding a contact to the phone book
void addContact() {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (!newContact) {
        printf("Oh, forsooth! The memory cannot be found!\n");
        return;
    }

    printf("Enter the name of thy beloved: ");
    scanf("%s", newContact->name);
    printf("Enter the number to which affection doth reach: ");
    scanf("%s", newContact->number);
    
    newContact->next = head; // Add to the garden
    head = newContact; // The heart now beats in the garden of memories

    printf("Oh sweet Romeo, thy contact hath been added!\n");
}

// A quest to find a number in the garden of love
void searchContact() {
    char name[100];
    printf("Seek thy beloved's name: ");
    scanf("%s", name);

    Contact* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("The number thou seekest for %s is: %s\n", name, temp->number);
            return;
        }
        temp = temp->next; // Traverse deeper into the garden
    }
    
    printf("Alas! Thy beloved could not be found in the realms of memory.\n");
}

// Display all contacts, a poetic ode to the memories
void displayContacts() {
    Contact* temp = head;
    if (temp == NULL) {
        printf("Oh, the garden is barren! No loves are recorded.\n");
        return;
    }
    
    printf("In the garden of our love, behold:\n");
    while (temp != NULL) {
        printf("Beloved: %s, Number: %s\n", temp->name, temp->number);
        temp = temp->next; // Continue our stroll
    }
}

// Free all allocated memory, a tragic farewell
void freeMemory() {
    Contact* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp); // Release the hearts back to the ether
    }
}

// The main act of the tragedy we call 'Phone Book'
int main() {
    int choice;

    do {
        printf("\nWelcome to the Phone Book of Love, a tender tale awaits:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Choose your fate (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                printf("Farewell dear friend, may love shine upon thee.\n");
                break;
            default:
                printf("Oh no, thou hast chosen an unworthy path! Try again.\n");
        }
    } while (choice != 4);

    freeMemory(); // Lay to rest the lonely hearts
    return 0;
}