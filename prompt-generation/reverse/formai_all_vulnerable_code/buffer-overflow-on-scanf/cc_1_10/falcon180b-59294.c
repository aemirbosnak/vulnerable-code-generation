//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int date;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

void addAppointment(Appointment appointments[], int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);
    printf("Enter date (dd): ");
    scanf("%d", &appointments[numAppointments].date);
    printf("Enter month (mm): ");
    scanf("%d", &appointments[numAppointments].month);
    printf("Enter year (yyyy): ");
    scanf("%d", &appointments[numAppointments].year);
    printf("Enter hour (hh): ");
    scanf("%d", &appointments[numAppointments].hour);
    printf("Enter minute (mm): ");
    scanf("%d", &appointments[numAppointments].minute);
    numAppointments++;
}

void displayAppointments(Appointment appointments[], int numAppointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %02d/%02d/%04d %02d:%02d\n", appointments[i].name, appointments[i].date, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }
}

int compareAppointments(const void *a, const void *b) {
    struct tm appointmentA, appointmentB;
    appointmentA.tm_year = (*(Appointment *)a).year - 1900;
    appointmentA.tm_mon = (*(Appointment *)a).month - 1;
    appointmentA.tm_mday = (*(Appointment *)a).date;
    appointmentA.tm_hour = (*(Appointment *)a).hour;
    appointmentA.tm_min = (*(Appointment *)a).minute;
    mktime(&appointmentA);

    appointmentB.tm_year = (*(Appointment *)b).year - 1900;
    appointmentB.tm_mon = (*(Appointment *)b).month - 1;
    appointmentB.tm_mday = (*(Appointment *)b).date;
    appointmentB.tm_hour = (*(Appointment *)b).hour;
    appointmentB.tm_min = (*(Appointment *)b).minute;
    mktime(&appointmentB);

    if (difftime(appointmentA.tm_sec, appointmentB.tm_sec) < 0)
        return -1;
    else if (difftime(appointmentA.tm_sec, appointmentB.tm_sec) > 0)
        return 1;
    else
        return 0;
}

void sortAppointments(Appointment appointments[], int numAppointments) {
    qsort(appointments, numAppointments, sizeof(Appointment), compareAppointments);
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("\nDo you want to add an appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            addAppointment(appointments, numAppointments);
        } else {
            break;
        }
    }

    sortAppointments(appointments, numAppointments);
    displayAppointments(appointments, numAppointments);

    return 0;
}