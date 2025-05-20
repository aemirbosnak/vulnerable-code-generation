//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants
#define MAX_NAME_LENGTH 30
#define MAX_APPOINTMENTS 10

// define struct for storing appointments
typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[11]; // format: MM/DD/YYYY
    char time[6]; // format: HH:MM (24-hour clock)
} Appointment;

// function to display menu options
void display_menu() {
    printf("--- Appointments Scheduler ---\n");
    printf("1. View all appointments\n");
    printf("2. Add new appointment\n");
    printf("3. Cancel appointment\n");
    printf("4. Exit\n");
}

// function to view all appointments
void view_appointments(Appointment appointments[], int num_appointments) {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
    } else {
        printf("All appointments:\n");
        for (int i = 0; i < num_appointments; i++) {
            printf("%d. %s on %s at %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
        }
    }
}

// function to add new appointment
void add_appointment(Appointment appointments[], int *num_appointments) {
    if (*num_appointments == MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    // prompt user for appointment details
    printf("Enter name: ");
    scanf("%s", appointments[*num_appointments].name);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", appointments[*num_appointments].date);
    printf("Enter time (HH:MM 24-hour clock): ");
    scanf("%s", appointments[*num_appointments].time);

    // increment number of appointments
    (*num_appointments)++;
}

// function to cancel appointment
void cancel_appointment(Appointment appointments[], int *num_appointments) {
    if (*num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    // display appointments and prompt for selection
    printf("Select appointment to cancel:\n");
    for (int i = 0; i < *num_appointments; i++) {
        printf("%d. %s on %s at %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
    int selection;
    scanf("%d", &selection);

    // shift appointments to remove cancelled appointment
    for (int i = selection-1; i < *num_appointments-1; i++) {
        strcpy(appointments[i].name, appointments[i+1].name);
        strcpy(appointments[i].date, appointments[i+1].date);
        strcpy(appointments[i].time, appointments[i+1].time);
    }

    // decrement number of appointments
    (*num_appointments)--;
}

int main() {
    // initialize appointments array and number of appointments counter
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    int choice = 0;
    while (choice != 4) {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_appointments(appointments, num_appointments);
                break;
            case 2:
                add_appointment(appointments, &num_appointments);
                break;
            case 3:
                cancel_appointment(appointments, &num_appointments);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}