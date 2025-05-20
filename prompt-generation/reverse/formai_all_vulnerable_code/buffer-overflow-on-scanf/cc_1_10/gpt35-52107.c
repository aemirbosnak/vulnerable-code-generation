//FormAI DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for a database entry
typedef struct {
    int id;
    char name[20];
    int age;
} Entry;

// Define the database as an array of Entries
Entry database[] = {
    {1, "John Smith", 34},
    {2, "Jane Doe", 27},
    {3, "Bob Johnson", 42},
    {4, "Alice Brown", 19},
    {5, "Max Williams", 56}
};

// Define a function to retrieve an Entry by its id
Entry getEntryById(int id) {
    for (int i = 0; i < 5; i++) {
        if (database[i].id == id) {
            return database[i];
        }
    }
    
    // If the id was not found, return an empty Entry
    Entry empty = {0, "", 0};
    return empty;
}

int main() {
    // Print a welcome message
    printf("Welcome to the Database Querying Program\n");
    printf("=======================================\n\n");
    
    // Prompt the user for an id
    printf("Enter an id to retrieve an Entry: ");
    int id;
    scanf("%d", &id);
    
    // Retrieve the Entry with the given id
    Entry entry = getEntryById(id);
    
    // Check if the entry is valid
    if (entry.id == 0) {
        printf("No Entry found with id %d\n", id);
    } else {
        // Print the details of the Entry
        printf("\nEntry Details\n");
        printf("===========================\n");
        printf("ID: %d\n", entry.id);
        printf("Name: %s\n", entry.name);
        printf("Age: %d\n", entry.age);
    }
    
    // Exit the program
    return 0;
}