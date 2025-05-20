//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
    char name[32];
    int age;
    char city[32];
} Person;

// Database
Person database[] = {
    {"John", 30, "New York"},
    {"Mary", 25, "Los Angeles"},
    {"Bob", 28, "Chicago"},
    {"Alice", 22, "Houston"},
    {"Tom", 32, "Dallas"}
};

// Number of records in the database
int num_records = sizeof(database) / sizeof(Person);

// Main function
int main() {
    // Print the database
    printf("Database:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s, %d, %s\n", database[i].name, database[i].age, database[i].city);
    }

    // Get a name from the user
    char name[32];
    printf("Enter a name: ");
    scanf("%s", name);

    // Search for the name in the database
    int found = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    // Print the result
    if (found) {
        printf("Name found in the database.\n");
    } else {
        printf("Name not found in the database.\n");
    }

    return 0;
}