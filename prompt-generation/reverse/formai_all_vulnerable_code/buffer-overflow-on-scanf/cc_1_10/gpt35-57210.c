//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

// define appointment structure
typedef struct {
    char date[20];
    char time[10];
    char name[50];
} Appointment;

// declare global variables
Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

// declare function prototypes
void addAppointment();
void viewAppointments();
void cancelAppointment();

int main() {
    // declare variables
    char option[10];

    printf("Welcome to Appointment Scheduler!\n");

    // loop until user chooses to exit
    while (1) {
        // display menu
        printf("\nPlease select an option:\n");
        printf("1. Add new appointment\n");
        printf("2. View appointments\n");
        printf("3. Cancel appointment\n");
        printf("4. Exit\n");

        // get user input
        printf("Enter option: ");
        fgets(option, 10, stdin);
        option[strcspn(option, "\n")] = 0; // remove newline character

        // execute chosen option
        if (strcmp(option, "1") == 0) {
            addAppointment();
        } else if (strcmp(option, "2") == 0) {
            viewAppointments();
        } else if (strcmp(option, "3") == 0) {
            cancelAppointment();
        } else if (strcmp(option, "4") == 0) {
            printf("Thank you for using Appointment Scheduler!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

// function to add a new appointment
void addAppointment() {
    // declare variables
    char date[20];
    char time[10];
    char name[50];

    // get user input
    printf("Enter date (mm/dd/yyyy): ");
    fgets(date, 20, stdin);
    date[strcspn(date, "\n")] = 0;

    printf("Enter time (hh:mm AM/PM): ");
    fgets(time, 10, stdin);
    time[strcspn(time, "\n")] = 0;

    printf("Enter patient name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    // create new appointment
    Appointment newAppointment;
    strcpy(newAppointment.date, date);
    strcpy(newAppointment.time, time);
    strcpy(newAppointment.name, name);

    // add appointment to list
    if (numAppointments < MAX_APPOINTMENTS) {
        appointments[numAppointments] = newAppointment;
        numAppointments++;
        printf("Appointment created successfully!\n");
    } else {
        printf("Cannot create appointment. Maximum appointments reached.\n");
    }
}

// function to view all appointments
void viewAppointments() {
    // check if there are appointments
    if (numAppointments > 0) {
        // loop through appointments and print details
        for (int i = 0; i < numAppointments; i++) {
            printf("Appointment %d:\n", i+1);
            printf("  Date: %s\n", appointments[i].date);
            printf("  Time: %s\n", appointments[i].time);
            printf("  Patient: %s\n", appointments[i].name);
        }
    } else {
        printf("No appointments scheduled.\n");
    }
}

// function to cancel an appointment
void cancelAppointment() {
    // declare variables
    int index;
    char confirm[5];

    // check if there are appointments
    if (numAppointments > 0) {
        // display appointments for user to choose from
        printf("Select appointment to cancel:\n");
        for (int i = 0; i < numAppointments; i++) {
            printf("%d. %s %s\n", i+1, appointments[i].date, appointments[i].time);
        }

        // get user input
        printf("Enter appointment number: ");
        scanf("%d", &index);
        getchar(); // remove newline character

        // confirm cancellation
        printf("Are you sure you want to cancel this appointment? (yes or no) ");
        fgets(confirm, 5, stdin);
        confirm[strcspn(confirm, "\n")] = 0;

        if (strcmp(confirm, "yes") == 0) {
            // shift appointments to remove cancelled appointment
            for (int i = index-1; i < numAppointments-1; i++) {
                appointments[i] = appointments[i+1];
            }
            numAppointments--;
            printf("Appointment cancelled successfully.\n");
        } else {
            printf("Appointment not cancelled.\n");
        }
    } else {
        printf("No appointments scheduled.\n");
    }
}