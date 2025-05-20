//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define DATE_FORMAT "%Y-%m-%d %H:%M"

typedef struct {
    char title[100];
    char date_time[20]; // Store date and time in string format
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Maximum appointment limit reached!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment title: ");
    getchar(); // clear buffer
    fgets(new_appointment.title, sizeof(new_appointment.title), stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline

    printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
    fgets(new_appointment.date_time, sizeof(new_appointment.date_time), stdin);
    new_appointment.date_time[strcspn(new_appointment.date_time, "\n")] = 0; // Remove newline

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
        printf("%d: %s at %s\n", i + 1, appointments[i].title, appointments[i].date_time);
    }
}

void delete_appointment() {
    view_appointments();
    if (appointment_count == 0) return;

    int appointment_number;
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &appointment_number);

    if (appointment_number < 1 || appointment_number > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = appointment_number - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift appointments left
    }
    appointment_count--;
    
    printf("Appointment deleted successfully!\n");
}

void display_menu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}