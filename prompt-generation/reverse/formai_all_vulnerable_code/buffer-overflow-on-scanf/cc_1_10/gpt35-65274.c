//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum appointments allowed
#define MAX_APPOINTMENTS 100

// Define the structure for an appointment
typedef struct Appointment {
    char name[50];
    char date[20];
    char time[15];
    char reason[100];
} Appointment;

// Define the global array for all appointments
Appointment appointments[MAX_APPOINTMENTS];

// Define the function for adding an appointment
void addAppointment() {
    // Check if maximum appointments have been reached
    if (sizeof(appointments) / sizeof(Appointment) >= MAX_APPOINTMENTS) {
        printf("Maximum appointments reached. Please delete an existing appointment before adding a new one.\n");
        return;
    }

    // Create a new appointment
    Appointment newAppointment;
    printf("Please enter the name of the appointment: ");
    fflush(stdin);
    fgets(newAppointment.name, 50, stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = '\0';

    printf("Please enter the date of the appointment (mm/dd/yyyy): ");
    fflush(stdin);
    fgets(newAppointment.date, 20, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = '\0';

    printf("Please enter the time of the appointment (hh:mm AM/PM): ");
    fflush(stdin);
    fgets(newAppointment.time, 15, stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = '\0';

    printf("Please enter the reason for the appointment: ");
    fflush(stdin);
    fgets(newAppointment.reason, 100, stdin);
    newAppointment.reason[strcspn(newAppointment.reason, "\n")] = '\0';

    // Add the appointment to the array
    appointments[sizeof(appointments) / sizeof(Appointment)] = newAppointment;

    printf("Appointment added.\n");
}

// Define the function for viewing all appointments
void viewAppointments() {
    // Check if any appointments exist
    if (sizeof(appointments) / sizeof(Appointment) == 0) {
        printf("No appointments found.\n");
        return;
    }

    // Loop through all appointments and print them
    printf("All Appointments:\n");
    for (int i = 0; i < sizeof(appointments) / sizeof(Appointment); i++) {
        // Check if the appointment exists (in case some appointments have been deleted)
        if (strlen(appointments[i].name) > 0) {
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("Reason: %s\n", appointments[i].reason);
            printf("--------------------\n");
        }
    }
}

// Define the function for deleting an appointment
void deleteAppointment() {
    // Check if any appointments exist
    if (sizeof(appointments) / sizeof(Appointment) == 0) {
        printf("No appointments found.\n");
        return;
    }

    // Prompt the user for the name of the appointment to delete
    char name[50];
    printf("Please enter the name of the appointment to delete: ");
    fflush(stdin);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    // Loop through all appointments to find the one to delete
    for (int i = 0; i < sizeof(appointments) / sizeof(Appointment); i++) {
        // Check if the appointment exists and has the same name
        if (strlen(appointments[i].name) > 0 && strcmp(appointments[i].name, name) == 0) {
            // Delete the appointment by clearing its fields
            memset(appointments[i].name, 0, sizeof(appointments[i].name));
            memset(appointments[i].date, 0, sizeof(appointments[i].date));
            memset(appointments[i].time, 0, sizeof(appointments[i].time));
            memset(appointments[i].reason, 0, sizeof(appointments[i].reason));

            printf("Appointment deleted.\n");
            return;
        }
    }

    printf("Appointment not found.\n");
}

int main() {
    // Display the welcome message
    printf("Welcome to the Appointment Scheduler program.\n");

    // Loop through all options until the user chooses to exit
    while (1) {
        printf("Please select an option:\n");
        printf("1. Add an appointment\n");
        printf("2. View all appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Exit\n");

        // Prompt the user for their option
        int option;
        scanf("%d", &option);

        // Handle the user's choice
        switch (option) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}