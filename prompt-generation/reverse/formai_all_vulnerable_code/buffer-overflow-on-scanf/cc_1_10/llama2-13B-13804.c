//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to store information about a person
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person;

// Function to read information about a person from the user
void get_person_info(person *person) {
    printf("Enter your name: ");
    fgets(person->name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &person->age);
}

// Function to display information about a person
void display_person_info(person person) {
    printf("Hello, my name is %s and I am %d years old.\n", person.name, person.age);
}

// Function to write information about a person to a file
void write_person_info(person person, FILE *file) {
    fprintf(file, "Hello, my name is %s and I am %d years old.\n", person.name, person.age);
}

int main() {
    person person;
    FILE *file;

    // Open a file for writing
    file = fopen("person_info.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read information about a person from the user
    get_person_info(&person);

    // Display information about the person
    display_person_info(person);

    // Write information about the person to the file
    write_person_info(person, file);

    // Close the file
    fclose(file);

    return 0;
}