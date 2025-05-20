//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ACTIVITIES 10

// Define a struct that represents a single activity, including its name and duration.
typedef struct activity_t {
    char name[MAX_NAME_LEN];
    int duration_minutes;
} activity_t;

// Define a struct that represents a fitness log for a single day,
// including a date and an array of activities.
typedef struct fitness_log_t {
    int day;
    int month;
    int year;
    int num_activities;
    activity_t activities[MAX_ACTIVITIES];
} fitness_log_t;

// Helper function to prompt the user for input and return an integer value.
int get_int_input(char* prompt) {
    char input_buffer[256];
    int value = 0;
    while (value == 0) {
        printf("%s", prompt);
        fgets(input_buffer, sizeof(input_buffer), stdin);
        if (sscanf(input_buffer, "%d", &value) != 1) {
            printf("Invalid input. Please enter a number.\n");
        }
    }
    return value;
}

// Helper function to prompt the user for input and return a string value.
void get_string_input(char* prompt, char* buffer, int buffer_size) {
    printf("%s", prompt);
    fgets(buffer, buffer_size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;  // Strip newline character.
}

// Helper function to display a fitness log to the console.
void display_fitness_log(fitness_log_t* log) {
    printf("Fitness Log for %d/%d/%d:\n", log->day, log->month, log->year);
    printf("Activities:\n");
    for (int i = 0; i < log->num_activities; i++) {
        printf("%s (%d minutes)\n", log->activities[i].name, log->activities[i].duration_minutes);
    }
}

// Function to add a new activity to a fitness log.
void add_activity(fitness_log_t* log) {
    if (log->num_activities >= MAX_ACTIVITIES) {
        printf("Cannot add more activities to the log.\n");
        return;
    }
    printf("Enter activity name: ");
    get_string_input("", log->activities[log->num_activities].name, sizeof(log->activities[log->num_activities].name));
    log->activities[log->num_activities].duration_minutes = get_int_input("Enter activity duration (minutes): ");
    log->num_activities++;
}

// Main program entry point.
int main() {
    char input_buffer[256];
    fitness_log_t fitness_log;
    memset(&fitness_log, 0, sizeof(fitness_log_t));  // Initialize the log to zero.

    // Prompt the user for the date of the fitness log.
    fitness_log.day = get_int_input("Enter day: ");
    fitness_log.month = get_int_input("Enter month: ");
    fitness_log.year = get_int_input("Enter year: ");

    // Loop until the user chooses to exit.
    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add new activity\n");
        printf("2. Display log\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3): ");
        fgets(input_buffer, sizeof(input_buffer), stdin);

        // Parse the user's choice and execute the corresponding action.
        int choice = 0;
        if (sscanf(input_buffer, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number from 1 to 3.\n");
            continue;
        }
        switch (choice) {
            case 1:
                add_activity(&fitness_log);
                break;
            case 2:
                display_fitness_log(&fitness_log);
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number from 1 to 3.\n");
                break;
        }
    }
}