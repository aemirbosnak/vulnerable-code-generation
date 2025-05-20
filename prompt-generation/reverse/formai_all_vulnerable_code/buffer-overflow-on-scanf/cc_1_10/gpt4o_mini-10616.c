//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int id;
    char name[50];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment new_appointment;
    new_appointment.id = appointment_count + 1;

    printf("Enter name for appointment: ");
    scanf(" %[^\n]", new_appointment.name);
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]", new_appointment.date);
    
    printf("Enter time (HH:MM): ");
    scanf(" %[^\n]", new_appointment.time);

    appointments[appointment_count] = new_appointment;
    appointment_count++;

    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("ID: %d, Name: %s, Date: %s, Time: %s\n",
               appointments[i].id,
               appointments[i].name,
               appointments[i].date,
               appointments[i].time);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments scheduled to delete.\n");
        return;
    }

    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > appointment_count) {
        printf("Invalid appointment ID!\n");
        return;
    }

    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Appointment deleted successfully!\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Select an option: ");
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
                printf("Exiting the Appointment Scheduler. Have a great day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}