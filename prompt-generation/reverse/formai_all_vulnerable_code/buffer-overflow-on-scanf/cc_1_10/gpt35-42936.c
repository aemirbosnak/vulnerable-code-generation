//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a constant for the maximum number of appointments the scheduler can handle
#define MAX_APPOINTMENTS 10

// Define structure for appointment
typedef struct {
    char name[50];
    char date[20];
    char time[20];
} Appointment;

// Function to print menu options
void printMenu() {
    printf("\nAPPOINTMENT SCHEDULER\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n\n");
}

// Function to view scheduled appointments
void viewAppointments(Appointment appointments[], int numAppointments) {
    printf("\n\n\tSCHEDULED APPOINTMENTS\n");
    printf("\t----------------------------\n");
    printf("\tName\t\tDate\t\tTime\n");
    printf("\t----------------------------\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("\t%s\t\t%s\t\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
    printf("\t----------------------------\n\n");
}

// Function to add appointment to scheduler
void addAppointment(Appointment appointments[], int *numAppointments) {
    // Check if maximum number of appointments has been reached
    if (*numAppointments == MAX_APPOINTMENTS) {
        printf("\n\n\tScheduler is full. Cannot add more appointments.\n\n");
        return;
    }

    // Prompt user to enter appointment details
    printf("\n\n\tEnter appointment details:\n");
    printf("\tName: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("\tDate [DD/MM/YYYY]: ");
    scanf("%s", appointments[*numAppointments].date);
    printf("\tTime [HH:MM]: ");
    scanf("%s", appointments[*numAppointments].time);

    // Increment the number of appointments by 1
    (*numAppointments)++;
    printf("\n\n\tAppointment added successfully.\n\n");
}

// Function to delete appointment from scheduler
void deleteAppointment(Appointment appointments[], int *numAppointments) {
    // Check if there are no appointments scheduled
    if (*numAppointments == 0) {
        printf("\n\n\tNo appointments to delete.\n\n");
        return;
    }

    // Prompt user to enter name of the appointment to be deleted
    char nameToDelete[50];
    printf("\n\n\tEnter name of appointment to be deleted: ");
    scanf("%s", nameToDelete);

    // Search for the appointment by name and delete it
    bool appointmentFound = false;
    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(appointments[i].name, nameToDelete) == 0) {
            // Shift the appointments array to the left starting from the appointment to delete
            for (int j = i; j < *numAppointments - 1; j++) {
                appointments[j] = appointments[j+1];
            }
            appointmentFound = true;
            // Decrement the number of appointments by 1
            (*numAppointments)--;
            printf("\n\n\tAppointment deleted successfully.\n\n");
            break;
        }
    }
    // If the appointment was not found, display appropriate message
    if (!appointmentFound) {
        printf("\n\n\tAppointment not found.\n\n");
    }
}

int main() {
    // Declare variables
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;

    // Display welcome message
    printf("\n\n\tWelcome to Appointment Scheduler\n\n");

    // Loop through menu options while choice is not 4 (Exit)
    do {
        printMenu();
        printf("\tEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                viewAppointments(appointments, numAppointments);
                break;
            case 2:
                addAppointment(appointments, &numAppointments);
                break;
            case 3:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 4:
                printf("\n\n\tThank you for using the Appointment Scheduler.\n\n");
                break;
            default:
                printf("\n\n\tInvalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}