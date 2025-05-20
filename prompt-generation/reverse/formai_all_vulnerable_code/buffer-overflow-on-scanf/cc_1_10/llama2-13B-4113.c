//LLAMA2-13B DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 256
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LEN];
    int age;
};

void init_name(struct person *person) {
    printf("Enter your name: ");
    fgets(person->name, MAX_NAME_LEN, stdin);
}

void init_age(struct person *person) {
    printf("Enter your age: ");
    scanf("%d", &person->age);
}

void print_person(struct person person) {
    printf("Hello, my name is %s and I am %d years old.\n", person.name, person.age);
}

int main() {
    struct person person;

    // Initialize name and age
    init_name(&person);
    init_age(&person);

    // Print the person's information
    print_person(person);

    // Ask the user for their favorite color
    printf("What is your favorite color? ");
    char favorite_color[50];
    fgets(favorite_color, 50, stdin);

    // Update the person's information
    person.name[strcspn(person.name, "\n")] = 0; // Remove the newline character
    strcat(person.name, " enjoys ");
    strcat(person.name, favorite_color);

    // Print the updated person's information
    print_person(person);

    return 0;
}