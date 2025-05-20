//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
/*
 * Appointment Scheduler Example Program
 *
 * Author: John Doe
 * Date: 2023-02-02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an appointment
typedef struct appointment {
    char* name;
    char* email;
    char* phone;
    int date;
    int time;
} Appointment;

// Function to add a new appointment
Appointment* add_appointment(Appointment* appointments, int num_appointments, char* name, char* email, char* phone, int date, int time) {
    // Check if the appointment is already in the list
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0 && strcmp(appointments[i].email, email) == 0 && strcmp(appointments[i].phone, phone) == 0 && appointments[i].date == date && appointments[i].time == time) {
            printf("Appointment already in the list\n");
            return appointments;
        }
    }

    // Add the new appointment to the list
    appointments = realloc(appointments, (num_appointments + 1) * sizeof(Appointment));
    appointments[num_appointments].name = name;
    appointments[num_appointments].email = email;
    appointments[num_appointments].phone = phone;
    appointments[num_appointments].date = date;
    appointments[num_appointments].time = time;
    num_appointments++;

    return appointments;
}

// Function to remove an appointment
Appointment* remove_appointment(Appointment* appointments, int num_appointments, char* name, char* email, char* phone, int date, int time) {
    // Check if the appointment is in the list
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0 && strcmp(appointments[i].email, email) == 0 && strcmp(appointments[i].phone, phone) == 0 && appointments[i].date == date && appointments[i].time == time) {
            // Remove the appointment from the list
            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j].name = appointments[j + 1].name;
                appointments[j].email = appointments[j + 1].email;
                appointments[j].phone = appointments[j + 1].phone;
                appointments[j].date = appointments[j + 1].date;
                appointments[j].time = appointments[j + 1].time;
            }
            num_appointments--;
            return appointments;
        }
    }

    // Appointment not found
    printf("Appointment not found\n");
    return appointments;
}

// Function to list all appointments
void list_appointments(Appointment* appointments, int num_appointments) {
    // Print all appointments
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s, Email: %s, Phone: %s, Date: %d, Time: %d\n", appointments[i].name, appointments[i].email, appointments[i].phone, appointments[i].date, appointments[i].time);
    }
}

int main() {
    // Initialize the appointment list
    Appointment* appointments = malloc(sizeof(Appointment));
    int num_appointments = 0;

    // Add appointments
    appointments = add_appointment(appointments, num_appointments, "John Doe", "johndoe@example.com", "555-555-5555", 2023, 14);
    appointments = add_appointment(appointments, num_appointments, "Jane Doe", "janedoe@example.com", "555-555-5556", 2023, 15);
    appointments = add_appointment(appointments, num_appointments, "Jimmy Doe", "jimmydoe@example.com", "555-555-5557", 2023, 16);

    // List all appointments
    list_appointments(appointments, num_appointments);

    // Remove an appointment
    appointments = remove_appointment(appointments, num_appointments, "Jimmy Doe", "jimmydoe@example.com", "555-555-5557", 2023, 16);

    // List all appointments again
    list_appointments(appointments, num_appointments);

    // Free memory
    free(appointments);

    return 0;
}