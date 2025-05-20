//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct for each entry in the mailing list */
typedef struct {
    char name[30];
    char email[50];
} MailingEntry;

/* Define a function to add a new entry to the mailing list */
void addEntry(MailingEntry *list, int *size) {
    /* Prompt the user for the new entry's name and email */
    printf("Enter the name: ");
    scanf("%s", list[*size].name);
    printf("Enter the email: ");
    scanf("%s", list[*size].email);

    /* Increment the size of the list */
    (*size)++;
}

/* Define a function to print out all entries in the mailing list */
void printList(MailingEntry *list, int size) {
    printf("\nMailing List\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", list[i].name);
        printf("Email: %s\n\n", list[i].email);
    }
}

int main() {
    /* Declare variables */
    MailingEntry *list; /* Dynamic array for the mailing list */
    int size = 0; /* Current size of the list */
    int option; /* User's menu option choice */
    char buffer[30]; /* Buffer to clear input */

    /* Allocate initial memory for the list */
    list = (MailingEntry *)malloc(sizeof(MailingEntry));

    /* Loop until the user chooses to exit */
    while (1) {
        /* Print menu options */
        printf("\nMenu:\n");
        printf("1. Add entry\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        /* Based on user's choice, perform an action */
        switch (option) {
            case 1:
                addEntry(list, &size);
                /* If the size of the list exceeds its current capacity, allocate more memory */
                if (size % 10 == 0 && size != 0) { /* Increase capacity every 10 entries */
                    list = (MailingEntry *)realloc(list, (size + 10) * sizeof(MailingEntry));
                    printf("Memory reallocated.\n");
                }
                break;
            case 2:
                printList(list, size);
                break;
            case 3:
                /* Free the memory allocated for the list and exit the program */
                free(list);
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                /* Clear input buffer */
                fgets(buffer, 30, stdin);
                printf("Invalid selection. Try again.\n");
        }
    }
}