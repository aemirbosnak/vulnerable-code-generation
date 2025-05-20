//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_STRING_LENGTH 50

typedef struct {
    char title[MAX_STRING_LENGTH];
    char description[MAX_STRING_LENGTH];
    struct tm date; // using struct tm for date representation
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment newAppointment;

    printf("Enter appointment title: ");
    fgets(newAppointment.title, MAX_STRING_LENGTH, stdin);
    newAppointment.title[strcspn(newAppointment.title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(newAppointment.description, MAX_STRING_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0;

    printf("Enter appointment date (YYYY MM DD HH MM): ");
    scanf("%d %d %d %d %d", &newAppointment.date.tm_year, &newAppointment.date.tm_mon, &newAppointment.date.tm_mday, &newAppointment.date.tm_hour, &newAppointment.date.tm_min);
    newAppointment.date.tm_year -= 1900; // Year is years since 1900
    newAppointment.date.tm_mon -= 1; // Month is 0-11

    // Save the current time for comparison later
    newAppointment.date.tm_sec = 0;
    mktime(&newAppointment.date); // Normalize the struct tm

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added successfully!\n");

    // Clear the input buffer
    while (getchar() != '\n');
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
    } else {
        printf("Appointments scheduled:\n");
        for (int i = 0; i < appointmentCount; ++i) {
            printf("%d. %s - %s on %04d-%02d-%02d %02d:%02d\n",
                i + 1,
                appointments[i].title,
                appointments[i].description,
                appointments[i].date.tm_year + 1900,
                appointments[i].date.tm_mon + 1,
                appointments[i].date.tm_mday,
                appointments[i].date.tm_hour,
                appointments[i].date.tm_min);
        }
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    viewAppointments();
    int index;
    printf("Enter appointment number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; ++i) {
        appointments[i] = appointments[i + 1]; // Shift appointments left
    }
    appointmentCount--;
    printf("Appointment deleted successfully!\n");
}

void menu() {
    int choice;
    do {
        printf("\n=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Clear the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Exiting the scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}