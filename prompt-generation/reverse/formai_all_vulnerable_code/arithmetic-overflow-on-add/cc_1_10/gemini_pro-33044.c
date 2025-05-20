//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Appointment structure
typedef struct Appointment {
    int id;
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Appointment list structure
typedef struct AppointmentList {
    Appointment *appointments;
    int size;
} AppointmentList;

// Create a new appointment
Appointment *createAppointment(int id, char *description, time_t start_time, time_t end_time) {
    // Allocate memory for the appointment
    Appointment *appointment = malloc(sizeof(Appointment));

    // Set the appointment's properties
    appointment->id = id;
    appointment->description = malloc(strlen(description) + 1);
    strcpy(appointment->description, description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;

    // Return the appointment
    return appointment;
}

// Add an appointment to an appointment list
void addAppointment(AppointmentList *list, Appointment *appointment) {
    // Reallocate memory for the appointment list if necessary
    if (list->size == 0) {
        list->appointments = malloc(sizeof(Appointment) * 1);
        list->size = 1;
    } else if (list->size >= 1) {
        list->appointments = realloc(list->appointments, sizeof(Appointment) * (list->size + 1));
        list->size++;
    }

    // Add the appointment to the list
    list->appointments[list->size - 1] = *appointment;
}

// Print an appointment
void printAppointment(Appointment *appointment) {
    printf("Appointment %d:\n", appointment->id);
    printf("Description: %s\n", appointment->description);
    printf("Start time: %s", ctime(&appointment->start_time));
    printf("End time: %s", ctime(&appointment->end_time));
}

// Print an appointment list
void printAppointmentList(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        printAppointment(&list->appointments[i]);
        printf("\n");
    }
}

// Get the current time
time_t getCurrentTime() {
    time_t current_time;

    time(&current_time);

    return current_time;
}

// Main function
int main() {
    // Create an appointment list
    AppointmentList list;
    list.appointments = NULL;
    list.size = 0;

    // Add some appointments to the list
    addAppointment(&list, createAppointment(1, "Meeting with client", getCurrentTime() + 3600, getCurrentTime() + 7200));
    addAppointment(&list, createAppointment(2, "Doctor's appointment", getCurrentTime() + 86400, getCurrentTime() + 93600));
    addAppointment(&list, createAppointment(3, "Dinner with friends", getCurrentTime() + 172800, getCurrentTime() + 180000));

    // Print the appointment list
    printAppointmentList(&list);

    // Free the memory allocated for the appointment list
    for (int i = 0; i < list.size; i++) {
        free(list.appointments[i].description);
    }
    free(list.appointments);

    return 0;
}