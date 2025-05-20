//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_SIZE 20
#define MAX_WORKOUT_SIZE 30

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
    float height, weight;
} User;

typedef struct {
    char workout[MAX_WORKOUT_SIZE];
    float duration, calories_burned;
    time_t date;
} Workout;

void log_workout(User user, Workout* workout) {
    /* Save workout to file */
    FILE *fptr;
    fptr = fopen("workouts.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fptr, "%s, %d, %.2f, %.2f, %s, %.2f, %.2f, %ld\n", 
            user.name, user.age, user.height, user.weight, 
            workout->workout, workout->duration, 
            workout->calories_burned, workout->date);
    fclose(fptr);
    printf("Workout logged successfully!\n");
}

int main() {
    User user;
    printf("Please enter your name: ");
    scanf("%s", user.name);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your height (in meters): ");
    scanf("%f", &user.height);
    printf("Please enter your weight (in kgs): ");
    scanf("%f", &user.weight);

    printf("Welcome %s!\n", user.name);

    char choice;
    do {
        printf("\nWhat type of workout did you do?\n");
        printf("1. Running\n");
        printf("2. Cycling\n");
        printf("3. Crossfit\n");
        printf("4. Yoga\n");
        printf("5. Other\n");
        printf("Please enter your choice: ");

        int workout_choice;
        scanf("%d", &workout_choice);

        Workout workout;
        switch (workout_choice) {
            case 1:
                strcpy(workout.workout, "Running");
                break;
            case 2:
                strcpy(workout.workout, "Cycling");
                break;
            case 3:
                strcpy(workout.workout, "Crossfit");
                break;
            case 4:
                strcpy(workout.workout, "Yoga");
                break;
            case 5:
                printf("Please enter the name of your workout: ");
                scanf("%s", workout.workout);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        if (workout_choice >= 1 && workout_choice <= 5) {
            printf("Please enter the duration of your workout (in minutes): ");
            scanf("%f", &workout.duration);

            switch (workout_choice) {
                case 1:
                    workout.calories_burned = 10 * user.weight * workout.duration;
                    break;
                case 2:
                    workout.calories_burned = 8 * user.weight * workout.duration;
                    break;
                case 3:
                    workout.calories_burned = 12 * user.weight * workout.duration;
                    break;
                case 4:
                    workout.calories_burned = 6 * user.weight * workout.duration;
                    break;
                case 5:
                    workout.calories_burned = 5 * user.weight * workout.duration;
                    break;
            }

            workout.date = time(NULL);
            log_workout(user, &workout);
        }

        printf("\nDo you want to log another workout [y/n]? ");
        scanf("%s", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}