//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN_HEIGHT 0
#define MAX_HEIGHT 300
#define MIN_WEIGHT 0
#define MAX_WEIGHT 500

typedef enum {
    SEDENTARY = 1,
    LIGHTLY_ACTIVE,
    MODERATELY_ACTIVE,
    VERY_ACTIVE,
    EXTREMELY_ACTIVE
} ActivityLevel;

typedef struct {
    char name[50];
    float height;
    float weight;
    int age;
    ActivityLevel activity;
} User;

float bmi_calculator(float height, float weight) {
    return weight / (height * height);
}

void print_bmi_status(float bmi) {
    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi < 25) {
        printf("Normal weight\n");
    } else if (bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obesity\n");
    }
}

int main() {
    User user;
    float bmi;
    int calories;

    printf("Please enter your name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';

    printf("Enter your height (cm): ");
    scanf("%f", &user.height);
    while (user.height < MIN_HEIGHT || user.height > MAX_HEIGHT) {
        printf("Invalid height. Please enter a valid height between %d and %d (cm): ", MIN_HEIGHT, MAX_HEIGHT);
        scanf("%f", &user.height);
    }

    printf("Enter your weight (kg): ");
    scanf("%f", &user.weight);
    while (user.weight < MIN_WEIGHT || user.weight > MAX_WEIGHT) {
        printf("Invalid weight. Please enter a valid weight between %d and %d (kg): ", MIN_WEIGHT, MAX_WEIGHT);
        scanf("%f", &user.weight);
    }

    printf("Enter your age: ");
    scanf("%d", &user.age);

    printf("Enter your daily activity level (1- Sedentary, 2- Lightly Active, 3- Moderately Active, 4- Very Active, 5- Extremely Active): ");
    scanf("%d", &user.activity);

    bmi = bmi_calculator(user.height, user.weight);
    print_bmi_status(bmi);

    switch (user.activity) {
        case SEDENTARY:
            calories = 1.2 * user.weight;
            break;
        case LIGHTLY_ACTIVE:
            calories = 1.375 * user.weight;
            break;
        case MODERATELY_ACTIVE:
            calories = 1.55 * user.weight;
            break;
        case VERY_ACTIVE:
            calories = 1.725 * user.weight;
            break;
        case EXTREMELY_ACTIVE:
            calories = 1.9 * user.weight;
            break;
        default:
            printf("Invalid activity level. Exiting program...\n");
            return 1;
    }

    printf("Based on your height, weight, age, and activity level, you burn approximately %d calories per day.\n", calories);

    return 0;
}