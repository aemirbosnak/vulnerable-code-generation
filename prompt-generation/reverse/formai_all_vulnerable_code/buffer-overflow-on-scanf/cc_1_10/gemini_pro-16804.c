//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment structure
typedef struct appointment {
    char *name;
    char *date;
    char *time;
} appointment;

// Appointment list
appointment *appointments = NULL;

// Appointment count
int appointment_count = 0;

// Create a new appointment
appointment *new_appointment(char *name, char *date, char *time) {
    appointment *appt = malloc(sizeof(appointment));
    if (appt == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for appointment.\n");
        exit(1);
    }
    appt->name = strdup(name);
    appt->date = strdup(date);
    appt->time = strdup(time);
    return appt;
}

// Add an appointment to the list
void add_appointment(appointment *appt) {
    appointments = realloc(appointments, (appointment_count + 1) * sizeof(appointment));
    if (appointments == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for appointment list.\n");
        exit(1);
    }
    appointments[appointment_count] = *appt;
    appointment_count++;
}

// Print the appointment list
void print_appointments() {
    for (int i = 0; i < appointment_count; i++) {
        printf("%s: %s %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

// Free the appointment list
void free_appointments() {
    for (int i = 0; i < appointment_count; i++) {
        free(appointments[i].name);
        free(appointments[i].date);
        free(appointments[i].time);
    }
    free(appointments);
}

// Interactive Appointment Scheduler
int main() {
    // Initialize the appointment list
    appointments = malloc(0 * sizeof(appointment));
    if (appointments == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for appointment list.\n");
        exit(1);
    }
    appointment_count = 0;

    // Get user input
    char name[100];
    char date[100];
    char time[100];
    printf("Welcome to the Best Appointment Scheduler Ever!\n");
    printf("What's your name?\n");
    scanf("%s", name);
    printf("What day would you like to make an appointment?\n");
    scanf("%s", date);
    printf("What time would you like to make an appointment?\n");
    scanf("%s", time);

    // Create a new appointment
    appointment *appt = new_appointment(name, date, time);

    // Add the appointment to the list
    add_appointment(appt);

    // Print the appointment list
    printf("\nHere's your appointment:\n");
    print_appointments();

    // Free the appointment list
    free_appointments();

    return 0;
}