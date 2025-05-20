//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100

// Define a struct to hold workout data
typedef struct {
    char name[50];
    time_t start_time;
    time_t end_time;
    int duration;
} workout_t;

// Function to print workout data
void print_workout(workout_t workout) {
    printf("Name: %s\n", workout.name);
    printf("Start Time: %s\n", ctime(&workout.start_time));
    printf("End Time: %s\n", ctime(&workout.end_time));
    printf("Duration: %d seconds\n", workout.duration);
}

// Function to calculate duration of a workout
int calculate_duration(time_t start_time, time_t end_time) {
    return difftime(end_time, start_time);
}

// Function to sort workouts by duration
void sort_workouts(workout_t workouts[], int num_workouts) {
    for (int i = 0; i < num_workouts - 1; i++) {
        for (int j = i + 1; j < num_workouts; j++) {
            if (calculate_duration(workouts[j].start_time, workouts[j].end_time) > calculate_duration(workouts[i].start_time, workouts[i].end_time)) {
                workout_t temp = workouts[i];
                workouts[i] = workouts[j];
                workouts[j] = temp;
            }
        }
    }
}

// Function to read workouts from a file
int read_workouts(workout_t workouts[], int num_workouts, FILE *file) {
    int count = 0;
    while (fscanf(file, "%s %ld %ld", workouts[count].name, &workouts[count].start_time, &workouts[count].end_time) == 3 && count < num_workouts) {
        workouts[count].duration = calculate_duration(workouts[count].start_time, workouts[count].end_time);
        count++;
    }
    return count;
}

// Function to write workouts to a file
void write_workouts(workout_t workouts[], int num_workouts, FILE *file) {
    for (int i = 0; i < num_workouts; i++) {
        fprintf(file, "%s %ld %ld\n", workouts[i].name, workouts[i].start_time, workouts[i].end_time);
    }
}

// Function to display workout statistics
void display_stats(workout_t workouts[], int num_workouts) {
    int total_duration = 0;
    for (int i = 0; i < num_workouts; i++) {
        total_duration += workouts[i].duration;
    }
    printf("Total workouts: %d\n", num_workouts);
    printf("Total duration: %d seconds\n", total_duration);
}

int main() {
    // Initialize workout data
    workout_t workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    // Read workouts from file
    FILE *file = fopen("workouts.txt", "r");
    if (file!= NULL) {
        num_workouts = read_workouts(workouts, MAX_WORKOUTS, file);
        fclose(file);
    }

    // Sort workouts by duration
    sort_workouts(workouts, num_workouts);

    // Print workout data
    for (int i = 0; i < num_workouts; i++) {
        print_workout(workouts[i]);
    }

    // Display workout statistics
    display_stats(workouts, num_workouts);

    return 0;
}