//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
    float weight;
    float bmi;
} Person;

void addPerson(Person *people, int *numPeople) {
    printf("Enter name: ");
    scanf("%s", people[*numPeople].name);

    printf("Enter age: ");
    scanf("%d", &people[*numPeople].age);

    printf("Enter height (in cm): ");
    scanf("%f", &people[*numPeople].height);

    printf("Enter weight (in kg): ");
    scanf("%f", &people[*numPeople].weight);

    people[*numPeople].bmi = people[*numPeople].weight / (people[*numPeople].height * people[*numPeople].height);

    (*numPeople)++;
}

void displayPeople(Person *people, int numPeople) {
    printf("Name\tAge\tHeight\tWeight\tBMI\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s\t%d\t%.2f\t%.2f\t%.2f\n", people[i].name, people[i].age, people[i].height, people[i].weight, people[i].bmi);
    }
}

void sortByAge(Person *people, int numPeople) {
    for (int i = 0; i < numPeople - 1; i++) {
        for (int j = i + 1; j < numPeople; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

void sortByBMI(Person *people, int numPeople) {
    for (int i = 0; i < numPeople - 1; i++) {
        for (int j = i + 1; j < numPeople; j++) {
            if (people[i].bmi > people[j].bmi) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int main() {
    Person people[MAX_SIZE];
    int numPeople = 0;

    while (1) {
        printf("1. Add person\n2. Display people\n3. Sort by age\n4. Sort by BMI\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPerson(people, &numPeople);
            break;
        case 2:
            displayPeople(people, numPeople);
            break;
        case 3:
            sortByAge(people, numPeople);
            displayPeople(people, numPeople);
            break;
        case 4:
            sortByBMI(people, numPeople);
            displayPeople(people, numPeople);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}