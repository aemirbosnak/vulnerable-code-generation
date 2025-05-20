//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 50
#define MAX_WORKOUTS 10

struct workout {
    char name[50];
    int duration;
    int calories_burned;
};

struct user {
    char name[50];
    int age;
    float height;
    float weight;
    bool is_male;
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts;
} users[MAX_USERS];

int num_users = 0;

void display_menu(void);
void add_user(void);
void log_workout(int user_index);
void display_user_stats(int user_index);

int main()
{
    int choice;

    while (1)
    {
        display_menu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_user();
                break;
            case 2:
                log_workout(0);
                break;
            case 3:
                log_workout(1);
                break;
            case 4:
                display_user_stats(0);
                break;
            case 5:
                display_user_stats(1);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

void display_menu()
{
    printf("\n\n");
    printf("***************************************************\n");
    printf("*************** FITNESS TRACKER MENU **************\n");
    printf("***************************************************\n");
    printf("*                                                 *\n");
    printf("* 1. Add a User                                   *\n");
    printf("* 2. Log a Workout for User #1                     *\n");
    printf("* 3. Log a Workout for User #2                     *\n");
    printf("* 4. Display Stats for User #1                     *\n");
    printf("* 5. Display Stats for User #2                     *\n");
    printf("* 6. Exit                                         *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");
}

void add_user()
{
    if (num_users >= MAX_USERS)
    {
        printf("Sorry, the maximum number of users has been reached.\n");
        return;
    }

    struct user new_user;

    printf("Enter user name: ");
    scanf("%s", new_user.name);

    printf("Enter user age: ");
    scanf("%d", &new_user.age);

    printf("Enter user height (in metres): ");
    scanf("%f", &new_user.height);

    printf("Enter user weight (in kg): ");
    scanf("%f", &new_user.weight);

    printf("Is user male (1 for yes, 0 for no): ");
    scanf("%d", &new_user.is_male);

    new_user.num_workouts = 0;

    users[num_users++] = new_user;

    printf("User added successfully!\n");
}

void log_workout(int user_index)
{
    if (user_index < 0 || user_index >= num_users)
    {
        printf("Invalid user index.\n");
        return;
    }

    struct user *current_user = &users[user_index];

    if (current_user->num_workouts >= MAX_WORKOUTS)
    {
        printf("Sorry, the maximum number of workouts has been reached for this user.\n");
        return;
    }

    struct workout new_workout;

    printf("Enter workout name: ");
    scanf("%s", new_workout.name);

    printf("Enter workout duration (in minutes): ");
    scanf("%d", &new_workout.duration);

    printf("Enter calories burned during workout: ");
    scanf("%d", &new_workout.calories_burned);

    current_user->workouts[current_user->num_workouts++] = new_workout;

    printf("Workout logged successfully for user %d!\n", user_index + 1);
}

void display_user_stats(int user_index)
{
    if (user_index < 0 || user_index >= num_users)
    {
        printf("Invalid user index.\n");
        return;
    }

    struct user *current_user = &users[user_index];

    float bmi = current_user->weight / (current_user->height * current_user->height);

    printf("\n***************************************************\n");
    printf("***************** USER STATS **********************\n");
    printf("***************************************************\n");
    printf("*                                                 *\n");
    printf("* Name: %-40s*\n", current_user->name);
    printf("* Age: %-41d*\n", current_user->age);
    printf("* Height: %-38.2fm*\n", current_user->height);
    printf("* Weight: %-38.2fkg*\n", current_user->weight);

    if (current_user->is_male)
    {
        printf("* Gender: Male                                    *\n");
        printf("* BMI: %-42.2f*\n", bmi);
    }
    else
    {
        printf("* Gender: Female                                  *\n");
        printf("* BMI: %-42.2f*\n", bmi + 1.0);
    }

    printf("*                                                 *\n");
    printf("***************************************************\n");

    printf("\n");

    printf("WORKOUTS:\n\n");

    if (current_user->num_workouts == 0)
    {
        printf("No workouts logged yet.\n");
    }
    else
    {
        int total_duration = 0;
        int total_calories = 0;

        for (int i = 0; i < current_user->num_workouts; i++)
        {
            struct workout w = current_user->workouts[i];

            printf("%-30s%-10d%-20d\n", w.name, w.duration, w.calories_burned);

            total_duration += w.duration;
            total_calories += w.calories_burned;
        }

        printf("\n");

        printf("TOTALS:\n");
        printf("Duration: %d minutes\n", total_duration);
        printf("Calories Burned: %d\n", total_calories);

        printf("\n");
    }
}