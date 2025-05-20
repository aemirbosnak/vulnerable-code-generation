//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct FitnessTracker {
    char* name;
    int steps;
    float calories;
    float distance;
    float weight;
    float height;
};

typedef struct FitnessTracker FitTrack;

int main() {

    FitTrack ft;
    ft.name = (char*) malloc(50 * sizeof(char));

    printf("Welcome to the Fitness Tracker!\n\n");

    printf("Please enter your name: ");
    fgets(ft.name, 50, stdin);

    printf("\nHello %s", ft.name);

    printf("\nPlease enter your weight in kgs: ");
    scanf("%f", &ft.weight);
    getchar();

    printf("\nPlease enter your height in metres: ");
    scanf("%f", &ft.height);
    getchar();

    printf("\nThank you!\n\n");

    ft.steps = 0;
    ft.calories = 0;
    ft.distance = 0;

    while(1) {

        printf("Enter number of steps or q to quit: ");
        char input[10];
        fgets(input, 10, stdin);

        if(strcmp(input, "q\n") == 0) {
            break;
        }

        int steps = atoi(input);

        ft.steps += steps;
        ft.distance += steps*0.0008; // Assuming average stride length = 0.8m
        ft.calories += steps*0.045*ft.weight; // Assuming 0.045 calories per step per kg

        printf("\nSteps: %d", ft.steps);
        printf("\nDistance: %.2f km", ft.distance);
        printf("\nCalories: %.2f cal", ft.calories);
        printf("\n\n");

    }

    printf("\n\nThank you for using the Fitness Tracker, %s!\n", ft.name);

    free(ft.name);

    return 0;
}