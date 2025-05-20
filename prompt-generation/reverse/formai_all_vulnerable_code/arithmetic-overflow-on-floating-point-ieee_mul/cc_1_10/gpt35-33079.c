//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>

// function to calculate total calories burned
float calcCaloriesBurned(float weight, int steps, float distance) {
    // average calories burned per step
    float calPerStep = weight / 4.0;
    
    // total calories burned based on number of steps taken
    float calFromSteps = steps * calPerStep;
    
    // total calories burned based on distance traveled
    float calFromDistance = weight * distance * 0.57;
    
    // total calories burned is the sum of calories burned from steps and distance
    float totalCal = calFromSteps + calFromDistance;
    
    return totalCal;
}

int main() {
    // variables to store user input
    float weight;
    int steps;
    float distance;
    
    // prompt user for input
    printf("Enter your weight in kg: ");
    scanf("%f", &weight);
    
    printf("Enter the number of steps taken: ");
    scanf("%d", &steps);
    
    printf("Enter the distance traveled in km: ");
    scanf("%f", &distance);
    
    // calculate total calories burned
    float totalCal = calcCaloriesBurned(weight, steps, distance);
    
    // display result to user
    printf("You burned %.2f calories!\n", totalCal);
    
    // determine user's activity level based on total calories burned
    if (totalCal < 100) {
        printf("You were not very active today. Try to get more steps or walk a longer distance tomorrow!\n");
    } else if (totalCal < 500) {
        printf("You had a moderately active day. Keep up the good work!\n");
    } else {
        printf("You had a very active day! Great job!\n");
    }
    
    return 0;
}