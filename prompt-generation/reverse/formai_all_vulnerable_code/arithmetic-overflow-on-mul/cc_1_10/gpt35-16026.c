//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[20];
    int age, weight, height;
};

struct workout {
    char type[20];
    int duration, calories;
};

void add_workout(struct user*, struct workout*);
void view_history(struct user*);

int main() {
    struct user current_user;
    struct workout current_workout;
    int choice;

    printf("Enter your name: ");
    fgets(current_user.name, 20, stdin);
    printf("Enter your age: ");
    scanf("%d", &current_user.age);
    printf("Enter your weight (in kilograms): ");
    scanf("%d", &current_user.weight);
    printf("Enter your height (in centimeters): ");
    scanf("%d", &current_user.height);

    while (1) {
        printf("\n\n--- Fitness Tracker ---\n");
        printf("1. Add workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout(&current_user, &current_workout);
                break;

            case 2:
                view_history(&current_user);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }

    }

    return 0;
}

void add_workout(struct user *current_user, struct workout *current_workout) {
    // get user input
    printf("\n--- Add workout ---\n");
    printf("Enter workout type: ");
    fgets(current_workout->type, 20, stdin);
    printf("Enter duration (in minutes): ");
    scanf("%d", &current_workout->duration);

    // calculate calories burned based on weight and duration
    current_workout->calories = (current_user->weight / 30) * current_workout->duration;

    // append workout to workout history file
    FILE *fp;
    fp = fopen("workout_history.txt", "a+");
    fprintf(fp, "User: %s, Workout type: %s, Duration: %d, Calories burned: %d\n",
            current_user->name, current_workout->type, current_workout->duration, current_workout->calories);
    fclose(fp);

    printf("Workout added successfully\n");
}

void view_history(struct user *current_user) {
    // read workout history file and print all entries for current user
    FILE *fp;
    char buffer[100];
    fp = fopen("workout_history.txt", "r");

    printf("\n--- Workout history ---\n");
    while (fgets(buffer, 100, fp)) {
        if (strstr(buffer, current_user->name)) {
            printf("%s", buffer);
        }
    }

    fclose(fp);
}