//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 50
#define MAX_EXERCISES 10

typedef struct {
    char name[50];
    int age;
    float weight; // in kg
    float height; // in cm
    float calories_burned;
    time_t last_update_time;
} User;

typedef struct {
    char exercise_name[30];
    float duration; // in minutes
    float calories_per_minute; // Calories burned per minute
} Exercise;

void add_user(User users[], int *user_count) {
    if (*user_count >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    printf("Enter user name: ");
    scanf("%s", users[*user_count].name);
    printf("Enter age: ");
    scanf("%d", &users[*user_count].age);
    printf("Enter weight (kg): ");
    scanf("%f", &users[*user_count].weight);
    printf("Enter height (cm): ");
    scanf("%f", &users[*user_count].height);
    users[*user_count].calories_burned = 0;
    users[*user_count].last_update_time = time(NULL);
    (*user_count)++;
    printf("User %s added successfully!\n", users[*user_count - 1].name);
}

void log_exercise(User *user, Exercise *exercise) {
    user->calories_burned += exercise->calories_per_minute * exercise->duration;
    user->last_update_time = time(NULL);

    printf("%s has completed %.2f minutes of %s.\n", user->name, exercise->duration, exercise->exercise_name);
    printf("Total calories burned: %.2f\n", user->calories_burned);
}

void display_user_info(User user) {
    printf("User Info:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Height: %.2f cm\n", user.height);
    printf("Calories Burned: %.2f\n", user.calories_burned);
    printf("Last Update: %s", ctime(&user.last_update_time));
}

void display_all_users(User users[], int user_count) {
    for (int i = 0; i < user_count; i++) {
        printf("%d. %s\n", i + 1, users[i].name);
    }
}

int main() {
    User users[MAX_USERS];
    int user_count = 0;
    Exercise exercises[MAX_EXERCISES] = {
        {"Running", 10, 8.5},
        {"Cycling", 10, 6},
        {"Swimming", 10, 5},
        {"Yoga", 10, 3},
        {"Weightlifting", 10, 6},
        {"Jump Rope", 10, 10},
        {"Rowing", 10, 9},
        {"Dancing", 10, 7},
        {"Boxing", 10, 8},
        {"Pilates", 10, 4}
    };

    int choice;

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Log Exercise\n");
        printf("3. Display User Info\n");
        printf("4. Display All Users\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(users, &user_count);
                break;
            case 2: {
                int user_index, exercise_index;
                printf("Select user (1-%d): ", user_count);
                scanf("%d", &user_index);
                if(user_index < 1 || user_index > user_count) {
                    printf("Invalid user selection.\n");
                    break;
                }
                printf("Select exercise (0-9):\n");
                for (int i = 0; i < MAX_EXERCISES; i++) {
                    printf("%d. %s\n", i, exercises[i].exercise_name);
                }
                scanf("%d", &exercise_index);
                if(exercise_index < 0 || exercise_index >= MAX_EXERCISES) {
                    printf("Invalid exercise selection.\n");
                    break;
                }
                
                // Enter duration
                printf("Enter duration (minutes): ");
                scanf("%f", &exercises[exercise_index].duration);
                log_exercise(&users[user_index - 1], &exercises[exercise_index]);
                break;
            }
            case 3: {
                int user_index;
                printf("Select user (1-%d): ", user_count);
                scanf("%d", &user_index);
                if(user_index < 1 || user_index > user_count) {
                    printf("Invalid user selection.\n");
                    break;
                }
                display_user_info(users[user_index - 1]);
                break;
            }
            case 4:
                display_all_users(users, user_count);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (1);

    return 0;
}