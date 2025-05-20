//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_AGE 150

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int main() {
    FILE *database;
    Person people[100];
    char query[MAX_NAME_LENGTH + 10];
    int num_people = 0;

    database = fopen("database.txt", "r");
    if (database == NULL) {
        printf("Error: Could not open database file.\n");
        return 1;
    }

    while (fscanf(database, "%s %d\n", people[num_people].name, &people[num_people].age)!= EOF) {
        num_people++;
        if (num_people == 100) {
            break;
        }
    }

    fclose(database);

    while (1) {
        printf("Enter a query (name age): ");
        scanf("%s", query);

        if (strcmp(query, "exit") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < num_people; i++) {
            if (strcmp(query, people[i].name) == 0) {
                printf("Name: %s\nAge: %d\n", people[i].name, people[i].age);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("No results found.\n");
        }
    }

    return 0;
}