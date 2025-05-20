//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200


typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_menu() {
    printf("=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("============================\n");
    printf("Select an option: ");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached!\n");
        return;
    }

    Appointment new_appointment;
    new_appointment.id = appointment_count + 1;

    printf("Enter appointment title: ");
    getchar(); // clear the newline character from previous input
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(new_appointment.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("Enter date (YYYY-MM-DD): ");
    char date_str[11];
    fgets(date_str, sizeof(date_str), stdin);
    date_str[strcspn(date_str, "\n")] = 0; // Remove newline
    
    printf("Enter time (HH:MM): ");
    char time_str[6];
    fgets(time_str, sizeof(time_str), stdin);
    time_str[strcspn(time_str, "\n")] = 0; // Remove newline

    sscanf(date_str, "%d-%d-%d", &new_appointment.date_time.tm_year, 
           &new_appointment.date_time.tm_mon, &new_appointment.date_time.tm_mday);
    sscanf(time_str, "%d:%d", &new_appointment.date_time.tm_hour, 
           &new_appointment.date_time.tm_min);
    new_appointment.date_time.tm_year -= 1900; // Adjust year
    new_appointment.date_time.tm_mon -= 1; // Adjust month
    new_appointment.date_time.tm_sec = 0;
    new_appointment.date_time.tm_isdst = -1;

    appointments[appointment_count] = new_appointment;
    appointment_count++;

    printf("Appointment added!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments found!\n");
        return;
    }

    printf("=== Appointments ===\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment ap = appointments[i];
        printf("ID: %d\n", ap.id);
        printf("Title: %s\n", ap.title);
        printf("Description: %s\n", ap.description);
        printf("Date & Time: %d-%02d-%02d %02d:%02d\n", 
               ap.date_time.tm_year + 1900, ap.date_time.tm_mon + 1, 
               ap.date_time.tm_mday, ap.date_time.tm_hour, ap.date_time.tm_min);
        printf("====================\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete!\n");
        return;
    }

    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > appointment_count) {
        printf("Invalid ID!\n");
        return;
    }

    // Shift appointments down
    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Appointment deleted!\n");
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
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}