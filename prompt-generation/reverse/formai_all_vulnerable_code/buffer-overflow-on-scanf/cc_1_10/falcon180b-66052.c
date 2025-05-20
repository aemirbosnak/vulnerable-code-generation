//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

typedef struct {
    char name[MAX_STR_LEN];
    int age;
    int weight;
    int height;
} person_t;

int main() {
    int num_people = 0;
    person_t *people = NULL;

    printf("Welcome to the Fitness Tracker!\n");
    printf("How many people would you like to track? ");
    scanf("%d", &num_people);

    people = (person_t *) malloc(num_people * sizeof(person_t));

    for (int i = 0; i < num_people; i++) {
        printf("Enter the name of person %d: ", i+1);
        scanf("%s", people[i].name);

        printf("Enter the age of %s: ", people[i].name);
        scanf("%d", &people[i].age);

        printf("Enter the weight of %s in pounds: ", people[i].name);
        scanf("%d", &people[i].weight);

        printf("Enter the height of %s in inches: ", people[i].name);
        scanf("%d", &people[i].height);
    }

    printf("\nFitness Tracker Results:\n");

    for (int i = 0; i < num_people; i++) {
        double bmi = (double) people[i].weight / (people[i].height * people[i].height);
        char bmi_category[MAX_STR_LEN];

        if (bmi < 18.5) {
            strcpy(bmi_category, "Underweight");
        } else if (bmi >= 18.5 && bmi < 25) {
            strcpy(bmi_category, "Normal weight");
        } else if (bmi >= 25 && bmi < 30) {
            strcpy(bmi_category, "Overweight");
        } else {
            strcpy(bmi_category, "Obese");
        }

        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Weight: %d pounds\n", people[i].weight);
        printf("Height: %d inches\n", people[i].height);
        printf("BMI: %.2f\n", bmi);
        printf("BMI Category: %s\n\n", bmi_category);
    }

    return 0;
}