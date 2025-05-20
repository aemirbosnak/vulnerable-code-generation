//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_NAME_LENGTH 20
#define MAX_TIME_LENGTH 10
#define MAX_APPOINTMENTS 5

// Declare Struct for Appointment
typedef struct appointment {
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

// Declare Global Variables
int numAppointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

// Function to Add Appointment
void addAppointment() {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the schedule is full. Please try again later.\n");
        return;
    }

    // Prompt user for appointment name and time
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
    printf("Please enter the name of the appointment: ");
    scanf("%s", name);
    printf("Please enter the time of the appointment (HH:MM): ");
    scanf("%s", time);

    // Create new appointment and add to array
    Appointment newAppointment;
    strcpy(newAppointment.name, name);
    strcpy(newAppointment.time, time);
    appointments[numAppointments] = newAppointment;
    numAppointments++;

    // Confirmation message
    printf("Appointment added successfully.\n");
}

// Function to View Appointments
void viewAppointments() {
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s - %s\n", i+1, appointments[i].name, appointments[i].time);
    }
}

// Main Function
int main() {
    // Display menu
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");

    // Loop for menu options
    int selection = 0;
    while (selection != 3) {
        printf("Please select an option: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }

    return 0;
}