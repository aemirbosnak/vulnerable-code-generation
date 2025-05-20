//Falcon-180B DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 1000
#define MAX_RESULT_LENGTH 1000

typedef struct {
    char *query;
    int result_count;
    char **results;
} QueryResult;

void execute_query(const char *query, QueryResult *result) {
    FILE *db_file = fopen("database.txt", "r");

    if (db_file == NULL) {
        printf("Error opening database file.\n");
        result->result_count = 0;
        return;
    }

    char line[MAX_QUERY_LENGTH];
    while (fgets(line, MAX_QUERY_LENGTH, db_file)!= NULL) {
        if (strstr(line, query)!= NULL) {
            result->result_count++;
            result->results = realloc(result->results, sizeof(char *) * result->result_count);
            result->results[result->result_count - 1] = strdup(line);
        }
    }

    fclose(db_file);
}

int main() {
    QueryResult result;
    char query[MAX_QUERY_LENGTH];

    printf("Enter a query: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    execute_query(query, &result);

    if (result.result_count == 0) {
        printf("No results found.\n");
    } else {
        printf("Results:\n");
        for (int i = 0; i < result.result_count; i++) {
            printf("%s\n", result.results[i]);
        }
    }

    for (int i = 0; i < result.result_count; i++) {
        free(result.results[i]);
    }
    free(result.results);

    return 0;
}