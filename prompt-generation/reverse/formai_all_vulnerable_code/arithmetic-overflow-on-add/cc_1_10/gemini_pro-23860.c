//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of an appointment
typedef struct appointment {
    int id;
    char *description;
    time_t start_time;
    time_t end_time;
} appointment_t;

// Create a new appointment
appointment_t *create_appointment(int id, char *description, time_t start_time, time_t end_time) {
    appointment_t *new_appointment = malloc(sizeof(appointment_t));
    new_appointment->id = id;
    new_appointment->description = strdup(description);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    return new_appointment;
}

// Free the memory allocated for an appointment
void free_appointment(appointment_t *appointment) {
    free(appointment->description);
    free(appointment);
}

// Print the details of an appointment
void print_appointment(appointment_t *appointment) {
    printf("Appointment ID: %d\n", appointment->id);
    printf("Description: %s\n", appointment->description);
    printf("Start time: %s", ctime(&appointment->start_time));
    printf("End time: %s", ctime(&appointment->end_time));
}

// Sort appointments by start time
int compare_appointments(const void *a, const void *b) {
    appointment_t *appt1 = (appointment_t *)a;
    appointment_t *appt2 = (appointment_t *)b;
    return appt1->start_time - appt2->start_time;
}

// Get the current day's date
time_t get_today() {
    time_t now = time(NULL);
    struct tm *today = localtime(&now);
    today->tm_hour = 0;
    today->tm_min = 0;
    today->tm_sec = 0;
    return mktime(today);
}

// Get the next day's date
time_t get_tomorrow() {
    time_t now = time(NULL);
    struct tm *tomorrow = localtime(&now);
    tomorrow->tm_hour = 0;
    tomorrow->tm_min = 0;
    tomorrow->tm_sec = 0;
    tomorrow->tm_mday++;
    return mktime(tomorrow);
}

// Get the start time of the next available time slot
time_t get_next_available_time(time_t start_time, time_t end_time, time_t interval) {
    time_t next_available_time = start_time;
    while (next_available_time < end_time) {
        if (next_available_time >= time(NULL)) {
            return next_available_time;
        }
        next_available_time += interval;
    }
    return -1;
}

// Schedule an appointment
appointment_t *schedule_appointment(time_t start_time, time_t end_time, char *description) {
    // Check if the start time is valid
    if (start_time < time(NULL)) {
        printf("Error: Start time must be in the future.\n");
        return NULL;
    }

    // Check if the end time is valid
    if (end_time <= start_time) {
        printf("Error: End time must be after the start time.\n");
        return NULL;
    }

    // Check if the description is valid
    if (description == NULL || strlen(description) == 0) {
        printf("Error: Description cannot be empty.\n");
        return NULL;
    }

    // Create a new appointment
    appointment_t *new_appointment = create_appointment(0, description, start_time, end_time);

    // Return the new appointment
    return new_appointment;
}

// Main function
int main() {
    // Create an array of appointments
    appointment_t *appointments[] = {
        create_appointment(1, "Meeting with the boss", get_today() + 3600, get_today() + 4200),
        create_appointment(2, "Doctor's appointment", get_tomorrow() + 10800, get_tomorrow() + 11400),
        create_appointment(3, "Lunch with friends", get_today() + 12600, get_today() + 13200),
    };

    // Sort the appointments by start time
    qsort(appointments, sizeof(appointments) / sizeof(appointment_t *), sizeof(appointment_t *), compare_appointments);

    // Print the appointments
    for (int i = 0; i < sizeof(appointments) / sizeof(appointment_t *); i++) {
        print_appointment(appointments[i]);
        printf("\n");
    }

    // Free the memory allocated for the appointments
    for (int i = 0; i < sizeof(appointments) / sizeof(appointment_t *); i++) {
        free_appointment(appointments[i]);
    }

    return 0;
}