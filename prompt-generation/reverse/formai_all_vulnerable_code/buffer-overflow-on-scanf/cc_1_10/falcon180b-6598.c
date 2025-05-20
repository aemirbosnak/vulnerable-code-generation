//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    time_t start_time;
    time_t end_time;
} Appointment;

int compare_appointments(const void *a, const void *b) {
    const Appointment *appointment_a = a;
    const Appointment *appointment_b = b;

    if (appointment_a->start_time < appointment_b->start_time) {
        return -1;
    } else if (appointment_a->start_time > appointment_b->start_time) {
        return 1;
    } else {
        return 0;
    }
}

void print_appointment(const Appointment *appointment) {
    printf("%s: %d (%ld - %ld)\n", appointment->name, appointment->priority, appointment->start_time, appointment->end_time);
}

int main() {
    int num_appointments;
    Appointment appointments[MAX_APPOINTMENTS];

    printf("Welcome to the Visionary Appointment Scheduler!\n");
    printf("How many appointments do you have today? (Max %d): ", MAX_APPOINTMENTS);
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter appointment %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Priority (1-10): ");
        scanf("%d", &appointments[i].priority);
        printf("Start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%ld", &appointments[i].start_time);
        printf("End time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%ld", &appointments[i].end_time);
    }

    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    printf("\nYour appointments for today:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}