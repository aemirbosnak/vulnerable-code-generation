//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define TITLE_LENGTH 50
#define DESCRIPTION_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char description[DESCRIPTION_LENGTH];
    char date[11]; // YYYY-MM-DD
    int hour;      // 0-23
    int minute;    // 0-59
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clear_screen() {
    // Clear console screen (for Unix-like systems)
    printf("\033[H\033[J");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments, limit reached!\n");
        return;
    }
    Appointment new_appointment;
    printf("Enter appointment title: ");
    fgets(new_appointment.title, TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(new_appointment.description, DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, 11, stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // Remove newline

    printf("Enter appointment time (hour minute): ");
    scanf("%d %d", &new_appointment.hour, &new_appointment.minute);
    getchar(); // Consume the newline character left by scanf

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment #%d\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
        printf("-------------------------\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    int index;
    printf("Enter the appointment number to delete (1-%d): ", appointment_count);
    scanf("%d", &index);
    getchar(); // Consume the newline character

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    // Shift appointments down to remove the selected one
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void display_menu() {
    printf("\n***** Appointment Scheduler *****\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("*********************************\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        clear_screen();
        display_menu();
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
                printf("Exiting scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
        
        printf("Press Enter to continue...\n");
        getchar(); // Wait for user to press Enter
    }

    return 0;
}