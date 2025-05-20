//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define APPOINTMENT_LENGTH 120 // in minutes

typedef struct {
    int id;
    char name[50];
    int start_time;
    int duration;
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} Schedule;

void print_schedule(Schedule schedule) {
    printf("-------------------------\n");
    printf("|   Schedule   |\n");
    printf("-------------------------\n");
    printf("| %-15s | %-15s | %-15s |\n", "ID", "Name", "Time");
    printf("-------------------------\n");

    for (int i = 0; i < schedule.num_appointments; ++i) {
        printf("| %-15d | %-15s | %-15d:%02d:%02d |\n", schedule.appointments[i].id, schedule.appointments[i].name,
               schedule.appointments[i].start_time / 60, schedule.appointments[i].start_time % 60);
    }

    printf("-------------------------\n");
}

bool add_appointment(Schedule *schedule, const char *name, int start_time) {
    if (schedule->num_appointments >= MAX_APPOINTMENTS) {
        return false;
    }

    Appointment appointment = {
        .id = schedule->num_appointments + 1,
        .name = name,
        .start_time = start_time,
        .duration = APPOINTMENT_LENGTH
    };

    schedule->appointments[schedule->num_appointments++] = appointment;
    return true;
}

bool check_conflicts(const Schedule schedule, int proposed_start_time) {
    for (int i = 0; i < schedule.num_appointments; ++i) {
        Appointment appointment = schedule.appointments[i];
        if ((appointment.start_time <= proposed_start_time && proposed_start_time < appointment.start_time + appointment.duration) ||
            (appointment.start_time + appointment.duration <= proposed_start_time && proposed_start_time < appointment.start_time)) {
            return false;
        }
    }

    return true;
}

int main() {
    Schedule schedule = {0};

    const char *appointment_names[] = {"Lady Lovelace's Tea Party", "Poet's Soiree", "Mathematical Congress",
                                       "Scientific Symposium", "Engineering Gathering"};

    // Seed random number generator
    srand(time(NULL));

    for (int i = 0; i < 5; ++i) {
        int proposed_start_time = 60 * rand() / RAND_MAX; // random start time between 0 and 1 hour

        // Check for conflicts before adding the appointment
        if (check_conflicts(schedule, proposed_start_time * 60)) {
            printf("Proposed appointment for %s at %d:%02d:%02d does not conflict with existing appointments.\n",
                   appointment_names[i], proposed_start_time / 60, proposed_start_time % 60);

            add_appointment(&schedule, appointment_names[i], proposed_start_time * 60);
        } else {
            printf("Proposed appointment for %s at %d:%02d:%02d conflicts with an existing appointment.\n",
                   appointment_names[i], proposed_start_time / 60, proposed_start_time % 60);
        }
    }

    print_schedule(schedule);

    return 0;
}