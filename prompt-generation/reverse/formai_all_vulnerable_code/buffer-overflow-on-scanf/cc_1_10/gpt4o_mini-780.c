//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define DATE_LENGTH 11
#define TIME_LENGTH 6
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter name of the person: ");
    scanf(" %[^\n]%*c", new_appointment.name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]%*c", new_appointment.date);
    printf("Enter time (HH:MM, use 24-hour format): ");
    scanf(" %[^\n]%*c", new_appointment.time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s - %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
    printf("\n");
}

void deleteAppointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter the appointment number to delete: ");
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

void clearAppointments() {
    appointment_count = 0;
    printf("All appointments cleared!\n");
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Clear All Appointments\n");
    printf("5. Exit\n");
    printf("----------------------------\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                clearAppointments();
                break;
            case 5:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}