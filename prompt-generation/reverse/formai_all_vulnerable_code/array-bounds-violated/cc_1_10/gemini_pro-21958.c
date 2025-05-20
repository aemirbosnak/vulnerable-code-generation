//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the database structure
typedef struct {
    int id;
    char name[255];
    int age;
} person;

// Create a database of 10 people
person database[] = {
    {1, "John", 20},
    {2, "Jane", 21},
    {3, "Bob", 22},
    {4, "Alice", 23},
    {5, "Tom", 24},
    {6, "Mary", 25},
    {7, "David", 26},
    {8, "Susan", 27},
    {9, "Mark", 28},
    {10, "Linda", 29}
};

// Get the number of people in the database
int get_num_people() {
    return sizeof(database) / sizeof(person);
}

// Get a person from the database by ID
person* get_person_by_id(int id) {
    for (int i = 0; i < get_num_people(); i++) {
        if (database[i].id == id) {
            return &database[i];
        }
    }
    return NULL;
}

// Add a person to the database
void add_person(person* person) {
    // Get the next available ID
    int next_id = get_num_people() + 1;

    // Set the person's ID
    person->id = next_id;

    // Add the person to the database
    database[next_id - 1] = *person;
}

// Delete a person from the database by ID
void delete_person_by_id(int id) {
    for (int i = 0; i < get_num_people(); i++) {
        if (database[i].id == id) {
            // Shift the remaining people in the database down one
            for (int j = i + 1; j < get_num_people(); j++) {
                database[j - 1] = database[j];
            }
            break;
        }
    }
}

// Print the database
void print_database() {
    for (int i = 0; i < get_num_people(); i++) {
        printf("%d %s %d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Main function
int main() {
    // Create a new person
    person new_person = {11, "John Doe", 30};

    // Add the new person to the database
    add_person(&new_person);

    // Print the database
    print_database();

    // Delete the new person from the database
    delete_person_by_id(11);

    // Print the database
    print_database();

    return 0;
}