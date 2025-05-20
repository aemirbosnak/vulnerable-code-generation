//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define MAX_DATE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[6]; // Format "HH:MM"
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void schedule_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot schedule more appointments.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter name for appointment: ");
    scanf(" %[^\n]", new_appointment.name);

    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]", new_appointment.date);

    printf("Enter time (HH:MM): ");
    scanf(" %[^\n]", new_appointment.time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment scheduled for %s on %s at %s.\n", new_appointment.name, new_appointment.date, new_appointment.time);
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d: %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void cancel_appointment() {
    int index;
    
    printf("Enter appointment number to cancel: ");
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment %d has been canceled.\n", index);
}

void display_menu() {
    printf("Appointment Scheduler\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}