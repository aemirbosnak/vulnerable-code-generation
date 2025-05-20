//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_LENGTH 30 // in minutes

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} appointment;

void print_appointment(appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("Start time: %d\n", appt.start_time);
    printf("End time: %d\n", appt.end_time);
}

int compare_appointments(const void *a, const void *b) {
    appointment *appt1 = (appointment *)a;
    appointment *appt2 = (appointment *)b;

    if (appt1->start_time < appt2->start_time) {
        return -1;
    } else if (appt1->start_time > appt2->start_time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_appointments;
    appointment *appointments;
    char input[100];
    int start_time, end_time;

    // Get number of appointments from user
    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    // Allocate memory for appointments
    appointments = (appointment *)malloc(num_appointments * sizeof(appointment));

    // Get appointment details from user
    for (int i = 0; i < num_appointments; i++) {
        printf("Enter appointment details for %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Start time: ");
        scanf("%d", &start_time);
        printf("End time: ");
        scanf("%d", &end_time);

        // Convert start and end times to minutes
        appointments[i].start_time = start_time * 60;
        appointments[i].end_time = end_time * 60;
    }

    // Sort appointments by start time
    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    // Print appointment schedule
    printf("\nAppointment schedule:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    free(appointments);
    return 0;
}