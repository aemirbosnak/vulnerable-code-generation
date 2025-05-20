//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//function prototypes
void displayMenu();
int getChoice();
void addNewUser();
void trackUserProgress();
void displayWorkouts();
void saveData();
void loadData();

//structs
struct User {
    char name[20];
    int age;
    double height;
    double weight;
    bool isMale;
    bool isBeginner;
    double bmi;
    double bmr;
    double maintenanceCalories;
    double dailyCaloricIntake;
    int weeksCompleted;
    double weightProgress[52];
    double workoutFrequency[7];
};

struct Workout {
    char name[20];
    char description[100];
    double caloriesBurnedPerMinute;
};

//global variables
int numUsers = 0;
int numWorkouts = 0;
struct User users[10];
struct Workout workouts[10];

int main() {
    loadData();
    bool quit = false;
    while (!quit) {
        displayMenu();
        int choice = getChoice();
        switch(choice) {
            case 1:
                addNewUser();
                break;
            case 2:
                trackUserProgress();
                break;
            case 3:
                displayWorkouts();
                break;
            case 4:
                saveData();
                quit = true;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

//function definitions
void displayMenu() {
    printf("\n----- C Fitness Tracker -----\n");
    printf("1. Add New User\n");
    printf("2. Track User Progress\n");
    printf("3. Display Workouts\n");
    printf("4. Save and Exit\n");
}

int getChoice() {
    char input[10];
    printf("Enter your choice: ");
    fgets(input, 10, stdin);
    int choice = atoi(input);
    return choice;
}

void addNewUser() {
    if (numUsers >= 10) {
        printf("Error: Max number of users reached.\n");
        return;
    }
    struct User newUser;
    printf("\nCreating a New User\n");
    printf("Enter user's name: ");
    fgets(newUser.name, 20, stdin);
    printf("Enter user's age: ");
    scanf("%d", &newUser.age);
    printf("Enter user's height (in meters): ");
    scanf("%lf", &newUser.height);
    printf("Enter user's weight (in kilograms): ");
    scanf("%lf", &newUser.weight);
    printf("Enter user's gender (M or F): ");
    char gender[10];
    fgets(gender, 10, stdin);
    if (gender[0] == 'M' || gender[0] == 'm') {
        newUser.isMale = true;
    } else {
        newUser.isMale = false;
    }
    printf("Is user a beginner (Y or N): ");
    char beginner[10];
    fgets(beginner, 10, stdin);
    if (beginner[0] == 'Y' || beginner[0] == 'y') {
        newUser.isBeginner = true;
    } else {
        newUser.isBeginner = false;
    }
    if (newUser.height <= 0 || newUser.weight <= 0) {
        printf("Error: Invalid height or weight entered.");
        return;
    }
    newUser.bmi = newUser.weight / (newUser.height * newUser.height);
    if (newUser.isMale) {
        newUser.bmr = 88.362 + (13.397 * newUser.weight) + (4.799 * newUser.height * 100) - (5.677 * newUser.age);
    } else {
        newUser.bmr = 447.593 + (9.247 * newUser.weight) + (3.098 * newUser.height * 100) - (4.330 * newUser.age);;
    }
    if (newUser.isBeginner) {
        newUser.maintenanceCalories = newUser.bmr * 1.3;
    } else {
        newUser.maintenanceCalories = newUser.bmr * 1.5;
    }
    newUser.dailyCaloricIntake = newUser.maintenanceCalories;
    users[numUsers] = newUser;
    numUsers++;
}

void trackUserProgress() {
    if (numUsers == 0) {
        printf("Error: No users found.");
        return;
    }
    printf("\nEnter User's Name: ");
    char userName[20];
    fgets(userName, 20, stdin);
    int userIndex = -1;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(userName, users[i].name) == 0) {
            userIndex = i;
            printf("\nUser Found!\n");
            break;
        }
    }
    if (userIndex == -1) {
        printf("Error: User not found.\n");
        return;
    }
    printf("Enter today's weight (in kilograms): ");
    double weightToday;
    scanf("%lf", &weightToday);
    users[userIndex].weightProgress[users[userIndex].weeksCompleted * 7] = weightToday;
    users[userIndex].dailyCaloricIntake = users[userIndex].dailyCaloricIntake - 500;
    printf("\n==========================\n");
    printf("Week %d, Day 1:\n", users[userIndex].weeksCompleted + 1);
    printf("==========================\n");
    printf("Daily Caloric Intake: %.0lf\n", users[userIndex].dailyCaloricIntake);
    printf("Weight Today: %.2lf\n", weightToday);
    double weeklyWorkouts = 0;
    for (int i = 0; i < 7; i++) {
        printf("Enter workout frequency for Day %d: ", i + 1);
        scanf("%lf", &users[userIndex].workoutFrequency[i]);
        weeklyWorkouts += users[userIndex].workoutFrequency[i];
    }
    weeklyWorkouts /= 7;
    printf("Average Weekly Workouts: %.2lf\n", weeklyWorkouts);
    if (users[userIndex].weeksCompleted > 0 && weeklyWorkouts > 1) {
        printf("Congrats! You've increased your workout frequency!");
    }
    users[userIndex].weeksCompleted++;
}

void displayWorkouts() {
    if (numWorkouts == 0) {
        printf("Error: No workouts found.");
        return;
    }
    printf("\nAvailable Workouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%d. %s (%.2lf cal/min)\n", i+1, workouts[i].name, workouts[i].caloriesBurnedPerMinute);
        printf("\t%s\n", workouts[i].description);
    }
    printf("\n");
}

