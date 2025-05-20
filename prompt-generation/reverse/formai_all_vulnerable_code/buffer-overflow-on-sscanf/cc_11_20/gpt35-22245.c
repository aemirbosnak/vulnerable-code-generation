//FormAI DATASET v1.0 Category: Database querying ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of names and queries
#define MAX_NAME_LENGTH 50
#define MAX_QUERY_LENGTH 100

// Define the struct for each record in the database
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char profession[MAX_NAME_LENGTH];
} Record;

// Define the database as an array of records
Record database[] = {
    {1, "John", 29, "Engineer"},
    {2, "Mary", 32, "Doctor"},
    {3, "Mike", 45, "Teacher"},
    {4, "Sarah", 23, "Student"},
    {5, "David", 31, "Manager"}
};

int main() {
    int num_records = sizeof(database) / sizeof(Record);

    // Prompt the user for a query
    char query[MAX_QUERY_LENGTH];
    printf("Enter a query (e.g. name=John): ");
    scanf("%s", query);

    // Split the query into its components
    char field[MAX_NAME_LENGTH];
    char value[MAX_NAME_LENGTH];
    sscanf(query, "%[^=]=%s", field, value);

    // Search the database for records that match the query
    int i, count = 0;
    Record *matches[MAX_NAME_LENGTH];
    for (i = 0; i < num_records; i++) {
        Record *r = &database[i];
        if (!strcmp(field, "id") && r->id == atoi(value)) {
            matches[count++] = r;
        }
        else if (!strcmp(field, "name") && !strcmp(r->name, value)) {
            matches[count++] = r;
        }
        else if (!strcmp(field, "age") && r->age == atoi(value)) {
            matches[count++] = r;
        }
        else if (!strcmp(field, "profession") && !strcmp(r->profession, value)) {
            matches[count++] = r;
        }
    }

    // Print the matched records
    printf("Matched %d record(s):\n", count);
    for (i = 0; i < count; i++) {
        Record *r = matches[i];
        printf("%d\t%s\t%d\t%s\n", r->id, r->name, r->age, r->profession);
    }

    return 0;
}