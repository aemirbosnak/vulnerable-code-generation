//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int day; // 1-31
    int month; // 1-12
    int year; 
    int hour; // 0-23
    int minute; // 0-59
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Error: Maximum appointments reached.\n");
        return;
    }
    
    Appointment new_appointment;
    printf("Enter appointment title: ");
    getchar(); // To consume leftover newline
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(new_appointment.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0;

    printf("Enter appointment date (day month year): ");
    scanf("%d %d %d", &new_appointment.day, &new_appointment.month, &new_appointment.year);

    printf("Enter appointment time (hour minute): ");
    scanf("%d %d", &new_appointment.hour, &new_appointment.minute);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment a = appointments[i];
        printf("%d. %s\nDescription: %s\nDate: %02d/%02d/%d\nTime: %02d:%02d\n\n", 
                i + 1, a.title, a.description, a.day, a.month, a.year, a.hour, a.minute);
    }
}

void deleteAppointment() {
    int index;
    viewAppointments();
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

void menu() {
    int choice;
    do {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
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
                printf("Exiting the scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}