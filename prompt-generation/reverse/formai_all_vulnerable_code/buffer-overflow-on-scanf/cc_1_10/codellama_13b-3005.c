//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: complex
/*
 * Appointment Scheduler
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

// Struct to store appointment details
typedef struct {
    char name[50];
    char date[20];
    char time[20];
    char duration[20];
} Appointment;

// Function to get appointment details from the user
void getAppointmentDetails(Appointment *appointment) {
    printf("Enter appointment name: ");
    scanf("%s", appointment->name);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", appointment->date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", appointment->time);
    printf("Enter appointment duration (HH:MM): ");
    scanf("%s", appointment->duration);
}

// Function to display appointment details
void displayAppointmentDetails(Appointment appointment) {
    printf("Appointment name: %s\n", appointment.name);
    printf("Appointment date: %s\n", appointment.date);
    printf("Appointment time: %s\n", appointment.time);
    printf("Appointment duration: %s\n", appointment.duration);
}

// Function to add appointment to the schedule
void addAppointment(Appointment *appointments, int *size, Appointment appointment) {
    appointments[*size] = appointment;
    *size += 1;
}

// Function to remove appointment from the schedule
void removeAppointment(Appointment *appointments, int *size, Appointment appointment) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(appointments[i].name, appointment.name) == 0) {
            appointments[i] = appointments[*size - 1];
            *size -= 1;
            break;
        }
    }
}

// Function to display all appointments in the schedule
void displayAppointments(Appointment *appointments, int size) {
    for (int i = 0; i < size; i++) {
        displayAppointmentDetails(appointments[i]);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int size = 0;

    // Get appointment details from the user
    Appointment appointment;
    getAppointmentDetails(&appointment);

    // Add appointment to the schedule
    addAppointment(appointments, &size, appointment);

    // Display all appointments in the schedule
    displayAppointments(appointments, size);

    // Remove appointment from the schedule
    removeAppointment(appointments, &size, appointment);

    // Display all appointments in the schedule
    displayAppointments(appointments, size);

    return 0;
}