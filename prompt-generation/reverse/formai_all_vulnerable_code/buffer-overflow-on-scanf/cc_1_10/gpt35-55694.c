//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 10
#define MAX_WORKOUT 5

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
} User;

typedef struct {
    char name[50];
    float duration_mins;
    float calories_burned;
} Workout;

typedef struct {
    User user;
    Workout workout[MAX_WORKOUT];
    int num_workouts;
} FitnessTracker;

int get_user_index(FitnessTracker* tracker, char* name) {
    for (int i = 0; i < MAX_USER; i++) {
        if (strcmp(tracker[i].user.name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_user(FitnessTracker* tracker) {
    if (tracker[MAX_USER-1].user.name[0] != '\0') {
        printf("Maximum number of users reached.\n");
        return;
    }

    User user;
    printf("Enter name: ");
    scanf("%49s", user.name);
    printf("Enter age: ");
    scanf("%d", &user.age);
    printf("Enter height (in meters): ");
    scanf("%f", &user.height);
    printf("Enter weight (in kg): ");
    scanf("%f", &user.weight);

    for (int i = 0; i < MAX_USER; i++) {
        if (tracker[i].user.name[0] == '\0') {
            tracker[i].user = user;
            printf("%s added successfully.\n", user.name);
            return;
        }
    }
}

void remove_user(FitnessTracker* tracker, char* name) {
    int index = get_user_index(tracker, name);
    if (index == -1) {
        printf("User not found.\n");
        return;
    }

    tracker[index].user.name[0] = '\0';
    tracker[index].num_workouts = 0;
    printf("%s removed successfully.\n", name);
}

void add_workout(FitnessTracker* tracker, char* username) {
    int index = get_user_index(tracker, username);
    if (index == -1) {
        printf("User not found.\n");
        return;
    }

    if (tracker[index].num_workouts == MAX_WORKOUT) {
        printf("Maximum number of workouts reached for this user.\n");
        return;
    }

    Workout workout;
    printf("Enter workout name: ");
    scanf("%49s", workout.name);
    printf("Enter duration (in minutes): ");
    scanf("%f", &workout.duration_mins);
    printf("Enter calories burned: ");
    scanf("%f", &workout.calories_burned);

    tracker[index].workout[tracker[index].num_workouts++] = workout;
    printf("%s workout added successfully for user %s.\n", workout.name, username);
}

void remove_workout(FitnessTracker* tracker, char* username, char* workoutname) {
    int index = get_user_index(tracker, username);
    if (index == -1) {
        printf("User not found.\n");
        return;
    }

    int workout_index = -1;
    for (int i = 0; i < tracker[index].num_workouts; i++) {
        if (strcmp(tracker[index].workout[i].name, workoutname) == 0) {
            workout_index = i;
            break;
        }
    }

    if (workout_index == -1) {
        printf("%s workout not found for user %s.\n", workoutname, username);
        return;
    }

    for (int i = workout_index; i < tracker[index].num_workouts-1; i++) {
        tracker[index].workout[i] = tracker[index].workout[i+1];
    }
    tracker[index].num_workouts--;
    printf("%s workout removed successfully for user %s.\n", workoutname, username);
}

void show_user(FitnessTracker* tracker, char* name) {
    int index = get_user_index(tracker, name);
    if (index == -1) {
        printf("User not found.\n");
        return;
    }

    User user = tracker[index].user;
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f meters\n", user.height);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Workouts:\n");

    for (int i = 0; i < tracker[index].num_workouts; i++) {
        Workout workout = tracker[index].workout[i];
        printf("\t%s - Duration: %.2f minutes, Calories burned: %.2f\n",
                workout.name, workout.duration_mins, workout.calories_burned);
    }
}

void show_all_users(FitnessTracker* tracker) {
    int count = 0;
    for (int i = 0; i < MAX_USER; i++) {
        if (tracker[i].user.name[0] != '\0') {
            count++;
            printf("\nUser %d\n", count);
            show_user(tracker, tracker[i].user.name);
        }
    }
    if (count == 0) {
        printf("No users found.\n");
    }
}

int main() {
    FitnessTracker tracker[MAX_USER] = {0};

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Add workout\n");
        printf("4. Remove workout\n");
        printf("5. Show user\n");
        printf("6. Show all users\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                add_user(tracker);
                break;
            }
            case 2: {
                char name[50];
                printf("Enter user name: ");
                scanf("%49s", name);
                remove_user(tracker, name);
                break;
            }
            case 3: {
                char username[50];
                printf("Enter user name: ");
                scanf("%49s", username);
                add_workout(tracker, username);
                break;
            }
            case 4: {
                char username[50];
                printf("Enter user name: ");
                scanf("%49s", username);
                char workoutname[50];
                printf("Enter workout name: ");
                scanf("%49s", workoutname);
                remove_workout(tracker, username, workoutname);
                break;
            }
            case 5: {
                char name[50];
                printf("Enter user name: ");
                scanf("%49s", name);
                show_user(tracker, name);
                break;
            }
            case 6: {
                show_all_users(tracker);
                break;
            }
            case 7: {
                printf("Exiting program.\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
}