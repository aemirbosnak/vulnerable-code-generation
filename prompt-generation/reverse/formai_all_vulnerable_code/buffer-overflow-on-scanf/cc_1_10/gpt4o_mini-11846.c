//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 256

typedef struct {
    int id;
    char description[MAX_DESC_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clear_screen() {
    // Clear the console screen
    printf("\033[H\033[J");
}

void display_menu() {
    printf("==== Appointment Scheduler ====\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("Choose an option: ");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full.\n");
        return;
    }

    Appointment new_appointment;
    new_appointment.id = appointment_count + 1; // Assign an ID based on the current count

    printf("Enter Description: ");
    getchar(); // To consume the newline character left by previous input
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    // Input date and time
    printf("Enter Date (YYYY-MM-DD): ");
    char date[11];
    fgets(date, 11, stdin);
    new_appointment.date_time.tm_year = atoi(strncpy(new_appointment.description, date, 4)) - 1900;
    new_appointment.date_time.tm_mon = atoi(date + 5) - 1;
    new_appointment.date_time.tm_mday = atoi(date + 8);
    
    printf("Enter Time (HH:MM): ");
    char time[6];
    fgets(time, 6, stdin);
    new_appointment.date_time.tm_hour = atoi(strncpy(new_appointment.description, time, 2));
    new_appointment.date_time.tm_min = atoi(time + 3);
    new_appointment.date_time.tm_sec = 0;

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("==== Scheduled Appointments ====\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment appointment = appointments[i];
        printf("ID: %d\n", appointment.id);
        printf("Description: %s\n", appointment.description);
        printf("Date: %04d-%02d-%02d\n", appointment.date_time.tm_year + 1900, appointment.date_time.tm_mon + 1, appointment.date_time.tm_mday);
        printf("Time: %02d:%02d\n", appointment.date_time.tm_hour, appointment.date_time.tm_min);
        printf("=========================\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    printf("Enter Appointment ID to delete: ");
    int id;
    scanf("%d", &id);
    
    if (id < 1 || id > appointment_count) {
        printf("Invalid Appointment ID.\n");
        return;
    }
    
    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift appointments to fill the gap
    }
    
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice;
    
    do {
        clear_screen();
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
                printf("Exiting, have a nice day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        
        printf("Press Enter to continue...");
        getchar(); // Wait for user input
        getchar(); // Consume the newline character
    } while (choice != 4);

    return 0;
}