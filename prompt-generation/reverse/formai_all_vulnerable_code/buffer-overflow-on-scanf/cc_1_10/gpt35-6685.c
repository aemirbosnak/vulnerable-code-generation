//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct UserData{
    char name[50];
    int age;
    double weight;
    double height;
};

struct Exercise{
    char name[50];
    double caloriesBurned;
    double durationInMinutes;
};

void displayWelcomeMessage(){
    printf("Welcome to the C Fitness Tracker program\n\n");
}

void displayMenu(){
    printf("\n\nWhat would you like to do?\n");
    printf("1. Add User Data\n");
    printf("2. Add Exercise\n");
    printf("3. Display User Data\n");
    printf("4. Display Exercise\n");
    printf("5. Exit\n");
}

void addUserData(struct UserData* userData){
    printf("Enter your name: ");
    scanf("%s", userData->name);
    printf("Enter your age: ");
    scanf("%d", &userData->age);
    printf("Enter your weight in kg: ");
    scanf("%lf", &userData->weight);
    printf("Enter your height in meters: ");
    scanf("%lf", &userData->height);
}

void addExercise(struct Exercise* exercise){
    printf("Enter Exercise name: ");
    scanf("%s", exercise->name);
    printf("Enter minutes exercised: ");
    scanf("%lf", &exercise->durationInMinutes);
    printf("Enter calories burned: ");
    scanf("%lf", &exercise->caloriesBurned);
}

void displayUserData(struct UserData* userData){
    printf("\n\n");
    printf("Name: %s\n", userData->name);
    printf("Age: %d\n", userData->age);
    printf("Weight: %.2lf kg\n", userData->weight);
    printf("Height: %.2lf meters\n", userData->height);
}

void displayExercise(struct Exercise* exercise){
    printf("\n\n");
    printf("Exercise: %s\n", exercise->name);
    printf("Duration: %.2lf minutes\n", exercise->durationInMinutes);
    printf("Calories Burned: %.2lf\n", exercise->caloriesBurned);
}

int main(){
    struct UserData userData;
    struct Exercise exercise;
    int choice = 0;

    displayWelcomeMessage();

    while(choice != 5){
        displayMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addUserData(&userData);
                break;
            case 2:
                addExercise(&exercise);
                break;
            case 3:
                if(strlen(userData.name) == 0){
                    printf("Error! User data not available!\n");
                } else {
                    displayUserData(&userData);
                }
                break;
            case 4:
                if(strlen(exercise.name) == 0){
                    printf("Error! Exercise data not available!\n");
                } else {
                    displayExercise(&exercise);
                }
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    printf("Exiting program....\n");

    return 0;
}