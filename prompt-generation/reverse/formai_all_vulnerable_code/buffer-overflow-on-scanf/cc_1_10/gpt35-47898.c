//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
// Fitness Tracker Program in Ada Lovelace Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20 // Maximum length of user name
#define MAX_WEEKS 4 // Maximum number of weeks to track
#define MAX_DAYS 7 // Maximum number of days in a week

// Define struct to hold exercise details
typedef struct {
    char name[MAX_NAME_LENGTH];
    int reps;
    int sets;
    int weight;
} Exercise;

// Define struct to hold daily workout details
typedef struct {
    char day[10];
    Exercise exercises[3];
} DailyWorkout;

// Define struct to hold weekly workouts
typedef struct {
    int weekNumber;
    DailyWorkout dailyWorkouts[MAX_DAYS];
} WeeklyWorkout;

// Define struct to hold user's details and weekly workouts
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender[10];
    float height;
    float weight;
    WeeklyWorkout weeklyWorkouts[MAX_WEEKS];
} User;

// Function to create new user
User createUser() {
    User user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your gender: ");
    scanf("%s", user.gender);
    printf("Enter your height in meters: ");
    scanf("%f", &user.height);
    printf("Enter your weight in kg: ");
    scanf("%f", &user.weight);
    printf("User created successfully!\n");
    return user;
}

// Function to add new exercise details
Exercise addExerciseDetails() {
    Exercise exercise;
    printf("Enter exercise name: ");
    scanf("%s", exercise.name);
    printf("Enter number of reps: ");
    scanf("%d", &exercise.reps);
    printf("Enter number of sets: ");
    scanf("%d", &exercise.sets);
    printf("Enter weight in kg: ");
    scanf("%d", &exercise.weight);
    return exercise;
}

// Function to add daily workout details
void addDailyWorkoutDetails(DailyWorkout *dailyWorkout) {
    printf("Enter day (e.g. Monday): ");
    scanf("%s", dailyWorkout->day);
    for(int i=0; i<3; i++) {
        printf("Enter details for exercise %d:\n", i+1);
        dailyWorkout->exercises[i] = addExerciseDetails();
    }
}

// Function to add weekly workout details
WeeklyWorkout addWeeklyWorkoutDetails(int weekNumber) {
    WeeklyWorkout weeklyWorkout;
    weeklyWorkout.weekNumber = weekNumber;
    for(int i=0; i<MAX_DAYS; i++) {
        printf("Enter workout details for day %d:\n", i+1);
        addDailyWorkoutDetails(&weeklyWorkout.dailyWorkouts[i]);
    }
    return weeklyWorkout;
}

// Main function to run program and track user's fitness progress
int main() {
    User user = createUser();
    int currentWeek = 1;
    while(currentWeek <= MAX_WEEKS) {
        printf("Enter workout details for week %d:\n", currentWeek);
        user.weeklyWorkouts[currentWeek-1] = addWeeklyWorkoutDetails(currentWeek);
        currentWeek++;
    }
    printf("\n\nCongratulations! You have successfully tracked your fitness progress for %d weeks.\n", MAX_WEEKS);
    return 0;
}