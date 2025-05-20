//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <string.h>

// struct to store person's details
struct Person {
    char name[100];
    char phoneNumber[20];
    char email[100];
};

// function to add person's details to the phone book
void addPerson(struct Person* person) {
    // Check if the phone book is empty
    if (person->name[0] == '\0') {
        // If the phone book is empty, add the person
        printf("Phone book is empty.\n");
        printf("Adding person details.\n");
        strcpy(person->name, "John Doe");
        strcpy(person->phoneNumber, "123-456-7890");
        strcpy(person->email, "johndoe@example.com");
    } else {
        // If the phone book is not empty, ask for person's details
        printf("Phone book is not empty. Please enter person's details.\n");
        scanf("%s %s %s", person->name, person->phoneNumber, person->email);
    }
}

// function to search person's details in the phone book
void searchPerson(struct Person* person) {
    // Check if the phone book is empty
    if (person->name[0] == '\0') {
        // If the phone book is empty, print error message
        printf("Phone book is empty.\n");
    } else {
        // If the phone book is not empty, search for person's details
        printf("Searching for person details.\n");
        printf("Name: %s\n", person->name);
        printf("Phone Number: %s\n", person->phoneNumber);
        printf("Email: %s\n", person->email);
    }
}

int main() {
    // Initialize the phone book
    struct Person phoneBook[100];
    int numPeople = 0;

    // Add person's details to the phone book
    printf("Enter number of people to add to the phone book: ");
    scanf("%d", &numPeople);

    for (int i = 0; i < numPeople; i++) {
        addPerson(&phoneBook[i]);
    }

    // Search for person's details in the phone book
    printf("Enter the person's name to search: ");
    scanf("%s", phoneBook[0].name);

    searchPerson(&phoneBook[0]);

    return 0;
}