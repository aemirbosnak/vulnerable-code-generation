//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments possible
#define MAX_APPOINTMENTS 50

// Define the structure for each appointment
struct Appointment {
    char name[50];
    char date[15];
    char time[10];
};

// Define global variables
struct Appointment schedule[MAX_APPOINTMENTS];
int numAppointments = 0;

// Function to add a new appointment to the schedule
void bookAppointment() {
    // Check if the schedule is full
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("The schedule is full. No more appointments available.\n");
        return;
    }

    // Ask for appointment details
    printf("Enter client name:\n");
    scanf("%s", &schedule[numAppointments].name);
    printf("Enter appointment date (dd/mm/yyyy):\n");
    scanf("%s", &schedule[numAppointments].date);
    printf("Enter appointment time (hh:mm):\n");
    scanf("%s", &schedule[numAppointments].time);

    // Increment the number of appointments and print confirmation
    numAppointments++;
    printf("Appointment booked successfully!\n");
}

// Function to cancel an existing appointment from the schedule
void cancelAppointment() {
    // Check if the schedule is empty
    if (numAppointments == 0) {
        printf("There are no appointments to cancel.\n");
        return;
    }

    // Ask for appointment details to cancel
    printf("Enter client name of appointment to cancel:\n");
    char name[50];
    scanf("%s", name);
    printf("Enter appointment date of appointment to cancel (dd/mm/yyyy):\n");
    char date[15];
    scanf("%s", date);
    printf("Enter appointment time of appointment to cancel (hh:mm):\n");
    char time[10];
    scanf("%s", time);

    // Loop through all appointments to find the one to cancel
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(schedule[i].name, name) == 0 &&
            strcmp(schedule[i].date, date) == 0 &&
            strcmp(schedule[i].time, time) == 0) {
            // Move all appointments after this one up one index to fill the gap
            for (int j = i+1; j < numAppointments; j++) {
                schedule[j-1] = schedule[j];
            }

            // Decrement the number of appointments and print confirmation
            numAppointments--;
            printf("Appointment cancelled successfully!\n");
            return;
        }
    }

    // If no match was found, then the appointment was not found
    printf("Appointment not found. Please try again.\n");
}

// Function to display the current schedule of appointments
void displaySchedule() {
    // Check if the schedule is empty
    if (numAppointments == 0) {
        printf("The schedule is empty. No appointments booked yet.\n");
        return;
    }

    // Display all appointments in the schedule
    printf("Appointment Schedule:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("[%d] %s on %s at %s\n", i+1, schedule[i].name, schedule[i].date, schedule[i].time);
    }
}

// Main function to run the program
int main() {
    // Display the menu and ask for user input
    int option;
    do {
        printf("Appointment Scheduler:\n");
        printf("1. Book an appointment\n");
        printf("2. Cancel an appointment\n");
        printf("3. Display current schedule\n");
        printf("4. Exit the program\n");
        printf("Enter your choice (1-4):\n");
        scanf("%d", &option);

        // Run the appropriate function based on user input
        switch (option) {
            case 1:
                bookAppointment();
                break;
            case 2:
                cancelAppointment();
                break;
            case 3:
                displaySchedule();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}