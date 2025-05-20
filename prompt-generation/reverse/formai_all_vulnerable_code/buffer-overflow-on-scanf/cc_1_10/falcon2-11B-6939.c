//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store appointment details
typedef struct appointment_t {
    char date[20];
    char time[20];
    char description[100];
} appointment_t;

// Function to display appointment details
void displayAppointment(appointment_t appointment) {
    printf("Date: %s\n", appointment.date);
    printf("Time: %s\n", appointment.time);
    printf("Description: %s\n", appointment.description);
}

// Function to add appointment to the schedule
void addAppointment(appointment_t* schedule, appointment_t appointment) {
    int i;
    for (i = 0; i < sizeof(schedule) / sizeof(appointment_t); i++) {
        if (strcmp(schedule[i].date, appointment.date) == 0 && strcmp(schedule[i].time, appointment.time) == 0) {
            printf("Appointment already exists\n");
            return;
        }
    }
    strcpy(schedule[i].date, appointment.date);
    strcpy(schedule[i].time, appointment.time);
    strcpy(schedule[i].description, appointment.description);
}

// Function to remove appointment from the schedule
void removeAppointment(appointment_t* schedule, appointment_t appointment) {
    int i;
    for (i = 0; i < sizeof(schedule) / sizeof(appointment_t); i++) {
        if (strcmp(schedule[i].date, appointment.date) == 0 && strcmp(schedule[i].time, appointment.time) == 0) {
            strcpy(schedule[i].date, "");
            strcpy(schedule[i].time, "");
            strcpy(schedule[i].description, "");
            return;
        }
    }
    printf("Appointment not found\n");
}

// Main function
int main() {
    appointment_t schedule[10]; // Maximum 10 appointments

    // Display welcome message
    printf("Welcome to the Appointment Scheduler!\n");

    // Loop until user wants to exit
    while (1) {
        char choice;
        printf("Enter 'a' to add an appointment, 'r' to remove an appointment, or 'q' to quit:\n");
        scanf(" %c", &choice);

        if (choice == 'a') {
            appointment_t appointment;
            printf("Enter date (DD-MM-YYYY):\n");
            scanf("%s", appointment.date);
            printf("Enter time (HH:MM):\n");
            scanf("%s", appointment.time);
            printf("Enter description:\n");
            scanf("%s", appointment.description);
            addAppointment(schedule, appointment);
        } else if (choice == 'r') {
            appointment_t appointment;
            printf("Enter date (DD-MM-YYYY):\n");
            scanf("%s", appointment.date);
            printf("Enter time (HH:MM):\n");
            scanf("%s", appointment.time);
            removeAppointment(schedule, appointment);
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Display schedule
    printf("Appointment Schedule:\n");
    for (int i = 0; i < sizeof(schedule) / sizeof(appointment_t); i++) {
        displayAppointment(schedule[i]);
    }

    return 0;
}