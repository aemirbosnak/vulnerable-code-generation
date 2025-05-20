//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum size of the array
#define MAX_SIZE 100

// Struct to hold fitness data
struct workout {
    char date[20];  // Date of workout
    int calories;   // Calories burnt during workout
    int duration;   // Duration of workout in minutes
};

// Function to convert minutes to hours and minutes
void convert_to_hours(int duration, int *hours, int *mins) {
    *hours = duration / 60;
    *mins = duration % 60;
}

int main() {
    struct workout logs[MAX_SIZE];  // Array to store workout logs
    int num_logs = 0;   // Counter for number of logs

    // Loop to get input from user and store the log
    char choice = 'y';
    while (choice == 'y') {
        printf("Enter date (DD/MM/YYYY): ");
        fflush(stdin);
        fgets(logs[num_logs].date, 20, stdin);
        logs[num_logs].date[strcspn(logs[num_logs].date, "\n")] = 0; // removing trailing newline character

        printf("Enter calories burned: ");
        scanf("%d", &logs[num_logs].calories);

        printf("Enter duration (in minutes): ");
        scanf("%d", &logs[num_logs].duration);

        num_logs++; // Incrementing log counter

        printf("Do you want to log another workout? (y/n): ");
        fflush(stdin);
        scanf("%c", &choice);
    }

    // Printing out logs in a formatted way
    printf("\n\nFitness Tracker Log:\n\n");
    printf("Date\t\tCalories Burned\tDuration\n");
    for (int i = 0; i < num_logs; i++) {
        int hours, mins;
        convert_to_hours(logs[i].duration, &hours, &mins);
        printf("%s\t%d\t\t%d:%02d\n", logs[i].date, logs[i].calories, hours, mins);
    }

    return 0;
}