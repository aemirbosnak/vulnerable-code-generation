//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to query the database and retrieve names and ages of people born in a given year
void queryDatabase(int year) {
    // Connect to the database
    char* db = "database.db";
    FILE* dbFile = fopen(db, "r");
    if (dbFile == NULL) {
        printf("Failed to connect to database.\n");
        return;
    }

    // Query the database for people born in the given year
    char query[256];
    sprintf(query, "SELECT name, age FROM people WHERE birth_year = %d", year);
    if (fscanf(dbFile, "%s", query)!= 1) {
        printf("Failed to retrieve query results.\n");
        fclose(dbFile);
        return;
    }

    // Process the query results
    int numRows = 0;
    int numFields = 0;
    fscanf(dbFile, "%d %d", &numRows, &numFields);
    for (int i = 0; i < numRows; i++) {
        char name[256], age[256];
        fscanf(dbFile, "%s %s", name, age);
        printf("%s (%d)\n", name, atoi(age));
    }

    // Close the database file
    fclose(dbFile);
}

int main() {
    // Prompt the user for the year to query
    printf("Enter the year to query: ");
    int year;
    if (scanf("%d", &year)!= 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Query the database for people born in the given year
    queryDatabase(year);

    return 0;
}