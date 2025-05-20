//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of appointments allowed
#define MAX_APPOINTMENTS 10

// define the maximum length of the appointment description
#define MAX_DESCRIPTION_LENGTH 50

// declare struct for the appointment
typedef struct Appointment {
    int hour;
    int minute;
    char description[MAX_DESCRIPTION_LENGTH];
} Appointment;

// declare an array to store the appointments
Appointment appointments[MAX_APPOINTMENTS];

// declare a variable to keep track of the number of appointments
int num_appointments = 0;

// function to print the menu options
void print_menu() {
    printf("Choose an option:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
}

// function to add an appointment
void add_appointment() {
    // check if there is space for a new appointment
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    // prompt user for appointment hour
    printf("Enter the appointment hour (0-23): ");
    int hour;
    scanf("%d", &hour);

    // prompt user for appointment minute
    printf("Enter the appointment minute (0-59): ");
    int minute;
    scanf("%d", &minute);

    // prompt user for appointment description
    printf("Enter the appointment description (max %d characters): ", MAX_DESCRIPTION_LENGTH);
    char description[MAX_DESCRIPTION_LENGTH];
    scanf("%s", description);

    // create a new appointment
    Appointment new_appointment;
    new_appointment.hour = hour;
    new_appointment.minute = minute;
    strcpy(new_appointment.description, description);

    // add the new appointment to the array
    appointments[num_appointments] = new_appointment;
    num_appointments++;

    // print a success message
    printf("Appointment added successfully.\n");
}

// function to view appointments
void view_appointments() {
    // check if there are any appointments
    if (num_appointments == 0) {
        printf("No appointments yet.\n");
        return;
    }

    // print a header for the appointment table
    printf("%-10s %-20s\n", "Time", "Description");
    printf("----------------------------------------------\n");

    // print each appointment in the array
    for (int i = 0; i < num_appointments; i++) {
        printf("%02d:%02d     %-20s\n", appointments[i].hour, appointments[i].minute, appointments[i].description);
    }
}

int main() {
    int choice;
    do {
        // print the menu options
        print_menu();

        // prompt user for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // handle user's choice
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}