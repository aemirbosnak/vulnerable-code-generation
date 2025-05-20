//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Declare a struct to represent metadata
typedef struct {
    int id;
    char *name;
    int age;
} Person;

// Create a function to extract metadata from a file
Person *extract_metadata(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    // Read the first line of the file, which contains the id
    int id;
    if (fscanf(file, "%d\n", &id) != 1) {
        fclose(file);
        return NULL;
    }

    // Read the second line of the file, which contains the name
    char *name = NULL;
    size_t name_len = 0;
    if (getline(&name, &name_len, file) == -1) {
        fclose(file);
        return NULL;
    }

    // Read the third line of the file, which contains the age
    int age;
    if (fscanf(file, "%d\n", &age) != 1) {
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Create a new Person struct and populate it with the extracted metadata
    Person *person = malloc(sizeof(Person));
    person->id = id;
    person->name = name;
    person->age = age;

    // Return the Person struct
    return person;
}

// Create a function to print the metadata of a Person struct
void print_metadata(Person *person) {
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Create a function to free the memory allocated for a Person struct
void free_metadata(Person *person) {
    free(person->name);
    free(person);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename was provided as an argument
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Extract the metadata from the file
    Person *person = extract_metadata(argv[1]);
    if (!person) {
        printf("Error: Could not extract metadata from file.\n");
        return 1;
    }

    // Print the metadata
    print_metadata(person);

    // Free the memory allocated for the Person struct
    free_metadata(person);

    return 0;
}