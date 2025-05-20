//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structure to store an appointment
typedef struct Appointment {
    char *title;
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Function to create a new appointment
Appointment *create_appointment(char *title, char *description, time_t start_time, time_t end_time) {
    Appointment *appt = malloc(sizeof(Appointment));
    if (appt == NULL) {
        return NULL;
    }

    appt->title = strdup(title);
    appt->description = strdup(description);
    appt->start_time = start_time;
    appt->end_time = end_time;

    return appt;
}

// Function to destroy an appointment
void destroy_appointment(Appointment *appt) {
    free(appt->title);
    free(appt->description);
    free(appt);
}

// Function to print an appointment
void print_appointment(Appointment *appt) {
    printf("Title: %s\n", appt->title);
    printf("Description: %s\n", appt->description);
    printf("Start time: %s", ctime(&appt->start_time));
    printf("End time: %s", ctime(&appt->end_time));
}

// Function to compare two appointments
int compare_appointments(const Appointment *appt1, const Appointment *appt2) {
    return appt1->start_time - appt2->start_time;
}

// Function to sort an array of appointments
void sort_appointments(Appointment **appts, int num_appts) {
    qsort(appts, num_appts, sizeof(Appointment *), (int (*)(const void *, const void *))compare_appointments);
}

// Function to find the first available time slot
time_t find_available_time_slot(Appointment **appts, int num_appts, time_t start_time, time_t end_time) {
    for (int i = 0; i < num_appts; i++) {
        if (appts[i]->start_time >= end_time) {
            return appts[i]->start_time;
        }
    }

    return -1;
}

// Function to schedule an appointment
int schedule_appointment(Appointment **appts, int *num_appts, Appointment *appt) {
    // Sort the appointments
    sort_appointments(appts, *num_appts);

    // Find the first available time slot
    time_t available_time_slot = find_available_time_slot(appts, *num_appts, appt->start_time, appt->end_time);

    // If there is no available time slot, return an error
    if (available_time_slot == -1) {
        return -1;
    }

    // Add the appointment to the array
    appts[*num_appts] = appt;
    (*num_appts)++;

    return 0;
}

// Function to cancel an appointment
int cancel_appointment(Appointment **appts, int *num_appts, Appointment *appt) {
    // Find the appointment in the array
    int index = -1;
    for (int i = 0; i < *num_appts; i++) {
        if (appts[i] == appt) {
            index = i;
            break;
        }
    }

    // If the appointment was not found, return an error
    if (index == -1) {
        return -1;
    }

    // Remove the appointment from the array
    for (int i = index; i < *num_appts - 1; i++) {
        appts[i] = appts[i + 1];
    }

    (*num_appts)--;

    return 0;
}

// Main function
int main() {
    // Create an array of appointments
    Appointment *appts[10];
    int num_appts = 0;

    // Schedule some appointments
    Appointment *appt1 = create_appointment("Doctor's appointment", "Annual checkup", time(NULL) + 3600, time(NULL) + 4200);
    schedule_appointment(appts, &num_appts, appt1);

    Appointment *appt2 = create_appointment("Meeting with boss", "Discuss project plans", time(NULL) + 10800, time(NULL) + 11400);
    schedule_appointment(appts, &num_appts, appt2);

    Appointment *appt3 = create_appointment("Lunch with friend", "Catch up", time(NULL) + 14400, time(NULL) + 15000);
    schedule_appointment(appts, &num_appts, appt3);

    // Print the appointments
    for (int i = 0; i < num_appts; i++) {
        print_appointment(appts[i]);
        printf("\n");
    }

    // Cancel an appointment
    cancel_appointment(appts, &num_appts, appt2);

    // Print the appointments again
    for (int i = 0; i < num_appts; i++) {
        print_appointment(appts[i]);
        printf("\n");
    }

    // Destroy the appointments
    for (int i = 0; i < num_appts; i++) {
        destroy_appointment(appts[i]);
    }

    return 0;
}