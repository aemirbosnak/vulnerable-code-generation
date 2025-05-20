//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 20 // maximum number of appointments that can be scheduled in a single day

// structure to hold details of an appointment
typedef struct {
    int hour;
    int minute;
    char description[100];
} Appointment;

// function to add a new appointment
void addAppointment(Appointment *appointments, int *appointmentIndex) {
    if (*appointmentIndex == MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached for today.\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter hour (24-hour format): ");
    scanf("%d", &newAppointment.hour);
    if (newAppointment.hour < 0 || newAppointment.hour > 23) {
        printf("Invalid hour. Please enter a value between 0 and 23.\n");
        return;
    }

    printf("Enter minute: ");
    scanf("%d", &newAppointment.minute);
    if (newAppointment.minute < 0 || newAppointment.minute > 59) {
        printf("Invalid minute. Please enter a value between 0 and 59.\n");
        return;
    }

    printf("Enter appointment description: ");
    scanf(" %[^\n]s", newAppointment.description);
    strcpy(appointments[*appointmentIndex].description, newAppointment.description);
    appointments[*appointmentIndex].hour = newAppointment.hour;
    appointments[*appointmentIndex].minute = newAppointment.minute;
    (*appointmentIndex)++;
    printf("Appointment added successfully.\n");
}

// function to display all scheduled appointments
void displayAppointments(Appointment *appointments, int appointmentIndex) {
    printf("Scheduled Appointments:\n");
    printf("Time                Description\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < appointmentIndex; i++) {
        printf("%02d:%02d              %s\n", appointments[i].hour, appointments[i].minute, appointments[i].description);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointmentIndex = 0;
    int choice;

    while (1) {
        printf("\n1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &appointmentIndex);
                break;
            case 2:
                displayAppointments(appointments, appointmentIndex);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}