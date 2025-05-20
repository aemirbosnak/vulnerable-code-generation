//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that displays the main menu
void displayMainMenu() {
    printf("Welcome to C Fitness Tracker\n");
    printf("-----------------------------\n");
    printf("1. Add new user\n");
    printf("2. Add new workout\n");
    printf("3. Add new meal\n");
    printf("4. View user's workouts\n");
    printf("5. View user's meals\n");
    printf("6. Exit\n");
}

// User structure
struct User {
    char name[50];
    int age;
    float height;
    float weight;
    char gender;
};

// Workout structure
struct Workout {
    char name[50];
    char type[50];
    float duration;
    float caloriesBurned;
};

// Meal structure
struct Meal {
    char name[50];
    char type[50];
    float calories;
};

// Function that creates a new user
void createNewUser() {
    FILE *fp;
    fp = fopen("users.dat", "ab");
    struct User user;
    printf("Enter name: ");
    scanf("%s", user.name);
    printf("Enter age: ");
    scanf("%d", &user.age);
    printf("Enter height (in cm): ");
    scanf("%f", &user.height);
    printf("Enter weight (in kg): ");
    scanf("%f", &user.weight);
    printf("Enter gender (M/F): ");
    scanf(" %c", &user.gender);
    fwrite(&user, sizeof(struct User), 1, fp);
    fclose(fp);
    printf("User created successfully!\n");
}

// Function that creates a new workout
void createNewWorkout() {
    FILE *fp;
    fp = fopen("workouts.dat", "ab");
    struct Workout workout;
    printf("Enter user's name: ");
    char name[50];
    scanf("%s", name);
    printf("Enter workout name: ");
    scanf("%s", workout.name);
    printf("Enter workout type: ");
    scanf("%s", workout.type);
    printf("Enter workout duration (in minutes): ");
    scanf("%f", &workout.duration);
    printf("Enter calories burned: ");
    scanf("%f", &workout.caloriesBurned);
    fwrite(&workout, sizeof(struct Workout), 1, fp);
    fclose(fp);
    printf("Workout created successfully!\n");
}

// Function that creates a new meal
void createNewMeal() {
    FILE *fp;
    fp = fopen("meals.dat", "ab");
    struct Meal meal;
    printf("Enter user's name: ");
    char name[50];
    scanf("%s", name);
    printf("Enter meal name: ");
    scanf("%s", meal.name);
    printf("Enter meal type: ");
    scanf("%s", meal.type);
    printf("Enter calories: ");
    scanf("%f", &meal.calories);
    fwrite(&meal, sizeof(struct Meal), 1, fp);
    fclose(fp);
    printf("Meal created successfully!\n");
}

// Function that displays a user's workouts
void viewUserWorkouts() {
    FILE *fp;
    fp = fopen("workouts.dat", "rb");
    char name[50];
    struct Workout workout;
    printf("Enter user's name: ");
    scanf("%s", name);
    while (fread(&workout, sizeof(struct Workout), 1, fp)) {
        if (strcmp(workout.name, name) == 0) {
            printf("Workout name: %s\n", workout.name);
            printf("Workout type: %s\n", workout.type);
            printf("Duration: %.2f minutes\n", workout.duration);
            printf("Calories burned: %.2f\n", workout.caloriesBurned);
            printf("-----------------------------\n");
        }
    }
    fclose(fp);
}

// Function that displays a user's meals
void viewUserMeals() {
    FILE *fp;
    fp = fopen("meals.dat", "rb");
    char name[50];
    struct Meal meal;
    printf("Enter user's name: ");
    scanf("%s", name);
    while (fread(&meal, sizeof(struct Meal), 1, fp)) {
        if (strcmp(meal.name, name) == 0) {
            printf("Meal name: %s\n", meal.name);
            printf("Meal type: %s\n", meal.type);
            printf("Calories: %.2f\n", meal.calories);
            printf("-----------------------------\n");
        }
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                createNewUser();
                break;
            case 2:
                createNewWorkout();
                break;
            case 3:
                createNewMeal();
                break;
            case 4:
                viewUserWorkouts();
                break;
            case 5:
                viewUserMeals();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.");
        }
    } while(1);
    return 0;
}