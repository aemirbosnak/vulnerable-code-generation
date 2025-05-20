//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

void addAppointment(Appointment *appointments, int numAppointments) {
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[numAppointments].name);
    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    scanf("%s", appointments[numAppointments].date);
    printf("Enter the time of the appointment (HH:MM): ");
    scanf("%s", appointments[numAppointments].time);
    numAppointments++;
}

void displayAppointments(Appointment *appointments, int numAppointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s - %s - %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment, 2 to display appointments, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addAppointment(appointments, numAppointments);
            break;
        case 2:
            displayAppointments(appointments, numAppointments);
            break;
        case 0:
            printf("\nExiting program...\n");
            break;
        default:
            printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}