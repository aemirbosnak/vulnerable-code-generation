//Gemma-7B DATASET v1.0 Category: Database querying ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY 10

typedef struct Query {
    char name[20];
    int age;
    double salary;
} Query;

int main() {
    // Database of Queries
    Query queries[MAX_QUERY] = {
        {"John Doe", 25, 50000},
        {"Jane Doe", 30, 60000},
        {"Mike Smith", 20, 40000},
        {"Mary Johnson", 22, 30000},
        {"David Lee", 27, 70000},
        {"Alice White", 23, 45000},
        {"Bob Green", 21, 35000},
        {"Ethan Brown", 26, 65000},
        {"Hannah Jones", 29, 55000},
        {"Thomas Anderson", 24, 40000}
    };

    // User Query Input
    char query_name[20];
    int query_age;
    double query_salary;

    // Querying the Database
    printf("Enter query name: ");
    scanf("%s", query_name);

    printf("Enter query age: ");
    scanf("%d", &query_age);

    printf("Enter query salary: ");
    scanf("%lf", &query_salary);

    // Finding Matching Queries
    int found = 0;
    for (int i = 0; i < MAX_QUERY; i++) {
        if (strcmp(queries[i].name, query_name) == 0 && queries[i].age == query_age && queries[i].salary == query_salary) {
            found = 1;
            printf("Found query: %s, %d, %lf\n", queries[i].name, queries[i].age, queries[i].salary);
        }
    }

    // No Match Found
    if (!found) {
        printf("No query found.\n");
    }

    return 0;
}