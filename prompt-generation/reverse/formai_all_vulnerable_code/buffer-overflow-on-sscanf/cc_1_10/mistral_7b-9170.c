//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_LENGTH_MAX 60

typedef struct {
    int id;
    char name[50];
    char description[50];
    int start_minute;
    int duration;
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} Schedule;

void print_schedule(Schedule* schedule) {
    for (int i = 0; i < schedule->num_appointments; ++i) {
        printf("%02d:%02d - %02d:%02d: %s: %s\n",
            schedule->appointments[i].start_minute / 60,
            schedule->appointments[i].start_minute % 60,
            schedule->appointments[i].start_minute / 60 + schedule->appointments[i].duration / 60,
            schedule->appointments[i].start_minute % 60 + schedule->appointments[i].duration % 60,
            schedule->appointments[i].name,
            schedule->appointments[i].description
        );
    }
}

bool is_valid_appointment(Schedule* schedule, Appointment appointment) {
    for (int i = 0; i < schedule->num_appointments; ++i) {
        if (appointment.start_minute >= schedule->appointments[i].start_minute
            && appointment.start_minute + appointment.duration <= schedule->appointments[i].start_minute + schedule->appointments[i].duration) {
            return false;
        }
    }
    return true;
}

void add_appointment(Schedule* schedule, Appointment appointment) {
    if (schedule->num_appointments == MAX_APPOINTMENTS) {
        fprintf(stderr, "Cannot add appointment. Schedule is full.\n");
        return;
    }

    if (!is_valid_appointment(schedule, appointment)) {
        fprintf(stderr, "Cannot add appointment. Appointment overlaps with existing appointment.\n");
        return;
    }

    schedule->appointments[schedule->num_appointments] = appointment;
    schedule->num_appointments++;
}

int main() {
    Schedule schedule = { .num_appointments = 0 };

    char line[200];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        Appointment appointment;
        sscanf(line, "%d %s %s %d %d",
            &appointment.id,
            appointment.name,
            appointment.description,
            &appointment.start_minute,
            &appointment.duration
        );

        appointment.start_minute -= 60; // Convert 24 hour format to minute format
        appointment.start_minute += appointment.duration; // Add appointment duration to start time

        add_appointment(&schedule, appointment);
    }

    print_schedule(&schedule);

    return 0;
}