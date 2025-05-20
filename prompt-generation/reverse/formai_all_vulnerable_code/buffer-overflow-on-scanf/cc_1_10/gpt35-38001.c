//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    char date[20];
    char time[20];
    char patient_name[50];
    char doctor_name[50];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS]; // declare an array to hold the appointments
int num_appointments = 0; // initialize the number of appointments to 0

// function to add a new appointment
void add_appointment() {
    if (num_appointments < MAX_APPOINTMENTS) {
        Appointment new_appointment;
        printf("Enter the date of the appointment (MM/DD/YYYY): ");
        scanf("%s", new_appointment.date);
        printf("Enter the time of the appointment (HH:MM AM/PM): ");
        scanf("%s", new_appointment.time);
        printf("Enter the name of the patient: ");
        scanf("%s", new_appointment.patient_name);
        printf("Enter the name of the doctor: ");
        scanf("%s", new_appointment.doctor_name);
        appointments[num_appointments] = new_appointment;
        num_appointments++;
        printf("Appointment added!\n");
    } else {
        printf("Sorry, the maximum number of appointments has been reached.\n");
    }
}

// function to print all appointments
void print_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
    } else {
        printf("Scheduled Appointments:\n");
        printf("Date\t\tTime\t\tDoctor\t\tPatient\n");
        for (int i = 0; i < num_appointments; i++) {
            Appointment appointment = appointments[i];
            printf("%s\t%s\t%s\t%s\n", appointment.date, appointment.time, appointment.doctor_name, appointment.patient_name);
        }
    }
}

int main() {
    int choice;
    bool running = true;
    while (running) {
        // print menu
        printf("\nAppointment Scheduler Menu\n");
        printf("--------------------\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");

        // get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // handle user choice
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                running = false;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}