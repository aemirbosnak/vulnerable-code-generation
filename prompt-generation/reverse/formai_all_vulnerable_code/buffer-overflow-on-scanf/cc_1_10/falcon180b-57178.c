//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
    float weight;
} person;

void create_person(person* p) {
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter height (in cm): ");
    scanf("%f", &p->height);
    printf("Enter weight (in kg): ");
    scanf("%f", &p->weight);
}

void display_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %0.2f cm\n", p.height);
    printf("Weight: %0.2f kg\n", p.weight);
}

int main() {
    person user;
    char choice;

    do {
        printf("\nFitness Tracker\n");
        printf("1. Create a new person\n");
        printf("2. Display person details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                create_person(&user);
                break;
            case '2':
                display_person(user);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '3');

    return 0;
}