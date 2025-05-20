//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
    float weight;
    int height;
} person;

void add_person(person *list, int index, char *name, int age, float weight, int height) {
    strncpy(list[index].name, name, MAX_SIZE);
    list[index].age = age;
    list[index].weight = weight;
    list[index].height = height;
}

void print_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Weight: %.2f\n", p.weight);
    printf("Height: %d\n", p.height);
}

void calculate_bmi(person p) {
    float bmi = p.weight / (p.height * p.height);
    printf("BMI: %.2f\n", bmi);
}

int main() {
    person list[MAX_SIZE];
    int size = 0;
    char input[MAX_SIZE];

    while (1) {
        printf("Enter name: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        add_person(list, size++, input, 0, 0, 0);
    }

    while (1) {
        printf("Enter name to search: ");
        scanf("%s", input);
        for (int i = 0; i < size; i++) {
            if (strcmp(list[i].name, input) == 0) {
                printf("Found person!\n");
                print_person(list[i]);
                calculate_bmi(list[i]);
                break;
            }
        }
    }

    return 0;
}