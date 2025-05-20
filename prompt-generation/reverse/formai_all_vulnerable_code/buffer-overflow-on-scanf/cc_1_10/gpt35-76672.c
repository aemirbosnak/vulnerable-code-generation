//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 20

struct Appointment {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct Appointment* appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Unable to add appointment. Maximum appointments reached.\n");
        return;
    }

    struct Appointment* appointment = malloc(sizeof(struct Appointment));
    printf("Enter client name: ");
    scanf("%s", appointment->name);
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &appointment->day, &appointment->month, &appointment->year);
    printf("Enter time (hh:mm): ");
    scanf("%d:%d", &appointment->hour, &appointment->minute);

    appointments[appointmentCount++] = appointment;
}

void listAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        struct Appointment* appointment = appointments[i];
        printf("%s on %02d/%02d/%04d at %02d:%02d\n", appointment->name, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
    }
}

void clearAppointments() {
    for (int i = 0; i < appointmentCount; i++) {
        free(appointments[i]);
    }
    appointmentCount = 0;
}

int main() {
    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("---------------------\n");
        printf("1. Add appointment\n");
        printf("2. List appointments\n");
        printf("3. Clear appointments\n");
        printf("4. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                listAppointments();
                break;
            case 3:
                clearAppointments();
                break;
            case 4:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}