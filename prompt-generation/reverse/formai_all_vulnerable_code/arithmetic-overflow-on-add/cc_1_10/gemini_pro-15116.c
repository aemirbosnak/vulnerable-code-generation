//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of appointments that can be scheduled.
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment.
typedef struct Appointment {
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Initialize the appointment scheduler.
Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

// Function to create a new appointment.
Appointment *create_appointment(char *description, time_t start_time, time_t end_time) {
    // Allocate memory for the new appointment.
    Appointment *appointment = malloc(sizeof(Appointment));

    // Initialize the appointment's fields.
    appointment->description = description;
    appointment->start_time = start_time;
    appointment->end_time = end_time;

    // Return the new appointment.
    return appointment;
}

// Function to add an appointment to the schedule.
void add_appointment(Appointment *appointment) {
    // Check if there is room for the new appointment.
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: The appointment scheduler is full.\n");
        return;
    }

    // Add the new appointment to the schedule.
    appointments[num_appointments++] = *appointment;
}

// Function to print the schedule.
void print_schedule() {
    // Loop through the appointments and print their details.
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s\n",
               appointments[i].description,
               ctime(&appointments[i].start_time),
               ctime(&appointments[i].end_time));
    }
}

// Main function.
int main() {
    // Create a few sample appointments.
    Appointment *appointment1 = create_appointment("Meeting with John", time(NULL) + 3600, time(NULL) + 7200);
    Appointment *appointment2 = create_appointment("Interview with Jane", time(NULL) + 10800, time(NULL) + 14400);
    Appointment *appointment3 = create_appointment("Doctor's appointment", time(NULL) + 18000, time(NULL) + 21600);

    // Add the appointments to the schedule.
    add_appointment(appointment1);
    add_appointment(appointment2);
    add_appointment(appointment3);

    // Print the schedule.
    print_schedule();

    // Free the memory allocated for the appointments.
    free(appointment1);
    free(appointment2);
    free(appointment3);

    return 0;
}