//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include<stdio.h>
#include<string.h>

// Define constants for the program
#define MAX_DAY 31
#define MAX_ACTIVITY 20
#define MAX_CALORIES 1000

// Define a struct for the date
struct Date {
    int day;
    int month;
    int year;
};

// Define a struct for the activity log for a day
struct ActivityLog {
    int caloriesBurned;
    char activity[MAX_ACTIVITY];
};

// Define a struct for the fitness tracker data for a month
struct FitnessTracker {
    struct ActivityLog logs[MAX_DAY];
    int totalCalories;
};

// Function to display the main menu
void displayMenu() {
    printf("\n\n");
    printf("Fitness Tracker\n");
    printf("---------------\n");
    printf("1. Add Activity\n");
    printf("2. View Activity\n");
    printf("3. Edit Activity\n");
    printf("4. Delete Activity\n");
    printf("5. View Statistics\n");
    printf("6. Exit\n");
    printf("\n\n");
}

// Function to get the date from the user
struct Date getDate() {
    struct Date date;
    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date.day, &date.month, &date.year);
    return date;
}

// Function to add an activity log for a day
void addActivity(struct FitnessTracker *ft) {
    struct Date date = getDate();
    printf("\nEnter Activity: ");
    char activity[MAX_ACTIVITY];
    scanf("%s", activity);
    printf("\nEnter Calories Burned: ");
    int calories = 0;
    scanf("%d", &calories);

    // Check if the date is valid
    if(date.day > MAX_DAY || date.day < 0 || date.month < 0 || date.month > 12) {
        printf("\nInvalid Date Entered!");
        return;
    }

    // Add the activity log to the fitness tracker data
    int index = date.day - 1;
    struct ActivityLog log;
    log.caloriesBurned = calories;
    strcpy(log.activity, activity);
    ft->logs[index] = log;
    ft->totalCalories += calories;
    printf("\nActivity Added Successfully!");
}

// Function to view the activity log for a day
void viewActivity(struct FitnessTracker ft) {
    struct Date date = getDate();
    int index = date.day - 1;
    struct ActivityLog log = ft.logs[index];
    printf("\nActivity for %d/%d/%d: \n\n", date.day, date.month, date.year);
    printf("Activity: %s\n", log.activity);
    printf("Calories Burned: %d\n", log.caloriesBurned);
}

// Function to edit the activity log for a day
void editActivity(struct FitnessTracker *ft) {
    struct Date date = getDate();
    int index = date.day - 1;
    struct ActivityLog log = ft->logs[index];
    printf("\nActivity for %d/%d/%d: \n\n", date.day, date.month, date.year);
    printf("Current Activity: %s\n", log.activity);
    printf("Current Calories Burned: %d\n", log.caloriesBurned);
    printf("\nEnter New Activity: ");
    char activity[MAX_ACTIVITY];
    scanf("%s", activity);
    printf("\nEnter New Calories Burned: ");
    int calories = 0;
    scanf("%d", &calories);
    strcpy(log.activity, activity);
    log.caloriesBurned = calories;
    ft->logs[index] = log;
    ft->totalCalories = ft->totalCalories - log.caloriesBurned + calories;
    printf("\nActivity Edited Successfully!");
}

// Function to delete the activity log for a day
void deleteActivity(struct FitnessTracker *ft) {
    struct Date date = getDate();
    int index = date.day - 1;
    struct ActivityLog log = ft->logs[index];
    printf("\nActivity for %d/%d/%d: \n\n", date.day, date.month, date.year);
    printf("Activity: %s\n", log.activity);
    printf("Calories Burned: %d\n", log.caloriesBurned);
    ft->totalCalories -= log.caloriesBurned;
    struct ActivityLog emptyLog = {0, ""};
    ft->logs[index] = emptyLog;
    printf("\nActivity Deleted Successfully!");
}

// Function to view the statistics for the month
void viewStatistics(struct FitnessTracker ft) {
    printf("\nMonthy Statistics: \n");
    printf("\nTotal Calories Burned: %d\n", ft.totalCalories);
}

// The main function
int main() {
    struct FitnessTracker ft;
    ft.totalCalories = 0;

    int choice = 0;

    // Display the main menu and prompt for user input
    do {
        displayMenu();
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addActivity(&ft); break;
            case 2: viewActivity(ft); break;
            case 3: editActivity(&ft); break;
            case 4: deleteActivity(&ft); break;
            case 5: viewStatistics(ft); break;
            case 6: printf("\nThank You For Using Fitness Tracker!\n"); break;
            default: printf("\nInvalid Choice!\n"); break;
        }
    } while(choice != 6);

    return 0;
}