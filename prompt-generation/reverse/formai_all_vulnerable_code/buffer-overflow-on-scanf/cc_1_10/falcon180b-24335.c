//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    char name[20];
    int age;
    int height;
    int weight;
} Person;

typedef struct {
    Person data[MAX_SIZE];
    int size;
} People;

void print_person(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %d\n", p.height);
    printf("Weight: %d\n", p.weight);
}

void print_people(People p) {
    int i;
    printf("Number of people: %d\n", p.size);
    for (i = 0; i < p.size; i++) {
        print_person(p.data[i]);
    }
}

int main() {
    People p;
    p.size = 0;
    int choice;
    char name[20];
    int age, height, weight;

    do {
        printf("1. Add person\n");
        printf("2. Print people\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name (max 20 characters): ");
                scanf("%s", p.data[p.size].name);
                printf("Enter age: ");
                scanf("%d", &p.data[p.size].age);
                printf("Enter height (in cm): ");
                scanf("%d", &p.data[p.size].height);
                printf("Enter weight (in kg): ");
                scanf("%d", &p.data[p.size].weight);
                p.size++;
                break;
            case 2:
                print_people(p);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}