//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DESC_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Helper function to display the menu
void display_menu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Choose an option: ");
}

// Function to add an appointment
void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Limit reached.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter title: ");
    getchar();  // consume newline
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // remove newline

    printf("Enter description: ");
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // remove newline

    printf("Enter date (YYYY-MM-DD): ");
    char date[11];
    fgets(date, 11, stdin);
    date[strcspn(date, "\n")] = 0; // remove newline

    printf("Enter time (HH:MM): ");
    char time[6];
    fgets(time, 6, stdin);
    time[strcspn(time, "\n")] = 0; // remove newline

    // Populate the date_time structure
    strptime(date, "%Y-%m-%d", &new_appointment.date_time);
    strptime(time, "%H:%M", &new_appointment.date_time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

// Function to view appointments
void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments available.\n");
        return;
    }

    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s\n", i + 1, appointments[i].title);
        printf("   Description: %s\n", appointments[i].description);
        printf("   Date & Time: %s", asctime(&appointments[i].date_time));
    }
}

// Function to delete an appointment
void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter appointment number to delete (1-%d): ", appointment_count);
    scanf("%d", &index);
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Shift appointments to delete the selected one
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
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
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}