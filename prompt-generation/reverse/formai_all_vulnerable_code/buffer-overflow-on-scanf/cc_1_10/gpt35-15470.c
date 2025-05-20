//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of exercises and workout sessions */
#define MAX_EXERCISES 20
#define MAX_SESSIONS 30

/* Define the Exercise struct */
typedef struct Exercise{
    char name[50];
    int calories_burned;
} Exercise;

/* Define the WorkoutSession struct */
typedef struct WorkoutSession{
    char date[20];
    Exercise exercises[MAX_EXERCISES];
    int num_exercises;
    int total_calories_burned;
} WorkoutSession;

/* Function to add a new exercise */
Exercise addExercise(){
    Exercise new_exercise;
    printf("Enter exercise name: ");
    fgets(new_exercise.name, 50, stdin);
    new_exercise.name[strcspn(new_exercise.name, "\n")] = 0; // Remove newline character
    printf("Enter calories burned per minute: ");
    scanf("%d", &new_exercise.calories_burned);
    getchar(); // Remove extra newline character
    return new_exercise;
}

/* Function to add a new workout session */
WorkoutSession addWorkoutSession(){
    WorkoutSession new_session;
    printf("\nEnter date of workout (MM/DD/YYYY): ");
    fgets(new_session.date, 20, stdin);
    new_session.date[strcspn(new_session.date, "\n")] = 0; // Remove newline character
    new_session.num_exercises = 0;
    new_session.total_calories_burned = 0;
    char add_exercise = 'y';
    while(add_exercise == 'y'){
        if(new_session.num_exercises >= MAX_EXERCISES){
            printf("\nMaximum number of exercises reached.\n");
            break;
        }
        new_session.exercises[new_session.num_exercises] = addExercise();
        printf("\nExercise %s added.\n", new_session.exercises[new_session.num_exercises].name);
        new_session.num_exercises++;
        printf("\nAdd another exercise? (y/n): ");
        scanf("%c", &add_exercise);
        getchar(); // Remove extra newline character
    }
    /* Calculate total calories burned for this session */
    for(int i = 0; i < new_session.num_exercises; i++){
        new_session.total_calories_burned += new_session.exercises[i].calories_burned;
    }
    return new_session;
}

/* Function to display all workout sessions */
void displayWorkoutSessions(WorkoutSession *sessions, int num_sessions){
    printf("\nWorkout Sessions:\n");
    printf("| %-2s | %-11s | %-25s | %-20s | %-15s |\n", " #", "Date", "Exercises", "Calories Burned", "Total Calories");
    printf("-----------------------------------------------------------------------\n");
    for(int i = 0; i < num_sessions; i++){
        printf("| %-2d | %-11s | ", i+1, sessions[i].date);
        for(int j = 0; j < sessions[i].num_exercises; j++){
            printf("%-20s| %-15d |\n", sessions[i].exercises[j].name, sessions[i].exercises[j].calories_burned);
        }
        printf("|    |                   | %-20s | %-15d |\n\n", "", sessions[i].total_calories_burned);
    }
}

/* Main function */
int main(){
    WorkoutSession sessions[MAX_SESSIONS];
    int num_sessions = 0;
    char add_session = 'y';
    while(add_session == 'y'){
        if(num_sessions >= MAX_SESSIONS){
            printf("\nMaximum number of workout sessions reached.\n");
            break;
        }
        sessions[num_sessions] = addWorkoutSession();
        printf("\nWorkout session added.\n");
        num_sessions++;
        printf("\nAdd another workout session? (y/n): ");
        scanf("%c", &add_session);
        getchar(); // Remove extra newline character
    }
    displayWorkoutSessions(sessions, num_sessions);
    return 0;
}