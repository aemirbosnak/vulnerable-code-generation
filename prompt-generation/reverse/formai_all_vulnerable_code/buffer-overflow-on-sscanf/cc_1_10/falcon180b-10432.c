//Falcon-180B DATASET v1.0 Category: Database querying ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_QUERY_LEN 500

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

int main() {
    FILE *db;
    Person *people = NULL;
    int num_people = 0;
    char query[MAX_QUERY_LEN];
    char name[MAX_NAME_LEN];
    int age;
    int result;

    // Open the database file
    db = fopen("people.db", "r");
    if (db == NULL) {
        printf("Error: could not open database file.\n");
        exit(1);
    }

    // Read in the people from the database
    while (fgets(query, MAX_QUERY_LEN, db)!= NULL) {
        sscanf(query, "%s %d", name, &age);
        result = realloc(people, sizeof(Person) * ++num_people);
        if (result == NULL) {
            printf("Error: could not allocate memory for person.\n");
            exit(1);
        }
        strcpy(people[num_people - 1].name, name);
        people[num_people - 1].age = age;
    }

    // Close the database file
    fclose(db);

    // Prompt the user for a query
    printf("Enter a query (name or age): ");
    fgets(query, MAX_QUERY_LEN, stdin);
    query[strcspn(query, "\n")] = '\0';

    // Perform the query
    int num_results = 0;
    Person *results = NULL;
    result = realloc(results, sizeof(Person) * num_people);
    if (result == NULL) {
        printf("Error: could not allocate memory for results.\n");
        exit(1);
    }
    for (int i = 0; i < num_people; i++) {
        if (strcmp(query, people[i].name) == 0 || people[i].age == atoi(query)) {
            results[num_results++] = people[i];
        }
    }

    // Print the results
    printf("Results:\n");
    for (int i = 0; i < num_results; i++) {
        printf("Name: %s\nAge: %d\n\n", results[i].name, results[i].age);
    }

    // Free the memory
    free(people);
    free(results);

    return 0;
}