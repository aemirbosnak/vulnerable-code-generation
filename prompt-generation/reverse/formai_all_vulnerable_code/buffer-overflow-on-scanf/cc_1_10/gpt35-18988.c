//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_APPOINTMENTS 10

struct appointment {
    char date[11];
    char time[6];
    char name[50];
};

struct appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void display_menu() {
    printf("\nAppointment Scheduler\n"
           "1. Add Appointment\n"
           "2. View Appointments\n"
           "3. Exit\n"
           "Enter your choice: ");
}

void add_appointment() {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Appointment list is full.\n");
        return;
    }

    struct appointment new_appointment;

    printf("Enter the date (mm/dd/yyyy): ");
    scanf("%s", new_appointment.date);

    printf("Enter the time (hh:mm): ");
    scanf("%s", new_appointment.time);

    printf("Enter the name of the person: ");
    scanf("%s", new_appointment.name);

    appointments[num_appointments++] = new_appointment;

    printf("\nAppointment added successfully.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments.\n");
        return;
    }

    printf("\nAppointments:\n");
    printf("Date\t\tTime\tName\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].date, appointments[i].time, appointments[i].name);
    }
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}