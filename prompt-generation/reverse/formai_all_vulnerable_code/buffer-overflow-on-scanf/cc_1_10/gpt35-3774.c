//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define MAX_APPOINTMENTS 100

// Global variables
int appointments[MAX_APPOINTMENTS];
int number_of_appointments = 0;

// Function declarations
void view_appointments();
void add_appointment();
void cancel_appointment();

// Main function
int main() {
    int input;
    bool running = true;
    while (running) {
        printf("Appointment Scheduler\n");
        printf("1. View Appointments\n");
        printf("2. Add Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit\n");
        printf("Select option (1-4): ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                view_appointments();
                break;
            case 2:
                add_appointment();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                running = false;
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid input. Please select option 1-4.\n");
                break;
        }
    }
    return 0;
}

// Function definitions
void view_appointments() {
    printf("Appointments:\n");
    if (number_of_appointments == 0) {
        printf("No appointments scheduled.\n");
    } else {
        for (int i = 0; i < number_of_appointments; i++) {
            printf("%d. Appointment %d\n", i+1, appointments[i]);
        }
    }
}

void add_appointment() {
    if (number_of_appointments == MAX_APPOINTMENTS) {
        printf("Maximum appointments reached. Cannot add more.\n");
        return;
    }

    int time;
    printf("Enter appointment time (in hours): ");
    scanf("%d", &time);

    appointments[number_of_appointments] = time;
    number_of_appointments++;

    printf("Appointment added at %d hours.\n", time);
}

void cancel_appointment() {
    if (number_of_appointments == 0) {
        printf("No appointments scheduled. Cannot cancel any.\n");
        return;
    }

    int appointment_number;
    printf("Enter appointment number to cancel: ");
    scanf("%d", &appointment_number);

    if (appointment_number < 1 || appointment_number > number_of_appointments) {
        printf("Invalid appointment number. Please select one between 1 and %d\n", number_of_appointments);
        return;
    }

    int time = appointments[appointment_number-1];
    printf("Appointment at %d hours cancelled.\n", time);

    for (int i = appointment_number-1; i < number_of_appointments-1; i++) {
        appointments[i] = appointments[i+1];
    }

    number_of_appointments--;
}