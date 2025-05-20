//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 50
#define TITLE_SIZE 30
#define DATE_SIZE 15

typedef struct {
    char title[TITLE_SIZE];
    char date[DATE_SIZE];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function to display the main menu
void display_menu() {
    printf("\n*** Appointment Scheduler ***\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

// Function to add an appointment
void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full! Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment title: ");
    scanf(" %[^\n]s", new_appointment.title);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]s", new_appointment.date);

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    printf("Appointment added successfully!\n");
}

// Function to view all appointments
void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("\n*** Your Appointments ***\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s\n", i + 1, appointments[i].title, appointments[i].date);
    }
}

// Function to delete an appointment
void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete!\n");
        return;
    }

    int index;
    printf("Select appointment number to delete (1-%d): ", appointment_count);
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        display_menu();
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
                printf("Exiting. See you next time!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}