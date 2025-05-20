//FormAI DATASET v1.0 Category: Database querying ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a record in the database
typedef struct Record {
    int id;
    char name[50];
    char email[50];
} Record;

// Define a function to read the database from a file
int readDatabase(Record *database, char *filename, int maxRecords) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s!", filename);
        return -1;
    }

    int numRecords = 0;
    char line[150];

    while (fgets(line, sizeof(line), file)) {
        if (numRecords >= maxRecords) {
            printf("Error: Maximum number of records exceeded.\n");
            break;
        }
        sscanf(line, "%d %s %s", &database[numRecords].id, database[numRecords].name, database[numRecords].email);
        numRecords++;
    }

    fclose(file);

    return numRecords;
}

// Define a function to print all the records in the database
void printDatabase(Record *database, int numRecords) {
    printf("ID   | Name                             | Email\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < numRecords; i++) {
        printf("%-4d | %-32s | %-32s\n", database[i].id, database[i].name, database[i].email);
    }
}

// Define a function to query the database by name
void queryDatabaseByName(Record *database, int numRecords, char *name) {
    printf("Results for name \"%s\":\n", name);
    printf("ID   | Name                             | Email\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("%-4d | %-32s | %-32s\n", database[i].id, database[i].name, database[i].email);
        }
    }
}

int main() {
    // Define the maximum number of records the database can hold
    const int MAX_RECORDS = 100;

    // Allocate memory for the database
    Record *database = (Record *)malloc(MAX_RECORDS * sizeof(Record));

    // Read the database from a file
    int numRecords = readDatabase(database, "database.txt", MAX_RECORDS);

    // Print the entire database
    printf("Database contents:\n");
    printDatabase(database, numRecords);

    // Query the database by name
    queryDatabaseByName(database, numRecords, "John Smith");

    // Free the memory allocated for the database
    free(database);

    return 0;
}