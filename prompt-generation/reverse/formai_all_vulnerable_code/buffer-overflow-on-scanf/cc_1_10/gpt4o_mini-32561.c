//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESC_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    struct tm time; // Time structure for appointment time
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment();
void view_appointments();
void delete_appointment();
void edit_appointment();
void display_menu();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        clear_buffer();

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
                edit_appointment();
                break;
            case 5: 
                printf("Exiting the Appointment Scheduler... Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n==============================\n");
    printf("     Appointment Scheduler     \n");
    printf("==============================\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Edit Appointment\n");
    printf("5. Exit\n");
}

void clear_buffer() {
    while (getchar() != '\n');
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment title: ");
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    char date[11];
    fgets(date, sizeof(date), stdin);
    strptime(date, "%Y-%m-%d", &new_appointment.time);

    printf("Enter appointment time (HH:MM) in 24-hour format: ");
    char time[6]; // HH:MM
    fgets(time, sizeof(time), stdin);
    sscanf(time, "%d:%d", &new_appointment.time.tm_hour, &new_appointment.time.tm_min);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments available.\n");
        return;
    }

    printf("\nYour Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment #%d:\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Description: %s\n", appointments[i].description);
        
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &appointments[i].time);
        printf("Date & Time: %s\n", buffer);
        printf("==============================\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    printf("Enter the appointment number to delete (1-%d): ", appointment_count);
    int appointment_no;
    scanf("%d", &appointment_no);
    clear_buffer();

    if (appointment_no < 1 || appointment_no > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = appointment_no - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift appointments
    }

    appointment_count--;
    printf("Appointment #%d deleted successfully!\n", appointment_no);
}

void edit_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to edit.\n");
        return;
    }

    printf("Enter the appointment number to edit (1-%d): ", appointment_count);
    int appointment_no;
    scanf("%d", &appointment_no);
    clear_buffer();

    if (appointment_no < 1 || appointment_no > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    Appointment *appt = &appointments[appointment_no - 1];

    printf("Editing appointment #%d\n", appointment_no);
    printf("Current Title: %s\n", appt->title);
    printf("Enter new title (leave blank to keep unchanged): ");
    char title_input[MAX_TITLE_LENGTH];
    fgets(title_input, MAX_TITLE_LENGTH, stdin);
    if (strlen(title_input) > 1) {
        title_input[strcspn(title_input, "\n")] = 0; // Strip newline
        strcpy(appt->title, title_input);
    }

    printf("Current Description: %s\n", appt->description);
    printf("Enter new description (leave blank to keep unchanged): ");
    char desc_input[MAX_DESC_LENGTH];
    fgets(desc_input, MAX_DESC_LENGTH, stdin);
    if (strlen(desc_input) > 1) {
        desc_input[strcspn(desc_input, "\n")] = 0; // Strip newline
        strcpy(appt->description, desc_input);
    }

    printf("Current Date: %04d-%02d-%02d\n", appt->time.tm_year + 1900, appt->time.tm_mon + 1, appt->time.tm_mday);
    printf("Enter new date (YYYY-MM-DD, leave blank to keep unchanged): ");
    char date_input[11];
    fgets(date_input, sizeof(date_input), stdin);
    if (strlen(date_input) > 1) {
        strptime(date_input, "%Y-%m-%d", &appt->time);
    }

    printf("Current Time: %02d:%02d\n", appt->time.tm_hour, appt->time.tm_min);
    printf("Enter new time (HH:MM, leave blank to keep unchanged): ");
    char time_input[6]; // HH:MM
    fgets(time_input, sizeof(time_input), stdin);
    if (strlen(time_input) > 1) {
        sscanf(time_input, "%d:%d", &appt->time.tm_hour, &appt->time.tm_min);
    }

    printf("Appointment updated successfully!\n");
}