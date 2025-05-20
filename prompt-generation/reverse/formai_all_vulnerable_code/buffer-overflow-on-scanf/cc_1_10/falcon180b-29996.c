//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    int weight;
    int height;
} Person;

void add_person(Person *people, int num_people) {
    char name[MAX_SIZE];
    int age, weight, height;

    printf("Enter person's name: ");
    scanf("%s", name);

    printf("Enter person's age: ");
    scanf("%d", &age);

    printf("Enter person's weight: ");
    scanf("%d", &weight);

    printf("Enter person's height: ");
    scanf("%d", &height);

    strcpy(people[num_people].name, name);
    people[num_people].age = age;
    people[num_people].weight = weight;
    people[num_people].height = height;

    num_people++;
}

void display_people(Person *people, int num_people) {
    printf("\nName\tAge\tWeight\tHeight\n");

    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\t%d\t%d\n", people[i].name, people[i].age, people[i].weight, people[i].height);
    }
}

void calculate_bmi(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        float bmi = (float)people[i].weight / (people[i].height * people[i].height);
        printf("%s's BMI is: %.2f\n", people[i].name, bmi);
    }
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (true) {
        printf("\nEnter 1 to add a person\nEnter 2 to display people\nEnter 3 to calculate BMI\nEnter 4 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_people >= MAX_SIZE) {
                printf("Maximum number of people reached.\n");
            } else {
                add_person(people, num_people);
            }
            break;

        case 2:
            display_people(people, num_people);
            break;

        case 3:
            calculate_bmi(people, num_people);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}