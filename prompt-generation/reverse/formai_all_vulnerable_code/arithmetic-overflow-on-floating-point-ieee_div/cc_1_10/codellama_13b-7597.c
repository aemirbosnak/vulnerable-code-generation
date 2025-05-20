//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXERCISES 10
#define MAX_USERS 10

typedef struct {
    char name[30];
    float weight;
    float height;
    float age;
    float bmi;
    int exercises[MAX_EXERCISES];
    float exercise_time[MAX_EXERCISES];
    float calories_burned[MAX_EXERCISES];
} User;

void calculate_bmi(User *user) {
    user->bmi = (user->weight / (user->height * user->height));
}

void calculate_calories_burned(User *user, int exercise_index) {
    switch (user->exercises[exercise_index]) {
        case 1: // Running
            user->calories_burned[exercise_index] = (user->exercise_time[exercise_index] * 6.66);
            break;
        case 2: // Swimming
            user->calories_burned[exercise_index] = (user->exercise_time[exercise_index] * 12.5);
            break;
        case 3: // Cycling
            user->calories_burned[exercise_index] = (user->exercise_time[exercise_index] * 9.33);
            break;
        default:
            user->calories_burned[exercise_index] = 0;
            break;
    }
}

void print_user(User *user) {
    printf("Name: %s\n", user->name);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Height: %.2f m\n", user->height);
    printf("Age: %.2f years\n", user->age);
    printf("BMI: %.2f\n", user->bmi);
    printf("Exercise Time: ");
    for (int i = 0; i < MAX_EXERCISES; i++) {
        printf("%.2f ", user->exercise_time[i]);
    }
    printf("\n");
    printf("Calories Burned: ");
    for (int i = 0; i < MAX_EXERCISES; i++) {
        printf("%.2f ", user->calories_burned[i]);
    }
    printf("\n");
}

int main() {
    User users[MAX_USERS];

    for (int i = 0; i < MAX_USERS; i++) {
        printf("Enter name: ");
        scanf("%s", users[i].name);
        printf("Enter weight: ");
        scanf("%f", &users[i].weight);
        printf("Enter height: ");
        scanf("%f", &users[i].height);
        printf("Enter age: ");
        scanf("%f", &users[i].age);
        calculate_bmi(&users[i]);

        for (int j = 0; j < MAX_EXERCISES; j++) {
            printf("Enter exercise time: ");
            scanf("%f", &users[i].exercise_time[j]);
            calculate_calories_burned(&users[i], j);
        }

        print_user(&users[i]);
    }

    return 0;
}