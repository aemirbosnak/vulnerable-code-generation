//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: scalable
/*
 * fitness_tracker.c
 *
 * A scalable C fitness tracker program.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a user's exercise log
typedef struct {
    char username[100];
    int age;
    int height;
    int weight;
    int gender;
    char exercise[100];
    int duration;
    int calories_burned;
    int date[3]; // year, month, day
} ExerciseLog;

// Function to create a new exercise log
ExerciseLog* create_exercise_log(char* username, int age, int height, int weight, int gender, char* exercise, int duration, int calories_burned, int year, int month, int day) {
    ExerciseLog* log = malloc(sizeof(ExerciseLog));
    strcpy(log->username, username);
    log->age = age;
    log->height = height;
    log->weight = weight;
    log->gender = gender;
    strcpy(log->exercise, exercise);
    log->duration = duration;
    log->calories_burned = calories_burned;
    log->date[0] = year;
    log->date[1] = month;
    log->date[2] = day;
    return log;
}

// Function to print an exercise log
void print_exercise_log(ExerciseLog* log) {
    printf("Username: %s\n", log->username);
    printf("Age: %d\n", log->age);
    printf("Height: %d\n", log->height);
    printf("Weight: %d\n", log->weight);
    printf("Gender: %d\n", log->gender);
    printf("Exercise: %s\n", log->exercise);
    printf("Duration: %d\n", log->duration);
    printf("Calories Burned: %d\n", log->calories_burned);
    printf("Date: %d/%d/%d\n", log->date[0], log->date[1], log->date[2]);
}

// Function to add an exercise log to a file
void add_exercise_log_to_file(char* filename, ExerciseLog* log) {
    FILE* file = fopen(filename, "a");
    if (file != NULL) {
        fprintf(file, "%s,%d,%d,%d,%d,%s,%d,%d,%d,%d,%d\n", log->username, log->age, log->height, log->weight, log->gender, log->exercise, log->duration, log->calories_burned, log->date[0], log->date[1], log->date[2]);
        fclose(file);
    }
}

// Function to read exercise logs from a file
void read_exercise_logs_from_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char line[1000];
        while (fgets(line, sizeof(line), file) != NULL) {
            char* username = strtok(line, ",");
            int age = atoi(strtok(NULL, ","));
            int height = atoi(strtok(NULL, ","));
            int weight = atoi(strtok(NULL, ","));
            int gender = atoi(strtok(NULL, ","));
            char* exercise = strtok(NULL, ",");
            int duration = atoi(strtok(NULL, ","));
            int calories_burned = atoi(strtok(NULL, ","));
            int year = atoi(strtok(NULL, ","));
            int month = atoi(strtok(NULL, ","));
            int day = atoi(strtok(NULL, ","));
            ExerciseLog* log = create_exercise_log(username, age, height, weight, gender, exercise, duration, calories_burned, year, month, day);
            print_exercise_log(log);
            free(log);
        }
        fclose(file);
    }
}

int main() {
    // Create a new exercise log
    ExerciseLog* log = create_exercise_log("John Doe", 25, 178, 70, 0, "Running", 30, 200, 2022, 3, 14);

    // Print the exercise log
    print_exercise_log(log);

    // Add the exercise log to a file
    add_exercise_log_to_file("logs.txt", log);

    // Read exercise logs from a file
    read_exercise_logs_from_file("logs.txt");

    // Free the exercise log
    free(log);

    return 0;
}