//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    time_t date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_menu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("============================\n");
    printf("Choose an option: ");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment description: ");
    getchar(); // clear the newline from previous input
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // remove newline

    printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
    struct tm tm = {0};
    char date_time_input[20];
    fgets(date_time_input, sizeof(date_time_input), stdin);
    strptime(date_time_input, "%Y-%m-%d %H:%M", &tm);
    new_appointment.date_time = mktime(&tm);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\n=== Scheduled Appointments ===\n");
    for (int i = 0; i < appointment_count; i++) {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", localtime(&appointments[i].date_time));
        printf("%d. %s at %s\n", i + 1, appointments[i].description, buffer);
    }
    printf("==============================\n");
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    view_appointments(); // Show existing appointments
    int index;
    printf("Enter appointment number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Delete the appointment
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice;
    while (1) {
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
                printf("Exiting the scheduler...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
    
    return 0;
}