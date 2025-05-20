//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information of a person
struct Person {
    char name[100];
    int age;
    char gender[10];
};

// Function to print information of a person
void printPerson(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %s\n", p.gender);
    printf("\n");
}

// Function to query the database
void queryDatabase(char * filename, char * field, char * value) {
    // Open the file for reading
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read each line of the file
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line and store information in a Person struct
        struct Person p;
        sscanf(line, "%s %d %s", p.name, &p.age, p.gender);

        // Check if the field matches the value
        if (strcmp(field, "name") == 0 && strcmp(p.name, value) == 0) {
            printPerson(p);
        } else if (strcmp(field, "age") == 0 && p.age == atoi(value)) {
            printPerson(p);
        } else if (strcmp(field, "gender") == 0 && strcmp(p.gender, value) == 0) {
            printPerson(p);
        }
    }

    // Close the file
    fclose(file);
}

int main() {
    // Create a database with some sample data
    FILE * file = fopen("database.txt", "w");
    fprintf(file, "John 25 Male\n");
    fprintf(file, "Jane 30 Female\n");
    fprintf(file, "Bob 40 Male\n");
    fprintf(file, "Alice 35 Female\n");
    fprintf(file, "Mike 20 Male\n");
    fclose(file);

    // Query the database for persons with name "John"
    printf("Querying database for persons with name \"John\":\n");
    queryDatabase("database.txt", "name", "John");

    // Query the database for persons with age 30
    printf("Querying database for persons with age 30:\n");
    queryDatabase("database.txt", "age", "30");

    // Query the database for persons with gender "Male"
    printf("Querying database for persons with gender \"Male\":\n");
    queryDatabase("database.txt", "gender", "Male");

    return 0;
}