//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int id;
    char date[11];    // Format: YYYY-MM-DD
    char time[6];     // Format: HH:MM
    char description[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full.\n");
        return;
    }
    
    Appointment new_appointment;
    new_appointment.id = appointment_count + 1;

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", new_appointment.date);
    
    printf("Enter time (HH:MM): ");
    scanf("%5s", new_appointment.time);
    
    printf("Enter description: ");
    getchar(); // Consume newline character left in the buffer
    fgets(new_appointment.description, sizeof(new_appointment.description), stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove trailing newline
    
    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully.\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    printf("ID\tDate       Time   Description\n");
    printf("-------------------------------------\n");
    
    for (int i = 0; i < appointment_count; i++) {
        printf("%d\t%s   %s   %s\n", 
               appointments[i].id, 
               appointments[i].date, 
               appointments[i].time, 
               appointments[i].description);
    }
    printf("\n");
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > appointment_count) {
        printf("Invalid appointment ID.\n");
        return;
    }

    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully.\n");
}

void display_menu() {
    printf("\n--- Appointment Scheduler Menu ---\n");
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
                printf("Exiting the appointment scheduler.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}