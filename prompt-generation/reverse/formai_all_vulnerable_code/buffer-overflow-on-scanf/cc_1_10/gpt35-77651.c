//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
//The Adventure of Mailing List

#include <stdio.h> 
#include <string.h> 

// Declare constant variables
#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 30
#define MAX_LIST_SIZE 100

// Declare struct for mailing list data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

// Declare struct for mailing list
typedef struct {
    Person persons[MAX_LIST_SIZE];
    int size;
} MailingList;

// Function to add a person to the mailing list
void addPerson(MailingList *list, char *name, char *email) {
    // Check if mailing list is full
    if (list->size >= MAX_LIST_SIZE) {
        printf("Sorry, the mailing list is full and cannot accept any more entries.\n");
    } else {
        // Create new person
        Person newPerson;
        strncpy(newPerson.name, name, MAX_NAME_LENGTH);
        strncpy(newPerson.email, email, MAX_EMAIL_LENGTH);
        
        // Add new person to mailing list
        list->persons[list->size] = newPerson;
        list->size++;
        printf("The person with name %s and email %s was added to the mailing list successfully.\n", name, email);
    }
}

// Function to remove a person from the mailing list
void removePerson(MailingList *list, char *email) {
    // Search for person with matching email
    int i;
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->persons[i].email, email) == 0) {
            // Remove person from mailing list
            int j;
            for (j = i+1; j < list->size; j++) {
                list->persons[j-1] = list->persons[j];
            }
            list->size--;
            
            printf("The person with email %s was removed from the mailing list successfully.\n", email);
            return;
        }
    }
    printf("Sorry, no person with email %s was found in the mailing list.\n", email);
}

// Function to display all persons in the mailing list
void displayList(MailingList *list) {
    printf("The current mailing list includes:\n");
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%d. Name: %s, Email: %s\n", i+1, list->persons[i].name, list->persons[i].email);
    }
}

// Main function
int main() {
    printf("Welcome to the mailing list manager program!\n");
    printf("In this program, you can add, remove, and display persons in a mailing list.\n");
    
    // Create empty mailing list
    MailingList list;
    list.size = 0;
    
    // Display menu options
    printf("1. Add a person to the mailing list\n");
    printf("2. Remove a person from the mailing list\n");
    printf("3. Display all persons in the mailing list\n");
    printf("4. Exit the program\n");
    
    int option = 0;
    while (option != 4) {
        printf("Please enter an option by numeric value: ");
        scanf("%d", &option);
        
        char name[MAX_NAME_LENGTH];
        char email[MAX_EMAIL_LENGTH];
        switch (option) {
            case 1:
                printf("Please enter the name of the person to add: ");
                scanf("%s", name);
                printf("Please enter the email of the person to add: ");
                scanf("%s", email);
                addPerson(&list, name, email);
                break;
            case 2:
                printf("Please enter the email of the person to remove: ");
                scanf("%s", email);
                removePerson(&list, email);
                break;
            case 3:
                displayList(&list);
                break;
            case 4:
                printf("Thank you for using the mailing list manager program.\n");
                break;
            default:
                printf("Sorry, that is not a valid option. Please enter a number between 1 and 4.\n");
        }
    }
    
    return 0;
}