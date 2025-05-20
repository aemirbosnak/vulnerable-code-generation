//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 255

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Maximum appointment limit reached. Can't add more appointments.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter appointment title: ");
    getchar(); // Clear new line character from buffer
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove trailing newline

    printf("Enter appointment description: ");
    fgets(new_appointment.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove trailing newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    char date[11]; // 10 for date and 1 for null terminator
    fgets(date, sizeof(date), stdin);
    new_appointment.date_time.tm_year = atoi(date) - 1900; // Adjust for tm_year
    new_appointment.date_time.tm_mon = atoi(date + 5) - 1; // Month is zero-based
    new_appointment.date_time.tm_mday = atoi(date + 8);
    
    printf("Enter appointment time (HH:MM): ");
    char time[6]; // 5 for time and 1 for null terminator
    fgets(time, sizeof(time), stdin);
    new_appointment.date_time.tm_hour = atoi(time);
    new_appointment.date_time.tm_min = atoi(time + 3);
    new_appointment.date_time.tm_sec = 0; // Default to 0 seconds
    new_appointment.date_time.tm_isdst = -1; // Not handling DST for simplicity

    appointments[appointment_count++] = new_appointment;

    printf("Your appointment has been added successfully!\n");
}

void displayAppointments() {
    if (appointment_count == 0) {
        printf("You have no appointments scheduled. What a clean slate!\n");
        return;
    }

    printf("Here are your scheduled appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment app = appointments[i];
        printf("%d. %s\n", i + 1, app.title);
        printf("   Description: %s\n", app.description);
        printf("   Date: %04d-%02d-%02d Time: %02d:%02d\n",
               app.date_time.tm_year + 1900,
               app.date_time.tm_mon + 1,
               app.date_time.tm_mday,
               app.date_time.tm_hour,
               app.date_time.tm_min);
    }
}

void deleteAppointment() {
    if (appointment_count == 0) {
        printf("You have no appointments to delete. An empty schedule is a delightful thing.\n");
        return;
    }

    displayAppointments();
    printf("Enter the number of the appointment to delete: ");
    int index;
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number. Please try again.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Your appointment has been deleted successfully! Thank you for using our scheduler!\n");
}

int main() {
    int choice;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("This simple program helps you manage your appointments with gratitude in every function.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler. Have a wonderful day!\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}