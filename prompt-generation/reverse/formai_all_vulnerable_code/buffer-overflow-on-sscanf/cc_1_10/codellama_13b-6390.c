//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: ephemeral
/*
 * Database Querying Example Program
 *
 * This program demonstrates how to perform a simple database query using the
 * C programming language and the Ephemeral programming style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
struct person {
    int id;
    char name[50];
    char email[100];
};

int main() {
    // Define the database query
    char query[100] = "SELECT * FROM people WHERE id = 1";

    // Open the database connection
    FILE *fp = fopen("database.txt", "r");

    // Check if the file is open
    if (fp == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    // Read the database contents
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line into a person structure
        struct person person;
        sscanf(line, "%d %s %s", &person.id, person.name, person.email);

        // Check if the person matches the query
        if (person.id == 1) {
            printf("Person found: %s (%s)\n", person.name, person.email);
            break;
        }
    }

    // Close the database connection
    fclose(fp);

    return 0;
}