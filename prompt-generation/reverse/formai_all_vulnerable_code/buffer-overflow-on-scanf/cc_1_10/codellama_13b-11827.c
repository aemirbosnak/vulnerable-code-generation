//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_EXERCISES 100
#define MAX_DAYS 365

typedef struct {
    char name[50];
    int age;
    char gender;
    float weight;
    float height;
} User;

typedef struct {
    char name[50];
    int duration;
    int calories_burned;
} Exercise;

typedef struct {
    User user;
    Exercise exercise[MAX_EXERCISES];
    int num_exercises;
} Day;

Day days[MAX_DAYS];
int num_days;

void print_menu() {
    printf("Welcome to the C Fitness Tracker!\n");
    printf("1. Add a new user\n");
    printf("2. Add a new exercise\n");
    printf("3. View user information\n");
    printf("4. View exercise information\n");
    printf("5. Quit\n");
}

void add_user() {
    User user;
    printf("Enter the user's name: ");
    scanf("%s", user.name);
    printf("Enter the user's age: ");
    scanf("%d", &user.age);
    printf("Enter the user's gender (M/F): ");
    scanf(" %c", &user.gender);
    printf("Enter the user's weight (kg): ");
    scanf("%f", &user.weight);
    printf("Enter the user's height (cm): ");
    scanf("%f", &user.height);
    days[num_days].user = user;
    num_days++;
}

void add_exercise() {
    Exercise exercise;
    printf("Enter the exercise's name: ");
    scanf("%s", exercise.name);
    printf("Enter the exercise's duration (minutes): ");
    scanf("%d", &exercise.duration);
    printf("Enter the exercise's calories burned: ");
    scanf("%d", &exercise.calories_burned);
    days[num_days].exercise[days[num_days].num_exercises] = exercise;
    days[num_days].num_exercises++;
}

void view_user_info() {
    int i, j;
    printf("User information:\n");
    for (i = 0; i < num_days; i++) {
        printf("User %d:\n", i + 1);
        printf("Name: %s\n", days[i].user.name);
        printf("Age: %d\n", days[i].user.age);
        printf("Gender: %c\n", days[i].user.gender);
        printf("Weight: %f kg\n", days[i].user.weight);
        printf("Height: %f cm\n", days[i].user.height);
        printf("Exercises:\n");
        for (j = 0; j < days[i].num_exercises; j++) {
            printf("%s: %d minutes, %d calories\n", days[i].exercise[j].name, days[i].exercise[j].duration, days[i].exercise[j].calories_burned);
        }
        printf("\n");
    }
}

void view_exercise_info() {
    int i, j;
    printf("Exercise information:\n");
    for (i = 0; i < num_days; i++) {
        for (j = 0; j < days[i].num_exercises; j++) {
            printf("%s: %d minutes, %d calories\n", days[i].exercise[j].name, days[i].exercise[j].duration, days[i].exercise[j].calories_burned);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                add_exercise();
                break;
            case 3:
                view_user_info();
                break;
            case 4:
                view_exercise_info();
                break;
            case 5:
                return 0;
        }
    }
}