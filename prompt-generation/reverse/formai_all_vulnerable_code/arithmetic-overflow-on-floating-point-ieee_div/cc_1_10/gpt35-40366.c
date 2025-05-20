//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// structs to hold information about the user and their workout
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
} User;

typedef struct {
    float distance;
    float calories;
    float time;
} Workout;

int main() {
    User user; // user object to hold user data
    Workout workout; // workout object to hold workout data

    // prompt user for input and store in user object
    printf("Enter your name: ");
    fgets(user.name, 50, stdin);

    printf("Enter your age: ");
    scanf("%d", &user.age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &user.weight);

    printf("Enter your height (in m): ");
    scanf("%f", &user.height);

    // prompt user for workout data and store in workout object
    printf("Enter distance of workout (in km): ");
    scanf("%f", &workout.distance);

    printf("Enter calories burned during workout: ");
    scanf("%f", &workout.calories);

    printf("Enter time taken for workout (in minutes): ");
    scanf("%f", &workout.time);

    // calculate and print workout statistics
    float speed = workout.distance / workout.time;
    float bmi = user.weight / (user.height * user.height);

    printf("\nWorkout Summary for %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Height: %.2f m\n", user.height);
    printf("Distance: %.2f km\n", workout.distance);
    printf("Calories Burned: %.2f\n", workout.calories);
    printf("Time Taken: %.2f minutes\n", workout.time);
    printf("Average Speed: %.2f km/h\n", speed*60);
    printf("BMI: %.2f\n", bmi);

    return 0;
}