//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct user {
    char name[50];
    char gender[10];
    int age;
    float height;
    float weight;
};

struct workout {
    char exercise[50];
    int sets;
    int reps;
    float weight;
};

typedef struct user User;
typedef struct workout Workout;

void input_user(User* user) {
    printf("Enter name: ");
    scanf("%[^\n]%*c", user->name);
    printf("Enter gender (Male/Female): ");
    scanf("%s", user->gender);
    printf("Enter age: ");
    scanf("%d", &user->age);
    printf("Enter height (in meters): ");
    scanf("%f", &user->height);
    printf("Enter weight (in kg): ");
    scanf("%f", &user->weight);
}

void print_user(User user) {
    printf("Name: %s\n", user.name);
    printf("Gender: %s\n", user.gender);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f meters\n", user.height);
    printf("Weight: %.2f kg\n", user.weight);
}

void input_workout(Workout* workout) {
    printf("Enter exercise name: ");
    scanf("%[^\n]%*c", workout->exercise);
    printf("Enter number of sets: ");
    scanf("%d", &workout->sets);
    printf("Enter reps per set: ");
    scanf("%d", &workout->reps);
    printf("Enter weight used (in kg): ");
    scanf("%f", &workout->weight);
}

void print_workout(Workout workout) {
    printf("Exercise: %s\n", workout.exercise);
    printf("Number of sets: %d\n", workout.sets);
    printf("Reps per set: %d\n", workout.reps);
    printf("Weight used: %.2f kg\n", workout.weight);
}

void save_workout(char* filename, Workout workout) {
    FILE* fp = fopen(filename, "a");
    if(fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fp, "%s,%d,%d,%.2f\n", workout.exercise, workout.sets, workout.reps, workout.weight);
    fclose(fp);
}

bool check_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        return false;
    }
    fclose(fp);
    return true;
}

void display_workouts(char* filename) {
    if(!check_file(filename)) {
        printf("No workouts found.\n");
        return;
    }
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    char line[100];
    printf("Workouts:\n");
    while(fgets(line, 100, fp)) {
        char* exercise = strtok(line, ",");
        int sets = atoi(strtok(NULL, ","));
        int reps = atoi(strtok(NULL, ","));
        float weight = atof(strtok(NULL, ","));
        printf("%s - Sets: %d, Reps: %d, Weight: %.2fkg\n", exercise, sets, reps, weight);
    }
    fclose(fp);
}

int main() {
    char filename[] = "workouts.csv";

    printf("Welcome to Fitness Tracker!\n");
    printf("Please enter your details:\n");
    User user;
    input_user(&user);
    printf("Your profile:\n");
    print_user(user);

    while(true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a workout\n");
        printf("2. View previous workouts\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            Workout workout;
            input_workout(&workout);
            save_workout(filename, workout);
            printf("Workout saved successfully.\n");
        } else if(choice == 2) {
            display_workouts(filename);
        } else if(choice == 3) {
            printf("Thank you for using Fitness Tracker!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}