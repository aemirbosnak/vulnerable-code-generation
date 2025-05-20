//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 20

// define struct for appointments
typedef struct {
    char name[MAX_NAME_LENGTH];
    int hour;
    int minute;
} Appointment;

// function to add a new appointment
void addAppointment(Appointment *appointments, int *numAppointments) {
    // check if there is room for a new appointment
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the schedule is full!\n");
        return;
    }

    // prompt user for the appointment name
    printf("What is the name of the appointment?\n");
    scanf("%s", &appointments[*numAppointments].name);

    // prompt user for the appointment time
    printf("At what hour is the appointment? (0-23)\n");
    scanf("%d", &appointments[*numAppointments].hour);
    printf("At what minute is the appointment? (0-59)\n");
    scanf("%d", &appointments[*numAppointments].minute);

    // increment the number of appointments
    (*numAppointments)++;

    printf("Appointment added for %02d:%02d with %s\n", appointments[*numAppointments - 1].hour, 
           appointments[*numAppointments - 1].minute, appointments[*numAppointments - 1].name);
}

// function to remove an appointment
void removeAppointment(Appointment *appointments, int *numAppointments) {
    // check if there are appointments to remove
    if (*numAppointments <= 0) {
        printf("Sorry, there are no appointments to remove!\n");
        return;
    }

    // prompt user for the appointment name to remove
    char appointmentName[MAX_NAME_LENGTH];
    printf("What is the name of the appointment to remove?\n");
    scanf("%s", &appointmentName);

    // loop through appointments to find matching appointments
    int i, j;
    for (i = 0; i < *numAppointments; i++) {
        // check if the appointment name matches
        if (strcmp(appointments[i].name, appointmentName) == 0) {
            // shift all subsequent appointments down one index
            for (j = i; j < *numAppointments - 1; j++) {
                strcpy(appointments[j].name, appointments[j+1].name);
                appointments[j].hour = appointments[j+1].hour;
                appointments[j].minute = appointments[j+1].minute;
            }
            // decrement the number of appointments
            (*numAppointments)--;
            printf("Appointment for %s removed\n", appointmentName);
            return;
        }
    }

    // if no matching appointment is found, print error message
    printf("Sorry, that appointment could not be found.\n");
}

// function to print all appointments
void printAppointments(Appointment *appointments, int numAppointments) {
    // check if there are any appointments to print
    if (numAppointments <= 0) {
        printf("Sorry, there are no appointments to print!\n");
        return;
    }

    // loop through appointments and print each appointment
    printf("Current appointments:\n");
    int i;
    for (i = 0; i < numAppointments; i++) {
        printf("%02d:%02d - %s\n", appointments[i].hour, appointments[i].minute, appointments[i].name);
    }
}

// main function
int main() {
    // define variables
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;

    printf("=========================\n");
    printf("Welcome to Appointment Scheduler!\n");
    printf("=========================\n");

    // loop through menu options until user chooses to exit
    do {
        // print menu options
        printf("\nPlease choose an option:\n");
        printf("1. Add an appointment\n");
        printf("2. Remove an appointment\n");
        printf("3. Print all appointments\n");
        printf("4. Exit\n");

        // get user input for menu choice
        scanf("%d", &choice);

        // perform action based on menu choice
        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                removeAppointment(appointments, &numAppointments);
                break;
            case 3:
                printAppointments(appointments, numAppointments);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Sorry, that is not a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}