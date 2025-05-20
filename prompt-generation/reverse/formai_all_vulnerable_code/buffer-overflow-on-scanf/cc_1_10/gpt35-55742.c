//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global constants
#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

// Define a struct to hold appointment data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
} Appointment;

// Define a function to display appointment information
void displayAppointment(Appointment appt) {
    printf("Appointment for %s on %s\n", appt.name, appt.date);
}

// Define main function
int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    char menuSelection;

    do {
        // Display main menu
        printf("\n\nAppointment Scheduler\n");
        printf("1. Add an appointment\n");
        printf("2. View all appointments\n");
        printf("3. Exit\n");
        printf("Enter selection: ");
        scanf(" %c", &menuSelection);

        // Handle menu input
        switch (menuSelection) {
            case '1': // Add appointment
                if (numAppointments >= MAX_APPOINTMENTS) {
                    printf("Maximum number of appointments already scheduled.\n");
                } else {
                    char name[MAX_NAME_LENGTH];
                    char date[MAX_DATE_LENGTH];
                    printf("\nEnter name: ");
                    scanf("%s", name);
                    printf("Enter date: ");
                    scanf("%s", date);
                    Appointment newAppt;
                    strcpy(newAppt.name, name);
                    strcpy(newAppt.date, date);
                    appointments[numAppointments++] = newAppt;
                    printf("\nAppointment added:\n");
                    displayAppointment(newAppt);
                }
                break;

            case '2': // View all appointments
                if (numAppointments == 0) {
                    printf("\nThere are no appointments scheduled.\n");
                } else {
                    printf("\nAll Appointments:\n");
                    for (int i = 0; i < numAppointments; i++) {
                        printf("%d. ", i+1);
                        displayAppointment(appointments[i]);
                    }
                }
                break;

            case '3': // Exit program
                printf("\nGoodbye.\n");
                break;

            default:
                printf("\nInvalid selection. Please try again.\n");
                break;
        }

    } while (menuSelection != '3');

    return 0;
}