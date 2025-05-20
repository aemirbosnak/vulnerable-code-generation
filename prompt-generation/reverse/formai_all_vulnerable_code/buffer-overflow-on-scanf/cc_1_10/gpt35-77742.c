//FormAI DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100
#define MAX_RECORDS 1000

// Struct to hold database records
typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    int age;
    double height;
    double weight;
} Record;

// Global array to hold database records
Record database[MAX_RECORDS];

// Function to print a given record
void printRecord(Record r) {
    printf("Name: %s\n", r.name);
    printf("Address: %s\n", r.address);
    printf("Age: %d\n", r.age);
    printf("Height: %f\n", r.height);
    printf("Weight: %f\n", r.weight);
    printf("\n");
}

int main() {
    int numRecords = 0; // Number of records in database
    char query[MAX_NAME_LEN]; // String to hold query

    // Hardcoded example data (in real program, would read from file)
    strcpy(database[0].name, "John");
    strcpy(database[0].address, "123 Main St");
    database[0].age = 30;
    database[0].height = 6.0;
    database[0].weight = 180.0;

    strcpy(database[1].name, "Jane");
    strcpy(database[1].address, "456 Oak St");
    database[1].age = 25;
    database[1].height = 5.5;
    database[1].weight = 120.0;

    strcpy(database[2].name, "Bob");
    strcpy(database[2].address, "789 Maple St");
    database[2].age = 40;
    database[2].height = 5.11;
    database[2].weight = 200.0;

    numRecords = 3;

    printf("Enter name of record to query: ");
    scanf("%s", query);

    // Loop through database and print records that match query
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, query) == 0) {
            printRecord(database[i]);
        }
    }

    return 0;
}