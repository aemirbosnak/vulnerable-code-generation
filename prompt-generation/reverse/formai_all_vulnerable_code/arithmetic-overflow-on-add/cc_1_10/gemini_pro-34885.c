//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structures
typedef struct {
    char name[32];
    int age;
    float height;
    float weight;
    int steps_taken;
    int calories_burned;
} User;

typedef struct {
    int day;
    int month;
    int year;
    int steps_taken;
    int calories_burned;
} ActivityLog;

// Function prototypes
void print_user_data(User *user);
void print_activity_log(ActivityLog *log);
void add_activity_log(User *user, ActivityLog *log);

// Main function
int main() {
    // Create a user
    User user = {
        "John Doe",
        30,
        1.80,
        80.0,
        0,
        0
    };

    // Create an activity log
    ActivityLog log = {
        0,
        0,
        0,
        0,
        0
    };

    // Add some activity logs
    add_activity_log(&user, &log);
    add_activity_log(&user, &log);
    add_activity_log(&user, &log);

    // Print the user data
    print_user_data(&user);

    // Print the activity log
    print_activity_log(&log);

    return 0;
}

// Function definitions
void print_user_data(User *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %.2f\n", user->height);
    printf("Weight: %.2f\n", user->weight);
    printf("Steps taken: %d\n", user->steps_taken);
    printf("Calories burned: %d\n", user->calories_burned);
}

void print_activity_log(ActivityLog *log) {
    printf("Date: %d/%d/%d\n", log->day, log->month, log->year);
    printf("Steps taken: %d\n", log->steps_taken);
    printf("Calories burned: %d\n", log->calories_burned);
}

void add_activity_log(User *user, ActivityLog *log) {
    // Get the current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Update the activity log
    log->day = tm->tm_mday;
    log->month = tm->tm_mon + 1;
    log->year = tm->tm_year + 1900;
    log->steps_taken = rand() % 10000;
    log->calories_burned = rand() % 1000;

    // Update the user data
    user->steps_taken += log->steps_taken;
    user->calories_burned += log->calories_burned;
}