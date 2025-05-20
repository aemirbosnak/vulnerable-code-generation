//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MINUTES_PER_HOUR 60

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start_hour;
    int start_minute;
    int duration;
} appointment;

int compare_appointments(const void *a, const void *b) {
    const appointment *appointment_a = a;
    const appointment *appointment_b = b;

    if (appointment_a->start_hour < appointment_b->start_hour) {
        return -1;
    } else if (appointment_a->start_hour > appointment_b->start_hour) {
        return 1;
    } else {
        if (appointment_a->start_minute < appointment_b->start_minute) {
            return -1;
        } else if (appointment_a->start_minute > appointment_b->start_minute) {
            return 1;
        } else {
            return 0;
        }
    }
}

void print_appointment(const appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Start Time: %02d:%02d\n", appointment->start_hour, appointment->start_minute);
    printf("Duration: %d minutes\n\n", appointment->duration);
}

int main() {
    int num_appointments;
    appointment appointments[MAX_APPOINTMENTS];
    char input_buffer[256];
    time_t current_time;
    struct tm *current_tm;

    printf("Enter the number of appointments (up to %d): ", MAX_APPOINTMENTS);
    scanf("%d", &num_appointments);

    printf("Enter the appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i+1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Start Time (HH:MM): ");
        scanf("%02d:%02d", &appointments[i].start_hour, &appointments[i].start_minute);
        printf("Duration (minutes): ");
        scanf("%d", &appointments[i].duration);
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}