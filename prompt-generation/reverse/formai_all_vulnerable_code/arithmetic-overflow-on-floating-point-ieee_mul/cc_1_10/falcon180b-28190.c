//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
} person;

void add_person(person *p) {
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter weight in kg: ");
    scanf("%f", &p->weight);
    printf("Enter height in cm: ");
    scanf("%f", &p->height);
    p->bmi = p->weight / (p->height * p->height);
}

void display_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Weight: %0.2f kg\n", p.weight);
    printf("Height: %0.2f cm\n", p.height);
    printf("BMI: %0.2f\n", p.bmi);
}

int main() {
    person p;
    int choice;

    do {
        printf("1. Add person\n");
        printf("2. Display person\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_person(&p);
                break;
            case 2:
                display_person(p);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}