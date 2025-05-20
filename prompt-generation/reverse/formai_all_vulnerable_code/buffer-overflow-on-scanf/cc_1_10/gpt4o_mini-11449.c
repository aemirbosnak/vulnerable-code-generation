//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 256

typedef struct {
    char description[MAX_DESC_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Unable to add more appointments, limit reached.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter the appointment description: ");
    getchar(); // Consume leftover newline
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("Enter the appointment date (YYYY-MM-DD): ");
    scanf("%10s", new_appointment.date);

    printf("Enter the appointment time (HH:MM): ");
    scanf("%5s", new_appointment.time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully.\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Your appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d: %s on %s at %s\n", i + 1, appointments[i].description, appointments[i].date, appointments[i].time);
    }
}

void deleteAppointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
  
    viewAppointments();
    
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
    } else {
        for (int i = index - 1; i < appointment_count - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        appointment_count--;
        printf("Appointment deleted successfully.\n");
    }
}

void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
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
                printf("Exiting the scheduler. Have a peaceful day ahead!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}