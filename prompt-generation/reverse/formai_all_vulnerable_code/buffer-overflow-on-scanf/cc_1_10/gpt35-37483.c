//FormAI DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum length of strings
#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50

// create a struct for a person's information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

// define the maximum number of people that can be stored
#define MAX_PEOPLE 100

// create an array to store the people
Person people[MAX_PEOPLE];

// create a variable to keep track of the number of people
int num_people = 0;

// create a function to add a new person to the mailing list
void add_person() {
    // check if there is space to add a new person
    if (num_people >= MAX_PEOPLE) {
        printf("Sorry, there is no space to add a new person.\n");
        return;
    }

    // create a new person
    Person new_person;

    // get the person's name
    printf("Enter the person's name: ");
    scanf("%s", new_person.name);

    // get the person's email
    printf("Enter the person's email: ");
    scanf("%s", new_person.email);

    // add the person to the array of people
    people[num_people] = new_person;

    // increment the number of people
    num_people++;

    // print a confirmation message
    printf("The person has been added to the mailing list.\n");
}

// create a function to print the list of people
void print_list() {
    // check if there are people to print
    if (num_people == 0) {
        printf("There are no people on the mailing list.\n");
        return;
    }

    // print the heading for the list
    printf("Name\t\tEmail\n");

    // loop through the people and print their information
    for (int i = 0; i < num_people; i++) {
        printf("%s\t\t%s\n", people[i].name, people[i].email);
    }
}

int main() {
    // print a welcome message
    printf("Welcome to the Medieval Mailing List Manager!\n");

    // create a variable to store the user's input
    int choice = 0;

    // loop until the user chooses to exit
    while (choice != 3) {
        // print the menu of options
        printf("\nWhat would you like to do?\n");
        printf("1. Add a person\n");
        printf("2. Print the list of people\n");
        printf("3. Exit\n");

        // get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // execute the user's choice
        switch (choice) {
            case 1:
                add_person();
                break;
            case 2:
                print_list();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    // exit the program
    return 0;
}