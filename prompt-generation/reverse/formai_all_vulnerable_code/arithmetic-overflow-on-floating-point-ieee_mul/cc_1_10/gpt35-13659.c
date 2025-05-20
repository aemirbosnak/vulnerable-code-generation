//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// a little humor to start things off
void make_joke(){
    printf("Why did the programmer quit his job? He didn't get arrays.\n");
}

// get user's input for their fitness stats
void get_stats(int* calories, int* steps, float* distance){
    printf("How many calories did you burn today?\n");
    scanf("%d", calories);
    printf("How many steps did you take?\n");
    scanf("%d", steps);
    printf("How far did you run in kilometers?\n");
    scanf("%f", distance);
}

// calculate the user's progress towards their goals
void calculate_progress(int goal_calories, int goal_steps, float goal_distance, 
                        int calories, int steps, float distance){
    float percent_calories = (float)calories / goal_calories * 100;
    float percent_steps = (float)steps / goal_steps * 100;
    float percent_distance = distance / goal_distance * 100;

    printf("You have completed %.2f%% of your calorie burning goal.\n", percent_calories);
    printf("You have completed %.2f%% of your step goal.\n", percent_steps);
    printf("You have completed %.2f%% of your distance goal.\n", percent_distance);
}

int main(){
    make_joke(); // gotta start with some humor
    int goal_calories, goal_steps;
    float goal_distance;
    printf("Welcome to the C Fitness Tracker!\n");
    printf("What is your goal for the number of calories to burn today?\n");
    scanf("%d", &goal_calories);
    printf("What is your goal for the number of steps to take today?\n");
    scanf("%d", &goal_steps);
    printf("What is your goal for the distance to run in kilometers today?\n");
    scanf("%f", &goal_distance);

    int calories, steps;
    float distance;
    get_stats(&calories, &steps, &distance);

    calculate_progress(goal_calories, goal_steps, goal_distance, 
                       calories, steps, distance);

    printf("Keep up the good work and remember, fitness is like a bank account. "
           "It may not show progress every day, but every little bit helps!\n");
    return 0;
}