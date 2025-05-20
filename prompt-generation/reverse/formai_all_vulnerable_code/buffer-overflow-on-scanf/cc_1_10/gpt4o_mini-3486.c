//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter the name for the appointment: ");
    scanf(" %[^\n]s", new_appointment.name);
    printf("Enter the description for the appointment: ");
    scanf(" %[^\n]s", new_appointment.description);
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    char date[11];
    scanf(" %s", date);
    printf("Enter appointment time (HH:MM): ");
    char time[6];
    scanf(" %s", time);

    strptime(date, "%Y-%m-%d", &new_appointment.date_time);
    strptime(time, "%H:%M", &new_appointment.date_time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("\nAppointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        char date_time_string[100];
        strftime(date_time_string, sizeof(date_time_string), "%Y-%m-%d %H:%M", &appointments[i].date_time);
        printf("Appointment %d:\n", i + 1);
        printf("  Name: %s\n", appointments[i].name);
        printf("  Description: %s\n", appointments[i].description);
        printf("  Date & Time: %s\n\n", date_time_string);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    printf("\nEnter the appointment number to delete (1 to %d): ", appointment_count);
    int index;
    scanf("%d", &index);
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void menu() {
    int choice;
    do {
        printf("\nAppointment Scheduler Menu:\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    menu();
    return 0;
}