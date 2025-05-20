//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void displayMenu() {
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Maximum appointment limit reached!\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter subject: ");
    getchar(); // clear newline from previous input
    fgets(newAppointment.subject, MAX_SUBJECT_LENGTH, stdin);
    strtok(newAppointment.subject, "\n"); // remove newline character

    printf("Enter description: ");
    fgets(newAppointment.description, MAX_DESCRIPTION_LENGTH, stdin);
    strtok(newAppointment.description, "\n"); // remove newline character

    printf("Enter date (YYYY-MM-DD): ");
    int year, month, day;
    scanf("%d-%d-%d", &year, &month, &day);
    
    printf("Enter time (HH:MM in 24-hour format): ");
    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    newAppointment.date_time.tm_year = year - 1900; // tm_year is year since 1900
    newAppointment.date_time.tm_mon = month - 1; // tm_mon is 0-11
    newAppointment.date_time.tm_mday = day;
    newAppointment.date_time.tm_hour = hour;
    newAppointment.date_time.tm_min = minute;
    newAppointment.date_time.tm_sec = 0;
    newAppointment.date_time.tm_isdst = -1; // let system determine if daylight saving time is in effect

    appointments[appointmentCount] = newAppointment;
    appointmentCount++;

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    for (int i = 0; i < appointmentCount; i++) {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &appointments[i].date_time);
        printf("Appointment %d:\n", i + 1);
        printf("  Subject: %s\n", appointments[i].subject);
        printf("  Description: %s\n", appointments[i].description);
        printf("  Date and Time: %s\n", buffer);
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter appointment number to delete (1-%d): ", appointmentCount);
    scanf("%d", &index);
    
    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    appointmentCount--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice;

    do {
        displayMenu();
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}