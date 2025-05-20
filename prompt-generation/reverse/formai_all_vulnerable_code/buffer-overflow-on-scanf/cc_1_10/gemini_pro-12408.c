//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the database structure:
typedef struct {
    char name[50];
    int age;
    char address[100];
} Person;

// Define the database:
Person database[100];

// Define the database size:
int databaseSize = 0;

// Define the menu options:
enum MenuOption {
    ADD_PERSON,
    DELETE_PERSON,
    PRINT_DATABASE,
    QUIT
};

// Get a menu option from the user:
enum MenuOption getMenuOption() {
    int option;
    printf("Enter a menu option:\n");
    printf("1. Add person\n");
    printf("2. Delete person\n");
    printf("3. Print database\n");
    printf("4. Quit\n");
    scanf("%d", &option);
    return option;
}

// Add a person to the database:
void addPerson() {
    // Get the person's name:
    printf("Enter the person's name:\n");
    scanf("%s", database[databaseSize].name);

    // Get the person's age:
    printf("Enter the person's age:\n");
    scanf("%d", &database[databaseSize].age);

    // Get the person's address:
    printf("Enter the person's address:\n");
    scanf("%s", database[databaseSize].address);

    // Increment the database size:
    databaseSize++;
}

// Delete a person from the database:
void deletePerson() {
    // Get the person's name:
    printf("Enter the person's name:\n");
    char name[50];
    scanf("%s", name);

    // Find the person in the database:
    int index = -1;
    for (int i = 0; i < databaseSize; i++) {
        if (strcmp(database[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the person was not found, print an error message:
    if (index == -1) {
        printf("Person not found.\n");
        return;
    }

    // Shift the database to remove the person:
    for (int i = index; i < databaseSize - 1; i++) {
        database[i] = database[i + 1];
    }

    // Decrement the database size:
    databaseSize--;
}

// Print the database:
void printDatabase() {
    printf("Database:\n");
    for (int i = 0; i < databaseSize; i++) {
        printf("%s, %d, %s\n", database[i].name, database[i].age, database[i].address);
    }
}

int main() {
    // Get a menu option from the user:
    enum MenuOption option = getMenuOption();

    // While the user does not want to quit, perform the selected action:
    while (option != QUIT) {
        switch (option) {
            case ADD_PERSON:
                addPerson();
                break;
            case DELETE_PERSON:
                deletePerson();
                break;
            case PRINT_DATABASE:
                printDatabase();
                break;
        }

        // Get a menu option from the user:
        option = getMenuOption();
    }

    return 0;
}