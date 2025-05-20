//FormAI DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>

// Define a struct for storing information about a person
struct Person {
    char name[50];
    int age;
};

// Define an array to store our person objects
struct Person people[10];

// Define a function for adding a new person to the database
void addPerson() {
    printf("Enter name: ");
    scanf("%s", &people[0].name);
    printf("Enter age: ");
    scanf("%d", &people[0].age);
    printf("Added person: %s, %d\n", people[0].name, people[0].age);
}

// Define a function for printing out all the people in the database
void printPeople() {
    for (int i = 0; i < 10; i++) {
        if (people[i].age != 0) {
            printf("%s, %d\n", people[i].name, people[i].age);
        }
    }
}

// Main function that runs the simulation
int main() {
    // Initialize the database with some sample data
    people[0].age = 24;
    strcpy(people[0].name, "Alice");
    people[1].age = 32;
    strcpy(people[1].name, "Bob");

    // Print a cheerful welcome message
    printf("Welcome to the Person Database Simulation!\n");

    // Use a while loop to keep the program running until the user chooses to exit
    int running = 1;
    while (running) {
        // Prompt the user to enter a command
        printf("Enter a command: (a)dd, (p)rint, or (q)uit\n");
        char command;
        scanf("%s", &command);

        // Use a switch statement to handle different commands
        switch (command) {
            case 'a':
                addPerson();
                break;
            case 'p':
                printPeople();
                break;
            case 'q':
                running = 0;
                break;
            default:
                printf("Invalid command! Try again.\n");
        }
    }

    // Print a cheerful goodbye message
    printf("Thanks for using the Person Database Simulation! Goodbye!\n");

    return 0;
}