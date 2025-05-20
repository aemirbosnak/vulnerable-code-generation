//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to print the menu
void print_menu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add Exercise\n");
    printf("2. View Exercise Log\n");
    printf("3. Quit\n");
}

// Function to add an exercise
void add_exercise(int *exercise_count, char **exercise_log, int max_exercises) {
    char input[100];
    int exercise_id = *exercise_count;

    printf("Enter the type of exercise:\n");
    scanf("%s", input);
    strcpy(exercise_log[exercise_id], input);

    (*exercise_count)++;
}

// Function to view the exercise log
void view_exercise_log(int exercise_count, char *exercise_log[], int max_exercises) {
    printf("Exercise Log:\n");
    for (int i = 0; i < exercise_count; i++) {
        printf("%d. %s\n", i+1, exercise_log[i]);
    }
}

// Main function
int main() {
    int exercise_count = 0;
    char *exercise_log[100];
    int max_exercises = 100;

    // Initialize the exercise log with empty strings
    for (int i = 0; i < max_exercises; i++) {
        exercise_log[i] = (char *) malloc(sizeof(char) * 100);
        strcpy(exercise_log[i], "");
    }

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_exercise(&exercise_count, exercise_log, max_exercises);
                break;
            case 2:
                view_exercise_log(exercise_count, exercise_log, max_exercises);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}