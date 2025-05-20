//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t appointment_time;
    int appointment_duration;
    char appointment_description[100];
} appointment;

int compare_appointments(const void *a, const void *b) {
    const appointment *appointment_a = (const appointment *)a;
    const appointment *appointment_b = (const appointment *)b;

    return difftime(appointment_a->appointment_time, appointment_b->appointment_time);
}

void print_appointment(const appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Appointment Time: %s\n", ctime(&appointment->appointment_time));
    printf("Appointment Duration: %d minutes\n", appointment->appointment_duration);
    printf("Appointment Description: %s\n", appointment->appointment_description);
    printf("\n");
}

int main() {
    int num_appointments;
    appointment appointments[MAX_APPOINTMENTS];

    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter the name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].appointment_description);
        strptime(appointments[i].appointment_description, "%Y-%m-%d %H:%M:%S", &(appointments[i].appointment_time));

        printf("Enter the appointment duration in minutes: ");
        scanf("%d", &appointments[i].appointment_duration);
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}