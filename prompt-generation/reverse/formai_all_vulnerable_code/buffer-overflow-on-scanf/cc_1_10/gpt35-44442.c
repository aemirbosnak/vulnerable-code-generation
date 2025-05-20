//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store appointment information
struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    char notes[256];
};

// Function to add an appointment
void addAppointment(struct Appointment* appt, int* numAppts) {
    // Ask for appointment information
    printf("Enter name: ");
    fgets(appt[*numAppts].name, 50, stdin);
    appt[*numAppts].name[strcspn(appt[*numAppts].name, "\n")] = 0;
    printf("Enter date (MM/DD/YYYY): ");
    fgets(appt[*numAppts].date, 20, stdin);
    appt[*numAppts].date[strcspn(appt[*numAppts].date, "\n")] = 0;
    printf("Enter time (HH:MM AM/PM): ");
    fgets(appt[*numAppts].time, 20, stdin);
    appt[*numAppts].time[strcspn(appt[*numAppts].time, "\n")] = 0;
    printf("Enter notes: ");
    fgets(appt[*numAppts].notes, 256, stdin);
    appt[*numAppts].notes[strcspn(appt[*numAppts].notes, "\n")] = 0;

    // Increment number of appointments
    *numAppts += 1;
}

// Function to display appointments
void displayAppointments(struct Appointment* appt, int numAppts) {
    // Check if there are appointments to display
    if (numAppts == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    // Display all appointments
    printf("Scheduled Appointments:\n");
    printf("-----------------------\n");
    for (int i = 0; i < numAppts; i++) {
        printf("Name: %s\n", appt[i].name);
        printf("Date: %s\n", appt[i].date);
        printf("Time: %s\n", appt[i].time);
        printf("Notes: %s\n\n", appt[i].notes);
    }
}

int main() {
    // Welcome message
    printf("Welcome to the Appointment Scheduler!\n");

    // Create array of appointments and number of appointments
    struct Appointment appt[10];
    int numAppts = 0;

    // Variable to store user's menu choice
    int choice;

    // Loop until user quits
    do {
        // Display menu options
        printf("Menu Options:\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n');

        // Perform action based on user's choice
        switch (choice) {
            case 1: // Add appointment
                addAppointment(&appt[0], &numAppts);
                break;
            case 2: // View appointments
                displayAppointments(&appt[0], numAppts);
                break;
            case 3: // Quit
                printf("Goodbye!\n");
                break;
            default: // Invalid input
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}