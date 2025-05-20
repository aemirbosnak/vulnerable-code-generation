//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DESCRIPTION_LENGTH 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    char date[11];  // Format: YYYY-MM-DD
    int hour;       // 0 - 23
    int minute;     // 0 - 59
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Max limit reached.\n");
        return;
    }

    Appointment new_appointment;
    
    printf("Enter your name: ");
    fgets(new_appointment.name, NAME_LENGTH, stdin);
    strtok(new_appointment.name, "\n"); // Remove trailing newline
    
    printf("Enter appointment description: ");
    fgets(new_appointment.description, DESCRIPTION_LENGTH, stdin);
    strtok(new_appointment.description, "\n"); // Remove trailing newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, 11, stdin);
    strtok(new_appointment.date, "\n"); // Remove trailing newline

    printf("Enter appointment time (HH:MM): ");
    scanf("%d:%d", &new_appointment.hour, &new_appointment.minute);
    getchar(); // Clear newline character from input buffer

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s - %s on %s at %02d:%02d\n", 
            i + 1, appointments[i].name, appointments[i].description, 
            appointments[i].date, appointments[i].hour, appointments[i].minute);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    view_appointments();
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // Clear newline character from input buffer

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

void display_menu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

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
                printf("Exiting the scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}