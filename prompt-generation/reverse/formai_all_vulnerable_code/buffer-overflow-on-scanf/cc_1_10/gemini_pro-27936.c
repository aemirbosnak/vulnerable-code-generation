//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// Define the database structure
typedef struct {
    int id;
    char *name;
    int age;
} Person;

// Define the database
Person database[] = {
    { 1, "John", 30 },
    { 2, "Jane", 25 },
    { 3, "Bob", 40 },
    { 4, "Alice", 35 },
    { 5, "Tom", 28 },
};

// Define the query function
int query(const char *name, int *age) {
    // Iterate over the database
    for (int i = 0; i < sizeof(database) / sizeof(database[0]); i++) {
        // Check if the name matches
        if (strcmp(database[i].name, name) == 0) {
            // Return the age if the name matches
            *age = database[i].age;
            return 0;
        }
    }

    // Return -1 if the name is not found
    return -1;
}

// Define the main function
int main() {
    // Define the name and age variables
    char name[256];
    int age;

    // Get the name from the user
    printf("Enter the name: ");
    scanf("%s", name);

    // Query the database
    int result = query(name, &age);

    // Check the result
    if (result == 0) {
        // Print the age if the name is found
        printf("The age of %s is %d\n", name, age);
    } else {
        // Print an error message if the name is not found
        printf("The name %s is not found\n", name);
    }

    return 0;
}