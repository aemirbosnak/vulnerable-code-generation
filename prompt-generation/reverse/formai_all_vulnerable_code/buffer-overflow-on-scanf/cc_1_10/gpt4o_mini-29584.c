//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DESCRIPTION_SIZE 100

typedef struct {
    char description[DESCRIPTION_SIZE];
    char date[11]; // YYYY-MM-DD
    char time[6];  // HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot add more appointments.\n");
        return;
    }
    
    Appointment new_appointment;
    
    printf("Enter appointment description: ");
    fgets(new_appointment.description, DESCRIPTION_SIZE, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline character
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // Remove newline character
    
    printf("Enter appointment time (HH:MM): ");
    fgets(new_appointment.time, sizeof(new_appointment.time), stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = 0; // Remove newline character
    
    appointments[appointment_count] = new_appointment;
    appointment_count++;
    
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nList of Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("-------------------------\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int index;
    view_appointments();
    printf("Enter appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // consume leftover newline
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }
    
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift left
    }
    
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void display_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // consume leftover newline

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
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}