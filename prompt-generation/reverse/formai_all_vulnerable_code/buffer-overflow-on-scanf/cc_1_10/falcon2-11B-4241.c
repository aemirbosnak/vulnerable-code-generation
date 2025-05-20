//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
} person;

void add_person(person* people, int size, int weight, int height, char* name) {
    people[size].age = 0;
    people[size].weight = weight;
    people[size].height = height;
    strcpy(people[size].name, name);
    size++;
}

void display_people(person* people, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s\nAge: %d\nWeight: %d\nHeight: %d\n\n", people[i].name, people[i].age, people[i].weight, people[i].height);
    }
}

int main() {
    person people[100];
    int size = 0;

    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        int weight, height, age;
        char name[50];

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter weight: ");
        scanf("%d", &weight);

        printf("Enter height: ");
        scanf("%d", &height);

        add_person(people, size, weight, height, name);

        printf("Do you want to add another person? (y/n)");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'y') {
            break;
        }
    }

    display_people(people, size);

    return 0;
}