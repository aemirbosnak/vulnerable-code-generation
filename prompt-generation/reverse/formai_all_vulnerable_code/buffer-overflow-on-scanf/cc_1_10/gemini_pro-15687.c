//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    char name[50];
    int age;
    char address[100];
    char phone[20];
} person;

// Define the database
person database[] = {
    {"John Smith", 30, "123 Main Street", "555-1212"},
    {"Jane Doe", 25, "456 Elm Street", "555-1213"},
    {"Bill Jones", 40, "789 Oak Street", "555-1214"},
    {"Mary Brown", 35, "1011 Pine Street", "555-1215"}
};

// Define the number of records in the database
#define NUM_RECORDS (sizeof(database) / sizeof(person))

// Main function
int main() {
    // Get the user's input
    char name[50];
    printf("Enter the name of the person you want to find: ");
    scanf("%s", name);

    // Search the database for the person
    int found = 0;
    for (int i = 0; i < NUM_RECORDS; i++) {
        if (strcmp(database[i].name, name) == 0) {
            // Person found
            found = 1;

            // Print the person's information
            printf("\nName: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Address: %s\n", database[i].address);
            printf("Phone: %s\n", database[i].phone);
            break;
        }
    }

    // If the person was not found, print an error message
    if (!found) {
        printf("Person not found.\n");
    }

    return 0;
}