//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Person;

int main() {
    FILE *database;
    Person *people = NULL;
    int num_people = 0;
    char query[100];

    // Open the database file for reading
    database = fopen("database.txt", "r");
    if (database == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    // Read in the number of people in the database
    fscanf(database, "%d", &num_people);

    // Allocate memory for the array of people
    people = malloc(num_people * sizeof(Person));
    if (people == NULL) {
        printf("Error allocating memory for people.\n");
        return 1;
    }

    // Read in each person's name and address from the database
    for (int i = 0; i < num_people; i++) {
        fscanf(database, "%s %s", people[i].name, people[i].address);
    }

    // Close the database file
    fclose(database);

    // Prompt the user for a query
    printf("Enter a query (name or address): ");
    scanf("%s", query);

    // Perform the query and print the results
    int num_matches = 0;
    for (int i = 0; i < num_people; i++) {
        if (strstr(people[i].name, query)!= NULL || strstr(people[i].address, query)!= NULL) {
            printf("%s %s\n", people[i].name, people[i].address);
            num_matches++;
        }
    }

    if (num_matches == 0) {
        printf("No matches found.\n");
    } else {
        printf("%d matches found.\n", num_matches);
    }

    // Free the memory allocated for the array of people
    free(people);

    return 0;
}