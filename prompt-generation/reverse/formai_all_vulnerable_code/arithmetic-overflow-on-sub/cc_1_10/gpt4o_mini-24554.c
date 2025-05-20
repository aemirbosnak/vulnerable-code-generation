//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 256

typedef struct {
    char description[MAX_DESC_LENGTH];
    time_t dateTime;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached! Cannot add more appointments.\n");
        return;
    }

    Appointment newAppointment;
    char timeString[100];

    printf("Enter appointment description: ");
    getchar();  // Consume newline
    fgets(newAppointment.description, MAX_DESC_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0;  // Remove trailing newline

    printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
    struct tm tm;
    scanf("%4d-%2d-%2d %2d:%2d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min);
    
    tm.tm_year -= 1900;  // Adjust year
    tm.tm_mon -= 1;      // Adjust month (0-11)
    tm.tm_sec = 0;
    newAppointment.dateTime = mktime(&tm);

    if (newAppointment.dateTime == -1) {
        printf("Invalid date and time input!\n");
        return;
    }

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added for %s\n", ctime(&newAppointment.dateTime));
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("Upcoming Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d: %s at %s", i + 1, appointments[i].description, ctime(&appointments[i].dateTime));
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    viewAppointments();
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully.\n");
}

void displayMenu() {
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Select an option: ");
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
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}