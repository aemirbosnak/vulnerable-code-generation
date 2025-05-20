//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_NAME_LENGTH 50
#define MAX_APPOINTMENT_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_APPOINTMENT_NAME_LENGTH];
    char description[MAX_APPOINTMENT_DESCRIPTION_LENGTH];
    int date;
    int time;
} Appointment;

void addAppointment(Appointment* appointments, int numAppointments) {
    printf("Enter appointment name: ");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter appointment description: ");
    scanf("%s", appointments[numAppointments].description);

    printf("Enter appointment date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &(appointments[numAppointments].date));

    printf("Enter appointment time (hh:mm): ");
    scanf("%d:%d", &(appointments[numAppointments].time));
}

void displayAppointments(Appointment* appointments, int numAppointments) {
    printf("Appointment List:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s - %s\n", i + 1, appointments[i].name, appointments[i].description);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addAppointment(appointments, numAppointments);
            numAppointments++;
        } else if (choice == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice, try again.\n");
        }
    }

    printf("\nAppointment List:\n");
    displayAppointments(appointments, numAppointments);

    return 0;
}