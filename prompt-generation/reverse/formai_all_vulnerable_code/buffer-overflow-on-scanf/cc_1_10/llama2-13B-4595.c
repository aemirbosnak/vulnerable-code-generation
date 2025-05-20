//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
typedef struct {
    char name[50];
    int age;
} person;

// Define an array to store database records
person database[10];

// Function to read and write database records
void read_database() {
    int i;
    printf("Enter name and age: ");
    for (i = 0; i < 10; i++) {
        scanf("%s %d", database[i].name, &database[i].age);
        printf("Record %d: %s (%d years old)\n", i + 1, database[i].name, database[i].age);
    }
}

// Function to search for a record in the database
int search_database(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, name) == 0) {
            return i + 1; // Return the record number if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to update a record in the database
void update_database(int record_number, char *new_name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (record_number == i + 1) {
            strcpy(database[i].name, new_name);
            printf("Record %d: %s (%d years old)\n", i + 1, new_name, database[i].age);
            return;
        }
    }
    printf("Record not found\n");
}

// Function to delete a record from the database
void delete_database(int record_number) {
    int i;
    for (i = 0; i < 10; i++) {
        if (record_number == i + 1) {
            // Remove the record from the array
            memmove(&database[i], &database[i + 1], (10 - i - 1) * sizeof(person));
            printf("Record %d deleted\n", record_number);
            return;
        }
    }
    printf("Record not found\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Initialize the database with some sample records
    for (int i = 0; i < 10; i++) {
        database[i].name[0] = 'A' + (rand() % 26); // Generate a random name
        database[i].age = rand() % 100 + 1; // Generate a random age
        printf("Record %d: %s (%d years old)\n", i + 1, database[i].name, database[i].age);
    }

    // Read and write database records
    read_database();

    // Search for a record in the database
    int found = search_database("Alice");
    if (found != -1) {
        update_database(found, "Bob");
    } else {
        printf("Record not found\n");
    }

    // Delete a record from the database
    delete_database(5);

    return 0;
}