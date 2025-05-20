//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define the appointment structure
typedef struct Appointment {
    char name[50];
    char description[200];
    time_t start_time;
    time_t end_time;
} Appointment;

// Define the appointment list structure
typedef struct AppointmentList {
    Appointment *appointments;
    int size;
    int capacity;
} AppointmentList;

// Create a new appointment list
AppointmentList *create_appointment_list() {
    AppointmentList *list = malloc(sizeof(AppointmentList));
    list->appointments = malloc(sizeof(Appointment) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

// Add an appointment to the list
void add_appointment(AppointmentList *list, Appointment appointment) {
    // Check if the list is full
    if (list->size == list->capacity) {
        // Reallocate the list to double the capacity
        list->appointments = realloc(list->appointments, sizeof(Appointment) * list->capacity * 2);
        list->capacity *= 2;
    }

    // Add the appointment to the list
    list->appointments[list->size] = appointment;
    list->size++;
}

// Remove an appointment from the list
void remove_appointment(AppointmentList *list, int index) {
    // Check if the index is valid
    if (index < 0 || index >= list->size) {
        return;
    }

    // Shift the appointments after the index down by one
    for (int i = index; i < list->size - 1; i++) {
        list->appointments[i] = list->appointments[i + 1];
    }

    // Decrement the size of the list
    list->size--;
}

// Find an appointment by name
Appointment *find_appointment_by_name(AppointmentList *list, char *name) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->appointments[i].name, name) == 0) {
            return &list->appointments[i];
        }
    }

    return NULL;
}

// Print the list of appointments
void print_appointment_list(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s\t%s\t%s\t%s\n", list->appointments[i].name, list->appointments[i].description, ctime(&list->appointments[i].start_time), ctime(&list->appointments[i].end_time));
    }
}

// Free the memory allocated for the list
void free_appointment_list(AppointmentList *list) {
    free(list->appointments);
    free(list);
}

// Get the current time
time_t get_current_time() {
    time_t current_time;
    time(&current_time);
    return current_time;
}

// Get the start time of an appointment
time_t get_start_time(Appointment appointment) {
    return appointment.start_time;
}

// Get the end time of an appointment
time_t get_end_time(Appointment appointment) {
    return appointment.end_time;
}

// Check if an appointment is overlapping with another appointment
bool is_overlapping(Appointment appointment1, Appointment appointment2) {
    return get_start_time(appointment1) < get_end_time(appointment2) && get_start_time(appointment2) < get_end_time(appointment1);
}

// Main function
int main() {
    // Create an appointment list
    AppointmentList *list = create_appointment_list();

    // Add some appointments to the list
    Appointment appointment1 = {"John Doe", "Meeting with the client", get_current_time() + 3600, get_current_time() + 4800};
    add_appointment(list, appointment1);
    Appointment appointment2 = {"Jane Doe", "Lunch with a friend", get_current_time() + 7200, get_current_time() + 8400};
    add_appointment(list, appointment2);
    Appointment appointment3 = {"John Doe", "Meeting with the team", get_current_time() + 10800, get_current_time() + 12000};
    add_appointment(list, appointment3);

    // Print the list of appointments
    printf("Appointments:\n");
    print_appointment_list(list);

    // Find an appointment by name
    Appointment *appointment = find_appointment_by_name(list, "John Doe");
    if (appointment != NULL) {
        printf("Found appointment: %s\n", appointment->name);
    } else {
        printf("Appointment not found.\n");
    }

    // Remove an appointment from the list
    remove_appointment(list, 1);

    // Print the list of appointments after removing the appointment
    printf("Appointments after removing an appointment:\n");
    print_appointment_list(list);

    // Free the memory allocated for the list
    free_appointment_list(list);

    return 0;
}