//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Struct for storing data about a workout session
typedef struct {
    int day;
    int month;
    int year;
    float duration;
    float distance;
    int calories;
} WorkoutSession;

// Function for displaying the menu
void displayMenu() {
    printf("\n");
    printf("+---------------------+\n");
    printf("|   FITNESS TRACKER   |\n");
    printf("+---------------------+\n");
    printf("| 1. Add Session      |\n");
    printf("| 2. View Sessions    |\n");
    printf("| 3. Delete Session   |\n");
    printf("| 4. Exit             |\n");
    printf("+---------------------+\n");
    printf("\n");
    printf("Enter an option: ");
}

// Function for adding a workout session
void addSession(WorkoutSession *sessions, int *numSessions) {
    printf("\n");
    printf("+---------------------+\n");
    printf("|     ADD SESSION     |\n");
    printf("+---------------------+\n");

    // Get the day, month, and year
    printf("Enter the day (1-31): ");
    scanf("%d", &sessions[*numSessions].day);
    printf("Enter the month (1-12): ");
    scanf("%d", &sessions[*numSessions].month);
    printf("Enter the year: ");
    scanf("%d", &sessions[*numSessions].year);

    // Get the duration, distance, and calories
    printf("Enter the duration (in minutes): ");
    scanf("%f", &sessions[*numSessions].duration);
    printf("Enter the distance (in kilometers): ");
    scanf("%f", &sessions[*numSessions].distance);
    printf("Enter the number of calories burned: ");
    scanf("%d", &sessions[*numSessions].calories);

    // Increment the number of sessions
    *numSessions += 1;
}

// Function for viewing all workout sessions
void viewSessions(WorkoutSession *sessions, int numSessions) {
    printf("\n");
    printf("+---------------------+\n");
    printf("|    VIEW SESSIONS    |\n");
    printf("+---------------------+\n");

    // Print all workout sessions
    for (int i = 0; i < numSessions; i++) {
        printf("Session %d:\n", i + 1);
        printf("  Date: %d/%d/%d\n", sessions[i].day, sessions[i].month, sessions[i].year);
        printf("  Duration: %.2f minutes\n", sessions[i].duration);
        printf("  Distance: %.2f kilometers\n", sessions[i].distance);
        printf("  Calories burned: %d\n", sessions[i].calories);
    }
}

// Function for deleting a workout session
void deleteSession(WorkoutSession *sessions, int *numSessions) {
    printf("\n");
    printf("+---------------------+\n");
    printf("|   DELETE SESSION    |\n");
    printf("+---------------------+\n");

    // Get the session number to delete
    printf("Enter the session number to delete: ");
    int sessionNum;
    scanf("%d", &sessionNum);

    // If the session number is valid, delete the session
    if (sessionNum > 0 && sessionNum <= *numSessions) {
        sessionNum -= 1;
        for (int i = sessionNum; i < *numSessions - 1; i++) {
            sessions[i] = sessions[i + 1];
        }
        *numSessions -= 1;
        printf("Session %d deleted.\n", sessionNum + 1);
    } else {
        printf("Invalid session number.\n");
    }
}

int main() {
    // Declare variables
    WorkoutSession sessions[100];
    int numSessions = 0;

    // Loop until the user chooses to exit
    int option = 0;
    while (option != 4) {
        displayMenu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                addSession(sessions, &numSessions);
                break;
            case 2:
                viewSessions(sessions, numSessions);
                break;
            case 3:
                deleteSession(sessions, &numSessions);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}