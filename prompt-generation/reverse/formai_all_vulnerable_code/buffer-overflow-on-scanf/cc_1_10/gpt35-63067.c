//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exercises {
    char name[30];
    int count;
    int calBurnt;
};

struct FitnessTracker {
    char name[30];
    int age;
    int height;
    int weight;
    char gender[10];
    int calorieIntake;
    struct Exercises exercises[10];
};

void displayMenu() {
    printf("\n\n*******************************************************************************\n\n");
    printf("\t\t Welcome to your Personal Fitness Tracker!\n\n");
    printf("\t\t 1. Set up your profile\n");
    printf("\t\t 2. Add a new exercise with calorie burnt\n");
    printf("\t\t 3. View your exercises and calorie balance\n");
    printf("\t\t 4. Exit");
    printf("\n\n*******************************************************************************\n\n");
}

void addExercise(struct FitnessTracker *fitness) {
    int i = 0;
    while (fitness->exercises[i].count != 0) {
        i++;
    }
    printf("\nEnter the name of the exercise: ");
    scanf("%s", fitness->exercises[i].name);
    printf("\nEnter the number of times you have done this exercise: ");
    scanf("%d", &fitness->exercises[i].count);
    printf("\nEnter the calories burnt for this exercise: ");
    scanf("%d", &fitness->exercises[i].calBurnt);
}

void viewProfile(struct FitnessTracker fitness) {
    printf("\n\n*******************************************************************************\n\n");
    printf("\t\t Your Profile:");
    printf("\n\n*******************************************************************************\n\n");
    printf("\nName: %s", fitness.name);
    printf("\nAge: %d", fitness.age);
    printf("\nGender: %s", fitness.gender);
    printf("\nHeight: %d cm", fitness.height);
    printf("\nWeight: %d kg", fitness.weight);
    printf("\nCalorie Intake: %d calories", fitness.calorieIntake);
    printf("\n\n*******************************************************************************\n\n");
}

void viewExercises(struct FitnessTracker fitness) {
    int totalCaloriesBurnt = 0;
    int i;
    printf("\n\n*******************************************************************************\n\n");
    printf("\t\t Your Exercises:");
    printf("\n\n*******************************************************************************\n\n");
    for (i = 0; fitness.exercises[i].count != 0 && i < 10; i++) {
        printf("\nName of Exercise: %s", fitness.exercises[i].name);
        printf("\nNumber of Times you have done this exercise: %d", fitness.exercises[i].count);
        printf("\nCalories Burnt for this exercise: %d", fitness.exercises[i].calBurnt);
        totalCaloriesBurnt += (fitness.exercises[i].count * fitness.exercises[i].calBurnt);
        printf("\n\n");
    }
    if (totalCaloriesBurnt > fitness.calorieIntake) {
        printf("\nYou have burned more calories than your intake!");
    }
    else if (totalCaloriesBurnt == fitness.calorieIntake) {
        printf("\nYour calorie intake and calories burnt are equal!");
    }
    else {
        printf("\nYou have consumed more calories than you have burnt!");
    }
    printf("\n\n*******************************************************************************\n\n");
}

int main() {
    struct FitnessTracker fitness;
    int choice, i;
    printf("\nHello there! Let's set up your Fitness Tracker!\n");
    printf("\nEnter your Name: ");
    scanf("%s", fitness.name);
    printf("\nEnter your Age: ");
    scanf("%d", &fitness.age);
    printf("\nEnter your Gender: (Male/Female/Other) ");
    scanf("%s", fitness.gender);
    printf("\nEnter your Height (cm): ");
    scanf("%d", &fitness.height);
    printf("\nEnter your Weight (kg): ");
    scanf("%d", &fitness.weight);
    printf("\nEnter your Average Calorie Intake (calories): ");
    scanf("%d", &fitness.calorieIntake);
    for (i = 0; i < 10; i++) { //Initialize all the exercises count to 0.
        fitness.exercises[i].count = 0;
    }
    while (1) {
        displayMenu();
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nSetting up your profile...\n");
            printf("\nEnter your Name: ");
            scanf("%s", fitness.name);
            printf("\nEnter your Age: ");
            scanf("%d", &fitness.age);
            printf("\nEnter your Gender: (Male/Female/Other) ");
            scanf("%s", fitness.gender);
            printf("\nEnter your Height (cm): ");
            scanf("%d", &fitness.height);
            printf("\nEnter your Weight (kg): ");
            scanf("%d", &fitness.weight);
            printf("\nEnter your Average Calorie Intake (calories): ");
            scanf("%d", &fitness.calorieIntake);
            break;
        case 2:
            printf("\nAdding a new exercise...\n");
            addExercise(&fitness);
            break;
        case 3:
            printf("\nViewing your profile and exercises...\n");
            viewProfile(fitness);
            viewExercises(fitness);
            break;
        case 4:
            printf("\nExiting the program...");
            exit(0);
        default:
            printf("\nInvalid choice! Try again.");
            break;
        }
    }
    return 0;
}