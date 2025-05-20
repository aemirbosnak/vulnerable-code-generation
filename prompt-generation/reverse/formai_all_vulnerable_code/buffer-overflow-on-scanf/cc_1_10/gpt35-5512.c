//FormAI DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure to represent each contact in the phonebook
typedef struct {
    char name[50];
    char number[20];
} Contact;

// function to add a contact to the phonebook
void addContact(Contact *phonebook, int *count) {
    printf("Enter name: ");
    fgets(phonebook[*count].name, 50, stdin);
    phonebook[*count].name[strcspn(phonebook[*count].name, "\n")] = 0; // remove newline character
    printf("Enter number: ");
    fgets(phonebook[*count].number, 20, stdin);
    phonebook[*count].number[strcspn(phonebook[*count].number, "\n")] = 0; // remove newline character
    (*count)++;
}

// function to search for a contact in the phonebook
void searchContact(Contact *phonebook, int count) {
    char name[50];
    printf("Enter name to search: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("%s's number is %s\n", phonebook[i].name, phonebook[i].number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found\n");
    }
}

// main function
int main() {
    int choice, count = 0;
    Contact *phonebook = (Contact *)malloc(100 * sizeof(Contact)); // allocate memory for 100 contacts
    printf("Welcome to the Phone Book!\n");
    do {
        printf("Choose an option:\n1. Add a contact\n2. Search for a contact\n3. Exit\n");
        scanf("%d", &choice);
        getchar(); // consume newline character
        switch (choice) {
            case 1:
                addContact(phonebook, &count);
                break;
            case 2:
                searchContact(phonebook, count);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);
    free(phonebook); // free memory allocated for phonebook
    return 0;
}