//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char *name;
    char *description;
    time_t start_time;
    time_t end_time;
};

struct AppointmentScheduler {
    struct Appointment *appointments[MAX_APPOINTMENTS];
    int num_appointments;
};

void initialize_scheduler(struct AppointmentScheduler *scheduler) {
    scheduler->num_appointments = 0;
}

int add_appointment(struct AppointmentScheduler *scheduler, struct Appointment *appointment) {
    if (scheduler->num_appointments == MAX_APPOINTMENTS) {
        return -1;
    }

    scheduler->appointments[scheduler->num_appointments++] = appointment;
    return 0;
}

void print_appointments(struct AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        struct Appointment *appointment = scheduler->appointments[i];
        printf("%s: %s, %s - %s\n", appointment->name, appointment->description, ctime(&appointment->start_time), ctime(&appointment->end_time));
    }
}

int main() {
    struct AppointmentScheduler scheduler;
    initialize_scheduler(&scheduler);

    struct Appointment appointment1;
    appointment1.name = "John Doe";
    appointment1.description = "Meeting with the boss";
    appointment1.start_time = time(NULL) + 3600;
    appointment1.end_time = appointment1.start_time + 3600;

    struct Appointment appointment2;
    appointment2.name = "Jane Doe";
    appointment2.description = "Lunch with a friend";
    appointment2.start_time = time(NULL) + 7200;
    appointment2.end_time = appointment2.start_time + 3600;

    add_appointment(&scheduler, &appointment1);
    add_appointment(&scheduler, &appointment2);

    print_appointments(&scheduler);

    return 0;
}