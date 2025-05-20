//FormAI DATASET v1.0 Category: Database querying ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for storing database records
typedef struct {
    char name[20];
    int age;
    char occupation[30];
} Record;

// Declare function for displaying menu options and getting user input
int display_menu();

int main() {
    FILE *database; // Declare file pointer
    Record rec; // Declare variable for storing record from database
    int option; // Declare variable for storing user menu choice
    char search_term[20]; // Declare variable for storing user search term

    // Attempt to open database file for reading and writing
    if ((database = fopen("database.txt", "r+")) == NULL) {
        printf("Error: Unable to open database file.\n");
        exit(1);
    }

    // Display menu options and get user input
    option = display_menu();

    // Main program loop
    while (option != 4) {
        switch (option) {
            case 1:
                // Add new record to database
                printf("Enter name: ");
                scanf("%s", rec.name);
                printf("Enter age: ");
                scanf("%d", &rec.age);
                printf("Enter occupation: ");
                scanf("%s", rec.occupation);
                fseek(database, 0, SEEK_END);
                fprintf(database, "%s %d %s\n", rec.name, rec.age, rec.occupation);
                printf("Record added successfully!\n\n");
                break;

            case 2:
                // Display all records in database
                rewind(database);
                printf("Name\tAge\tOccupation\n");
                while (fscanf(database, "%s %d %s\n", rec.name, &rec.age, rec.occupation) != EOF) {
                    printf("%s\t%d\t%s\n", rec.name, rec.age, rec.occupation);
                }
                break;

            case 3:
                // Search database for records matching search term
                printf("Enter search term: ");
                scanf("%s", search_term);
                rewind(database);
                printf("Name\tAge\tOccupation\n");
                while (fscanf(database, "%s %d %s\n", rec.name, &rec.age, rec.occupation) != EOF) {
                    if (strstr(rec.name, search_term) != NULL || strstr(rec.occupation, search_term) != NULL) {
                        printf("%s\t%d\t%s\n", rec.name, rec.age, rec.occupation);
                    }
                }
                break;

            default:
                // Invalid menu option selected
                printf("Invalid option selected.\n");
                break;
        }

        // Display menu options and get user input
        option = display_menu();
    }

    // Close database file
    fclose(database);

    return 0;
}

// Function for displaying menu options and getting user input
int display_menu() {
    int option;

    printf("1. Add new record\n");
    printf("2. Display all records\n");
    printf("3. Search database\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
    scanf("%d", &option);
    printf("\n");

    return option;
}