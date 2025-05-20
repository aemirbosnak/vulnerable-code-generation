//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
// Appointment Scheduler Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store appointment information
typedef struct {
    char name[50];
    char date[10];
    char time[10];
} Appointment;

// Function to add an appointment
void addAppointment(Appointment *appointment) {
    printf("Enter appointment name: ");
    scanf("%s", appointment->name);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", appointment->date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", appointment->time);
}

// Function to print appointment details
void printAppointment(Appointment *appointment) {
    printf("Appointment Details:\n");
    printf("Name: %s\n", appointment->name);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
}

// Function to delete an appointment
void deleteAppointment(Appointment *appointment) {
    printf("Enter appointment name to delete: ");
    scanf("%s", appointment->name);
    printf("Enter appointment date to delete (YYYY-MM-DD): ");
    scanf("%s", appointment->date);
    printf("Enter appointment time to delete (HH:MM): ");
    scanf("%s", appointment->time);
}

int main() {
    // Create an appointment structure
    Appointment appointment;

    // Add an appointment
    addAppointment(&appointment);

    // Print appointment details
    printAppointment(&appointment);

    // Delete an appointment
    deleteAppointment(&appointment);

    return 0;
}