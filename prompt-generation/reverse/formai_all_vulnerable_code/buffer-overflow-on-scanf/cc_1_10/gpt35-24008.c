//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <string.h>

struct appointment {
    char date[20];
    char time[20];
    char reason[100];
};

int main() {
    // declare variables
    char name[50];
    struct appointment appt[5];
    int count = 0;

    // get user input for name
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Please enter your name: ");
    fgets(name, 50, stdin);

    // display main menu
    printf("\nHi, %s\n", name);
    printf("What would you like to do?\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
    printf("Enter your choice (1, 2, or 3): ");

    int choice;
    scanf("%d", &choice);

    while (choice != 3) {
        switch (choice) {
            case 1:
                // user wants to schedule appointment
                printf("\nYou have chosen to schedule an appointment.\n");
                
                // check if limit of 5 appointments has been reached
                if (count >= 5) {
                    printf("Sorry, you have reached the limit of appointments (5).\n");
                    break;
                }
                
                printf("Please enter the date (mm/dd/yyyy): ");
                scanf("%s", appt[count].date);

                printf("Please enter the time (hh:mm am/pm): ");
                scanf("%s", appt[count].time);

                printf("Please enter the reason for the appointment: ");
                scanf("%s", appt[count].reason);

                count++;
                printf("\nAppointment successfully scheduled!\n");
                break;

            case 2:
                // user wants to view their appointments
                printf("\nYou have chosen to view your appointments.\n");

                // check if there are any appointments to display
                if (count == 0) {
                    printf("You have no appointments scheduled.\n");
                    break;
                }

                printf("\nYour Appointments:\n");
                for (int i = 0; i < count; i++) {
                    printf("Appointment %d:\n", i+1);
                    printf("Date: %s\n", appt[i].date);
                    printf("Time: %s\n", appt[i].time);
                    printf("Reason: %s\n", appt[i].reason);
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // display main menu again
        printf("\nWhat would you like to do now?\n");
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice (1, 2, or 3): ");
        scanf("%d", &choice);
    }

    printf("\nThank you for using the Appointment Scheduler!\n");

    return 0;
}