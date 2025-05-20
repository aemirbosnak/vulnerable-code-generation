//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Appointment {
    char *description;       // Short description of the appointment.
    time_t start_time;      // Epoch time for the start of the appointment.
    time_t end_time;        // Epoch time for the end of the appointment.
} Appointment;

typedef struct AppointmentScheduler {
    Appointment *appointments[100];        // Array to hold the appointments.
    int appointment_count;              // Number of appointments in the array.
} AppointmentScheduler;

// Create a new appointment scheduler.
AppointmentScheduler *appointment_scheduler_create() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    if (scheduler == NULL) {
        return NULL;
    }

    scheduler->appointment_count = 0;

    return scheduler;
}

// Destroy an appointment scheduler.
void appointment_scheduler_destroy(AppointmentScheduler *scheduler) {
    if (scheduler == NULL) {
        return;
    }

    for (int i = 0; i < scheduler->appointment_count; i++) {
        free(scheduler->appointments[i]->description);
        free(scheduler->appointments[i]);
    }

    free(scheduler);
}

// Add an appointment to the scheduler.
int appointment_scheduler_add(AppointmentScheduler *scheduler, const char *description, time_t start_time, time_t end_time) {
    if (scheduler == NULL) {
        return -1;
    }

    if (scheduler->appointment_count >= 100) {
        return -2;
    }

    Appointment *appointment = malloc(sizeof(Appointment));
    if (appointment == NULL) {
        return -3;
    }

    appointment->description = strdup(description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;

    scheduler->appointments[scheduler->appointment_count] = appointment;
    scheduler->appointment_count++;

    return 0;
}

// Remove an appointment from the scheduler.
int appointment_scheduler_remove(AppointmentScheduler *scheduler, int index) {
    if (scheduler == NULL) {
        return -1;
    }

    if (index < 0 || index >= scheduler->appointment_count) {
        return -2;
    }

    free(scheduler->appointments[index]->description);
    free(scheduler->appointments[index]);

    for (int i = index; i < scheduler->appointment_count - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }

    scheduler->appointment_count--;

    return 0;
}

// Print the appointments in the scheduler.
void appointment_scheduler_print(AppointmentScheduler *scheduler) {
    if (scheduler == NULL) {
        return;
    }

    for (int i = 0; i < scheduler->appointment_count; i++) {
        Appointment *appointment = scheduler->appointments[i];

        printf("%d. %s (%s - %s)\n", i, appointment->description, ctime(&appointment->start_time), ctime(&appointment->end_time));
    }
}

// Main function.
int main() {
    // Create an appointment scheduler.
    AppointmentScheduler *scheduler = appointment_scheduler_create();

    // Add some appointments to the scheduler.
    appointment_scheduler_add(scheduler, "Raid the bunker", time(NULL) + 3600, time(NULL) + 7200);
    appointment_scheduler_add(scheduler, "Scavenge for supplies", time(NULL) + 86400, time(NULL) + 108000);
    appointment_scheduler_add(scheduler, "Repair the generator", time(NULL) + 172800, time(NULL) + 194400);

    // Print the appointments in the scheduler.
    appointment_scheduler_print(scheduler);

    // Remove an appointment from the scheduler.
    appointment_scheduler_remove(scheduler, 1);

    // Print the appointments in the scheduler again.
    appointment_scheduler_print(scheduler);

    // Destroy the appointment scheduler.
    appointment_scheduler_destroy(scheduler);

    return 0;
}