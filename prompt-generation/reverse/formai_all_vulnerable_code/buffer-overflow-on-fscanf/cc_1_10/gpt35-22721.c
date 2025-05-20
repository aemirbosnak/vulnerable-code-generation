//FormAI DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data for a single record in the database 
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Record;

// Function to read a record from a file 
Record readRecord(FILE* fp) {
    Record record;
    fscanf(fp, "%d %s %d %f", &record.id, record.name, &record.age, &record.salary);
    return record;
}

// Function to print a single record 
void printRecord(Record record) {
    printf("%d %s %d %.2f\n", record.id, record.name, record.age, record.salary);
}

int main() {
    FILE* fp = fopen("data.txt", "r"); // Open the file for reading 
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    // Read all records from the file into an array 
    Record records[100];
    int numRecords = 0;
    while (!feof(fp) && numRecords < 100) {
        records[numRecords] = readRecord(fp);
        numRecords++;
    }

    // Query the database for all records with a salary greater than $50,000 
    printf("Records with salaries over $50,000:\n");
    for (int i = 0; i < numRecords; i++) {
        if (records[i].salary > 50000.0) {
            printRecord(records[i]);
        }
    }

    fclose(fp); // Close the file 
    return 0;
}