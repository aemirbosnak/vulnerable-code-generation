//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
/*
 * C Appointment Scheduler Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50

// Struct to represent an appointment
typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment_t;

// Function to create a new appointment
appointment_t* new_appointment(char* name, time_t start_time, time_t end_time) {
    appointment_t* appointment = (appointment_t*) malloc(sizeof(appointment_t));
    strcpy(appointment->name, name);
    appointment->start_time = start_time;
    appointment->end_time = end_time;
    return appointment;
}

// Function to print all appointments in the schedule
void print_appointments(appointment_t* appointments[], int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        appointment_t* appointment = appointments[i];
        printf("%s: %s - %s\n", appointment->name, ctime(&appointment->start_time), ctime(&appointment->end_time));
    }
}

// Function to add an appointment to the schedule
void add_appointment(appointment_t* appointments[], int* num_appointments, char* name, time_t start_time, time_t end_time) {
    // Check if there is space in the schedule
    if (*num_appointments == MAX_APPOINTMENTS) {
        printf("Schedule is full. Unable to add appointment.\n");
        return;
    }
    // Create a new appointment
    appointment_t* appointment = new_appointment(name, start_time, end_time);
    // Add the appointment to the schedule
    appointments[(*num_appointments)++] = appointment;
}

// Function to remove an appointment from the schedule
void remove_appointment(appointment_t* appointments[], int* num_appointments, char* name) {
    // Find the appointment with the given name
    int i;
    for (i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i]->name, name) == 0) {
            break;
        }
    }
    // Check if the appointment was found
    if (i == *num_appointments) {
        printf("Appointment not found.\n");
        return;
    }
    // Remove the appointment from the schedule
    appointment_t* appointment = appointments[i];
    free(appointment);
    // Shift the remaining appointments to the left
    for (int j = i; j < *num_appointments - 1; j++) {
        appointments[j] = appointments[j + 1];
    }
    // Decrement the number of appointments
    (*num_appointments)--;
}

// Function to find the first appointment with a given name
appointment_t* find_appointment(appointment_t* appointments[], int num_appointments, char* name) {
    // Find the appointment with the given name
    int i;
    for (i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i]->name, name) == 0) {
            break;
        }
    }
    // Check if the appointment was found
    if (i == num_appointments) {
        return NULL;
    }
    // Return the found appointment
    return appointments[i];
}

int main() {
    // Create an array to store the appointments
    appointment_t* appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    // Add some appointments to the schedule
    add_appointment(appointments, &num_appointments, "Appointment 1", 1234567890, 1234567890 + 3600);
    add_appointment(appointments, &num_appointments, "Appointment 2", 1234567890 + 7200, 1234567890 + 10800);
    add_appointment(appointments, &num_appointments, "Appointment 3", 1234567890 + 14400, 1234567890 + 18000);
    // Print all appointments in the schedule
    print_appointments(appointments, num_appointments);
    // Remove an appointment from the schedule
    remove_appointment(appointments, &num_appointments, "Appointment 2");
    // Print all appointments in the schedule again
    print_appointments(appointments, num_appointments);
    // Find the first appointment with a given name
    appointment_t* appointment = find_appointment(appointments, num_appointments, "Appointment 3");
    if (appointment != NULL) {
        printf("Found appointment: %s - %s\n", ctime(&appointment->start_time), ctime(&appointment->end_time));
    }
    return 0;
}