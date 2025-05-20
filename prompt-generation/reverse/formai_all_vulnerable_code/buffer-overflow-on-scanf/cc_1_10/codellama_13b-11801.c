//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
/*
 * C Appointment Scheduler Example Program
 *
 * By: Your Name
 *
 * This program allows users to schedule appointments for a day
 * and view a list of their upcoming appointments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for appointment
struct appointment {
    char name[50];
    char time[10];
    char date[10];
    char duration[10];
};

// Function to add appointment
void addAppointment(struct appointment *appointments, int *count) {
    // Get input from user
    printf("Enter appointment name: ");
    scanf("%s", appointments[*count].name);
    printf("Enter appointment time: ");
    scanf("%s", appointments[*count].time);
    printf("Enter appointment date: ");
    scanf("%s", appointments[*count].date);
    printf("Enter appointment duration: ");
    scanf("%s", appointments[*count].duration);

    // Increment count
    (*count)++;
}

// Function to view appointments
void viewAppointments(struct appointment *appointments, int count) {
    // Loop through appointments
    for (int i = 0; i < count; i++) {
        // Print appointment
        printf("Appointment %d: %s at %s on %s for %s minutes\n", i + 1, appointments[i].name, appointments[i].time, appointments[i].date, appointments[i].duration);
    }
}

int main() {
    // Initialize variables
    struct appointment appointments[10];
    int count = 0;
    char input[5];

    // Loop until user quits
    while (strcmp(input, "quit") != 0) {
        // Get user input
        printf("Enter a command: ");
        scanf("%s", input);

        // Check user input
        if (strcmp(input, "add") == 0) {
            // Add appointment
            addAppointment(appointments, &count);
        } else if (strcmp(input, "view") == 0) {
            // View appointments
            viewAppointments(appointments, count);
        }
    }

    return 0;
}