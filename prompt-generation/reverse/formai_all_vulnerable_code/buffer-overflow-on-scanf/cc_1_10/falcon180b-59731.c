//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MINUTES_PER_HOUR 60

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start_hour;
    int start_minute;
    int end_hour;
    int end_minute;
} Appointment;

void schedule_appointment(Appointment* appointment) {
    printf("Enter the name for the appointment: ");
    scanf("%s", appointment->name);

    printf("Enter the start time (HH:MM): ");
    scanf("%d:%d", &appointment->start_hour, &appointment->start_minute);

    appointment->start_hour %= 24;
    appointment->start_minute %= MINUTES_PER_HOUR;

    printf("Enter the end time (HH:MM): ");
    scanf("%d:%d", &appointment->end_hour, &appointment->end_minute);

    appointment->end_hour %= 24;
    appointment->end_minute %= MINUTES_PER_HOUR;
}

void print_appointment(const Appointment* appointment) {
    printf("%s (%02d:%02d - %02d:%02d)\n", appointment->name, appointment->start_hour, appointment->start_minute, appointment->end_hour, appointment->end_minute);
}

int compare_appointments(const void* a, const void* b) {
    const Appointment* appointment_a = (const Appointment*)a;
    const Appointment* appointment_b = (const Appointment*)b;

    if (appointment_a->start_hour < appointment_b->start_hour) {
        return -1;
    } else if (appointment_a->start_hour > appointment_b->start_hour) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    srand(time(NULL));

    while (num_appointments < MAX_APPOINTMENTS) {
        Appointment new_appointment;
        schedule_appointment(&new_appointment);

        int i;
        for (i = 0; i < num_appointments; i++) {
            if (compare_appointments(&appointments[i], &new_appointment) == 0) {
                printf("Error: Appointment already scheduled.\n");
                break;
            }
        }

        if (i == num_appointments) {
            appointments[num_appointments++] = new_appointment;
        }
    }

    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}