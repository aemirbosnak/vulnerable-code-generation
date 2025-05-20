//Falcon-180B DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the structure of a record in the database
typedef struct {
    char name[50];
    int age;
    float salary;
} Record;

// Open the database file and read in the records
void openDatabase(Record* records) {
    FILE* file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Error: could not open database file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %d %f\n", records[count].name, &records[count].age, &records[count].salary)!= EOF) {
        count++;
    }

    fclose(file);
}

// Print the records in the database
void printRecords(Record* records, int numRecords) {
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%s\t%d\t%.2f\n", records[i].name, records[i].age, records[i].salary);
    }
}

// Query the database and print the results
void queryDatabase(Record* records, int numRecords, char* query) {
    int matches = 0;
    Record* results = (Record*) malloc(sizeof(Record) * MAX_RECORDS);

    int index = 0;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, query) == 0) {
            results[index++] = records[i];
            if (index >= MAX_RECORDS) {
                printf("Error: too many matches found.\n");
                free(results);
                return;
            }
        }
    }

    if (index == 0) {
        printf("No matches found.\n");
    } else {
        printf("Matches found:\n");
        printRecords(results, index);
    }

    free(results);
}

int main() {
    Record records[MAX_RECORDS];
    openDatabase(records);

    char query[50];
    printf("Enter a name to search for: ");
    scanf("%s", query);

    queryDatabase(records, MAX_RECORDS, query);

    return 0;
}