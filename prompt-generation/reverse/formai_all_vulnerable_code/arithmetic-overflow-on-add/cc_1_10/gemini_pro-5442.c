//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store appointment data
typedef struct Appointment {
    char *name;
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Function to create a new appointment
Appointment *create_appointment(char *name, char *description, time_t start_time, time_t end_time) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->description = strdup(description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;
    return appointment;
}

// Function to compare two appointments by start time
int compare_appointments(const void *a, const void *b) {
    Appointment *appointment1 = (Appointment *)a;
    Appointment *appointment2 = (Appointment *)b;
    return appointment1->start_time - appointment2->start_time;
}

// Function to print an appointment
void print_appointment(Appointment *appointment) {
    printf("%s: %s (%s - %s)\n", appointment->name, appointment->description, ctime(&appointment->start_time), ctime(&appointment->end_time));
}

// Function to free the memory allocated for an appointment
void free_appointment(Appointment *appointment) {
    free(appointment->name);
    free(appointment->description);
    free(appointment);
}

// Main function
int main() {
    // Create an array of appointments
    Appointment *appointments[] = {
        create_appointment("Appointment 1", "Description 1", time(NULL) + 3600, time(NULL) + 7200),
        create_appointment("Appointment 2", "Description 2", time(NULL) + 10800, time(NULL) + 14400),
        create_appointment("Appointment 3", "Description 3", time(NULL) + 18000, time(NULL) + 21600),
        create_appointment("Appointment 4", "Description 4", time(NULL) + 25200, time(NULL) + 28800),
        create_appointment("Appointment 5", "Description 5", time(NULL) + 32400, time(NULL) + 36000),
    };

    // Sort the appointments by start time
    qsort(appointments, sizeof(appointments) / sizeof(Appointment *), sizeof(Appointment *), compare_appointments);

    // Print the appointments
    for (int i = 0; i < sizeof(appointments) / sizeof(Appointment *); i++) {
        print_appointment(appointments[i]);
    }

    // Free the memory allocated for the appointments
    for (int i = 0; i < sizeof(appointments) / sizeof(Appointment *); i++) {
        free_appointment(appointments[i]);
    }

    return 0;
}