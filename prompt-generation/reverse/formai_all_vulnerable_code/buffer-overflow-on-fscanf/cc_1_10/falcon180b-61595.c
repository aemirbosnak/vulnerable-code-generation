//Falcon-180B DATASET v1.0 Category: Database querying ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

struct Record {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
};

int main() {
    FILE *database = fopen("database.txt", "r");
    if (database == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    char query[MAX_VALUE_LENGTH];
    printf("Enter query:\n");
    fgets(query, MAX_VALUE_LENGTH, stdin);
    fclose(database);

    database = fopen("database.txt", "r");
    if (database == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    struct Record records[100];
    int num_records = 0;

    while (fscanf(database, "%s %s", records[num_records].name, records[num_records].value)!= EOF) {
        num_records++;
    }

    fclose(database);

    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, "Name") == 0 && strcmp(records[i].value, "John") == 0) {
            printf("Name: John\n");
        } else if (strcmp(records[i].name, "Age") == 0 && strcmp(records[i].value, "25") == 0) {
            printf("Age: 25\n");
        }
    }

    return 0;
}