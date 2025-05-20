//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include<stdio.h>

struct FitnessTracker{
    char name[20];
    int age;
    float height;
    float weight;
    float caloriesIntake;
    int steps;
    float distanceWalked;
};

struct FitnessTracker getFitnessDetails(struct FitnessTracker user){
    printf("\nEnter your name : ");
    scanf("%s", user.name);
    printf("\nEnter your age : ");
    scanf("%d", &user.age);
    printf("\nEnter your height (in meters and height should be a decimal value) : ");
    scanf("%f", &user.height);
    printf("\nEnter your weight (in kilograms and weight should be a decimal value) : ");
    scanf("%f", &user.weight);
    printf("\nEnter your average daily calorie intake (should be a decimal value) : ");
    scanf("%f", &user.caloriesIntake);
    printf("\nEnter the number of steps you take in a day : ");
    scanf("%d", &user.steps);
    printf("\nEnter the distance you walk in a day (in kilometers and distance should be a decimal value) : ");
    scanf("%f", &user.distanceWalked);
    return user;
}

void displayFitnessDetails(struct FitnessTracker user){
    printf("\nName          : %s", user.name);
    printf("\nAge           : %d", user.age);
    printf("\nHeight        : %.2f meters", user.height);
    printf("\nWeight        : %.2f kilograms", user.weight);
    printf("\nCalories Intake: %.2f calories", user.caloriesIntake);
    printf("\nSteps Taken   : %d steps", user.steps);
    printf("\nDistance Walked: %.2f kilometers", user.distanceWalked);
}

void goal(struct FitnessTracker user){
    int stepsPerDay;
    float distanceWalkPerDay, caloriesPerDay;

    stepsPerDay = 10000;
    distanceWalkPerDay = 8;
    caloriesPerDay = 2000;

    if(user.steps <= stepsPerDay && user.distanceWalked <= distanceWalkPerDay && user.caloriesIntake <= caloriesPerDay){
        printf("\nGreat job! You have met your daily fitness goal. Keep it up!");
    }
    else{
        printf("\nYou have not reached your daily fitness goal. Work harder!");
    }
}

int main(){
    struct FitnessTracker user;
    int programRun = 1;
    int userInput;

    printf("\nWelcome to the Fitness Tracker!\n");

    while(programRun == 1){
        printf("\nWhat would you like to do?\n");
        printf("1 - Enter fitness details\n");
        printf("2 - Display fitness details\n");
        printf("3 - Check fitness goal\n");
        printf("4 - Exit program\n");
        scanf("%d", &userInput);

        switch(userInput){
            case 1:
                user = getFitnessDetails(user);
                break;

            case 2:
                displayFitnessDetails(user);
                break;

            case 3:
                goal(user);
                break;

            case 4:
                programRun = 0;
                printf("\nThank you for using the Fitness Tracker!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}