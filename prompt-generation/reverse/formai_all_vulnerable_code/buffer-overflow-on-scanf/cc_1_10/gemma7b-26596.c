//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[20];
    char date[20];
    char time[20];
    int status;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];

void displayAppointments() {
    int i = 0;
    for (i = 0; i < MAX_APPOINTMENTS && appointments[i].status != 0; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Status: %d\n", appointments[i].status);
        printf("\n");
    }
}

void scheduleAppointment() {
    int i = 0;
    for (i = 0; i < MAX_APPOINTMENTS && appointments[i].status != 0; i++) {}

    printf("Enter your name: ");
    scanf("%s", appointments[i].name);

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", appointments[i].date);

    printf("Enter the time (hh:mm): ");
    scanf("%s", appointments[i].time);

    appointments[i].status = 1;
}

int main() {
    int choice;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("1. Display Appointments\n");
    printf("2. Schedule Appointment\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayAppointments();
            break;
        case 2:
            scheduleAppointment();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}