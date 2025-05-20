//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
    float weight;
    int height;
    int bmi;
    int heart_rate;
} person;

void add_person(person *people, int *num_people) {
    printf("Enter name: ");
    scanf("%s", people[*num_people].name);

    printf("Enter age: ");
    scanf("%d", &people[*num_people].age);

    printf("Enter weight (in kg): ");
    scanf("%f", &people[*num_people].weight);

    printf("Enter height (in cm): ");
    scanf("%d", &people[*num_people].height);

    people[*num_people].bmi = (people[*num_people].weight / (people[*num_people].height / 100.0)) * 100;
    people[*num_people].heart_rate = 220 - people[*num_people].age;

    (*num_people)++;
}

void display_person(person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight (in kg): %f\n", person.weight);
    printf("Height (in cm): %d\n", person.height);
    printf("BMI: %.2f\n", person.bmi);
    printf("Heart Rate: %d\n", person.heart_rate);
}

void display_people(person people[], int num_people) {
    printf("Number of people: %d\n", num_people);
    for (int i = 0; i < num_people; i++) {
        display_person(people[i]);
    }
}

int main() {
    person people[MAX_SIZE];
    int num_people = 0;

    add_person(people, &num_people);

    display_people(people, num_people);

    return 0;
}