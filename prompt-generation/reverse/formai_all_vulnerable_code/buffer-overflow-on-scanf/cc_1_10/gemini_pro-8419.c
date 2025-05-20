//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    int id;
    char name[256];
    double value;
} record;

// Define the database
record database[] = {
    { 1, "John Doe", 100.0 },
    { 2, "Jane Smith", 200.0 },
    { 3, "Bill Jones", 300.0 },
    { 4, "Mary Johnson", 400.0 },
    { 5, "Bob Brown", 500.0 }
};

// Define the number of records in the database
const int num_records = sizeof(database) / sizeof(record);

// Define the query function
double query(const char *name) {
    // Iterate over the database
    for (int i = 0; i < num_records; i++) {
        // Check if the name matches the query
        if (strcmp(database[i].name, name) == 0) {
            // Return the value
            return database[i].value;
        }
    }

    // Return -1 if the name is not found
    return -1.0;
}

// Define the main function
int main() {
    // Get the name from the user
    char name[256];
    printf("Enter the name: ");
    scanf("%s", name);

    // Query the database
    double value = query(name);

    // Print the result
    if (value >= 0.0) {
        printf("The value for %s is %f\n", name, value);
    } else {
        printf("The name %s is not found in the database\n", name);
    }

    return 0;
}