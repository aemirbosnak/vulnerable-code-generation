//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int start_time; // in minutes past midnight
    int end_time; // in minutes past midnight
} appointment_t;

// Global array of appointments
appointment_t appointments[MAX_APPOINTMENTS];

// Number of appointments in the array
int num_appointments = 0;

// Function to compare two appointments by start time
int compare_appointments(const void *a, const void *b) {
    const appointment_t *appt1 = (const appointment_t *)a;
    const appointment_t *appt2 = (const appointment_t *)b;

    return appt1->start_time - appt2->start_time;
}

// Function to add an appointment to the array
void add_appointment(char *name, char *description, int start_time, int end_time) {
    // Check if the array is full
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Error: Appointment array is full.\n");
        return;
    }

    // Check if the start time is valid
    if (start_time < 0 || start_time > 1440) {
        printf("Error: Invalid start time.\n");
        return;
    }

    // Check if the end time is valid
    if (end_time < 0 || end_time > 1440) {
        printf("Error: Invalid end time.\n");
        return;
    }

    // Check if the start time is before the end time
    if (start_time >= end_time) {
        printf("Error: Start time must be before end time.\n");
        return;
    }

    // Copy the appointment into the array
    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].description, description);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    // Increment the number of appointments
    num_appointments++;
}

// Function to print the appointments in the array
void print_appointments() {
    // Sort the appointments by start time
    qsort(appointments, num_appointments, sizeof(appointment_t), compare_appointments);

    // Print the appointments
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%d - %d): %s\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time, appointments[i].description);
    }
}

// Function to find an appointment by name
appointment_t *find_appointment(char *name) {
    // Loop through the appointments
    for (int i = 0; i < num_appointments; i++) {
        // Check if the appointment name matches the given name
        if (strcmp(appointments[i].name, name) == 0) {
            // Return the appointment
            return &appointments[i];
        }
    }

    // Return NULL if the appointment was not found
    return NULL;
}

// Function to delete an appointment by name
void delete_appointment(char *name) {
    // Find the appointment
    appointment_t *appt = find_appointment(name);

    // Check if the appointment was found
    if (appt == NULL) {
        printf("Error: Appointment not found.\n");
        return;
    }

    // Shift the appointments after the deleted appointment to the left
    for (int i = appt - appointments + 1; i < num_appointments; i++) {
        appointments[i - 1] = appointments[i];
    }

    // Decrement the number of appointments
    num_appointments--;
}

// Function to get user input
void get_user_input(char *name, char *description, int *start_time, int *end_time) {
    // Get the appointment name
    printf("Enter appointment name: ");
    scanf(" %s", name);

    // Get the appointment description
    printf("Enter appointment description: ");
    scanf(" %[^\n]%*c", description);

    // Get the appointment start time
    printf("Enter appointment start time (in minutes past midnight): ");
    scanf(" %d", start_time);

    // Get the appointment end time
    printf("Enter appointment end time (in minutes past midnight): ");
    scanf(" %d", end_time);
}

// Main function
int main() {
    // Get user input
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int start_time;
    int end_time;
    get_user_input(name, description, &start_time, &end_time);

    // Add the appointment to the array
    add_appointment(name, description, start_time, end_time);

    // Print the appointments
    print_appointments();

    return 0;
}