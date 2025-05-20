//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold appointment information
typedef struct {
    char patientName[50];
    char doctorName[50];
    char appointmentDate[10];
    char appointmentTime[10];
} Appointment;

// Function prototype for scheduling an appointment
void scheduleAppointment(Appointment* appointment);

// Function prototype for cancelling an appointment
void cancelAppointment(Appointment* appointment);

int main() {
    int option;
    Appointment appointment = {"", "", "", ""};

    // Display menu options and get user input
    do {
        printf("\nAppointment Scheduler Menu\n");
        printf("1. Schedule an appointment\n");
        printf("2. Cancel an appointment\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                scheduleAppointment(&appointment);
                printf("\nAppointment scheduled successfully!\n");
                printf("Patient Name: %s\n", appointment.patientName);
                printf("Doctor Name: %s\n", appointment.doctorName);
                printf("Appointment Date: %s\n", appointment.appointmentDate);
                printf("Appointment Time: %s\n", appointment.appointmentTime);
                break;
            }
            case 2: {
                cancelAppointment(&appointment);
                printf("\nAppointment cancelled successfully!\n");
                printf("Patient Name: %s\n", appointment.patientName);
                printf("Doctor Name: %s\n", appointment.doctorName);
                printf("Appointment Date: %s\n", appointment.appointmentDate);
                printf("Appointment Time: %s\n", appointment.appointmentTime);
                break;
            }
            case 3: {
                printf("\nExiting Appointment Scheduler...\n");
                break;
            }
            default: {
                printf("\nInvalid option, please try again.\n");
                break;
            }
        }
    } while (option != 3);

    return 0;
}

void scheduleAppointment(Appointment* appointment) {
    // Get appointment details from user input
    printf("\nEnter patient name: ");
    fflush(stdin);
    fgets(appointment->patientName, 50, stdin);
    printf("Enter doctor name: ");
    fflush(stdin);
    fgets(appointment->doctorName, 50, stdin);
    printf("Enter appointment date (MM/DD/YYYY): ");
    fflush(stdin);
    fgets(appointment->appointmentDate, 10, stdin);
    printf("Enter appointment time (HH:MM AM/PM): ");
    fflush(stdin);
    fgets(appointment->appointmentTime, 10, stdin);
}

void cancelAppointment(Appointment* appointment) {
    // Clear appointment details
    memset(appointment->patientName, '\0', sizeof(appointment->patientName));
    memset(appointment->doctorName, '\0', sizeof(appointment->doctorName));
    memset(appointment->appointmentDate, '\0', sizeof(appointment->appointmentDate));
    memset(appointment->appointmentTime, '\0', sizeof(appointment->appointmentTime));
}