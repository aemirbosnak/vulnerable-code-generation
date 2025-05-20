//Falcon-180B DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10
#define MAX_AGE 150

typedef struct {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int age;
} record;

int main() {
    record database[100];
    int num_records = 0;

    // Initialize the database
    strcpy(database[num_records].id, "001");
    strcpy(database[num_records].name, "John Doe");
    database[num_records].age = 30;
    num_records++;

    strcpy(database[num_records].id, "002");
    strcpy(database[num_records].name, "Jane Doe");
    database[num_records].age = 28;
    num_records++;

    strcpy(database[num_records].id, "003");
    strcpy(database[num_records].name, "Bob Smith");
    database[num_records].age = 45;
    num_records++;

    // Query the database
    char query[MAX_ID_LENGTH];
    printf("Enter ID to search for: ");
    scanf("%s", query);

    int found = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(query, database[i].id) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", database[i].name);
            printf("ID: %s\n", database[i].id);
            printf("Age: %d\n", database[i].age);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Record not found.\n");
    }

    return 0;
}