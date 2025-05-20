//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Appointment {
    int month;
    int day;
    int hour;
    char* description;
} Appointment;

void printAppointment(Appointment* appt) {
    printf("Date: %d/%d\n", appt->month, appt->day);
    printf("Time: %d:00\n", appt->hour);
    printf("Description: %s\n", appt->description);
}

void makeAppointment(Appointment* appt) {
    printf("Enter the month, day, and hour of the appointment (separated by spaces): ");
    scanf("%d %d %d", &(appt->month), &(appt->day), &(appt->hour));

    printf("Enter a brief description of the appointment: ");
    appt->description = malloc(sizeof(char)*256);
    scanf(" %[^\n]", appt->description);
}

void printMenu() {
    printf("1. New appointment\n");
    printf("2. View next appointment\n");
    printf("3. Exit\n");
    printf("Enter your selection: ");
}

int main() {
    int selection;
    Appointment* appt = malloc(sizeof(Appointment));
    bool hasAppointment = false;

    do {
        printMenu();
        scanf("%d", &selection);

        switch(selection) {
            case 1:
                makeAppointment(appt);
                hasAppointment = true;
                break;
            case 2:
                if(hasAppointment) {
                    printf("Next appointment:\n");
                    printAppointment(appt);
                } else {
                    printf("There are no appointments scheduled.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid selection. Try again.\n");
                break;
        }

    } while(selection != 3);

    free(appt->description);
    free(appt);

    return 0;
}