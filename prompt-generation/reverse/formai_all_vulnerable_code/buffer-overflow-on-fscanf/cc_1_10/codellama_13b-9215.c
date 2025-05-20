//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: inquisitive
/*
 * Inquisitive Database Querying Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_FILE "database.txt"
#define MAX_QUERY_LEN 100

typedef struct {
    char name[100];
    int age;
    char email[100];
} Person;

int main() {
    // Open the database file
    FILE *fp = fopen(DB_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", DB_FILE);
        return 1;
    }

    // Read the database into memory
    Person people[100];
    int num_people = 0;
    while (fscanf(fp, "%s %d %s", people[num_people].name, &people[num_people].age, people[num_people].email) == 3) {
        num_people++;
    }

    // Close the database file
    fclose(fp);

    // Ask the user for a query
    char query[MAX_QUERY_LEN];
    printf("Enter a query: ");
    fgets(query, MAX_QUERY_LEN, stdin);

    // Process the query
    if (strcmp(query, "age") == 0) {
        printf("Age: ");
        for (int i = 0; i < num_people; i++) {
            printf("%d ", people[i].age);
        }
        printf("\n");
    } else if (strcmp(query, "name") == 0) {
        printf("Name: ");
        for (int i = 0; i < num_people; i++) {
            printf("%s ", people[i].name);
        }
        printf("\n");
    } else if (strcmp(query, "email") == 0) {
        printf("Email: ");
        for (int i = 0; i < num_people; i++) {
            printf("%s ", people[i].email);
        }
        printf("\n");
    } else {
        printf("Invalid query\n");
    }

    return 0;
}