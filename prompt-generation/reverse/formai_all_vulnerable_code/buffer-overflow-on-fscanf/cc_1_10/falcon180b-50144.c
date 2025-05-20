//Falcon-180B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of records that can be stored in the database
#define MAX_RECORDS 100

// Define the structure of a record in the database
typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Record;

// Open the database file for reading
FILE* openDatabase(char* filename) {
    FILE* database = fopen(filename, "r");
    if (database == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }
    return database;
}

// Read a record from the database
Record readRecord(FILE* database) {
    Record record;
    fscanf(database, "%s %d %s", record.name, &record.age, record.occupation);
    return record;
}

// Close the database file
void closeDatabase(FILE* database) {
    fclose(database);
}

// Print a record to the console
void printRecord(Record record) {
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Occupation: %s\n", record.occupation);
}

// Search the database for records that match a given query
void searchDatabase(FILE* database, char* query) {
    Record record;
    while (fscanf(database, "%s %d %s", record.name, &record.age, record.occupation)!= EOF) {
        if (strcmp(record.name, query) == 0 || strcmp(record.occupation, query) == 0) {
            printRecord(record);
        }
    }
}

int main() {
    // Open the database file
    FILE* database = openDatabase("database.txt");

    // Search the database for records that match a given query
    char query[50];
    printf("Enter a query (name or occupation): ");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = '\0'; // Remove newline character from input
    searchDatabase(database, query);

    // Close the database file
    closeDatabase(database);

    return 0;
}