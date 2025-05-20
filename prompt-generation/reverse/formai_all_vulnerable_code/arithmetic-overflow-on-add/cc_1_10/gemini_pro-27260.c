//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    char *name;
    time_t start_time;
    time_t end_time;
} appointment_t;

typedef struct {
    appointment_t *appointments;
    int num_appointments;
    unsigned int max_appointments;
} schedule_t;

// Create a new schedule
schedule_t *create_schedule(void)
{
    schedule_t *schedule = malloc(sizeof(schedule_t));
    if (!schedule) {
        return NULL;
    }

    schedule->appointments = NULL;
    schedule->num_appointments = 0;
    schedule->max_appointments = 0;

    return schedule;
}

// Destroy a schedule
void destroy_schedule(schedule_t *schedule)
{
    if (!schedule) {
        return;
    }

    for (int i = 0; i < schedule->num_appointments; i++) {
        free(schedule->appointments[i].name);
    }

    free(schedule->appointments);
    free(schedule);
}

// Add an appointment to a schedule
int add_appointment(schedule_t *schedule, char *name, time_t start_time, time_t end_time)
{
    if (!schedule) {
        return -1;
    }

    // Check if the appointment overlaps with any existing appointments
    for (int i = 0; i < schedule->num_appointments; i++) {
        if (schedule->appointments[i].start_time <= start_time && schedule->appointments[i].end_time >= start_time) {
            return -1;
        }
        if (schedule->appointments[i].start_time <= end_time && schedule->appointments[i].end_time >= end_time) {
            return -1;
        }
    }

    // Allocate memory for the new appointment
    appointment_t *appointment = malloc(sizeof(appointment_t));
    if (!appointment) {
        return -1;
    }

    // Initialize the new appointment
    appointment->name = strdup(name);
    appointment->start_time = start_time;
    appointment->end_time = end_time;

    // Add the new appointment to the schedule
    if (schedule->num_appointments == schedule->max_appointments) {
        // Allocate more memory for the schedule
        schedule->appointments = realloc(schedule->appointments, sizeof(appointment_t) * (schedule->max_appointments + 10));
        if (!schedule->appointments) {
            free(appointment);
            return -1;
        }

        schedule->max_appointments += 10;
    }

    schedule->appointments[schedule->num_appointments] = *appointment;
    schedule->num_appointments++;

    return 0;
}

// Remove an appointment from a schedule
int remove_appointment(schedule_t *schedule, char *name)
{
    int i;
    int found = 0;

    if (!schedule) {
        return -1;
    }

    // Find the appointment to remove
    for (i = 0; i < schedule->num_appointments; i++) {
        if (strcmp(schedule->appointments[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    // If the appointment was found, remove it from the schedule
    if (found) {
        free(schedule->appointments[i].name);
        schedule->num_appointments--;
        for (int j = i; j < schedule->num_appointments; j++) {
            schedule->appointments[j] = schedule->appointments[j + 1];
        }
    }

    return found ? 0 : -1;
}

// Print the schedule
void print_schedule(schedule_t *schedule)
{
    if (!schedule) {
        return;
    }

    for (int i = 0; i < schedule->num_appointments; i++) {
        printf("%s: %s - %s\n", schedule->appointments[i].name, ctime(&schedule->appointments[i].start_time), ctime(&schedule->appointments[i].end_time));
    }
}

int main(void)
{
    // Create a new schedule
    schedule_t *schedule = create_schedule();

    // Add some appointments to the schedule
    add_appointment(schedule, "John Doe", time(NULL) + 3600, time(NULL) + 7200);
    add_appointment(schedule, "Jane Doe", time(NULL) + 7200, time(NULL) + 10800);

    // Print the schedule
    print_schedule(schedule);

    // Remove an appointment from the schedule
    remove_appointment(schedule, "John Doe");

    // Print the schedule again
    print_schedule(schedule);

    // Destroy the schedule
    destroy_schedule(schedule);

    return 0;
}