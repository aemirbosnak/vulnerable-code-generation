//LLAMA2-13B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_NAME_LENGTH 32
#define MAX_AGE 100

// Structure to hold a person's name and age
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person;

// Function to generate a random name
void generate_name(person *person) {
    int i, j;
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        person->name[i] = 'a' + (rand() % 26);
    }
}

// Function to calculate and print the person's age in years, months, and days
void print_age(person *person) {
    int age_years = person->age / 365;
    int age_months = (person->age % 365) / 30;
    int age_days = (person->age % 30) % 365;
    printf("Age: %d years, %d months, %d days\n", age_years, age_months, age_days);
}

int main() {
    // Create a person structure
    person person = {
        .name = "John",
        .age = 35
    };

    // Generate a random name
    generate_name(&person);

    // Print the person's age
    print_age(&person);

    // Get the person's name and age from the user
    printf("Enter your name: ");
    fgets(person.name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &person.age);

    // Generate a random name again
    generate_name(&person);

    // Print the person's age again
    print_age(&person);

    return 0;
}