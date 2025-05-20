//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int height;
    int weight;
    int steps;
} Person;

void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %d\n", person->height);
    printf("Weight: %d\n", person->weight);
    printf("Steps: %d\n", person->steps);
}

void add_person(Person* person, char* name, int age, int height, int weight, int steps) {
    strcpy(person->name, name);
    person->age = age;
    person->height = height;
    person->weight = weight;
    person->steps = steps;
}

int main() {
    Person* people[10];
    int num_people = 0;

    while (num_people < 10) {
        char name[50];
        int age, height, weight, steps;
        printf("Enter the name of the person: ");
        scanf("%s", name);
        printf("Enter the age of the person: ");
        scanf("%d", &age);
        printf("Enter the height of the person in cm: ");
        scanf("%d", &height);
        printf("Enter the weight of the person in kg: ");
        scanf("%d", &weight);
        printf("Enter the number of steps taken by the person: ");
        scanf("%d", &steps);

        Person person;
        add_person(&person, name, age, height, weight, steps);
        people[num_people] = &person;
        num_people++;

        printf("\n");
    }

    srand(time(NULL));
    int random_person = rand() % num_people;

    Person* selected_person = people[random_person];

    print_person(selected_person);
    printf("\n");

    return 0;
}