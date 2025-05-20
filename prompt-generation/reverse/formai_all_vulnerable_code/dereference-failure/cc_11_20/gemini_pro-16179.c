//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_LINE_LEN 100
#define MAX_RECORDS 10

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    int wealth;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

int main() {
    // Load the database from a file
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening database file\n");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        // Parse the line into a record
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        int wealth = atoi(strtok(NULL, ","));

        // Store the record in the database
        strcpy(records[num_records].name, name);
        records[num_records].age = age;
        records[num_records].wealth = wealth;
        num_records++;
    }

    fclose(fp);

    // Query the database
    char query[MAX_LINE_LEN];
    while (1) {
        printf("Enter a query (or 'quit' to exit): ");
        fgets(query, MAX_LINE_LEN, stdin);

        if (strcmp(query, "quit\n") == 0) {
            break;
        }

        // Parse the query
        char *field = strtok(query, " ");
        char *value = strtok(NULL, "\n");

        // Execute the query
        for (int i = 0; i < num_records; i++) {
            if (strcmp(field, "name") == 0 && strcmp(records[i].name, value) == 0) {
                printf("Record found:\n");
                printf("Name: %s\n", records[i].name);
                printf("Age: %d\n", records[i].age);
                printf("Wealth: %d\n", records[i].wealth);
            } else if (strcmp(field, "age") == 0 && records[i].age == atoi(value)) {
                printf("Record found:\n");
                printf("Name: %s\n", records[i].name);
                printf("Age: %d\n", records[i].age);
                printf("Wealth: %d\n", records[i].wealth);
            } else if (strcmp(field, "wealth") == 0 && records[i].wealth == atoi(value)) {
                printf("Record found:\n");
                printf("Name: %s\n", records[i].name);
                printf("Age: %d\n", records[i].age);
                printf("Wealth: %d\n", records[i].wealth);
            }
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}