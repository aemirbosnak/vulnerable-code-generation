//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int age;
    int weight;
    int height;
} person;

void create_person(person *p) {
    printf("Enter your name: ");
    scanf("%s", p->name);
    printf("Enter your age: ");
    scanf("%d", &p->age);
    printf("Enter your weight (in kg): ");
    scanf("%d", &p->weight);
    printf("Enter your height (in cm): ");
    scanf("%d", &p->height);
}

void display_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Weight (in kg): %d\n", p.weight);
    printf("Height (in cm): %d\n", p.height);
}

int main() {
    person user;
    create_person(&user);
    display_person(user);

    int choice;
    printf("\nWhat would you like to do?\n");
    printf("1. Enter workout details\n");
    printf("2. View workout history\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int duration;
        char exercise[20];
        printf("Enter the duration of your workout (in minutes): ");
        scanf("%d", &duration);
        printf("Enter the type of exercise you did: ");
        scanf("%s", exercise);

        printf("You worked out for %d minutes doing %s.\n", duration, exercise);
    } else if (choice == 2) {
        printf("Workout history:\n");
        // TODO: Implement workout history
    } else if (choice == 3) {
        printf("Exiting...\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}