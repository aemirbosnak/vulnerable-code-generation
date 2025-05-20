//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

struct appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int time;
};

typedef struct appointment Appointment;

int compare_appointments(const void* a, const void* b) {
    const Appointment* appointment_a = (const Appointment*)a;
    const Appointment* appointment_b = (const Appointment*)b;

    int cmp = strcmp(appointment_a->name, appointment_b->name);
    if (cmp!= 0) {
        return cmp;
    }

    cmp = strcmp(appointment_a->date, appointment_b->date);
    if (cmp!= 0) {
        return cmp;
    }

    return appointment_a->time - appointment_b->time;
}

void print_appointment(const Appointment* appointment) {
    printf("%-50s %-20s %d\n", appointment->name, appointment->date, appointment->time);
}

int main() {
    int num_appointments;
    scanf("%d", &num_appointments);

    Appointment appointments[MAX_APPOINTMENTS];
    for (int i = 0; i < num_appointments; i++) {
        scanf("%s %s %d", appointments[i].name, appointments[i].date, &appointments[i].time);
    }

    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}