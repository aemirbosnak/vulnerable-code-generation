//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 20
#define MAX_LOG_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned; // each exercise can vary
} Exercise;

typedef struct {
    time_t timestamp;
    int totalExercises;
    int totalCaloriesBurned;
    Exercise exercises[MAX_EXERCISES];
} LogEntry;

LogEntry fitnessLog[MAX_LOG_ENTRIES];
int logCount = 0;

void initExercise(Exercise *exercise, const char *name, int duration, int calories) {
    strncpy(exercise->name, name, MAX_NAME_LENGTH);
    exercise->duration = duration;
    exercise->caloriesBurned = calories;
}

void addExerciseToLog(Exercise *exercise) {
    if (logCount >= MAX_LOG_ENTRIES) {
        printf("Log is full! Cannot add more exercises.\n");
        return;
    }
    
    LogEntry *currentLog = &fitnessLog[logCount];
    currentLog->timestamp = time(NULL);
    currentLog->totalExercises = 0;
    currentLog->totalCaloriesBurned = 0;
    
    currentLog->exercises[currentLog->totalExercises] = *exercise;
    currentLog->totalExercises++;
    currentLog->totalCaloriesBurned += exercise->caloriesBurned;
    
    logCount++;
}

void displayLog() {
    printf("Fitness Log:\n");
    for (int i = 0; i < logCount; i++) {
        LogEntry *entry = &fitnessLog[i];
        char buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&entry->timestamp);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("Entry %d:\n", i + 1);
        printf("Date and Time: %s\n", buffer);
        printf("Total Exercises: %d\n", entry->totalExercises);
        printf("Total Calories Burned: %d\n", entry->totalCaloriesBurned);
        printf("Exercises:\n");
        for (int j = 0; j < entry->totalExercises; j++) {
            printf("  - %s: %d minutes, %d calories\n", 
                entry->exercises[j].name, 
                entry->exercises[j].duration, 
                entry->exercises[j].caloriesBurned);
        }
        printf("---------------------------------\n");
    }
}

void survivalMode() {
    printf("Welcome to the Fitness Tracker Survival Mode\n");
    printf("Your health is your most important asset in this dystopian world.\n");
    while (1) {
        int choice;
        Exercise exercise;
        printf("Choose an option:\n");
        printf("1. Add cardio exercise (running, scavenging)\n");
        printf("2. Add strength exercise (lifting, combat training)\n");
        printf("3. Display fitness log\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initExercise(&exercise, "Running", rand() % 60 + 1, rand() % 500 + 100);
                addExerciseToLog(&exercise);
                printf("Added running exercise to log.\n");
                break;
            case 2:
                initExercise(&exercise, "Lifting", rand() % 60 + 1, rand() % 400 + 100);
                addExerciseToLog(&exercise);
                printf("Added lifting exercise to log.\n");
                break;
            case 3:
                displayLog();
                break;
            case 4:
                printf("Stay strong, survivor! Until next time...\n");
                exit(0);
            default:
                printf("Invalid choice! Please, choose again.\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    survivalMode();
    return 0;
}