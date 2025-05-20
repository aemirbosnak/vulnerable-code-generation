//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DESCRIPTION_LENGTH 100

typedef struct {
    char description[DESCRIPTION_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function prototypes
void add_appointment();
void view_appointments();
void delete_appointment();
void print_menu();

int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

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

void print_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached. Cannot add more.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment description: ");
    fgets(new_appointment.description, DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, 11, stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // Remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(new_appointment.time, 6, stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = 0; // Remove newline

    appointments[appointment_count] = new_appointment;
    appointment_count++;

    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n--- Scheduled Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d: %s on %s at %s\n", 
               i + 1, appointments[i].description, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments scheduled to delete.\n");
        return;
    }

    int index;
    printf("Enter the appointment number to delete (1 to %d): ", appointment_count);
    scanf("%d", &index);
    getchar(); // Consume the newline character
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Shift appointments down to remove the selected one
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Appointment %d has been deleted successfully!\n", index);
}