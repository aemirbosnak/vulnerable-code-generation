//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_DESC_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Sorry! The appointment list is full. Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter the name of the appointment: ");
    fgets(new_appointment.name, MAX_NAME_LENGTH, stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = '\0'; // Remove newline

    printf("Enter the description of the appointment: ");
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = '\0'; // Remove newline

    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = '\0'; // Remove newline

    printf("Enter the time of the appointment (HH:MM): ");
    fgets(new_appointment.time, sizeof(new_appointment.time), stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = '\0'; // Remove newline

    appointments[appointment_count++] = new_appointment;

    printf("Yay! Appointment added successfully.\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("Oops! No appointments scheduled yet!\n");
        return;
    }

    printf("\nYour Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("------------------------------\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("Oh no! No appointments to delete!\n");
        return;
    }

    view_appointments();
    int index;
    printf("Enter the number of the appointment you wish to delete: ");
    scanf("%d", &index);
    getchar(); // Clear newline from input buffer

    if (index < 1 || index > appointment_count) {
        printf("Oops! Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Hooray! Appointment deleted successfully.\n");
}

void menu() {
    int choice;
    do {
        printf("\n=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

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
                printf("Thank you for using the Appointment Scheduler! Have a great day!\n");
                break;
            default:
                printf("Oops! That's not a valid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Happy Appointment Scheduler!\n");
    menu();
    return 0;
}