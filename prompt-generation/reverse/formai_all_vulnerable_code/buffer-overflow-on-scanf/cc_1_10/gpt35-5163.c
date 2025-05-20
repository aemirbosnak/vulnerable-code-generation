//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>

// Function to display menu options
void displayMenu() {
    printf("\n\n\t APPOINTMENT SCHEDULER\n");
    printf("\t ---------------------\n");
    printf("\t 1. Schedule Appointment\n");
    printf("\t 2. View Appointments\n");
    printf("\t 3. Cancel Appointment\n");
    printf("\t 4. Exit\n");
    printf("\t ---------------------\n");
    printf("\t Enter your choice: ");
}

int main() {
    int choice, numAppointments = 0;
    char name[50], date[50], time[50];

    // Create an array of structures to hold appointments
    struct Appointment {
        char name[50];
        char date[50];
        char time[50];
    } appointments[50];

    // Loop until user chooses to exit
    do {
        // Display menu options
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Schedule a new appointment
                printf("\n\n\t SCHEDULE APPOINTMENT\n");
                printf("\t -------------------\n");
                printf("\t Enter name: ");
                scanf("%s", name);
                printf("\t Enter date: ");
                scanf("%s", date);
                printf("\t Enter time: ");
                scanf("%s", time);

                // Add the appointment to the array
                strcpy(appointments[numAppointments].name, name);
                strcpy(appointments[numAppointments].date, date);
                strcpy(appointments[numAppointments].time, time);

                // Increment numAppointments
                numAppointments++;

                printf("\n\n\t Appointment scheduled successfully!\n");
                break;

            case 2: // View existing appointments
                if (numAppointments == 0) {
                    printf("\n\n\t There are no appointments scheduled!\n");
                } else {
                    printf("\n\n\t APPOINTMENT DETAILS\n");
                    printf("\t -------------------\n");
                    for (int i = 0; i < numAppointments; i++) {
                        printf("\t Appointment #%d:\n", i+1);
                        printf("\t Name: %s\n", appointments[i].name);
                        printf("\t Date: %s\n", appointments[i].date);
                        printf("\t Time: %s\n\n", appointments[i].time);
                    }
                }
                break;

            case 3: // Cancel an appointment
                if (numAppointments == 0) {
                    printf("\n\n\t There are no appointments scheduled!\n");
                } else {
                    printf("\n\n\t CANCEL APPOINTMENT\n");
                    printf("\t -----------------\n");
                    printf("\t Enter the appointment number to cancel: ");
                    int apptNum;
                    scanf("%d", &apptNum);

                    // Shift all appointments after the cancelled one back by one
                    for (int i = apptNum - 1; i < numAppointments - 1; i++) {
                        strcpy(appointments[i].name, appointments[i+1].name);
                        strcpy(appointments[i].date, appointments[i+1].date);
                        strcpy(appointments[i].time, appointments[i+1].time);
                    }

                    // Decrement numAppointments
                    numAppointments--;

                    printf("\n\n\t Appointment cancelled successfully!\n");
                }
                break;

            case 4: // Exit the program
                printf("\n\n\t Thank you for using the Appointment Scheduler.\n");
                break;

            default:
                printf("\n\n\t Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}