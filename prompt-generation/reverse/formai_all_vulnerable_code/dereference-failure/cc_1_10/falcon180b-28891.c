//Falcon-180B DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_NUM_RESULTS 100
#define MAX_FIELD_LENGTH 64

typedef struct {
    char *name;
    int id;
} Record;

typedef struct {
    char *query;
    int num_results;
    Record *results;
} QueryResult;

void execute_query(char *query, QueryResult *result) {
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open database file.\n");
        exit(1);
    }

    char line[MAX_QUERY_LENGTH];
    while (fgets(line, MAX_QUERY_LENGTH, fp)!= NULL) {
        if (strstr(line, query)!= NULL) {
            char *token = strtok(line, " ");
            while (token!= NULL) {
                if (isdigit(token[0])) {
                    int id = atoi(token);
                    result->results[result->num_results].id = id;
                    result->results[result->num_results].name = strdup(token + 1);
                    result->num_results++;
                    if (result->num_results >= MAX_NUM_RESULTS) {
                        break;
                    }
                }
                token = strtok(NULL, " ");
            }
        }
    }

    fclose(fp);
}

void print_results(QueryResult *result) {
    printf("Query results:\n");
    for (int i = 0; i < result->num_results; i++) {
        printf("%d: %s\n", result->results[i].id, result->results[i].name);
    }
}

int main() {
    char query[MAX_QUERY_LENGTH];
    printf("Enter a query:\n");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    QueryResult result;
    execute_query(query, &result);

    print_results(&result);

    for (int i = 0; i < result.num_results; i++) {
        free(result.results[i].name);
    }
    free(result.results);

    return 0;
}