//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char date[11]; // format: YYYY-MM-DD
    char time[6];  // format: HH:MM
    char details[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function Prototypes
void show_menu();
void schedule_appointment();
void view_appointments();
void delete_appointment();
void edit_appointment();
void clear_screen();

int main() {
    int choice;
    while (1) {
        clear_screen();
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after scanf

        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                edit_appointment();
                break;
            case 4:
                delete_appointment();
                break;
            case 5:
                printf("Exiting the Appointment Scheduler. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\nPress Enter to continue...");
        getchar(); // Wait for user to press enter
    }
    return 0;
}

void show_menu() {
    printf("=== Appointment Scheduler ===\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Edit Appointment\n");
    printf("4. Delete Appointment\n");
    printf("5. Exit\n");
}

void schedule_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot schedule more appointments. Limit reached.\n");
        return;
    }

    printf("Enter Appointment Name: ");
    fgets(appointments[appointment_count].name, 50, stdin);
    appointments[appointment_count].name[strcspn(appointments[appointment_count].name, "\n")] = 0; // Remove newline

    printf("Enter Appointment Date (YYYY-MM-DD): ");
    fgets(appointments[appointment_count].date, 11, stdin);
    appointments[appointment_count].date[strcspn(appointments[appointment_count].date, "\n")] = 0;

    printf("Enter Appointment Time (HH:MM): ");
    fgets(appointments[appointment_count].time, 6, stdin);
    appointments[appointment_count].time[strcspn(appointments[appointment_count].time, "\n")] = 0;

    printf("Enter Appointment Details: ");
    fgets(appointments[appointment_count].details, 100, stdin);
    appointments[appointment_count].details[strcspn(appointments[appointment_count].details, "\n")] = 0;

    appointment_count++;
    printf("Appointment scheduled successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("=== Your Appointments ===\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
        printf("   Details: %s\n", appointments[i].details);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments scheduled to delete.\n");
        return;
    }

    int index;
    view_appointments();
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // To consume newline character after scanf

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift appointments left
    }

    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void edit_appointment() {
    if (appointment_count == 0) {
        printf("No appointments scheduled to edit.\n");
        return;
    }

    int index;
    view_appointments();
    printf("Enter the appointment number to edit: ");
    scanf("%d", &index);
    getchar(); // To consume newline character after scanf

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    printf("Editing appointment: %s on %s at %s\n", appointments[index - 1].name, appointments[index - 1].date, appointments[index - 1].time);
    printf("Enter new name (leave blank to keep current): ");
    char buffer[50];
    fgets(buffer, 50, stdin);
    if (strlen(buffer) > 1) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        strcpy(appointments[index - 1].name, buffer);
    }

    printf("Enter new date (leave blank to keep current, format YYYY-MM-DD): ");
    fgets(buffer, 11, stdin);
    if (strlen(buffer) > 1) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        strcpy(appointments[index - 1].date, buffer);
    }

    printf("Enter new time (leave blank to keep current, format HH:MM): ");
    fgets(buffer, 6, stdin);
    if (strlen(buffer) > 1) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        strcpy(appointments[index - 1].time, buffer);
    }

    printf("Enter new details (leave blank to keep current): ");
    fgets(buffer, 100, stdin);
    if (strlen(buffer) > 1) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        strcpy(appointments[index - 1].details, buffer);
    }

    printf("Appointment edited successfully!\n");
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}