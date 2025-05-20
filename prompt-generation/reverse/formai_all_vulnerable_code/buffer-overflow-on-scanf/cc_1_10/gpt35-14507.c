//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct {
    char name[50];
    char purpose[100];
    date appt_date;
} appointment;

void get_date(date *d) {
    printf("Enter year: ");
    scanf("%d", &d->year);

    printf("Enter month: ");
    scanf("%d", &d->month);

    printf("Enter day: ");
    scanf("%d", &d->day);
}

void get_appointment(appointment *appt) {
    printf("Enter name: ");
    scanf("%s", appt->name);

    printf("Enter purpose: ");
    scanf("%s", appt->purpose);

    printf("Enter appointment date:\n");
    get_date(&appt->appt_date);
}

void display_appointment(appointment *appt) {
    printf("Name: %s\n", appt->name);
    printf("Purpose: %s\n", appt->purpose);
    printf("Appointment date: %d-%d-%d\n", appt->appt_date.year, appt->appt_date.month, appt->appt_date.day);
}

int main() {
    int num_appointments;
    int i;

    printf("Enter the number of appointments to schedule: ");
    scanf("%d", &num_appointments);

    appointment *appointments = malloc(num_appointments * sizeof(appointment));

    for (i = 0; i < num_appointments; i++) {
        printf("Enter details for appointment %d:\n", i + 1);
        get_appointment(&appointments[i]);
    }

    printf("\nAppointments scheduled:\n");

    for (i = 0; i < num_appointments; i++) {
        printf("\nAppointment %d:\n", i + 1);
        display_appointment(&appointments[i]);
    }

    free(appointments);

    return 0;
}