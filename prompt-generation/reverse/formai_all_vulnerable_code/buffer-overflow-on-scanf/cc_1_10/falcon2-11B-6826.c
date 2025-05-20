//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    double weight;
    double height;
} person;

void add_person(person* person_list, int size, person new_person) {
    if (size == 0) {
        person_list[0] = new_person;
    } else if (size == 1) {
        person_list[1] = new_person;
    } else {
        person_list[size - 1].weight = new_person.weight;
        person_list[size - 1].height = new_person.height;
    }
}

void display_person_list(person* person_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", person_list[i].name);
        printf("Age: %d\n", person_list[i].age);
        printf("Weight: %.2f kg\n", person_list[i].weight);
        printf("Height: %.2f cm\n", person_list[i].height);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = 0;
    person person_list[5];

    printf("Enter the name of the first person: ");
    scanf("%s", person_list[0].name);
    printf("Enter the age of the first person: ");
    scanf("%d", &person_list[0].age);
    printf("Enter the weight of the first person: ");
    scanf("%lf", &person_list[0].weight);
    printf("Enter the height of the first person: ");
    scanf("%lf", &person_list[0].height);
    add_person(person_list, size, person_list[0]);

    printf("Enter the name of the second person: ");
    scanf("%s", person_list[1].name);
    printf("Enter the age of the second person: ");
    scanf("%d", &person_list[1].age);
    printf("Enter the weight of the second person: ");
    scanf("%lf", &person_list[1].weight);
    printf("Enter the height of the second person: ");
    scanf("%lf", &person_list[1].height);
    add_person(person_list, size, person_list[1]);

    printf("Enter the name of the third person: ");
    scanf("%s", person_list[2].name);
    printf("Enter the age of the third person: ");
    scanf("%d", &person_list[2].age);
    printf("Enter the weight of the third person: ");
    scanf("%lf", &person_list[2].weight);
    printf("Enter the height of the third person: ");
    scanf("%lf", &person_list[2].height);
    add_person(person_list, size, person_list[2]);

    printf("Enter the name of the fourth person: ");
    scanf("%s", person_list[3].name);
    printf("Enter the age of the fourth person: ");
    scanf("%d", &person_list[3].age);
    printf("Enter the weight of the fourth person: ");
    scanf("%lf", &person_list[3].weight);
    printf("Enter the height of the fourth person: ");
    scanf("%lf", &person_list[3].height);
    add_person(person_list, size, person_list[3]);

    printf("Enter the name of the fifth person: ");
    scanf("%s", person_list[4].name);
    printf("Enter the age of the fifth person: ");
    scanf("%d", &person_list[4].age);
    printf("Enter the weight of the fifth person: ");
    scanf("%lf", &person_list[4].weight);
    printf("Enter the height of the fifth person: ");
    scanf("%lf", &person_list[4].height);
    add_person(person_list, size, person_list[4]);

    display_person_list(person_list, size);

    return 0;
}