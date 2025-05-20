//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define TITLE_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char description[DESC_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    
    Appointment new_appointment;
    
    printf("Enter appointment title: ");
    getchar();  // To consume the newline character
    fgets(new_appointment.title, TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline

    printf("Enter a description: ");
    fgets(new_appointment.description, DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline
    
    printf("Enter date (YYYY-MM-DD): ");
    fgets(new_appointment.date, 11, stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // Remove newline

    printf("Enter time (HH:MM): ");
    fgets(new_appointment.time, 6, stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = 0; // Remove newline

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
        printf("Appointment %d:\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("-------------------------------\n");
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
        printf("Invalid appointment number!\n");
    } else {
        for (int i = index - 1; i < appointment_count - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        appointment_count--;
        printf("Appointment deleted successfully!\n");
    }
}

void displayMenu() {
    printf("\n===============================\n");
    printf("  Appointment Scheduler  \n");
    printf("===============================\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("===============================\n");
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
                printf("Thank you for using the Appointment Scheduler! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}