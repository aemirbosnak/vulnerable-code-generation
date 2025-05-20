//Falcon-180B DATASET v1.0 Category: Database querying ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_NUM_RESULTS 100

// Struct to store query results
typedef struct {
    char *column_name;
    char *value;
} query_result;

// Function to execute a query
query_result *execute_query(char *query) {
    char *token = strtok(query, " ");
    int num_results = 0;
    query_result *results = malloc(sizeof(query_result) * MAX_NUM_RESULTS);

    // Parse the query and store the results
    while (token!= NULL && num_results < MAX_NUM_RESULTS) {
        if (strcmp(token, "SELECT") == 0) {
            token = strtok(NULL, " ");
            if (token!= NULL) {
                results[num_results].column_name = strdup(token);
            }
        } else if (strcmp(token, "FROM") == 0) {
            token = strtok(NULL, " ");
            if (token!= NULL) {
                results[num_results].value = strdup(token);
            }
        }
        num_results++;
        token = strtok(NULL, " ");
    }

    return results;
}

// Function to print the query results
void print_results(query_result *results, int num_results) {
    for (int i = 0; i < num_results; i++) {
        printf("%s: %s\n", results[i].column_name, results[i].value);
    }
}

int main() {
    char query[MAX_QUERY_LENGTH];

    // Example queries
    printf("Enter a query (e.g. SELECT column_name FROM table_name):\n");
    scanf("%s", query);
    query_result *results = execute_query(query);
    print_results(results, MAX_NUM_RESULTS);

    return 0;
}