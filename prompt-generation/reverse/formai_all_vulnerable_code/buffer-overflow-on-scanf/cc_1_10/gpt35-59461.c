//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Max number of appointments in a day
#define MAX_APPOINTMENTS 10

// Struct to hold appointment data
struct Appointment {
    char date[11];
    char time[6];
    char description[100];
};

// Array to hold all appointments
struct Appointment appointments[MAX_APPOINTMENTS];

// Function to add a new appointment
void add_appointment() {
    // Check if there's room for another appointment
    if (sizeof(appointments)/sizeof(appointments[0]) == MAX_APPOINTMENTS) {
        printf("Sorry, the maximum number of appointments has been reached for today.\n");
        return;
    }

    // Get the appointment details from the user
    char date[11], time[6], description[100];
    printf("Enter the date of the appointment (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter the time of the appointment (HH:MM): ");
    scanf("%s", time);
    printf("Enter a description of the appointment: ");
    scanf(" %[^\n]s", description);

    // Add the appointment to the appointments array
    int i;
    for (i = 0; i < sizeof(appointments)/sizeof(appointments[0]); i++) {
        if (strcmp(appointments[i].date, "") == 0) {
            strcpy(appointments[i].date, date);
            strcpy(appointments[i].time, time);
            strcpy(appointments[i].description, description);
            printf("Appointment added!\n");
            break;
        }
    }

    // If the loop finished without adding the appointment, it means there were no more empty slots
    if (i == sizeof(appointments)/sizeof(appointments[0])) {
        printf("Sorry, the maximum number of appointments has been reached for today.\n");
    }
}

// Function to remove an appointment
void remove_appointment() {
    // Get the date and time of the appointment to remove
    char date[11], time[6];
    printf("Enter the date of the appointment to remove (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter the time of the appointment to remove (HH:MM): ");
    scanf("%s", time);

    // Find the appointment in the appointments array and remove it
    bool appointment_found = false;
    int i;
    for (i = 0; i < sizeof(appointments)/sizeof(appointments[0]); i++) {
        if (strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
            // Found the appointment, remove it by setting its fields to empty strings
            strcpy(appointments[i].date, "");
            strcpy(appointments[i].time, "");
            strcpy(appointments[i].description, "");
            printf("Appointment removed!\n");
            appointment_found = true;
            break;
        }
    }

    // If the loop finished without finding the appointment, it means it doesn't exist
    if (!appointment_found) {
        printf("Appointment not found.\n");
    }
}

// Function to display all appointments
void display_appointments() {
    // Print the header row
    printf("%-12s%-8s%-30s\n", "Date", "Time", "Description");
    printf("----------------------------------------------\n");

    // Loop through all appointments and print them
    int i, appointment_count = 0;
    for (i = 0; i < sizeof(appointments)/sizeof(appointments[0]); i++) {
        if (strcmp(appointments[i].date, "") != 0) {
            printf("%-12s%-8s%-30s\n", appointments[i].date, appointments[i].time, appointments[i].description);
            appointment_count++;
        }
    }

    // If there were no appointments, print a message saying so
    if (appointment_count == 0) {
        printf("No appointments found.\n");
    }
}

int main() {
    // Initialize the appointments array with empty strings
    int i;
    for (i = 0; i < sizeof(appointments)/sizeof(appointments[0]); i++) {
        strcpy(appointments[i].date, "");
        strcpy(appointments[i].time, "");
        strcpy(appointments[i].description, "");
    }

    // Loop through the menu until the user chooses to exit
    int choice;
    while (true) {
        // Print the menu
        printf("\nAppointment Scheduler\n");
        printf("---------------------\n");
        printf("1. Add an appointment\n");
        printf("2. Remove an appointment\n");
        printf("3. Display all appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                remove_appointment();
                break;
            case 3:
                display_appointments();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}