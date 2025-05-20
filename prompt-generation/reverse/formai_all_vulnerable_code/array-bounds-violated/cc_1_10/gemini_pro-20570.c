//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    int id;
    char name[256];
    int age;
    char address[256];
} Person;

// Define the database
Person database[] = {
    { 1, "John Doe", 30, "123 Main Street" },
    { 2, "Jane Doe", 25, "456 Elm Street" },
    { 3, "John Smith", 40, "789 Oak Street" },
    { 4, "Jane Smith", 35, "1011 Pine Street" }
};

// Define the size of the database
int database_size = sizeof(database) / sizeof(database[0]);

// Print the database
void print_database() {
    for (int i = 0; i < database_size; i++) {
        printf("%d %s %d %s\n", database[i].id, database[i].name, database[i].age, database[i].address);
    }
}

// Add a person to the database
void add_person(Person person) {
    database[database_size++] = person;
}

// Delete a person from the database
void delete_person(int id) {
    for (int i = 0; i < database_size; i++) {
        if (database[i].id == id) {
            database[i] = database[database_size-- - 1];
            break;
        }
    }
}

// Update a person in the database
void update_person(Person person) {
    for (int i = 0; i < database_size; i++) {
        if (database[i].id == person.id) {
            database[i] = person;
            break;
        }
    }
}

// Main function
int main() {
    // Print the database
    printf("Initial database:\n");
    print_database();

    // Add a person to the database
    Person new_person = { 5, "John Jones", 28, "1234 Maple Street" };
    add_person(new_person);

    // Print the database
    printf("\nDatabase after adding a person:\n");
    print_database();

    // Delete a person from the database
    delete_person(2);

    // Print the database
    printf("\nDatabase after deleting a person:\n");
    print_database();

    // Update a person in the database
    Person updated_person = { 1, "John Doe", 35, "123 Main Street, Apt. 1" };
    update_person(updated_person);

    // Print the database
    printf("\nDatabase after updating a person:\n");
    print_database();

    return 0;
}