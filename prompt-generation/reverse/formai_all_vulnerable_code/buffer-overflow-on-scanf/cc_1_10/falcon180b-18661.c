//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    int age;
    float weight;
    int steps;
} person;

void create_person(person *p) {
    printf("Enter name: ");
    scanf("%s", p->name);

    printf("Enter age: ");
    scanf("%d", &p->age);

    printf("Enter weight (in kg): ");
    scanf("%f", &p->weight);

    printf("Enter number of steps taken today: ");
    scanf("%d", &p->steps);
}

void display_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Weight: %0.2f kg\n", p.weight);
    printf("Steps taken today: %d\n", p.steps);
}

void update_steps(person *p) {
    printf("Enter new number of steps taken today: ");
    scanf("%d", &p->steps);
}

int main() {
    person user;
    char choice;

    do {
        printf("\nFitness Tracker\n");
        printf("1. Create a new person\n");
        printf("2. Display person details\n");
        printf("3. Update number of steps taken today\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Creating a new person...\n");
                create_person(&user);
                printf("Person created successfully!\n");
                break;

            case '2':
                printf("Displaying person details...\n");
                display_person(user);
                break;

            case '3':
                printf("Updating number of steps taken today...\n");
                update_steps(&user);
                printf("Steps updated successfully!\n");
                break;

            case '4':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '4');

    return 0;
}