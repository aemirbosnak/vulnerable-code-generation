//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Exercise {
    char name[20];
    int calories;
    int duration;
} Exercise;

void display_menu();
void add_exercise(Exercise *log, int *index);
void view_log(Exercise *log, int *index);
void delete_log(Exercise *log, int *index);
int calculate_calories_burned(Exercise *log, int *index);

int main() {
    Exercise log[100];
    int choice, index = 0;

    do {
        display_menu();

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_exercise(log, &index);
                break;
            case 2:
                view_log(log, &index);
                break;
            case 3:
                delete_log(log, &index);
                break;
            case 4:
                printf("Total calories burned: %d\n", calculate_calories_burned(log, &index));
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void display_menu() {
    printf("\nFitness Tracker Menu\n");
    printf("1. Add exercise\n");
    printf("2. View log\n");
    printf("3. Delete log\n");
    printf("4. Calculate total calories burned\n");
    printf("5. Exit program\n");
    printf("Enter your choice: ");
}

void add_exercise(Exercise *log, int *index) {
    Exercise e;

    printf("Enter the name of the exercise: ");
    scanf("%s", e.name);

    printf("Enter the number of calories burned during the exercise: ");
    scanf("%d", &e.calories);

    printf("Enter the duration of the exercise (in minutes): ");
    scanf("%d", &e.duration);

    log[*index] = e;
    (*index)++;

    printf("Exercise added successfully!\n");
}

void view_log(Exercise *log, int *index) {
    if (*index == 0) {
        printf("No exercises logged.\n");
    } else {
        printf("Exercise Log\n");
        printf("_________________________________________________________\n");
        printf("|%-20s|%-20s|%-20s|\n","Exercise","Calories","Duration");
        printf("|____________________|____________________|____________________|\n");

        for (int i = 0; i < *index; i++) {
            printf("|%-20s|%-20d|%-20d|\n", log[i].name, log[i].calories, log[i].duration);
        }
    }
}

void delete_log(Exercise *log, int *index) {
    int pos;

    view_log(log, index);

    printf("\nEnter the position of the exercise to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *index) {
        printf("Invalid position, please try again.\n");
    } else {
        for (int i = pos - 1; i < *index - 1; i++) {
            log[i] = log[i + 1];
        }

        (*index)--;

        printf("Exercise deleted successfully!\n");
    }
}

int calculate_calories_burned(Exercise *log, int *index) {
    int total = 0;

    for (int i = 0; i < *index; i++) {
        total += log[i].calories;
    }

    return total;
}