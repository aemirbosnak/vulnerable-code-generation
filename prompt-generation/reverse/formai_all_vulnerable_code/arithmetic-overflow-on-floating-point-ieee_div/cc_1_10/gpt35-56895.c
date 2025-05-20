//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>

typedef struct {
    float weight;
    float height;
    int age;
    char gender;
} UserInfo;

typedef struct {
    float distance;
    int time;
    float calories;
    float pace;
} WorkoutData;

float calculateBMI(UserInfo info) {
    return info.weight / (info.height * info.height);
}

void printBMIStatus(UserInfo info) {
    float bmi = calculateBMI(info);

    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi < 25) {
        printf("Normal weight\n");
    } else if (bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obese\n");
    }
}

void logWorkoutData(WorkoutData data) {
    printf("\n--- Workout Summary ---\n");
    printf("Distance: %.2f km\n", data.distance);
    printf("Time: %d minutes\n", data.time);
    printf("Calories Burned: %.2f kcal\n", data.calories);
    printf("Pace: %.2f min/km\n", data.pace);
}

WorkoutData startWorkout(UserInfo info) {
    float distance;
    int time;

    printf("--- Start Workout ---\n");

    printf("Enter distance (km): ");
    scanf("%f", &distance);

    printf("Enter time (minutes): ");
    scanf("%d", &time);

    float pace = time / distance;
    float caloriesBurned = (info.gender == 'M' ? 0.75 : 0.66) * info.weight * distance;
    WorkoutData data = {distance, time, caloriesBurned, pace};

    printf("Workout Completed!\n");
    logWorkoutData(data);

    return data;
}

int main() {
    UserInfo user = {80, 1.8, 25, 'M'};
    WorkoutData workout1 = startWorkout(user);
    printBMIStatus(user);

    return 0;
}