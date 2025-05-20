//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[50];
    int age;
    float height;
    float weight;
    float goal_weight;
    float bmi;
};

struct exercise {
    char name[50];
    int calories_burnt;
};

int main() {
    struct user u;
    struct exercise e[5];
    int num_exercises = 5;
    int total_calories_burnt = 0;
    int i;

    /* Set user's info */
    printf("Enter your name: ");
    fgets(u.name, 50, stdin);
    printf("Enter your age: ");
    scanf("%d", &u.age);
    printf("Enter your height in meters: ");
    scanf("%f", &u.height);
    printf("Enter your weight in kilograms: ");
    scanf("%f", &u.weight);
    printf("Enter your goal weight in kilograms: ");
    scanf("%f", &u.goal_weight);

    /* Calculate user's BMI */
    u.bmi = (u.weight) / (u.height * u.height);

    /* Set exercises */
    strncpy(e[0].name, "Running", 50);
    e[0].calories_burnt = 500;
    strncpy(e[1].name, "Yoga", 50);
    e[1].calories_burnt = 200;
    strncpy(e[2].name, "Swimming", 50);
    e[2].calories_burnt = 300;
    strncpy(e[3].name, "Cycling", 50);
    e[3].calories_burnt = 400;
    strncpy(e[4].name, "Weight lifting", 50);
    e[4].calories_burnt = 250;

    /* Print user's info */
    printf("\nHi %s", u.name);
    printf("Age: %d\n", u.age);
    printf("Height: %.2f meters\n", u.height);
    printf("Weight: %.2f kilograms\n", u.weight);
    printf("Goal weight: %.2f kilograms\n", u.goal_weight);
    printf("\nYour BMI is: %.2f\n", u.bmi);

    /* Print exercises */
    printf("\nList of exercises:\n");
    for (i = 0; i < num_exercises; i++) {
        printf("%d. %s (%d calories burnt)\n", i+1, e[i].name, e[i].calories_burnt);
    }

    /* Taking input from user */
    printf("\nEnter the exercise number you have done: ");
    int ex_number;
    scanf("%d", &ex_number);

    /* Calculating the total calories burnt */
    total_calories_burnt = e[ex_number-1].calories_burnt;

    /* Printing the total calories burnt */
    printf("\nYou burnt %d calories.\n", total_calories_burnt);

    /* Calculating the weight lost */
    float weight_diff = u.weight - u.goal_weight;
    float calories_to_lose_weight = weight_diff * 7700;

    /* Printing the weight lost */
    printf("\nYou need to burn %0.2f calories to reach your goal weight.\n", calories_to_lose_weight);

    /* Bye message */
    printf("\nThanks for using our fitness tracker. Bye!\n");

    return 0;
}