//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_EXERCISES 10

/*
    This C Fitness Tracker program keeps track of a user's 
    daily exercise routine and provides a summary of their progress.

    The user can add exercises to their routine, remove exercises, 
    view their current routine and get a summary of their progress
    based on total time spent exercising and number of exercises 
    completed.
*/

typedef struct {
    char name[20];
    int time;
} Exercise;

void addExercise(Exercise *exercises, int *numExercises);
void removeExercise(Exercise *exercises, int *numExercises);
void viewRoutine(Exercise *exercises, int *numExercises);
void getSummary(Exercise *exercises, int *numExercises);

int main() {

    int numExercises = 0, choice = 0;
    Exercise exercises[MAX_EXERCISES];

    while(choice != 5) {

        printf("\nWhat would you like to do?\n"
               "1. Add an exercise\n"
               "2. Remove an exercise\n"
               "3. View current routine\n"
               "4. Get summary of progress\n"
               "5. Quit program\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addExercise(exercises, &numExercises);
                break;

            case 2:
                removeExercise(exercises, &numExercises);
                break;

            case 3:
                viewRoutine(exercises, &numExercises);
                break;

            case 4:
                getSummary(exercises, &numExercises);
                break;

            case 5: 
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice, please try again.\n");
                break;

        }

    }

    return 0;

}

/*
    Adds an exercise to the user's routine based on user input.
*/
void addExercise(Exercise *exercises, int *numExercises) {

    char name[20];
    int time;

    // check if there's room for another exercise
    if(*numExercises == MAX_EXERCISES) {
        printf("\nYou have reached the maximum number of exercises.\n");
        return;
    }

    printf("\nEnter name of exercise: ");
    scanf("%s", name);

    printf("Enter duration of exercise (in minutes): ");
    scanf("%d", &time);

    // add exercise to array of exercises
    Exercise e;
    strcpy(e.name, name);
    e.time = time;
    exercises[*numExercises] = e;

    printf("\n%s exercise added to routine.\n", name);

    // increment number of exercises
    (*numExercises)++;

}

/*
    Removes an exercise from the user's routine based on user input.
*/
void removeExercise(Exercise *exercises, int *numExercises) {

    int index;

    // check if there are any exercises to remove
    if(*numExercises == 0) {
        printf("\nThere are no exercises to remove.\n");
        return;
    }

    // display current routine
    viewRoutine(exercises, numExercises);

    printf("\nEnter index of exercise to remove: ");
    scanf("%d", &index);

    // check if index is valid
    if(index < 0 || index >= *numExercises) {
        printf("\nInvalid index, please try again.\n");
        return;
    }

    printf("\n%s exercise removed from routine.\n", exercises[index].name);

    // move all exercises after the removed exercise down by one position
    for(int i = index; i < *numExercises-1; i++) {
        exercises[i] = exercises[i+1];
    }

    // decrement number of exercises
    (*numExercises)--;

}

/*
    Views the user's current routine.
*/
void viewRoutine(Exercise *exercises, int *numExercises) {

    // check if there are any exercises in the routine
    if(*numExercises == 0) {
        printf("\nThere are no exercises in your routine.\n");
        return;
    }

    printf("\nCurrent routine:\n");

    // display all exercises in the routine
    for(int i = 0; i < *numExercises; i++) {
        printf("%d. %s (%d mins)\n", i, exercises[i].name, exercises[i].time);
    }

}

/*
    Provides the user with a summary of their progress based
    on the total time spent exercising and the number of exercises
    completed.
*/
void getSummary(Exercise *exercises, int *numExercises) {

    int totalTime = 0;

    // calculate total time spent exercising
    for(int i = 0; i < *numExercises; i++) {
        totalTime += exercises[i].time;
    }

    // display summary of progress
    printf("\nSummary of progress:\n"
           "Total time spent exercising: %d mins\n"
           "Number of exercises completed: %d\n", totalTime, *numExercises);

}