//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100
#define MAX_GPA 4.0

struct person {
    char name[MAX_NAME_LEN];
    int age;
    double gpa;
};

int main() {
    struct person person1, person2, person3;
    int choice;

    // Initialize person1
    strcpy(person1.name, "Alice");
    person1.age = 25;
    person1.gpa = 3.5;

    // Initialize person2
    strcpy(person2.name, "Bob");
    person2.age = 30;
    person2.gpa = 4.2;

    // Initialize person3
    strcpy(person3.name, "Charlie");
    person3.age = 35;
    person3.gpa = 3.8;

    // Display initial values
    printf("Person 1:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("GPA: %f\n", person1.gpa);

    printf("\nPerson 2:\n");
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);
    printf("GPA: %f\n", person2.gpa);

    printf("\nPerson 3:\n");
    printf("Name: %s\n", person3.name);
    printf("Age: %d\n", person3.age);
    printf("GPA: %f\n", person3.gpa);

    // Ask user for input
    printf("Enter choice (1, 2, or 3): ");
    scanf("%d", &choice);

    // Handle user input
    switch (choice) {
        case 1:
            // Do something with person1
            printf("You have chosen to work with person1:\n");
            printf("Name: %s\n", person1.name);
            printf("Age: %d\n", person1.age);
            printf("GPA: %f\n", person1.gpa);
            break;

        case 2:
            // Do something with person2
            printf("You have chosen to work with person2:\n");
            printf("Name: %s\n", person2.name);
            printf("Age: %d\n", person2.age);
            printf("GPA: %f\n", person2.gpa);
            break;

        case 3:
            // Do something with person3
            printf("You have chosen to work with person3:\n");
            printf("Name: %s\n", person3.name);
            printf("Age: %d\n", person3.age);
            printf("GPA: %f\n", person3.gpa);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}