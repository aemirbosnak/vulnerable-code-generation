//FormAI DATASET v1.0 Category: Database querying ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to hold data from database
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {

    // Open and read in data from database file
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open database file.\n");
        return 1;
    }

    // Read first line of file to determine number of records
    int num_records;
    fscanf(fp, "%d\n", &num_records);

    // Allocate memory for array of Person structs based on number of records
    Person *people = (Person*) malloc(num_records * sizeof(Person));

    // Read in data for each record and store it in the corresponding array element
    for (int i = 0; i < num_records; i++) {
        fscanf(fp, "%d,%[^,],%d\n", &people[i].id, people[i].name, &people[i].age);
    }

    // Close the file
    fclose(fp);

    // Print out the data for all records in the array
    for (int i = 0; i < num_records; i++) {
        printf("Person %d:\n", people[i].id);
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n\n", people[i].age);
    }

    // Give user the option to search for a specific record
    int search_id;
    printf("Enter the ID of the person you would like to search for: ");
    scanf("%d", &search_id);

    // Search for the record with the specified ID
    for (int i = 0; i < num_records; i++) {
        if (people[i].id == search_id) {
            printf("Person %d:\n", people[i].id);
            printf("Name: %s\n", people[i].name);
            printf("Age: %d\n", people[i].age);
            return 0;
        }
    }

    // If no record with specified ID is found, tell the user
    printf("No record with ID %d found.\n", search_id);

    // Free the memory allocated for the array
    free(people);

    return 0;
}