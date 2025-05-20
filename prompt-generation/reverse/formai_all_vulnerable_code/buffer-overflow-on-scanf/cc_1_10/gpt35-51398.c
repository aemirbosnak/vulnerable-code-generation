//FormAI DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define database structure
typedef struct {
    char name[50];
    int age;
    char city[50];
} Person;

// Define function to read data from the database
void readDatabase(Person* database, int numEntries) {
    // Code to read data from the database
}

// Define function to query the database
Person* queryDatabaseByName(Person* database, int numEntries, char* name) {
    Person* results = NULL; // Initialize results pointer to NULL
    int numResults = 0; // Initialize number of results to 0

    // Loop through each entry in the database
    for (int i = 0; i < numEntries; i++) {
        // Check if name matches
        if (strcmp(database[i].name, name) == 0) {
            // Allocate memory for new result
            results = realloc(results, (numResults + 1) * sizeof(Person));
            // Copy data from database to result
            memcpy(&results[numResults], &database[i], sizeof(Person));
            // Increment number of results
            numResults++;
        }
    }

    // Return results
    return results;
}

// Define main function
int main() {
    // Initialize database
    Person database[100];
    int numEntries = 0;

    // Code to populate database

    // Read data from database
    readDatabase(database, numEntries);

    // Query database by name
    char name[50];
    printf("Enter name to search for: ");
    scanf("%s", name);
    Person* results = queryDatabaseByName(database, numEntries, name);
    int numResults = 0;
    if (results != NULL) {
        // Print results
        printf("Results for %s:\n", name);
        for (int i = 0; i < numResults; i++) {
            printf("- %s, %d, %s\n", results[i].name, results[i].age, results[i].city);
        }
        // Free memory for results
        free(results);
    } else {
        printf("No results found for %s.\n", name);
    }

    return 0;
}