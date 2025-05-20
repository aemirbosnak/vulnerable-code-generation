//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointment_id;
    time_t appointment_time;
    char appointment_description[MAX_NAME_LENGTH];
} Appointment;

void print_appointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Appointment ID: %d\n", appointment.appointment_id);
    printf("Appointment Time: %s\n", ctime(&appointment.appointment_time));
    printf("Appointment Description: %s\n", appointment.appointment_description);
}

int compare_appointment_time(const void* a, const void* b) {
    const Appointment* appointment_a = (const Appointment*)a;
    const Appointment* appointment_b = (const Appointment*)b;

    return difftime(appointment_a->appointment_time, appointment_b->appointment_time);
}

int main() {
    int num_appointments = 0;
    Appointment* appointments = NULL;

    while (num_appointments == 0 || num_appointments > MAX_APPOINTMENTS) {
        printf("Enter the number of appointments (1 to %d): ", MAX_APPOINTMENTS);
        scanf("%d", &num_appointments);
    }

    appointments = malloc(num_appointments * sizeof(Appointment));

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter the name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter the appointment ID for appointment %d: ", i+1);
        scanf("%d", &appointments[i].appointment_id);

        printf("Enter the appointment time for appointment %d (YYYY-MM-DD HH:MM:SS): ", i+1);
        scanf("%s", appointments[i].appointment_description);
        strptime(appointments[i].appointment_description, "%Y-%m-%d %H:%M:%S", &appointments[i].appointment_time);

        printf("Appointment %d scheduled.\n", i+1);
    }

    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointment_time);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    free(appointments);

    return 0;
}