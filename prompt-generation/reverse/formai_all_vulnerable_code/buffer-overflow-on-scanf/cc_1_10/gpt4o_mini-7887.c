//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESCRIPTION 256

typedef struct {
    char description[MAX_DESCRIPTION];
    char date[11];  // Format: YYYY-MM-DD
    char time[6];   // Format: HH:MM
} Appointment;

Appointment *appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum limit reached.\n");
        return;
    }
    
    Appointment *new_appointment = (Appointment *)malloc(sizeof(Appointment));
    if (!new_appointment) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter appointment description: ");
    getchar();  // Clear newline character from buffer
    fgets(new_appointment->description, MAX_DESCRIPTION, stdin);
    strcspn(new_appointment->description, "\n"); // Remove newline
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%10s", new_appointment->date);
    
    printf("Enter appointment time (HH:MM): ");
    scanf("%5s", new_appointment->time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment *appt = appointments[i];
        printf("%d: %s on %s at %s\n", i + 1, appt->description, appt->date, appt->time);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments scheduled to delete.\n");
        return;
    }

    view_appointments();
    int index;
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    free(appointments[index - 1]); // Free the memory
    for (int i = index - 1; i < appointment_count - 1; i++) {
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
}

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
                printf("Exiting the program. Goodbye!\n");
                // Free all allocated memory
                for (int i = 0; i < appointment_count; i++) {
                    free(appointments[i]);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}