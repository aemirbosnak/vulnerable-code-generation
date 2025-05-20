//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment struct
typedef struct Appointment {
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
    Appointment **appointments;
    int num_appointments;
} AppointmentScheduler;

// Create a new appointment
Appointment *create_appointment(char *description, time_t start_time, time_t end_time) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->description = description;
    appointment->start_time = start_time;
    appointment->end_time = end_time;
    return appointment;
}

// Create a new appointment scheduler
AppointmentScheduler *create_appointment_scheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->appointments = malloc(0);
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    scheduler->appointments = realloc(scheduler->appointments, (scheduler->num_appointments + 1) * sizeof(Appointment *));
    scheduler->appointments[scheduler->num_appointments] = appointment;
    scheduler->num_appointments++;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler *scheduler, int index) {
    free(scheduler->appointments[index]);
    for (int i = index; i < scheduler->num_appointments - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }
    scheduler->num_appointments--;
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        Appointment *appointment = scheduler->appointments[i];
        printf("%s: %s - %s\n", appointment->description, ctime(&appointment->start_time), ctime(&appointment->end_time));
    }
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    add_appointment(scheduler, create_appointment("Meeting with John", time(NULL), time(NULL) + 3600));
    add_appointment(scheduler, create_appointment("Lunch with Mary", time(NULL) + 3600, time(NULL) + 7200));
    add_appointment(scheduler, create_appointment("Dinner with Bob", time(NULL) + 7200, time(NULL) + 10800));

    // Print the appointments in the scheduler
    printf("Appointments:\n");
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, 1);

    // Print the appointments in the scheduler
    printf("Appointments after removing lunch with Mary:\n");
    print_appointments(scheduler);

    // Free the appointment scheduler
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]);
    }
    free(scheduler->appointments);
    free(scheduler);

    return 0;
}