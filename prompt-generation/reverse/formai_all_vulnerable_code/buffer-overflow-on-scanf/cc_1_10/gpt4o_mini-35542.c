//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100

struct Appointment {
    char description[MAX_DESC_LENGTH];
    time_t timestamp;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void print_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
    printf("Choose an option: ");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached!\n");
        return;
    }
    
    struct Appointment new_appointment;
    printf("Enter appointment description: ");
    scanf(" %[^\n]s", new_appointment.description);
    printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
    
    struct tm timeinfo;
    char date_input[20];
    scanf(" %[^\n]s", date_input);
    
    strptime(date_input, "%Y-%m-%d %H:%M", &timeinfo);
    new_appointment.timestamp = mktime(&timeinfo);

    if (new_appointment.timestamp == -1) {
        printf("Invalid date/time format!\n");
        return;
    }

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        char time_buf[26];
        struct tm *tm_info;

        tm_info = localtime(&appointments[i].timestamp);
        strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M", tm_info);
        printf("%d: %s at %s\n", i + 1, appointments[i].description, time_buf);
    }
    printf("--------------------\n");
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    view_appointments();
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice;
    
    while (1) {
        print_menu();
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}