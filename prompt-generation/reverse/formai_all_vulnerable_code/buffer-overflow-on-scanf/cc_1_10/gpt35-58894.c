//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of name and appointment type
#define MAX_NAME_LENGTH 50
#define MAX_APPT_TYPE_LENGTH 50

// Define struct for appointment
typedef struct {
    char name[MAX_NAME_LENGTH];
    char appt_type[MAX_APPT_TYPE_LENGTH];
    int hour;
    int minute;
} appt;

// Function to print out the appointment information
void print_appt(appt a) {
    printf("%s has an appointment for %s at %02d:%02d\n", a.name, a.appt_type, a.hour, a.minute);
}

int main() {
    // Define variables to store input information
    char name[MAX_NAME_LENGTH];
    char appt_type[MAX_APPT_TYPE_LENGTH];
    int hour, minute;

    // Initialize appt array with maximum number of appointments
    appt appts[50];
    int num_appts = 0;

    // Define variable to store user choice
    int choice;

    // Loop until user chooses to exit
    while (1) {
        printf("Enter 1 to schedule an appointment, 2 to view appointments, or 3 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Get appointment information from user
            printf("Enter your name: ");
            scanf("%s", name);

            printf("Enter the type of appointment: ");
            scanf("%s", appt_type);

            printf("Enter the hour of the appointment (0-23): ");
            scanf("%d", &hour);

            printf("Enter the minute of the appointment (0-59): ");
            scanf("%d", &minute);

            // Create new appointment and add it to the array
            appt new_appt;
            strcpy(new_appt.name, name);
            strcpy(new_appt.appt_type, appt_type);
            new_appt.hour = hour;
            new_appt.minute = minute;
            appts[num_appts++] = new_appt;
        } else if (choice == 2) {
            // Print out all scheduled appointments
            printf("Scheduled Appointments:\n");
            for (int i = 0; i < num_appts; i++) {
                print_appt(appts[i]);
            }
        } else if (choice == 3) {
            // Exit the program
            break;
        } else {
            // Invalid input
            printf("Invalid input. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}