//Falcon-180B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    FILE* dbFile = fopen(filename, "r");

    if (dbFile == NULL) {
        printf("Error: could not open database file.\n");
        exit(1);
    }

    return dbFile;
}

// Read a record from the database file
Record readRecord(FILE* dbFile) {
    Record record;
    fscanf(dbFile, "%s %d %s", record.name, &record.age, record.occupation);

    return record;
}

// Close the database file
void closeDatabase(FILE* dbFile) {
    fclose(dbFile);
}

// Print the records in the database
void printRecords(Record records[], int numRecords) {
    printf("Name\tAge\tOccupation\n");

    for (int i = 0; i < numRecords; i++) {
        printf("%s\t%d\t%s\n", records[i].name, records[i].age, records[i].occupation);
    }
}

// Query the database for records matching a certain criteria
void queryDatabase(Record records[], int numRecords, char* query) {
    printf("Query results:\n");

    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].occupation, query) == 0) {
            printf("%s\t%d\t%s\n", records[i].name, records[i].age, records[i].occupation);
        }
    }
}

int main() {
    // Open the database file
    FILE* dbFile = openDatabase("database.txt");

    // Read the records from the database file
    Record records[MAX_RECORDS];
    int numRecords = 0;

    while (fscanf(dbFile, "%s %d %s", records[numRecords].name, &records[numRecords].age, records[numRecords].occupation)!= EOF) {
        numRecords++;

        if (numRecords == MAX_RECORDS) {
            printf("Error: maximum number of records reached.\n");
            closeDatabase(dbFile);
            exit(1);
        }
    }

    closeDatabase(dbFile);

    // Print all the records in the database
    printf("All records:\n");
    printRecords(records, numRecords);

    // Query the database for records matching a certain criteria
    char query[50];
    printf("Enter a query (occupation): ");
    scanf("%s", query);

    queryDatabase(records, numRecords, query);

    return 0;
}