void saveData() {
    FILE *fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error: File could not be opened.\n");
        return;
    }
    fprintf(fp, "%d\n", numUsers);
    for (int i = 0; i < numUsers; i++) {
        fprintf(fp, "%s\n", users[i].name);
        fprintf(fp, "%d\n", users[i].age);
        fprintf(fp, "%lf\n", users[i].height);
        fprintf(fp, "%lf\n", users[i].weight);
        fprintf(fp, "%d\n", users[i].isMale);
        fprintf(fp, "%d\n", users[i].isBeginner);
        fprintf(fp, "%lf\n", users[i].bmi);
        fprintf(fp, "%lf\n", users[i].bmr);
        fprintf(fp, "%lf\n", users[i].maintenanceCalories);
        fprintf(fp, "%lf\n", users[i].dailyCaloricIntake);
        fprintf(fp, "%d\n", users[i].weeksCompleted);
        fprintf(fp, "%d ", 52);
        for (int j = 0; j < 52; j++) {
            fprintf(fp, "%lf ", users[i].weightProgress[j]);
        }
        fprintf(fp, "\n");
        for (int j = 0; j < 7; j++) {
            fprintf(fp, "%lf ", users[i].workoutFrequency[j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "%d\n", numWorkouts);
    for (int i = 0; i < numWorkouts; i++) {
        fprintf(fp, "%s\n", workouts[i].name);
        fprintf(fp, "%s\n", workouts[i].description);
        fprintf(fp, "%lf\n", workouts[i].caloriesBurnedPerMinute);
    }
    fclose(fp);
}

void loadData() {
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: File could not be opened.\n");
        return;
    }
    fscanf(fp, "%d\n", &numUsers);
    for (int i = 0; i < numUsers; i++) {
        struct User loadedUser;
        fgets(loadedUser.name, 20, fp);
        fscanf(fp, "%d\n", &loadedUser.age);
        fscanf(fp, "%lf\n", &loadedUser.height);
        fscanf(fp, "%lf\n", &loadedUser.weight);
        fscanf(fp, "%d\n", &loadedUser.isMale);
        fscanf(fp, "%d\n", &loadedUser.isBeginner);
        fscanf(fp, "%lf\n", &loadedUser.bmi);
        fscanf(fp, "%lf\n", &loadedUser.bmr);
        fscanf(fp, "%lf\n", &loadedUser.maintenanceCalories);
        fscanf(fp, "%lf\n", &loadedUser.dailyCaloricIntake);
        fscanf(fp, "%d\n", &loadedUser.weeksCompleted);
        int temp;
        fscanf(fp, "%d ", &temp);
        for (int j = 0; j < temp; j++) {
            fscanf(fp, "%lf ", &loadedUser.weightProgress[j]);
        }
        fscanf(fp, "\n");
        for (int j = 0; j < 7; j++) {
            fscanf(fp, "%lf ", &loadedUser.workoutFrequency[j]);
        }
        fscanf(fp, "\n");
        users[i] = loadedUser;
    }
    fscanf(fp, "%d\n", &numWorkouts);
    for (int i = 0; i < numWorkouts; i++) {
        struct Workout loadedWorkout;
        fgets(loadedWorkout.name, 20, fp);
        fgets(loadedWorkout.description, 100, fp);
        fscanf(fp, "%lf\n", &loadedWorkout.caloriesBurnedPerMinute);
        workouts[i] = loadedWorkout;
    }
    fclose(fp);
}