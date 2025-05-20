//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of appointments that can be scheduled in a day
#define MAX_APPOINTMENTS 10

// Define structure for an appointment
struct Appointment {
    char patientName[50];
    int time; // 24-hour format: e.g. 1430 means 2:30 PM
};

// Define function signatures
void scheduleAppointment(struct Appointment[], int*);
bool isTimeSlotAvailable(struct Appointment[], int, int);
void displayAppointments(struct Appointment[], int);

// Main function
int main() {
    struct Appointment appointments[MAX_APPOINTMENTS]; // Create an array to store appointments
    int numOfAppointments = 0;

    bool isRunning = true;
    while (isRunning) {
        // Display the menu
        printf("\n\nAppointment Scheduler\n");
        printf("1. Schedule an Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                scheduleAppointment(appointments, &numOfAppointments);
                break;
            case 2:
                displayAppointments(appointments, numOfAppointments);
                break;
            case 3:
                isRunning = false;
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

// Schedule an appointment
void scheduleAppointment(struct Appointment appointments[], int* numOfAppointments) {
    // Check if maximum number of appointments reached
    if (*numOfAppointments == MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached for today. Try again tomorrow.\n");
        return;
    }

    // Get details from user
    char patientName[50];
    int time;
    printf("Enter patient name: ");
    scanf("%s", patientName);
    printf("Enter time of appointment (in 24-hour format): ");
    scanf("%d", &time);

    // Check if time slot is available
    if (!isTimeSlotAvailable(appointments, *numOfAppointments, time)) {
        printf("Appointment time not available. Please choose a different time.\n");
        return;
    }

    // Create the appointment and add to the array
    struct Appointment appointment;
    strcpy(appointment.patientName, patientName);
    appointment.time = time;
    appointments[*numOfAppointments] = appointment;
    (*numOfAppointments)++;
    printf("Appointment Scheduled Successfully.\n");
}

// Check if time slot is available
bool isTimeSlotAvailable(struct Appointment appointments[], int numOfAppointments, int time) {
    // Check if appointment already exists at the given time
    for (int i = 0; i < numOfAppointments; i++) {
        if (appointments[i].time == time) {
            return false;
        }
    }

    // Check if time is within working hours (10:00 AM to 5:00 PM)
    if (time < 1000 || time > 1700) {
        return false;
    }

    return true;
}

// Display all appointments
void displayAppointments(struct Appointment appointments[], int numOfAppointments) {
    if (numOfAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nAppointments for Today:\n");
    for (int i = 0; i < numOfAppointments; i++) {
        printf("%d: %s at %d\n", i+1, appointments[i].patientName, appointments[i].time);
    }
}