//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    char date[30];
    char time[30];
    char patient_name[50];
    char doctor_name[50];
};

void display_menu() {
    printf("Welcome to the Appointment Scheduler\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
}

void schedule_appointment(struct Appointment *appointments, int *num_appointments) {
    if (*num_appointments >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    struct Appointment new_appointment;

    printf("Enter appointment date: ");
    scanf("%s", new_appointment.date);
    printf("Enter appointment time: ");
    scanf("%s", new_appointment.time);
    printf("Enter patient name: ");
    scanf("%s", new_appointment.patient_name);
    printf("Enter doctor name: ");
    scanf("%s", new_appointment.doctor_name);

    appointments[*num_appointments] = new_appointment;

    (*num_appointments)++;
}

void view_appointments(struct Appointment *appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }

    printf("Date\t\tTime\t\tPatient\t\tDoctor\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].date, appointments[i].time, appointments[i].patient_name, appointments[i].doctor_name);
    }
}

int main() {
    int option;
    int num_appointments = 0;
    struct Appointment appointments[MAX_APPOINTMENTS];

    do {
        display_menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                schedule_appointment(appointments, &num_appointments);
                break;
            case 2:
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                printf("Exiting Appointment Scheduler. Have a nice day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);

    return 0;
}