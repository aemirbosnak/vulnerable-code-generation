//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 256

typedef struct {
    char description[MAX_DESC_LENGTH];
    char date[11];  // Format: YYYY-MM-DD
    char time[6];   // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment();
void view_appointments();
void delete_appointment();
void display_menu();

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
                printf("Exiting the Appointment Scheduler. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void display_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Unable to add appointment. Appointment limit reached.\n");
        return;
    }
    
    Appointment new_appointment;
    printf("Enter appointment description: ");
    getchar();  // To consume newline character left in the buffer
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = '\0'; // Remove newline
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", new_appointment.time);
    
    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\n--- Your Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s at %s\n", 
            i + 1, 
            appointments[i].description, 
            appointments[i].date, 
            appointments[i].time);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the number of the appointment to delete (1 to %d): ", appointment_count);
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}