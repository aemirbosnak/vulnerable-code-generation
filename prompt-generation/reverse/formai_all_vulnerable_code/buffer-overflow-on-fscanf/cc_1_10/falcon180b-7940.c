//Falcon-180B DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define MAX_QUERY_LENGTH 100

typedef struct {
    char name[MAX_FIELD_SIZE];
    int age;
    float salary;
} Record;

int main() {
    FILE *fp;
    Record records[MAX_RECORDS];
    int num_records = 0;
    char query[MAX_QUERY_LENGTH];

    // Open the database file for reading
    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }

    // Read each record from the file
    while (fscanf(fp, "%s %d %f", records[num_records].name, &records[num_records].age, &records[num_records].salary)!= EOF) {
        num_records++;
    }

    // Close the database file
    fclose(fp);

    // Prompt the user for a query
    printf("Enter a query (e.g. name = John):\n");
    scanf("%s", query);

    // Perform the query
    int result_count = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, query) == 0) {
            printf("Name: %s\nAge: %d\nSalary: $%.2f\n", records[i].name, records[i].age, records[i].salary);
            result_count++;
        }
    }

    if (result_count == 0) {
        printf("No results found.\n");
    }

    return 0;
}