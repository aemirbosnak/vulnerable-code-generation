//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char date[20];
    char time[20];
    char name[50];
};

void scheduleAppointment(struct Appointment appointment);
void viewAppointment(struct Appointment appointment);
void cancelAppointment(struct Appointment appointment);

int main() {
    struct Appointment appointment;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", appointment.date);

    printf("Enter time (hh:mm): ");
    scanf("%s", appointment.time);

    printf("Enter name: ");
    scanf("%s", appointment.name);

    scheduleAppointment(appointment);
    viewAppointment(appointment);
    cancelAppointment(appointment);

    return 0;
}

void scheduleAppointment(struct Appointment appointment) {
    printf("\n\nScheduled appointment:\n");
    printf("Date: %s\n", appointment.date);
    printf("Time: %s\n", appointment.time);
    printf("Name: %s\n", appointment.name);
}

void viewAppointment(struct Appointment appointment) {
    printf("\n\nViewing appointment:\n");
    printf("Date: %s\n", appointment.date);
    printf("Time: %s\n", appointment.time);
    printf("Name: %s\n", appointment.name);
}

void cancelAppointment(struct Appointment appointment) {
    printf("\n\nCanceling appointment:\n");
    printf("Date: %s\n", appointment.date);
    printf("Time: %s\n", appointment.time);
    printf("Name: %s\n", appointment.name);
}