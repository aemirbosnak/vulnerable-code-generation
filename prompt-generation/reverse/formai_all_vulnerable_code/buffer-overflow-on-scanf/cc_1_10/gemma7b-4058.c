//Gemma-7B DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    int age;
    double salary;
} Record;

void query_database(Record *records, int num_records) {
    char query[MAX_RECORD_SIZE];
    printf("Enter your query: ");
    scanf("%s", query);

    // Parse the query
    char *keywords = strsep(query, " ");
    char *conditions = strsep(keywords, "=");

    // Check if the query is valid
    if (conditions == NULL) {
        printf("Invalid query.\n");
        return;
    }

    // Filter the records
    for (int i = 0; i < num_records; i++) {
        int match = 1;
        for (char *keyword = keywords; keyword != NULL; keyword++) {
            if (strstr(records[i].name, keyword) == NULL) {
                match = 0;
            }
        }

        if (match) {
            printf("Name: %s, Age: %d, Salary: %.2lf\n", records[i].name, records[i].age, records[i].salary);
        }
    }
}

int main() {
    Record records[] = {
        {"John Doe", 25, 50000},
        {"Jane Doe", 30, 60000},
        {"Peter Pan", 12, 30000}
    };

    int num_records = 3;

    query_database(records, num_records);

    return 0;
}