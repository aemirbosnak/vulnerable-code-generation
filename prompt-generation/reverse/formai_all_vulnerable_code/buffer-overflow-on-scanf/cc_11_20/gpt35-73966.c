//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_APPOINTMENTS 10

struct Appointment {
    char date[11];
    char time[6];
    char patient_name[50];
    char doctor_name[50];
};

int main() {

    struct Appointment appointments[MAX_APPOINTMENTS];
    int appointment_count = 0;

    // Display the main menu
    printf("\n\n==============================\n");
    printf("C Appointment Scheduler Program\n");
    printf("==============================\n\n");

    while (1) {
        printf("1. View Appointments\n");
        printf("2. Add Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit Application\n\n");

        // Get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // View Appointments
            printf("\nView Appointments\n");
            printf("=================\n\n");

            if (appointment_count == 0) {
                printf("No appointments scheduled.\n\n");
            } else {
                for (int i = 0; i < appointment_count; i++) {
                    printf("Date: %s\n", appointments[i].date);
                    printf("Time: %s\n", appointments[i].time);
                    printf("Patient Name: %s\n", appointments[i].patient_name);
                    printf("Doctor Name: %s\n\n", appointments[i].doctor_name);
                }
            }
        } else if (choice == 2) {
            // Add Appointment
            printf("\nAdd Appointment\n");
            printf("===============\n");

            if (appointment_count == MAX_APPOINTMENTS) {
                printf("Maximum number of appointments reached.\n\n");
            } else {
                printf("Enter Appointment Details: \n");

                struct Appointment new_appointment;

                // Get date
                printf("Date (dd/mm/yyyy): ");
                scanf("%s", new_appointment.date);

                // Get time
                printf("Time (hh:mm): ");
                scanf("%s", new_appointment.time);

                // Get patient name
                printf("Patient Name: ");
                scanf("%s", new_appointment.patient_name);

                // Get doctor name
                printf("Doctor Name: ");
                scanf("%s", new_appointment.doctor_name);

                // Add new appointment to array
                appointments[appointment_count++] = new_appointment;

                printf("\nAppointment added successfully.\n\n");
            }
        } else if (choice == 3) {
            // Cancel Appointment
            printf("\nCancel Appointment\n");
            printf("==================\n");

            if (appointment_count == 0) {
                printf("No appointments scheduled.\n\n");
            } else {
                // Get date and time of the appointment to cancel
                char date[11], time[6];
                printf("Enter the date of the appointment to cancel (dd/mm/yyyy): ");
                scanf("%s", date);
                printf("Enter the time of the appointment to cancel (hh:mm): ");
                scanf("%s", time);

                // Find the appointment in the array
                int appointment_index = -1;
                for (int i = 0; i < appointment_count; i++) {
                    if (strcmp(date, appointments[i].date) == 0 && strcmp(time, appointments[i].time) == 0) {
                        appointment_index = i;
                        break;
                    }
                }

                // Remove the appointment from the array
                if (appointment_index != -1) {
                    for (int i = appointment_index; i < appointment_count-1; i++) {
                        appointments[i] = appointments[i+1];
                    }
                    appointment_count--;
                    printf("\nAppointment cancelled successfully.\n\n");
                } else {
                    printf("\nAppointment not found.\n\n");
                }
            }
        } else if (choice == 4) {
            // Exit Application
            printf("\nExiting...\n\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}