//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached!\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter appointment title: ");
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = '\0'; // Remove newline

    printf("Enter appointment description: ");
    fgets(new_appointment.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = '\0'; // Remove newline

    printf("Enter appointment date (yyyy-mm-dd): ");
    char date[11];
    fgets(date, 11, stdin);
    
    printf("Enter appointment time (HH:MM): ");
    char time[6];
    fgets(time, 6, stdin);

    // Parse date and time
    sscanf(date, "%d-%d-%d", &new_appointment.date_time.tm_year, &new_appointment.date_time.tm_mon, &new_appointment.date_time.tm_mday);
    sscanf(time, "%d:%d", &new_appointment.date_time.tm_hour, &new_appointment.date_time.tm_min);

    new_appointment.date_time.tm_year -= 1900; // Year since 1900
    new_appointment.date_time.tm_mon -= 1;      // Month from 0 to 11
    new_appointment.date_time.tm_sec = 0;
    new_appointment.date_time.tm_isdst = -1;    // Determine if DST is in effect

    appointments[appointment_count] = new_appointment; 
    appointment_count++;

    printf("Appointment added successfully.\n");
}

void list_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment appt = appointments[i];
        char date_buf[30], time_buf[10];
        strftime(date_buf, sizeof(date_buf), "%Y-%m-%d", &appt.date_time);
        strftime(time_buf, sizeof(time_buf), "%H:%M", &appt.date_time);
        printf("%d. %s - %s on %s at %s\n", i + 1, appt.title, appt.description, date_buf, time_buf);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    list_appointments();

    int index;
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &index);
    clear_input_buffer();

    if (index < 1 || index > appointment_count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    appointment_count--;
    printf("Appointment deleted successfully.\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Exiting the scheduler.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}