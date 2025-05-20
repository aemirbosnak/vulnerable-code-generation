//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define struct for mailing list entry
typedef struct entry {
    char name[30];
    char email[100];
    struct entry *next;
} Entry;

// Function to add a new entry to the mailing list
void addEntry(Entry **head) {
    Entry *newEntry = (Entry*) malloc(sizeof(Entry)); //allocate memory for new entry
    printf("Enter name: ");
    scanf("%s", newEntry->name);
    printf("Enter email: ");
    scanf("%s", newEntry->email);
    newEntry->next = *head; //new entry becomes the head
    *head = newEntry; //assign the head to the new entry
}

// Function to print the entire mailing list
void printList(Entry *head) {
    if(head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Mailing List:\n");
    while(head != NULL) {
        printf("Name: %s\nEmail: %s\n", head->name, head->email);
        head = head->next;
    }
}

int main() {
    Entry *head = NULL; //initialize head pointer to NULL
    int input;
    while(1) {
        printf("\nSelect an option:\n");
        printf("1. Add new entry\n");
        printf("2. Print mailing list\n");
        printf("3. Exit\n");
        printf("Enter option number: ");
        scanf("%d", &input);
        switch(input) {
            case 1:
                addEntry(&head);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");    
        }
    }
    return 0;
}