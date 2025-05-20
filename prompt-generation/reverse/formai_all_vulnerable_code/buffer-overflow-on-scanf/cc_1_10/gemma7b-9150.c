//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];
} Appointment;

Appointment appointments[MAX_Appointments];

void scheduleAppointment(Appointment *appointment) {
    printf("Enter your name: ");
    scanf("%s", appointment->name);

    printf("Enter the date: ");
    scanf("%s", appointment->date);

    printf("Enter the time: ");
    scanf("%s", appointment->time);
}

void displayAppointments() {
    for (int i = 0; i < MAX_Appointments; i++) {
        if (appointments[i].name[0] != '\0') {
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Appointment Scheduler!\n");

    printf("1. Schedule an appointment\n");
    printf("2. Display appointments\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            scheduleAppointment(&appointments[0]);
            break;
        case 2:
            displayAppointments();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}