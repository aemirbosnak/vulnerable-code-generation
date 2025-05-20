//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>

// Function to print welcome message and menu options
void displayMenu() {
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Please select an option from the menu:\n");
    printf("1. Create new appointment\n");
    printf("2. View upcoming appointments\n");
    printf("3. Cancel appointment\n");
    printf("4. Exit\n");
}

int main() {
    int option; // variable to store user's menu option choice
    int numAppointments = 0; // variable to keep track of number of appointments
    char appointments[10][30]; // 2d array to store appointments (maximum 10)

    while (1) {
        displayMenu();
        scanf("%d", &option);

        // switch statement to perform different actions based on user's menu option choice
        switch(option) {
            case 1: // create new appointment
                if (numAppointments == 10) {
                    printf("Sorry, the maximum number of appointments has been reached!\n");
                    break;
                }
                printf("Enter the date and time of the appointment (format: 'MM/DD/YYYY HH:MM AM/PM'): ");
                scanf(" %[^\n]%*c", appointments[numAppointments]); // read appointment date and time input from user and store in array
                numAppointments++; // increment the number of appointments
                printf("Appointment successfully scheduled!\n");
                break;

            case 2: // view upcoming appointments
                if (numAppointments == 0) {
                    printf("You have no upcoming appointments!\n");
                } else {
                    printf("Upcoming Appointments:\n");
                    for (int i = 0; i < numAppointments; i++) {
                        printf("%d. %s\n", i+1, appointments[i]); // print the appointment date and time
                    }
                }
                break;

            case 3: // cancel appointment
                if (numAppointments == 0) {
                    printf("You have no upcoming appointments to cancel!\n");
                    break;
                }
                printf("Enter the number of the appointment you would like to cancel: ");
                int cancelIndex;
                scanf("%d", &cancelIndex); // read input for the appointment number to cancel
                if (cancelIndex < 1 || cancelIndex > numAppointments) {
                    printf("Invalid appointment number!\n");
                    break;
                }
                printf("Are you sure you want to cancel the following appointment: %s\n", appointments[cancelIndex-1]);
                char confirmation;
                scanf(" %c", &confirmation);
                if (confirmation == 'y' || confirmation == 'Y') {
                    for (int i = cancelIndex; i < numAppointments; i++) {
                        strcpy(appointments[i-1], appointments[i]); // shift subsequent appointments up one index in the array
                    }
                    numAppointments--; // decrement the number of appointments
                    printf("Appointment cancelled successfully!\n");
                }
                break;

            case 4: // exit program
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                return 0;

            default: // invalid menu option choice
                printf("Invalid menu option selected. Please try again.\n");
                break;
        }
    }
    return 0;
}