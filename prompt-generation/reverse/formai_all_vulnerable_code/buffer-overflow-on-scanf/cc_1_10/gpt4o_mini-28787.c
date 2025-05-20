//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct Appointment {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    struct tm dateTime; // Holds the date and time information
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void displayMenu() {
    printf("\n===============================\n");
    printf("  Welcome to the Appointment Scheduler\n");
    printf("===============================\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("===============================\n");
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached!\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter name for the appointment: ");
    scanf(" %[^\n]%*c", newAppointment.name); // Read a string with spaces
    printf("Enter description: ");
    scanf(" %[^\n]%*c", newAppointment.description); // Read a string with spaces
    
    printf("Enter date (YYYY-MM-DD): ");
    int year, month, day;
    scanf("%d-%d-%d", &year, &month, &day);
    printf("Enter time (HH MM)24-hour format: ");
    int hour, minute;
    scanf("%d %d", &hour, &minute);

    newAppointment.dateTime.tm_year = year - 1900; // Year since 1900
    newAppointment.dateTime.tm_mon = month - 1; // Month is 0-11
    newAppointment.dateTime.tm_mday = day;
    newAppointment.dateTime.tm_hour = hour;
    newAppointment.dateTime.tm_min = minute;
    newAppointment.dateTime.tm_sec = 0;
    newAppointment.dateTime.tm_isdst = -1; // Not considering DST adjustment

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    printf("\n===============================\n");
    printf("  Your Appointments\n");
    printf("===============================\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date and Time: %s", asctime(&appointments[i].dateTime));
        printf("-------------------------------\n");
    }
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int appointmentNumber;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &appointmentNumber);

    if (appointmentNumber < 1 || appointmentNumber > appointmentCount) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = appointmentNumber - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift the appointments
    }
    appointmentCount--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

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
                printf("Thank you for using the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}