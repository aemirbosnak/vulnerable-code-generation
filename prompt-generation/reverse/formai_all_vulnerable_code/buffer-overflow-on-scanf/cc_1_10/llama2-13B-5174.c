//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100
#define MIN_AGE 18

struct person {
    char name[MAX_NAME_LEN];
    int age;
};

int main() {
    struct person person1, person2, person3;
    char choice;

    // Initialize person1
    strcpy(person1.name, "Alice");
    person1.age = 25;

    // Initialize person2
    strcpy(person2.name, "Bob");
    person2.age = 30;

    // Initialize person3
    strcpy(person3.name, "Charlie");
    person3.age = 35;

    // Print names and ages
    printf("Person 1: %s, age %d\n", person1.name, person1.age);
    printf("Person 2: %s, age %d\n", person2.name, person2.age);
    printf("Person 3: %s, age %d\n", person3.name, person3.age);

    // Get user input
    printf("Please enter a choice (1, 2, or 3): ");
    scanf("%d", &choice);

    // Conditional statements based on user input
    if (choice == 1) {
        // Print "Alice is the oldest."
        printf("Alice is the oldest.%s", person1.name);
    } else if (choice == 2) {
        // Print "Bob is the youngest."
        printf("Bob is the youngest.%s", person2.name);
    } else {
        // Print "Charlie is the middle child."
        printf("Charlie is the middle child.%s", person3.name);
    }

    // Print a final message
    printf("Goodbye!%s", person1.name);

    return 0;
}