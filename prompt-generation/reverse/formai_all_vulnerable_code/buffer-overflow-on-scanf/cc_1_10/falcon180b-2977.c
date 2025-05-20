//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_HEALTH_POINTS 100
#define MAX_ENERGY_POINTS 100
#define MAX_STEPS 10000

typedef struct {
    char name[50];
    int age;
    int health_points;
    int energy_points;
    int steps;
} person;

void initialize_person(person *p) {
    strcpy(p->name, "");
    p->age = 0;
    p->health_points = MAX_HEALTH_POINTS;
    p->energy_points = MAX_ENERGY_POINTS;
    p->steps = 0;
}

void display_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Health Points: %d\n", p.health_points);
    printf("Energy Points: %d\n", p.energy_points);
    printf("Steps: %d\n", p.steps);
}

void update_health_points(person *p, int hp) {
    if (hp >= 0 && hp <= MAX_HEALTH_POINTS) {
        p->health_points += hp;
    }
}

void update_energy_points(person *p, int ep) {
    if (ep >= 0 && ep <= MAX_ENERGY_POINTS) {
        p->energy_points += ep;
    }
}

void update_steps(person *p, int s) {
    if (s >= 0 && s <= MAX_STEPS) {
        p->steps += s;
    }
}

int main() {
    person user;
    initialize_person(&user);

    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Update Health Points\n");
        printf("2. Update Energy Points\n");
        printf("3. Update Steps\n");
        printf("4. Display Stats\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of health points to update: ");
                int hp;
                scanf("%d", &hp);
                update_health_points(&user, hp);
                break;
            case 2:
                printf("Enter the number of energy points to update: ");
                int ep;
                scanf("%d", &ep);
                update_energy_points(&user, ep);
                break;
            case 3:
                printf("Enter the number of steps to update: ");
                int s;
                scanf("%d", &s);
                update_steps(&user, s);
                break;
            case 4:
                display_person(user);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}