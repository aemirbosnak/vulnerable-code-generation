//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for workout data
typedef struct {
    char name[50];
    int duration;
    int calories;
    time_t start_time;
    time_t end_time;
} workout;

// Function to display menu
void display_menu() {
    printf("\nWELCOME TO FITNESS TRACKER\n");
    printf("1. Add a workout\n");
    printf("2. View workouts\n");
    printf("3. Exit\n");
}

// Function to add a workout
void add_workout() {
    workout w;
    printf("\nEnter workout name: ");
    scanf("%s", w.name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &w.duration);
    printf("Enter calories burned: ");
    scanf("%d", &w.calories);
    time_t now = time(NULL);
    w.start_time = now;
    w.end_time = now + w.duration * 60;
    printf("\nWorkout added successfully!\n");
}

// Function to view workouts
void view_workouts() {
    FILE *fp;
    workout w;
    fp = fopen("workouts.txt", "r");
    if (fp == NULL) {
        printf("\nNo workouts found.\n");
        return;
    }
    while (fscanf(fp, "%s %d %d %ld %ld", w.name, &w.duration, &w.calories, &w.start_time, &w.end_time)!= EOF) {
        printf("\nWorkout name: %s\n", w.name);
        printf("Duration: %d minutes\n", w.duration);
        printf("Calories burned: %d\n", w.calories);
        printf("Start time: %s\n", ctime(&w.start_time));
        printf("End time: %s\n", ctime(&w.end_time));
        printf("\n");
    }
    fclose(fp);
}

// Main function
int main() {
    int choice;
    char filename[50] = "workouts.txt";
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("\nError: unable to create file.\n");
        exit(1);
    }
    fclose(fp);
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                view_workouts();
                break;
            case 3:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}