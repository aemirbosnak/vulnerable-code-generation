//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Maximum number of appointments and appointment length
#define MAX_APPOINTMENTS 100
#define APPOINTMENT_LENGTH 30

// Appointment struct
typedef struct {
    int hour;
    int minute;
    char description[APPOINTMENT_LENGTH];
} Appointment;

// Global variable for storing appointments
Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

// Function to check if an appointment is valid
bool isValid(char *string) {
    int i = 0;
    // Loop through the string
    while (string[i]) {
        // Check if the character is a digit or a colon
        if (!isdigit(string[i]) && string[i] != ':') {
            return false;
        }
        i++;
    }
    return true;
}

int main() {

    // Display welcome message
    printf("Welcome to the Appointment Scheduler\n");

    // Loop until user chooses to exit
    while (true) {

        // Display menu options
        printf("\nMenu Options:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View scheduled appointments\n");
        printf("3. Exit\n");

        // Prompt user for action choice
        printf("\nPlease choose an option: ");
        int choice = 0;
        scanf("%d", &choice);

        // Check user's choice
        if (choice == 1) {
            // Schedule an appointment

            // Check if maximum number of appointments has been reached
            if (appointmentCount == MAX_APPOINTMENTS) {
                printf("Sorry, maximum number of appointments reached\n");
                continue;
            }

            // Prompt user for appointment time and description
            printf("\nPlease enter appointment time (HH:MM): ");
            char time[6];
            scanf("%s", time);
            if (!isValid(time)) {
                printf("Sorry, invalid time entered\n");
                continue;
            }
            printf("Please enter appointment description (max %d characters): ", APPOINTMENT_LENGTH);
            char description[APPOINTMENT_LENGTH];
            scanf(" %[^\n]s", description);
            if (strlen(description) > APPOINTMENT_LENGTH) {
                printf("Sorry, description is too long\n");
                continue;
            }

            // Create new appointment and add to appointment list
            Appointment newAppointment;
            sscanf(time, "%d:%d", &newAppointment.hour, &newAppointment.minute);
            strcpy(newAppointment.description, description);
            appointments[appointmentCount++] = newAppointment;

            printf("Appointment successfully scheduled\n");

        } else if (choice == 2) {
            // View scheduled appointments

            // Check if any appointments have been scheduled
            if (appointmentCount == 0) {
                printf("No appointments have been scheduled\n");
                continue;
            }

            // Loop through appointments and display
            printf("\nScheduled Appointments:\n");
            for (int i = 0; i < appointmentCount; i++) {
                printf("%d:%02d - %s\n", appointments[i].hour, appointments[i].minute,
                        appointments[i].description);
            }

        } else if (choice == 3) {
            // Exit program
            printf("\nGoodbye!\n");
            return 0;
        } else {
            // Invalid choice
            printf("\nInvalid option, please choose again\n");
        }
    }

    return 0;
}