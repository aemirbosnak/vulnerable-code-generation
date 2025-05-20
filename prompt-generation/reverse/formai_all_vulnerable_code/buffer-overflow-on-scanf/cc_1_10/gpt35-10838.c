//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand((unsigned) time(&t)); //initialize random seed

    //initialize appointment schedule with empty slots
    int schedule[7][8];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            schedule[i][j] = 0;
        }
    }

    printf("Welcome to the appointment scheduler!\n\n");

    while (1) {
        int choice;
        printf("Please choose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View schedule\n");
        printf("3. Quit\n");
        printf("Enter a choice (1-3): ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            int day, hour;
            printf("Enter the day of the week (1-7): ");
            scanf("%d", &day);
            printf("Enter the hour of the day (1-8): ");
            scanf("%d", &hour);

            if (schedule[day-1][hour-1] == 1) {
                printf("That slot is already taken. Please choose another.\n");
            } else {
                schedule[day-1][hour-1] = 1;
                printf("Appointment scheduled for day %d, hour %d.\n", day, hour);
            }
        } else if (choice == 2) {
            printf("Schedule:\n");
            printf("      8AM  9AM  10AM 11AM 12PM  1PM  2PM  3PM\n");
            printf("   __________________________________________\n");
            for (int i = 0; i < 7; i++) {
                printf("Day %d|", i+1);
                for (int j = 0; j < 8; j++) {
                    printf("  %d   ", schedule[i][j]);
                }
                printf(" |\n");
            }
            printf("   __________________________________________\n");
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

        printf("\n");
    }

    return 0;
}