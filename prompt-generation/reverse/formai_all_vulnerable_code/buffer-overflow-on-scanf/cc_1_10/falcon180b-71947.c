//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start_time;
    int end_time;
} Appointment;

void print_appointment(Appointment* a) {
    printf("Name: %s\n", a->name);
    printf("Start time: %d\n", a->start_time);
    printf("End time: %d\n", a->end_time);
}

int main() {
    int num_appointments, i;
    Appointment* appointments = malloc(MAX_APPOINTMENTS * sizeof(Appointment));

    printf("Enter number of appointments (up to %d): ", MAX_APPOINTMENTS);
    scanf("%d", &num_appointments);

    for (i = 0; i < num_appointments; i++) {
        printf("Enter name for appointment #%d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Enter start time (in minutes since 12:00 AM): ");
        scanf("%d", &appointments[i].start_time);

        printf("Enter end time (in minutes since 12:00 AM): ");
        scanf("%d", &appointments[i].end_time);
    }

    int current_time = 0;
    while (current_time < 1440) { // 1440 minutes in a day
        int next_appointment_time = -1;
        for (i = 0; i < num_appointments; i++) {
            if (appointments[i].start_time > current_time && (next_appointment_time == -1 || appointments[i].start_time < next_appointment_time)) {
                next_appointment_time = appointments[i].start_time;
            }
        }

        if (next_appointment_time!= -1) {
            printf("Next appointment at %d minutes (12:00 AM = 0): %s\n", next_appointment_time, appointments[next_appointment_time - current_time].name);
        }

        current_time++;
    }

    free(appointments);
    return 0;
}