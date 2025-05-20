//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include<stdio.h>
#include<stdlib.h>

//User defined data type for storing fitness data
typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
    int steps;
    float distance;
    int calories;
} Fitness;

//Function to calculate BMI
void calculate_bmi(Fitness *user) {
    user->bmi = user->weight / ((user->height/100)*(user->height/100));
}

//Function to get user data
void get_data(Fitness *user) {
    printf("Please enter your name: ");
    scanf("%s", user->name);
    printf("Please enter your age: ");
    scanf("%d", &user->age);
    printf("Please enter your height in cm: ");
    scanf("%f", &user->height);
    printf("Please enter your weight in kg: ");
    scanf("%f", &user->weight);
    calculate_bmi(user);
}

//Function to update step count
void update_step_count(Fitness *user) {
    int steps;
    printf("Please enter the number of steps taken: ");
    scanf("%d", &steps);
    user->steps += steps;
    user->distance += steps*0.7;
    user->calories += steps*0.05;
}

int main() {
    Fitness user;
    user.steps = 0;
    user.distance = 0;
    user.calories = 0;
    get_data(&user);

    //Display user data
    printf("\nName: %s\nAge: %d\nHeight: %.2f cm\nWeight: %.2f kg\nBMI: %.2f\nSteps: %d\nDistance: %.2f km\nCalories Burnt: %d\n", user.name, user.age, user.height, user.weight, user.bmi, user.steps, user.distance, user.calories);

    //Update step count
    update_step_count(&user);

    //Display updated fitness data
    printf("\nName: %s\nAge: %d\nHeight: %.2f cm\nWeight: %.2f kg\nBMI: %.2f\nSteps: %d\nDistance: %.2f km\nCalories Burnt: %d\n", user.name, user.age, user.height, user.weight, user.bmi, user.steps, user.distance, user.calories);

    return 0;
}