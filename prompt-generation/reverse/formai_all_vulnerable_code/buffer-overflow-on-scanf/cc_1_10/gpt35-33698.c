//FormAI DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to represent a person in the phone book
typedef struct {
    char name[50];
    char phone[20];
} Person;

// function to add a person to the phone book
void addPerson(Person* book[], int* numPeople) {
    // allocate memory for the new person struct
    Person* newPerson = malloc(sizeof(Person));
    if (newPerson == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        return;
    }
    // prompt user for the new person's name and phone number
    printf("Enter the person's name: ");
    fgets(newPerson->name, 50, stdin);
    // remove the newline character at the end of the string
    newPerson->name[strcspn(newPerson->name, "\n")] = '\0';
    printf("Enter the person's phone number: ");
    fgets(newPerson->phone, 20, stdin);
    // remove the newline character at the end of the string
    newPerson->phone[strcspn(newPerson->phone, "\n")] = '\0';
    // add the new person to the phone book
    book[*numPeople] = newPerson;
    (*numPeople)++;
    printf("Person added to the phone book!\n");
}

// function to search for a person in the phone book
void searchPerson(Person* book[], int numPeople) {
    char searchTerm[50];
    printf("Enter the name of the person you want to search for: ");
    fgets(searchTerm, 50, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';
    // loop through the phone book to find the person
    int i;
    int found = 0; // boolean flag to indicate if the person was found
    for (i = 0; i < numPeople; i++) {
        if (strcmp(searchTerm, book[i]->name) == 0) {
            printf("Name: %s\nPhone: %s\n", book[i]->name, book[i]->phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Person not found in phone book!\n");
    }
}

// function to print the entire phone book
void printPhoneBook(Person* book[], int numPeople) {
    int i;
    for (i = 0; i < numPeople; i++) {
        printf("Name: %s\nPhone: %s\n\n", book[i]->name, book[i]->phone);
    }
}

int main() {
    Person* phoneBook[100];
    int numPeople = 0;
    int choice = 0;
    do {
        printf("****** Phone Book Menu ******\n");
        printf("1. Add person to phone book\n");
        printf("2. Search for person in phone book\n");
        printf("3. Print entire phone book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the newline character from input buffer
        switch (choice) {
            case 1:
                addPerson(phoneBook, &numPeople);
                break;
            case 2:
                searchPerson(phoneBook, numPeople);
                break;
            case 3:
                printPhoneBook(phoneBook, numPeople);
                break;
            case 4:
                printf("Exiting phone book...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    // free memory allocated for each person in the phone book
    int i;
    for (i = 0; i < numPeople; i++) {
        free(phoneBook[i]);
    }
    return 0;
}