//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm start_time;
    struct tm end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void print_welcome_message() {
    printf("\n*****************************************\n");
    printf("*       Welcome to the Appointment      *\n");
    printf("*              Scheduler!               *\n");
    printf("*****************************************\n\n");
}

void print_menu() {
    printf("Select an option:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Your choice: ");
}

void add_appointment() {
    if (appointment_count < MAX_APPOINTMENTS) {
        Appointment new_appt;
        printf("Enter the name for the appointment: ");
        fgets(new_appt.name, MAX_NAME_LENGTH, stdin);
        new_appt.name[strcspn(new_appt.name, "\n")] = 0; // Remove trailing newline
        
        printf("Enter a description: ");
        fgets(new_appt.description, MAX_DESCRIPTION_LENGTH, stdin);
        new_appt.description[strcspn(new_appt.description, "\n")] = 0; // Remove trailing newline
        
        printf("Enter start time (YYYY-MM-DD HH:MM): ");
        char start_time[20], end_time[20];
        fgets(start_time, 20, stdin);
        
        strptime(start_time, "%Y-%m-%d %H:%M", &new_appt.start_time);

        printf("Enter end time (YYYY-MM-DD HH:MM): ");
        fgets(end_time, 20, stdin);
        strptime(end_time, "%Y-%m-%d %H:%M", &new_appt.end_time);

        appointments[appointment_count++] = new_appt;
        printf("Appointment added successfully!\n");
    } else {
        printf("Cannot add more appointments, limit reached!\n");
    }
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; ++i) {
        Appointment a = appointments[i];
        printf("Appointment #%d:\n", i + 1);
        printf("Name: %s\n", a.name);
        printf("Description: %s\n", a.description);
        printf("Start Time: %s", asctime(&a.start_time));
        printf("End Time: %s\n", asctime(&a.end_time));
        printf("=======================================\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    view_appointments();
    printf("Select appointment number to delete (1 to %d): ", appointment_count);
    int index;
    scanf("%d", &index);
    getchar(); // Consume newline after integer input

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
    } else {
        for (int i = index - 1; i < appointment_count - 1; ++i) {
            appointments[i] = appointments[i + 1]; // Shift appointments left
        }
        appointment_count--;
        printf("Appointment deleted successfully!\n");
    }
}

int main() {
    print_welcome_message();
    
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline after integer input
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
                printf("Thank you for using the Appointment Scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}