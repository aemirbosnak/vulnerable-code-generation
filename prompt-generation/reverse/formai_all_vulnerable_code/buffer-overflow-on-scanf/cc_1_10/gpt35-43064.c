//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structs for appointment, date and time
struct appointment {
    char name[50];
    struct date {
        int month;
        int day;
        int year;
    } date;
    struct time {
        int hour;
        int minute;
    } time;
};

// Declare functions used in main
void scheduleAppointment(struct appointment [], int);
void editAppointment(struct appointment [], int);
void viewAppointments(struct appointment [], int);

// Main function
int main() {

    int numAppointments = 0; // initialize number of appointments to 0
    char userChoice = 'a'; // initialize userChoice to a non-quit value

    // Create an array of appointments with a maximum of 100
    struct appointment appointments[100];

    // Main menu
    while (userChoice != 'q') {
        printf("Appointment Scheduler\n");
        printf("---------------------\n");
        printf("1 - Schedule Appointment\n");
        printf("2 - Edit Appointment\n");
        printf("3 - View Appointments\n");
        printf("q - Quit\n");
        printf("\nEnter choice: ");
        scanf(" %c", &userChoice);

        switch (userChoice) {
            case '1': // Schedule Appointment
                scheduleAppointment(appointments, numAppointments);
                numAppointments++;
                break;
            case '2': // Edit Appointment
                editAppointment(appointments, numAppointments);
                break;
            case '3': // View Appointments
                viewAppointments(appointments, numAppointments);
                break;
            case 'q': // Quit
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    printf("Exiting program. Thank you for using the Appointment Scheduler!\n");

    return 0;
}


// Function to schedule appointment
void scheduleAppointment(struct appointment appointments[], int numAppointments) {

    // Prompt user for appointment name
    printf("Enter name for appointment: ");
    scanf("%s", &appointments[numAppointments].name);

    // Prompt user for appointment date
    printf("Enter date for appointment (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &appointments[numAppointments].date.month, &appointments[numAppointments].date.day, &appointments[numAppointments].date.year);

    // Prompt user for appointment time
    printf("Enter time for appointment (hh:mm): ");
    scanf("%d:%d", &appointments[numAppointments].time.hour, &appointments[numAppointments].time.minute);

    printf("Appointment scheduled successfully!\n");
}


// Function to edit appointment
void editAppointment(struct appointment appointments[], int numAppointments) {

    // Prompt user for appointment name to edit
    char editAppointmentName[50];
    printf("Enter name of appointment to edit: ");
    scanf("%s", editAppointmentName);

    bool appointmentFound = false;

    // Search array for appointment name
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(editAppointmentName, appointments[i].name) == 0) {
            appointmentFound = true;

            // Prompt user for new appointment date
            printf("Enter new date for appointment (mm/dd/yyyy): ");
            scanf("%d/%d/%d", &appointments[i].date.month, &appointments[i].date.day, &appointments[i].date.year);

            // Prompt user for new appointment time
            printf("Enter new time for appointment (hh:mm): ");
            scanf("%d:%d", &appointments[i].time.hour, &appointments[i].time.minute);

            printf("Appointment updated successfully!\n");
        }
    }

    if (!appointmentFound) printf("Appointment not found.\n");
}


// Function to view appointments
void viewAppointments(struct appointment appointments[], int numAppointments) {

    // Sort array by date and time
    for (int i = 0; i < numAppointments - 1; i++) {
        for (int j = i+1; j < numAppointments; j++) {
            if (appointments[j].date.year < appointments[i].date.year
                || (appointments[j].date.year == appointments[i].date.year
                && (appointments[j].date.month < appointments[i].date.month
                || (appointments[j].date.month == appointments[i].date.month
                && (appointments[j].date.day < appointments[i].date.day
                || (appointments[j].date.day == appointments[i].date.day
                && (appointments[j].time.hour < appointments[i].time.hour
                || (appointments[j].time.hour == appointments[i].time.hour
                && appointments[j].time.minute < appointments[i].time.minute)))))))) {
                struct appointment tempAppointment = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = tempAppointment;
            }
        }
    }

    // Print each appointment in the array
    printf("\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - ", appointments[i].name);
        printf("%d/%d/%d @ ", appointments[i].date.month, appointments[i].date.day, appointments[i].date.year);
        printf("%02d:%02d\n", appointments[i].time.hour, appointments[i].time.minute);
    }
    printf("\n");
}