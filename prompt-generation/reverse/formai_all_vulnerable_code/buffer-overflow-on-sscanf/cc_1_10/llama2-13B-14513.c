//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure to hold the data
typedef struct {
    char name[50];
    int age;
} person;

// Define the array to store the data
person persons[10];

// Function to read data from the database
void read_database() {
    // Open the database file in read-only mode
    FILE *db = fopen("people.dat", "r");

    // Check if the file is not empty
    if (db == NULL) {
        printf("Error: No data found in the database\n");
        return;
    }

    // Read the data from the file
    char line[100];
    while (fgets(line, 100, db) != NULL) {
        // Parse the data from the line
        person p;
        sscanf(line, "%s %d", p.name, &p.age);

        // Add the data to the array
        persons[sizeof(persons) - 1] = p;
    }

    // Close the database file
    fclose(db);
}

// Function to write data to the database
void write_database() {
    // Open the database file in write-only mode
    FILE *db = fopen("people.dat", "w");

    // Check if the file is not empty
    if (db == NULL) {
        printf("Error: No data found in the database\n");
        return;
    }

    // Write the data to the file
    for (int i = 0; i < sizeof(persons) / sizeof(persons[0]); i++) {
        fprintf(db, "%s %d\n", persons[i].name, persons[i].age);
    }

    // Close the database file
    fclose(db);
}

int main() {
    // Read the data from the database
    read_database();

    // Print the data
    for (int i = 0; i < sizeof(persons) / sizeof(persons[0]); i++) {
        printf("%d. %s\n", i + 1, persons[i].name);
    }

    // Write the data back to the database
    write_database();

    return 0;
}