//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the exercise types
#define PUSHUPS 0
#define SQUATS 1
#define LUNGES 2
#define PLANKS 3
#define BURPEES 4

// Define the exercise names
char *exercise_names[] = {"Pushups", "Squats", "Lunges", "Planks", "Burpees"};

// Define the exercise descriptions
char *exercise_descriptions[] = {
    "Pushups: A compound exercise that works the chest, triceps, and shoulders.",
    "Squats: A compound exercise that works the legs, glutes, and core.",
    "Lunges: A compound exercise that works the legs, glutes, and core.",
    "Planks: A core exercise that works the abs, obliques, and lower back.",
    "Burpees: A full-body exercise that works the legs, glutes, core, chest, triceps, and shoulders."
};

// Define the exercise durations
int exercise_durations[] = {30, 60, 30, 60, 30};

// Define the exercise intensities
int exercise_intensities[] = {3, 2, 2, 1, 4};

// Define the exercise calories burned
int exercise_calories_burned[] = {100, 200, 150, 100, 250};

// Define the number of exercises
#define NUM_EXERCISES 5

// Define the maximum number of exercises per workout
#define MAX_EXERCISES_PER_WORKOUT 3

// Define the maximum duration of a workout
#define MAX_WORKOUT_DURATION 60

// Define the minimum intensity of a workout
#define MIN_WORKOUT_INTENSITY 2

// Define the maximum intensity of a workout
#define MAX_WORKOUT_INTENSITY 4

// Define the target calorie burn for a workout
#define TARGET_CALORIE_BURN 300

// Create a struct to store the workout data
typedef struct {
    int exercises[MAX_EXERCISES_PER_WORKOUT];
    int durations[MAX_EXERCISES_PER_WORKOUT];
    int intensities[MAX_EXERCISES_PER_WORKOUT];
    int calories_burned;
    int duration;
    int intensity;
} workout_t;

// Create a function to generate a random workout
workout_t generate_workout() {
    // Create a new workout
    workout_t workout;

    // Select a random number of exercises
    int num_exercises = rand() % MAX_EXERCISES_PER_WORKOUT + 1;

    // Select random exercises
    for (int i = 0; i < num_exercises; i++) {
        workout.exercises[i] = rand() % NUM_EXERCISES;
    }

    // Select random durations
    for (int i = 0; i < num_exercises; i++) {
        workout.durations[i] = rand() % exercise_durations[workout.exercises[i]] + 1;
    }

    // Select random intensities
    for (int i = 0; i < num_exercises; i++) {
        workout.intensities[i] = rand() % exercise_intensities[workout.exercises[i]] + 1;
    }

    // Calculate the total calories burned
    workout.calories_burned = 0;
    for (int i = 0; i < num_exercises; i++) {
        workout.calories_burned += exercise_calories_burned[workout.exercises[i]] * workout.durations[i] * workout.intensities[i];
    }

    // Calculate the total duration
    workout.duration = 0;
    for (int i = 0; i < num_exercises; i++) {
        workout.duration += workout.durations[i];
    }

    // Calculate the average intensity
    workout.intensity = 0;
    for (int i = 0; i < num_exercises; i++) {
        workout.intensity += workout.intensities[i];
    }
    workout.intensity /= num_exercises;

    // Return the workout
    return workout;
}

// Create a function to print the workout data
void print_workout(workout_t workout) {
    // Print the workout header
    printf("Workout Summary\n");
    printf("---------------------\n");

    // Print the exercise data
    for (int i = 0; i < MAX_EXERCISES_PER_WORKOUT; i++) {
        if (workout.exercises[i] != -1) {
            printf("%s: %d seconds (%d intensity)\n", exercise_names[workout.exercises[i]], workout.durations[i], workout.intensities[i]);
        }
    }

    // Print the total calories burned
    printf("Total Calories Burned: %d\n", workout.calories_burned);

    // Print the total duration
    printf("Total Duration: %d seconds\n", workout.duration);

    // Print the average intensity
    printf("Average Intensity: %d\n", workout.intensity);
}

// Create a function to main
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random workout
    workout_t workout = generate_workout();

    // Print the workout data
    print_workout(workout);

    return 0;
}