//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10

struct Workout {
    char name[30];
    int reps;
    int sets;
    int calories;
};

struct Fitness_Tracker {
    struct Workout workouts[MAX_WORKOUTS];
    int num_workouts;
    int total_calories;
};

void display_menu() {
    printf("--------------------------------\n");
    printf("RETRO FITNESS TRACKER\n");
    printf("--------------------------------\n");
    printf("1. Add Workout\n");
    printf("2. Display Workouts\n");
    printf("3. Track Progress\n");
    printf("4. Exit\n");
    printf("--------------------------------\n");
}

void add_workout(struct Fitness_Tracker *tracker) {
    if (tracker->num_workouts == MAX_WORKOUTS) {
        printf("You have reached the maximum number of workouts.\n");
        return;
    }
    
    printf("\nEnter workout name: ");
    scanf("%s", tracker->workouts[tracker->num_workouts].name);
    printf("Enter number of reps: ");
    scanf("%d", &tracker->workouts[tracker->num_workouts].reps);
    printf("Enter number of sets: ");
    scanf("%d", &tracker->workouts[tracker->num_workouts].sets);
    printf("Enter calories burned: ");
    scanf("%d", &tracker->workouts[tracker->num_workouts].calories);
    
    tracker->total_calories += tracker->workouts[tracker->num_workouts].calories;
    tracker->num_workouts++;
    
    printf("\nWorkout added successfully!\n");
}

void display_workouts(struct Fitness_Tracker *tracker) {
    if (tracker->num_workouts == 0) {
        printf("No workouts recorded yet.\n");
        return;
    }
    
    printf("\n------------------------\n");
    for (int i = 0; i < tracker->num_workouts; i++) {
        printf("\nWorkout #%d: %s\n", i+1, tracker->workouts[i].name);
        printf("Reps: %d\n", tracker->workouts[i].reps);
        printf("Sets: %d\n", tracker->workouts[i].sets);
        printf("Calories burned: %d\n", tracker->workouts[i].calories);
        printf("------------------------\n");
    }
}

void track_progress(struct Fitness_Tracker *tracker) {
    printf("\n----------------------------------\n");
    printf("TOTAL WORKOUTS: %d\n", tracker->num_workouts);
    printf("TOTAL CALORIES BURNED: %d\n", tracker->total_calories);
    printf("----------------------------------\n");
}

int main() {
    struct Fitness_Tracker tracker;
    tracker.num_workouts = 0;
    tracker.total_calories = 0;
    
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_workout(&tracker);
                break;
            case 2:
                display_workouts(&tracker);
                break;
            case 3:
                track_progress(&tracker);
                break;
            case 4:
                printf("\nThank you for using the Retro Fitness Tracker!\n");
                break;
            default:
                printf("\nInvalid choice. Please select a valid option.\n");
                break;
        }
        
        printf("\n");
        
    } while (choice != 4);
    
    return 0;
}