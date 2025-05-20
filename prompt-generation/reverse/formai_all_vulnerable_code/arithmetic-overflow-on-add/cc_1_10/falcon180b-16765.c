//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Defining the struct for the fitness tracker
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
    int calories;
} FitnessTracker;

//Function to calculate BMI
float calculateBMI(float weight, float height) {
    float bmi = weight / (height * height);
    return bmi;
}

//Function to display fitness tracker data
void displayFitnessTracker(FitnessTracker ft) {
    printf("Name: %s\n", ft.name);
    printf("Age: %d\n", ft.age);
    printf("Weight: %0.2f\n", ft.weight);
    printf("Height: %0.2f\n", ft.height);
    printf("BMI: %0.2f\n", ft.bmi);
    printf("Steps: %d\n", ft.steps);
    printf("Calories: %d\n", ft.calories);
}

//Function to update fitness tracker data
void updateFitnessTracker(FitnessTracker *ft, int steps, int calories) {
    ft->steps += steps;
    ft->calories += calories;
}

//Function to get user input for fitness tracker data
void getFitnessTrackerData(FitnessTracker *ft) {
    printf("Enter your name: ");
    scanf("%s", ft->name);
    printf("Enter your age: ");
    scanf("%d", &ft->age);
    printf("Enter your weight in kg: ");
    scanf("%f", &ft->weight);
    printf("Enter your height in cm: ");
    scanf("%f", &ft->height);
}

//Function to get user input for steps and calories
void getStepsAndCalories(int *steps, int *calories) {
    printf("Enter the number of steps you took today: ");
    scanf("%d", steps);
    printf("Enter the number of calories you burned today: ");
    scanf("%d", calories);
}

//Main function
int main() {
    FitnessTracker ft;
    int steps, calories;

    //Getting user input for fitness tracker data
    getFitnessTrackerData(&ft);

    //Calculating BMI
    ft.bmi = calculateBMI(ft.weight, ft.height);

    //Displaying initial fitness tracker data
    printf("Initial Fitness Tracker Data:\n");
    displayFitnessTracker(ft);

    //Loop to get user input for steps and calories daily
    while(1) {
        getStepsAndCalories(&steps, &calories);
        updateFitnessTracker(&ft, steps, calories);

        //Displaying updated fitness tracker data
        printf("\nUpdated Fitness Tracker Data:\n");
        displayFitnessTracker(ft);

        //Resetting steps and calories for next day
        ft.steps = 0;
        ft.calories = 0;

        //Asking user if they want to continue
        printf("\nDo you want to continue? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if(choice == 'n') {
            break;
        }
    }

    return 0;
}