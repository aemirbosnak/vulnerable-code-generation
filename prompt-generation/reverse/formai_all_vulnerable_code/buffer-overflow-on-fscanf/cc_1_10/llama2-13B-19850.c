//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <assert.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100
#define MIN_AGE 18
#define MAX_HEIGHT 200
#define MIN_HEIGHT 150

// Define a structure to hold the data
struct person {
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
};

// Function to read data from a file
struct person read_data(FILE *file) {
    struct person person;
    char line[1024];

    // Read name, age, and height from file
    fscanf(file, "%s %d %f", line, &person.age, &person.height);

    // Return the person struct
    return person;
}

// Function to write data to a file
void write_data(struct person person, FILE *file) {
    char line[1024];

    // Format name, age, and height for writing
    sprintf(line, "%s %d %f", person.name, person.age, person.height);

    // Write to file
    fprintf(file, "%s", line);
}

int main() {
    // Open data file
    FILE *file = fopen("happy_data.txt", "r");

    // Check if file open failed
    if (file == NULL) {
        printf("Error opening file happy_data.txt\n");
        return 1;
    }

    // Read data from file
    struct person person;
    while (1) {
        person = read_data(file);

        // Check if EOF reached
        if (feof(file)) break;

        // Print data
        printf("Name: %s, Age: %d, Height: %f\n", person.name, person.age, person.height);
    }

    // Close file
    fclose(file);

    // Open data file again for writing
    file = fopen("happy_data.txt", "w");

    // Check if file open failed
    if (file == NULL) {
        printf("Error opening file happy_data.txt for writing\n");
        return 2;
    }

    // Write data to file
    struct person happy_person = {
        .name = "Happy",
        .age = 27,
        .height = 180.5f
    };
    write_data(happy_person, file);

    // Close file
    fclose(file);

    return 0;
}