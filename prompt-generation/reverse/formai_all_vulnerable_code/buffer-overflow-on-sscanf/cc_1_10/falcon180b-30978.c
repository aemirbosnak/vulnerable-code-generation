//Falcon-180B DATASET v1.0 Category: Database querying ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUERY_LENGTH 1000
#define MAX_RESULT_LENGTH 1000
#define MAX_NUM_RESULTS 100

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *results;
    int num_results;
} QueryResult;

void query_database(char *query, QueryResult *result) {
    FILE *database = fopen("database.txt", "r");
    if (database == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    char line[MAX_QUERY_LENGTH];
    while (fgets(line, MAX_QUERY_LENGTH, database)!= NULL) {
        Person *person = malloc(sizeof(Person));
        sscanf(line, "%s %d", person->name, &person->age);
        result->results = realloc(result->results, sizeof(Person) * ++result->num_results);
        result->results[result->num_results - 1] = *person;
        free(person);
    }

    fclose(database);
}

void print_results(QueryResult *result) {
    if (result->num_results == 0) {
        printf("No results found.\n");
        return;
    }

    for (int i = 0; i < result->num_results; i++) {
        printf("%s (%d years old)\n", result->results[i].name, result->results[i].age);
    }
}

int main() {
    char query[MAX_QUERY_LENGTH];
    printf("Enter a query (e.g. 'John' or 'age > 30'):\n");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    QueryResult result;
    query_database(query, &result);
    print_results(&result);

    free(result.results);
    return 0;
}