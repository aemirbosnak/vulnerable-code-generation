//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000

struct Appointment {
    char clientName[50];
    char date[15];
    int startTime;
    int endTime;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void printMenu() {
    printf("\n-------- Appointment Scheduler --------\n");
    printf("1. View all Appointments\n");
    printf("2. Add New Appointment\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("---------------------------------------\n");
}

void printAppointments() {
    printf("\nTotal Appointments: %d\n\n", numAppointments);
    printf("Client Name\tDate\tStartTime\tEndTime\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t\t%s\t%d\t\t%d\n", appointments[i].clientName, appointments[i].date, appointments[i].startTime, appointments[i].endTime);
    }
}

void addAppointment() {
    struct Appointment newAppointment;

    printf("\nEnter Client Name: ");
    scanf("%s", newAppointment.clientName);

    printf("Enter Date (Format: DD/MM/YYYY): ");
    scanf("%s", newAppointment.date);

    printf("Enter Start Time (24 Hour Format): ");
    scanf("%d", &newAppointment.startTime);

    printf("Enter End Time (24 Hour Format): ");
    scanf("%d", &newAppointment.endTime);

    if (newAppointment.startTime >= newAppointment.endTime) {
        printf("Error: End time must be after Start time!\n");
        return;
    }

    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Error: Maximum limit of Appointments reached!\n");
        return;
    }

    appointments[numAppointments++] = newAppointment;

    printf("\nAppointment added successfully!\n");
}

void cancelAppointment() {
    char clientName[50];
    printf("\nEnter Client Name of Appointment to Cancel: ");
    scanf("%s", clientName);
    bool foundAppointment = false;

    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].clientName, clientName) == 0) {
            foundAppointment = true;
            numAppointments--;

            for (int j = i; j < numAppointments; j++) {
                appointments[j] = appointments[j+1];
            }

            printf("\nAppointment for %s on %s from %d to %d cancelled successfully!\n", appointments[i].clientName, appointments[i].date, appointments[i].startTime, appointments[i].endTime);
        }
    }

    if (!foundAppointment) {
        printf("\nError: Appointment not found for %s!\n", clientName);
    }
}

int main() {
    int choice = 0;

    printf("\n---------- Welcome to the Happy Scheduler App! ----------\n");

    while (choice != 4) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printAppointments();
                break;
            case 2:
                addAppointment();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("\nThank you for using Happy Scheduler App!\n");
                break;
            default:
                printf("\nError: Invalid choice!\n");
                break;
        }
    }

    return 0;
}