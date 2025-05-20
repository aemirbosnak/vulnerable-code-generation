//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: standalone
/*
 * Fitness Tracker Example Program
 *
 * This program tracks the user's physical activity and displays it on a graph.
 * It uses a command-line interface and allows the user to input their activity.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about the user's activity
typedef struct {
    char activity[50]; // Activity type (e.g. "walking", "running", etc.)
    int duration; // Duration of activity in minutes
} Activity;

// Function to display the activity graph
void display_activity_graph(Activity* activities, int num_activities) {
    printf("Activity Graph:\n");
    for (int i = 0; i < num_activities; i++) {
        printf("|");
        for (int j = 0; j < activities[i].duration; j++) {
            printf("=");
        }
        printf("|\n");
    }
}

int main() {
    // Initialize variables
    Activity activities[100]; // Array to store activity information
    int num_activities = 0; // Number of activities entered by the user
    char input[50]; // User input

    // Loop until the user exits the program
    while (1) {
        // Display the menu
        printf("Welcome to the Fitness Tracker!\n");
        printf("1. Add an activity\n");
        printf("2. Display activity graph\n");
        printf("3. Exit\n");

        // Get the user's input
        scanf("%s", input);

        // Add an activity
        if (strcmp(input, "1") == 0) {
            printf("Enter the activity type: ");
            scanf("%s", activities[num_activities].activity);
            printf("Enter the duration (in minutes): ");
            scanf("%d", &activities[num_activities].duration);
            num_activities++;
        }

        // Display the activity graph
        else if (strcmp(input, "2") == 0) {
            display_activity_graph(activities, num_activities);
        }

        // Exit the program
        else if (strcmp(input, "3") == 0) {
            break;
        }

        // Invalid input
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}