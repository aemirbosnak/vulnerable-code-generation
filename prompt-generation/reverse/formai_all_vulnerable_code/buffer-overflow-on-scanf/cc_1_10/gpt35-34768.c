//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10
// Maximum appointments that the scheduler can handle

struct Appointment {
    char name[30];
    char date[20];
    char time[10];
};
// Appointment struct to hold name, date and time of the appointment

void scheduleAppointment(struct Appointment *appointments, int *numAppointments);
void viewAppointments(struct Appointment *appointments, int numAppointments);

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS]; 
    int numAppointments = 0;
    int choice;

    while (true) {
        printf("Enter 1 to schedule an appointment\n");
        printf("Enter 2 to view all appointments\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting appointment scheduler\n");
                exit(0);
            case 1:
                scheduleAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            default:
                printf("Invalid choice selected\n");
                break;
        }
    }

    return 0;
}

void scheduleAppointment(struct Appointment *appointments, int *numAppointments) {
    if (*numAppointments == MAX_APPOINTMENTS) {
        printf("Maximum appointments reached\n");
        return;
    }

    struct Appointment newAppointment;

    printf("Enter name of appointment: ");
    scanf("%s", newAppointment.name);

    printf("Enter date of appointment (dd/mm/yyyy): ");
    scanf("%s", newAppointment.date);

    printf("Enter time of appointment (hh:mm): ");
    scanf("%s", newAppointment.time);

    appointments[*numAppointments] = newAppointment;
    *numAppointments += 1;

    printf("Appointment scheduled successfully!\n");
}

void viewAppointments(struct Appointment *appointments, int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments scheduled\n");
        return;
    }

    printf("All Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Appointment %d:\n", i+1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("\n");
    }
}