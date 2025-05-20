//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    char date[11]; // format: YYYY-MM-DD
    char time[6];  // format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_menu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Select an option: ");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Unable to add more appointments.\n");
        return;
    }

    Appointment new_appointment;
    
    printf("Enter appointment description: ");
    getchar(); // consume newline
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    strtok(new_appointment.description, "\n"); // remove trailing newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    strtok(new_appointment.date, "\n"); // remove trailing newline

    printf("Enter appointment time (HH:MM): ");
    fgets(new_appointment.time, sizeof(new_appointment.time), stdin);
    strtok(new_appointment.time, "\n"); // remove trailing newline

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n=== Scheduled Appointments ===\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. [%s] at %s - %s\n", i + 1, appointments[i].date, appointments[i].time, appointments[i].description);
    }
    printf("==============================\n");
}

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

    // Shift appointments to the left
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}