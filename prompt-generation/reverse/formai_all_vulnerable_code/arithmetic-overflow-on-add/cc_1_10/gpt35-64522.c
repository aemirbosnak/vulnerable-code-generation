//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// structure for the fitness tracker data
typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
    int target_steps;
    int total_steps;
    float distance;
    float calories_burned;
} Tracker;

// function to calculate BMI
void calculate_bmi(Tracker *t) {
    t->bmi = t->weight / ((t->height/100) * (t->height/100));
}

// function to track steps and distance
void track_steps(Tracker *t, int steps) {
    t->total_steps += steps;
    t->distance = t->total_steps * 0.7; // assuming each step is 0.7 meters
}

// function to track calories burned
void track_calories(Tracker *t) {
    t->calories_burned = t->total_steps * 0.05; // assuming 1 step burns 0.05 calories
}

int main() {
    Tracker t;

    // getting user input
    printf("Enter your name: ");
    scanf("%s", t.name);
    printf("Enter your age: ");
    scanf("%d", &t.age);
    printf("Enter your height in cm: ");
    scanf("%f", &t.height);
    printf("Enter your weight in kg: ");
    scanf("%f", &t.weight);
    printf("Enter your target steps for the day: ");
    scanf("%d", &t.target_steps);

    // calculating initial BMI
    calculate_bmi(&t);

    printf("\nWelcome %s!\n", t.name);
    printf("Your BMI is %.2f\n", t.bmi);

    // tracking steps throughout the day
    for(int i=1; i<=12; i++) { // assuming user is awake for 12 hours
        printf("\nHour %d\n", i);
        int steps;
        printf("Enter the number of steps you took this hour: ");
        scanf("%d", &steps);
        track_steps(&t, steps);
    }

    // tracking calories burned
    track_calories(&t);

    printf("\nYou took a total of %d steps today and walked %.2f km.\n", t.total_steps, t.distance/1000);
    printf("You burned a total of %.2f calories!\n", t.calories_burned);

    // checking if user achieved their target steps
    if(t.total_steps >= t.target_steps) {
        printf("Congratulations on achieving your target steps for the day!\n");
    } else {
        printf("You did not achieve your target steps for the day. Keep trying!\n");
    }

    return 0;
}