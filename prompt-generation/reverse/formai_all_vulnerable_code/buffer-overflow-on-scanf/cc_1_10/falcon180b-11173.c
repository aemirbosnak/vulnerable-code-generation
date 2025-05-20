//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float weight;
    float height;
    float bmi;
} Person;

void addPerson(Person *people, int *size) {
    printf("Enter name: ");
    scanf("%s", people[*size].name);
    printf("Enter age: ");
    scanf("%d", &people[*size].age);
    printf("Enter weight: ");
    scanf("%f", &people[*size].weight);
    printf("Enter height: ");
    scanf("%f", &people[*size].height);
    people[*size].bmi = people[*size].weight / (people[*size].height * people[*size].height);
    printf("BMI: %f\n", people[*size].bmi);
    (*size)++;
}

void displayPeople(Person *people, int size) {
    printf("Name\tAge\tWeight\tHeight\tBMI\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%.2f\t%.2f\t%.2f\n", people[i].name, people[i].age, people[i].weight, people[i].height, people[i].bmi);
    }
}

int main() {
    Person people[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("1. Add person\n2. Display people\n3. Exit\n");
        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPerson(people, &size);
                break;
            case 2:
                displayPeople(people, size);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}