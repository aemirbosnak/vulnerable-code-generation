//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
    char *name;
    char *email;
    int age;
} Person;

// Database array
Person database[] = {
    {"John Doe", "john.doe@example.com", 30},
    {"Jane Doe", "jane.doe@example.com", 25},
    {"Bob Smith", "bob.smith@example.com", 40},
    {"Alice Jones", "alice.jones@example.com", 35},
};

// Database size
#define DATABASE_SIZE (sizeof(database) / sizeof(Person))

// Main function
int main() {
    // User input
    char name[256];
    printf("Enter a name: ");
    scanf("%s", name);

    // Search the database
    int found = 0;
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i].name, name) == 0) {
            // Found the person
            found = 1;

            // Print the person's information
            printf("Name: %s\n", database[i].name);
            printf("Email: %s\n", database[i].email);
            printf("Age: %d\n", database[i].age);

            break;
        }
    }

    // Not found
    if (!found) {
        printf("Person not found.\n");
    }

    return 0;
}