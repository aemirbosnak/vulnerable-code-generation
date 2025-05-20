//FormAI DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PEOPLE 100

// Define a new struct to hold the person's name and email
typedef struct person {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

// Declare function prototypes
void print_menu();
int add_person(Person people[], int count);
void view_people(Person people[], int count);
void save_to_file(Person people[], int count);

int main() {
    // Declare variables for the program
    int choice, count = 0;
    Person people[MAX_PEOPLE];

    // Print the menu and get the user's choice
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement for the user's choice
        switch (choice) {
            case 1:
                count = add_person(people, count);
                break;
            case 2:
                view_people(people, count);
                break;
            case 3:
                save_to_file(people, count);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

// Function to print the menu options
void print_menu() {
    printf("\nMenu options:\n");
    printf("1. Add person to mailing list\n");
    printf("2. View all people on mailing list\n");
    printf("3. Save mailing list to file\n");
    printf("4. Exit program\n");
}

// Function to add a person to the mailing list
int add_person(Person people[], int count) {
    // Check if there is room for another person
    if (count >= MAX_PEOPLE) {
        printf("Sorry, the mailing list is full.\n");
        return count;
    }

    // Get the person's name and email
    printf("Enter the person's name: ");
    scanf("%s", people[count].name);
    printf("Enter the person's email: ");
    scanf("%s", people[count].email);

    // Increment the count
    count++;

    // Return the new count
    return count;
}

// Function to view all people on the mailing list
void view_people(Person people[], int count) {
    // Check if there are any people on the mailing list
    if (count == 0) {
        printf("There are no people on the mailing list.\n");
        return;
    }

    // Loop through the people and print their name and email
    printf("Mailing list:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", people[i].name, people[i].email);
    }
}

// Function to save the mailing list to a file
void save_to_file(Person people[], int count) {
    FILE *fp;

    // Open the file for writing
    fp = fopen("mailing_list.txt", "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Loop through the people and write their name and email to the file
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\t%s\n", people[i].name, people[i].email);
    }

    // Close the file
    fclose(fp);

    // Print confirmation message
    printf("Mailing list saved to file.\n");
}