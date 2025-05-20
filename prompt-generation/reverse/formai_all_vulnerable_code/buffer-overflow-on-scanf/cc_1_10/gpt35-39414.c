//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

// Define a struct to hold the database record information
typedef struct {
    int id;
    char name[30];
    int age;
} Record;

// Define the database
Record database[100];

// Define global variables to keep track of the number of records and the next free index in the database
int num_records = 0;
int next_free_index = 0;

// Define a function to add a record to the database
void add_record(int id, char* name, int age) {
    // Check that there is space in the database
    if (next_free_index >= 100) {
        printf("Error: Database is full\n");
        return;
    }
    // Create the new record
    Record new_record;
    new_record.id = id;
    strcpy(new_record.name, name);
    new_record.age = age;
    // Add the new record to the database
    database[next_free_index] = new_record;
    num_records++;
    next_free_index++;
}

// Define a function to search for a record by ID
Record* find_record(int id) {
    // Loop through all records in the database
    for (int i = 0; i < num_records; i++) {
        // Check if the ID matches
        if (database[i].id == id) {
            // Return a pointer to the record in the database array
            return &database[i];
        }
    }
    // If no record is found, return NULL
    return NULL;
}

// Define a function to remove a record from the database by ID
void remove_record(int id) {
    // Loop through all records in the database
    for (int i = 0; i < num_records; i++) {
        // Check if the ID matches
        if (database[i].id == id) {
            // Move all subsequent records one position back in the database array
            for (int j = i; j < num_records - 1; j++) {
                database[j] = database[j+1];
            }
            // Decrement the number of records and next free index
            num_records--;
            next_free_index--;
            // Print a message indicating success
            printf("Record with ID %d removed from the database\n", id);
            return;
        }
    }
    // If no record is found, print an error message
    printf("Error: Record with ID %d not found in the database\n", id);
}

// Define a function to print all records in the database
void print_database() {
    printf("ID\tName\t\tAge\n");
    printf("--\t----\t\t---\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Define a pthread function to add a record to the database
void* add_record_thread(void* arg) {
    int id = *(int*)arg;
    char name[30];
    int age;
    printf("Enter name and age for record with ID %d: ", id);
    scanf("%s %d", name, &age);
    add_record(id, name, age);
}

// Define a pthread function to find a record in the database
void* find_record_thread(void* arg) {
    int id = *(int*)arg;
    Record* record = find_record(id);
    if (record != NULL) {
        printf("Record with ID %d found in the database: %s, %d years old\n", id, record->name, record->age);
    } else {
        printf("Error: Record with ID %d not found in the database\n", id);
    }
}

// Define a pthread function to remove a record from the database
void* remove_record_thread(void* arg) {
    int id = *(int*)arg;
    remove_record(id);
}

int main() {
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};
    // Create three threads to interact with the database
    pthread_create(&threads[0], NULL, add_record_thread, &ids[0]);
    pthread_create(&threads[1], NULL, find_record_thread, &ids[1]);
    pthread_create(&threads[2], NULL, remove_record_thread, &ids[2]);
    // Wait for the threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    // Print the final state of the database
    printf("Final state of the database:\n");
    print_database();
    return 0;
}