//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment();
void view_appointments();
void delete_appointment();
void display_menu();
void clear_input_buffer();

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer(); // Clear the newline character from input buffer

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
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Unable to add more appointments.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter Name: ");
    fgets(new_appointment.name, MAX_NAME_LENGTH, stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = 0; // Remove newline

    printf("Enter Description: ");
    fgets(new_appointment.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("Enter Date (YYYY-MM-DD): ");
    fgets(new_appointment.date, 11, stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // Remove newline

    printf("Enter Time (HH:MM): ");
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

    printf("\n=== Scheduled Appointments ===\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n\n", appointments[i].time);
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
    clear_input_buffer(); // Clear the newline character from input buffer

    if (index < 1 || index > appointment_count) {
        printf("Invalid number. Please try again.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment %d deleted successfully!\n", index);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
}