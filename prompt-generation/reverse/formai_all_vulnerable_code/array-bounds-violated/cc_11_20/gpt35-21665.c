//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>

int main()
{
    char weekDays[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int appointments[7][12] = {0};
    int day, hour, choice, i, j;

    printf("Welcome to the Appointment Scheduler!\n\n");

    do {
        printf("1. Schedule an Appointment\n");
        printf("2. Cancel an Appointment\n");
        printf("3. View Appointments\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the day of the week (1-7): ");
                scanf("%d", &day);

                printf("Enter the hour of the day (1-12): ");
                scanf("%d", &hour);

                if (appointments[day-1][hour-1]) {
                    printf("\nOops! An appointment already exists for that day and time. Please choose a different day and/or time.\n\n");
                } else {
                    appointments[day-1][hour-1] = 1;
                    printf("\nCongratulations! Your appointment has been scheduled for %s at %d:00.\n\n", weekDays[day-1], hour);
                }

                break;

            case 2:
                printf("\nEnter the day of the week (1-7): ");
                scanf("%d", &day);

                printf("Enter the hour of the day (1-12): ");
                scanf("%d", &hour);

                if (appointments[day-1][hour-1]) {
                    appointments[day-1][hour-1] = 0;
                    printf("\nYour appointment has been cancelled for %s at %d:00. Sorry for the inconvenience.\n\n", weekDays[day-1], hour);
                } else {
                    printf("\nOops! No appointment exists for that day and time. Please choose a different day and/or time.\n\n");
                }

                break;

            case 3:
                printf("\nAppointments:\n");

                for (i = 0; i < 7; i++) {
                    printf("%s: ", weekDays[i]);
                    for (j = 0; j < 12; j++) {
                        if (appointments[i][j]) {
                            printf("%d:00, ", j+1);
                        }
                    }
                    printf("\n");
                }

                printf("\n");

                break;

            case 4:
                printf("\nThank you for using the Appointment Scheduler! Have a great day!\n\n");
                break;

            default:
                printf("\nOops! Invalid choice. Please choose a valid option (1-4).\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}