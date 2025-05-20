//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct user {
    char name[20];
    int age;
    double weight;
    double height;
    double bmi;
    int steps;
    int calories;
};

struct user *create_user() {
    struct user *user = (struct user *)malloc(sizeof(struct user));
    if (user == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    return user;
}

void set_user_info(struct user *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (kg): ");
    scanf("%lf", &user->weight);
    printf("Enter your height (cm): ");
    scanf("%lf", &user->height);
    user->bmi = user->weight / (user->height * user->height);
    printf("Your BMI is %.2lf\n", user->bmi);
}

void set_daily_goals(struct user *user) {
    printf("Enter your daily step goal: ");
    scanf("%d", &user->steps);
    printf("Enter your daily calorie goal: ");
    scanf("%d", &user->calories);
}

void print_user_info(struct user *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %lf kg\n", user->weight);
    printf("Height: %lf cm\n", user->height);
    printf("BMI: %.2lf\n", user->bmi);
    printf("Daily step goal: %d\n", user->steps);
    printf("Daily calorie goal: %d\n", user->calories);
}

void print_progress(struct user *user) {
    printf("Steps taken: ");
    for (int i = 0; i < user->steps; i++) {
        printf("*");
    }
    printf("\n");
    printf("Calories burned: ");
    for (int i = 0; i < user->calories; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    struct user *user = create_user();
    set_user_info(user);
    set_daily_goals(user);
    int steps = 0;
    int calories = 0;
    while (1) {
        int rand_steps = rand() % user->steps + 1;
        int rand_calories = rand() % user->calories + 1;
        steps += rand_steps;
        calories += rand_calories;
        if (steps >= user->steps) {
            printf("Congratulations! You have reached your daily step goal.\n");
            break;
        }
        if (calories >= user->calories) {
            printf("Congratulations! You have burned your daily calorie goal.\n");
            break;
        }
        print_progress(user);
        sleep(1);
    }
    print_user_info(user);
    return 0;
}