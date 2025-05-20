//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

// Define a structure for each record in the database
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

// Open the database file for reading
FILE *openDatabase(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }
    return fp;
}

// Close the database file
void closeDatabase(FILE *fp) {
    fclose(fp);
}

// Read a single record from the database file
Record readRecord(FILE *fp) {
    Record record;
    fscanf(fp, "%s %d", record.name, &record.age);
    return record;
}

// Write a single record to the database file
void writeRecord(FILE *fp, Record record) {
    fprintf(fp, "%s %d\n", record.name, record.age);
}

// Query the database for records matching a given name
void queryByName(FILE *fp, char *name) {
    Record record;
    while (fscanf(fp, "%s %d", record.name, &record.age)!= EOF) {
        if (strcmp(record.name, name) == 0) {
            printf("Found record for %s:\n", name);
            printf("Age: %d\n", record.age);
        }
    }
}

// Query the database for records where age is greater than or equal to a given value
void queryByAge(FILE *fp, int age) {
    Record record;
    while (fscanf(fp, "%s %d", record.name, &record.age)!= EOF) {
        if (record.age >= age) {
            printf("Found record(s) with age >= %d:\n", age);
            printf("Name: %s\n", record.name);
            printf("Age: %d\n", record.age);
        }
    }
}

int main() {
    // Open the database file
    FILE *fp = openDatabase("database.txt");

    // Query the database for records matching a given name
    char name[MAX_NAME_LENGTH];
    printf("Enter a name to search for: ");
    scanf("%s", name);
    queryByName(fp, name);

    // Query the database for records where age is greater than or equal to a given value
    int age;
    printf("Enter an age to search for: ");
    scanf("%d", &age);
    queryByAge(fp, age);

    // Close the database file
    closeDatabase(fp);

    return 0;
}