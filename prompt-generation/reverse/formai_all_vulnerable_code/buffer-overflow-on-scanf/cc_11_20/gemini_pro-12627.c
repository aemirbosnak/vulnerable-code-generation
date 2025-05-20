//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
    char *name;
    int age;
    char *address;
} person_t;

// Database array
person_t database[] = {
    { "John Doe", 30, "123 Main Street" },
    { "Jane Smith", 25, "456 Elm Street" },
    { "Bill Jones", 40, "789 Oak Street" },
    { "Mary Johnson", 35, "1011 Pine Street" },
    { "Tom Brown", 28, "1213 Maple Street" }
};

// Number of records in the database
int num_records = sizeof(database) / sizeof(person_t);

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Peaceful Database!\n");

    // Get the user's input
    char input[100];
    printf("Enter a command (search, add, delete, or quit): ");
    scanf("%s", input);

    // Process the user's input
    while (strcmp(input, "quit") != 0) {
        if (strcmp(input, "search") == 0) {
            // Get the search term
            char search_term[100];
            printf("Enter a search term: ");
            scanf("%s", search_term);

            // Search the database for the search term
            int found = 0;
            for (int i = 0; i < num_records; i++) {
                if (strstr(database[i].name, search_term) != NULL) {
                    // Print the record
                    printf("%s, %d, %s\n", database[i].name, database[i].age, database[i].address);
                    found = 1;
                }
            }

            // If the search term was not found, print an error message
            if (!found) {
                printf("No records found for the search term '%s'.\n", search_term);
            }
        } else if (strcmp(input, "add") == 0) {
            // Get the new record's data
            char name[100];
            int age;
            char address[100];
            printf("Enter the new record's name: ");
            scanf("%s", name);
            printf("Enter the new record's age: ");
            scanf("%d", &age);
            printf("Enter the new record's address: ");
            scanf("%s", address);

            // Add the new record to the database
            person_t new_record = { name, age, address };
            database[num_records++] = new_record;

            // Print a success message
            printf("New record added to the database.\n");
        } else if (strcmp(input, "delete") == 0) {
            // Get the record's name
            char name[100];
            printf("Enter the name of the record to delete: ");
            scanf("%s", name);

            // Delete the record from the database
            int found = 0;
            for (int i = 0; i < num_records; i++) {
                if (strcmp(database[i].name, name) == 0) {
                    // Delete the record
                    for (int j = i; j < num_records - 1; j++) {
                        database[j] = database[j + 1];
                    }
                    num_records--;
                    found = 1;
                    break;
                }
            }

            // If the record was not found, print an error message
            if (!found) {
                printf("No records found for the name '%s'.\n", name);
            } else {
                // Print a success message
                printf("Record deleted from the database.\n");
            }
        } else {
            // Print an error message
            printf("Invalid command. Please enter 'search', 'add', 'delete', or 'quit'.\n");
        }

        // Get the user's input
        printf("Enter a command (search, add, delete, or quit): ");
        scanf("%s", input);
    }

    // Print a goodbye message
    printf("Thank you for using the Peaceful Database!\n");

    return 0;
}