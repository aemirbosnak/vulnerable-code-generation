//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[DATE_LENGTH];
    int hour; // 0-23 for hours
    int minute; // 0-59 for minutes
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete an Appointment\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Select an option: ");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Limit reached!\n");
        return;
    }
    
    Appointment new_appointment;

    printf("Enter name for the appointment: ");
    scanf(" %[^\n]s", new_appointment.name);
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]s", new_appointment.date);
    
    printf("Enter hour (0-23): ");
    scanf("%d", &new_appointment.hour);
    
    printf("Enter minute (0-59): ");
    scanf("%d", &new_appointment.minute);
    
    appointments[appointment_count] = new_appointment;
    appointment_count++;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s at %02d:%02d\n", 
               i + 1, appointments[i].name, appointments[i].date,
               appointments[i].hour, appointments[i].minute);
    }
    printf("---------------------\n");
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int index;
    view_appointments();
    
    printf("Select the number of the appointment to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid selection. Please try again.\n");
        return;
    }
    
    // Shift appointments down
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice = 0;

    while (choice != 4) {
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
                printf("Exiting the scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}