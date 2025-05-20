//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    int weight;
    int height;
    int steps;
} person;

void init_person(person* p) {
    strcpy(p->name, "");
    p->age = 0;
    p->weight = 0;
    p->height = 0;
    p->steps = 0;
}

void print_person(person* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Weight: %d\n", p->weight);
    printf("Height: %d\n", p->height);
    printf("Steps: %d\n", p->steps);
}

int main() {
    person p1, p2;
    init_person(&p1);
    init_person(&p2);

    printf("Enter name of person 1: ");
    scanf("%s", p1.name);
    printf("Enter age of person 1: ");
    scanf("%d", &p1.age);
    printf("Enter weight of person 1: ");
    scanf("%d", &p1.weight);
    printf("Enter height of person 1: ");
    scanf("%d", &p1.height);
    printf("Enter steps of person 1: ");
    scanf("%d", &p1.steps);

    printf("Enter name of person 2: ");
    scanf("%s", p2.name);
    printf("Enter age of person 2: ");
    scanf("%d", &p2.age);
    printf("Enter weight of person 2: ");
    scanf("%d", &p2.weight);
    printf("Enter height of person 2: ");
    scanf("%d", &p2.height);
    printf("Enter steps of person 2: ");
    scanf("%d", &p2.steps);

    printf("Person 1:\n");
    print_person(&p1);
    printf("\n");

    printf("Person 2:\n");
    print_person(&p2);
    printf("\n");

    return 0;
}