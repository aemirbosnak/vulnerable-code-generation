//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int start_time;
    int end_time;
    int duration;
    int priority;
} Appointment;

void schedule_appointment(Appointment* appointments, int n, Appointment* new_appointment) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(appointments[i].name, new_appointment->name) == 0) {
            printf("Appointment already exists for %s\n", new_appointment->name);
            return;
        }
    }
    appointments[n] = *new_appointment;
    n++;
}

void print_appointments(Appointment appointments[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Name: %s, Start Time: %d, End Time: %d, Duration: %d, Priority: %d\n",
               appointments[i].name, appointments[i].start_time, appointments[i].end_time,
               appointments[i].duration, appointments[i].priority);
    }
}

int main() {
    Appointment appointments[100];
    int n = 0;

    printf("Enter appointments (name, start_time, end_time, duration, priority):\n");
    while (1) {
        Appointment new_appointment;
        printf("Enter name:\n");
        scanf("%s", new_appointment.name);

        printf("Enter start time:\n");
        scanf("%d", &new_appointment.start_time);

        printf("Enter end time:\n");
        scanf("%d", &new_appointment.end_time);

        printf("Enter duration:\n");
        scanf("%d", &new_appointment.duration);

        printf("Enter priority:\n");
        scanf("%d", &new_appointment.priority);

        schedule_appointment(appointments, n, &new_appointment);
        n++;

        printf("Enter more appointments? (y/n):\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    printf("Appointments:\n");
    print_appointments(appointments, n);

    return 0;
}