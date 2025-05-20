//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MINUTES_PER_HOUR 60

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Time startTime;
    Time endTime;
} Appointment;

int compareAppointments(const void* a, const void* b) {
    Appointment* appointmentA = (Appointment*)a;
    Appointment* appointmentB = (Appointment*)b;

    if (appointmentA->startTime.hour < appointmentB->startTime.hour) {
        return -1;
    } else if (appointmentA->startTime.hour > appointmentB->startTime.hour) {
        return 1;
    } else {
        if (appointmentA->startTime.minute < appointmentB->startTime.minute) {
            return -1;
        } else if (appointmentA->startTime.minute > appointmentB->startTime.minute) {
            return 1;
        } else {
            return 0;
        }
    }
}

void printAppointments(Appointment* appointments, int numAppointments) {
    qsort(appointments, numAppointments, sizeof(Appointment), compareAppointments);

    for (int i = 0; i < numAppointments; i++) {
        printf("%s: %02d:%02d - %02d:%02d\n", appointments[i].name, appointments[i].startTime.hour, appointments[i].startTime.minute, appointments[i].endTime.hour, appointments[i].endTime.minute);
    }
}

int main() {
    int numAppointments;
    printf("Enter the number of appointments: ");
    scanf("%d", &numAppointments);

    Appointment* appointments = (Appointment*)malloc(numAppointments * sizeof(Appointment));

    for (int i = 0; i < numAppointments; i++) {
        printf("Enter the name for appointment %d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Enter the start time (HH:MM) for appointment %s: ", appointments[i].name);
        scanf("%d:%d", &appointments[i].startTime.hour, &appointments[i].startTime.minute);

        printf("Enter the end time (HH:MM) for appointment %s: ", appointments[i].name);
        scanf("%d:%d", &appointments[i].endTime.hour, &appointments[i].endTime.minute);
    }

    printAppointments(appointments, numAppointments);

    free(appointments);

    return 0;
}