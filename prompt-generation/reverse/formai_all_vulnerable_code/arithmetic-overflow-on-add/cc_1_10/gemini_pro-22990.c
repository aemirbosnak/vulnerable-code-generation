//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Appointment {
    char *title;
    time_t start_time;
    time_t end_time;
} Appointment;

typedef struct AppointmentScheduler {
    Appointment **appointments;
    int num_appointments;
} AppointmentScheduler;

AppointmentScheduler *create_appointment_scheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->appointments = malloc(0);
    scheduler->num_appointments = 0;
    return scheduler;
}

void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]->title);
        free(scheduler->appointments[i]);
    }
    free(scheduler->appointments);
    free(scheduler);
}

bool is_overlapping(Appointment *a1, Appointment *a2) {
    return a1->start_time < a2->end_time && a2->start_time < a1->end_time;
}

bool add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    if (scheduler->num_appointments == 0) {
        scheduler->appointments = realloc(scheduler->appointments, sizeof(Appointment *));
        scheduler->appointments[0] = appointment;
        scheduler->num_appointments++;
        return true;
    }
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (!is_overlapping(scheduler->appointments[i], appointment)) {
            scheduler->appointments = realloc(scheduler->appointments, sizeof(Appointment *) * (scheduler->num_appointments + 1));
            for (int j = scheduler->num_appointments; j > i; j--) {
                scheduler->appointments[j] = scheduler->appointments[j - 1];
            }
            scheduler->appointments[i] = appointment;
            scheduler->num_appointments++;
            return true;
        }
    }
    return false;
}

void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s: %s - %s\n", scheduler->appointments[i]->title, ctime(&scheduler->appointments[i]->start_time), ctime(&scheduler->appointments[i]->end_time));
    }
}

int main() {
    AppointmentScheduler *scheduler = create_appointment_scheduler();

    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->title = "Meeting with Bob";
    appointment1->start_time = time(NULL) + 3600;
    appointment1->end_time = time(NULL) + 4800;

    add_appointment(scheduler, appointment1);

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->title = "Lunch with Alice";
    appointment2->start_time = time(NULL) + 7200;
    appointment2->end_time = time(NULL) + 8400;

    add_appointment(scheduler, appointment2);

    Appointment *appointment3 = malloc(sizeof(Appointment));
    appointment3->title = "Call with Charlie";
    appointment3->start_time = time(NULL) + 10800;
    appointment3->end_time = time(NULL) + 12000;

    add_appointment(scheduler, appointment3);

    print_appointments(scheduler);

    destroy_appointment_scheduler(scheduler);

    return 0;
}