//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 5

typedef struct appointment {
    char name[20];
    char date[20];
    char time[10];
    bool occupied;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];

void initializeAppointments() {
    for (int i=0; i<MAX_APPOINTMENTS; i++) {
        appointments[i].occupied = false;
    }
}

void displayAppointments() {
    printf("Appointments:\n");
    printf("----------------------------\n");
    for (int i=0; i<MAX_APPOINTMENTS; i++) {
        if (appointments[i].occupied) {
            printf("Appointment %d:\n", i+1);
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("----------------------------\n");
        }
    }
}

void addAppointment() {
    for (int i=0; i<MAX_APPOINTMENTS; i++) {
        if (!appointments[i].occupied) {
            printf("Enter name: ");
            scanf("%s", appointments[i].name);
            printf("Enter date: ");
            scanf("%s", appointments[i].date);
            printf("Enter time: ");
            scanf("%s", appointments[i].time);
            appointments[i].occupied = true;
            printf("Appointment added!\n");
            return;
        }
    }
    printf("Sorry, all appointment slots are taken.\n");
}

void removeAppointment() {
    int appointmentNumber;
    printf("Enter appointment number to remove (1-%d): ", MAX_APPOINTMENTS);
    scanf("%d", &appointmentNumber);
    if (appointmentNumber < 1 || appointmentNumber > MAX_APPOINTMENTS) {
        printf("Invalid appointment number.\n");
        return;
    }
    int i = appointmentNumber - 1;
    if (!appointments[i].occupied) {
        printf("This appointment is already empty.\n");
        return;
    }
    appointments[i].occupied = false;
    printf("Appointment removed!\n");
}

void displayMenu() {
    printf("\n");
    printf("1. Display Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Remove Appointment\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;

    initializeAppointments();

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAppointments();
                break;
            case 2:
                addAppointment();
                break;
            case 3:
                removeAppointment();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}