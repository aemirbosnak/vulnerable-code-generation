//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char name[50];
    int age;
    float income;
    float expenses;
    float savings;
} person;

void create_person(person *p) {
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter income: ");
    scanf("%f", &p->income);
    printf("Enter expenses: ");
    scanf("%f", &p->expenses);
    printf("Enter savings: ");
    scanf("%f", &p->savings);
}

void display_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Income: $%.2f\n", p.income);
    printf("Expenses: $%.2f\n", p.expenses);
    printf("Savings: $%.2f\n", p.savings);
}

void main() {
    int choice;
    person p;
    do {
        system("clear");
        printf("Post-Apocalyptic Personal Finance Planner\n\n");
        printf("1. Create a new person\n");
        printf("2. Display person's information\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_person(&p);
                printf("Person created successfully!\n");
                break;
            case 2:
                display_person(p);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);
}