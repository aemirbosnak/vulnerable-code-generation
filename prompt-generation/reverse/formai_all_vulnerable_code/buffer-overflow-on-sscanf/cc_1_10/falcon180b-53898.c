//Falcon-180B DATASET v1.0 Category: Database querying ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_NUM_RESULTS 100
#define MAX_RESULT_LENGTH 1024

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

typedef struct {
    Person *data;
    int num_results;
} QueryResult;

void query_database(const char *query, QueryResult *result) {
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    char line[MAX_QUERY_LENGTH];
    while (fgets(line, MAX_QUERY_LENGTH, fp)!= NULL) {
        Person p;
        sscanf(line, "%s %d %s", p.name, &p.age, p.email);

        if (strcmp(p.name, query) == 0) {
            result->data = &p;
            result->num_results = 1;
            break;
        }
    }

    fclose(fp);
}

int main() {
    char query[MAX_QUERY_LENGTH];
    printf("Enter a name to search for: ");
    scanf("%s", query);

    QueryResult result;
    query_database(query, &result);

    if (result.num_results == 0) {
        printf("No results found.\n");
    } else {
        printf("Name: %s\n", result.data->name);
        printf("Age: %d\n", result.data->age);
        printf("Email: %s\n", result.data->email);
    }

    return 0;
}