//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char reason[100];
    time_t start_time;
    int duration;
} Appointment;

void add_appointment(Appointment *appointments, int num_appointments, char *name, char *reason, time_t start_time, int duration) {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be added.\n");
        return;
    }
    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].reason, reason);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].duration = duration;
    num_appointments++;
}

void print_appointments(Appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s (Duration: %d minutes)\n", appointments[i].name, appointments[i].reason, appointments[i].duration);
    }
}

void schedule_appointment(Appointment *appointments, int num_appointments, time_t current_time) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].start_time == current_time) {
            printf("%s's appointment is starting now.\n", appointments[i].name);
        }
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments, "John Doe", "Annual check-up", time(NULL) + 60*60*24*2, 30);
    add_appointment(appointments, num_appointments, "Jane Smith", "Follow-up visit", time(NULL) + 60*60*24*2 + 60*60, 45);

    printf("Appointments scheduled:\n");
    print_appointments(appointments, num_appointments);

    time_t current_time = time(NULL);
    while (current_time <= appointments[0].start_time) {
        current_time += 60;
        schedule_appointment(appointments, num_appointments, current_time);
    }

    return 0;
}