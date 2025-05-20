//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define TITLE_LEN 50
#define DESC_LEN 200

typedef struct {
    char title[TITLE_LEN];
    char description[DESC_LEN];
    struct tm dateTime;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot add more appointments.\n");
        return;
    }
    
    Appointment newAppointment;
    
    printf("Enter appointment title: ");
    fgets(newAppointment.title, TITLE_LEN, stdin);
    newAppointment.title[strcspn(newAppointment.title, "\n")] = '\0'; // Remove newline

    printf("Enter appointment description: ");
    fgets(newAppointment.description, DESC_LEN, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = '\0'; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    char date[11];
    fgets(date, sizeof(date), stdin);
    sscanf(date, "%d-%d-%d", &newAppointment.dateTime.tm_year, &newAppointment.dateTime.tm_mon, &newAppointment.dateTime.tm_mday);
    newAppointment.dateTime.tm_year -= 1900; // Adjust year
    newAppointment.dateTime.tm_mon -= 1; // Adjust month

    printf("Enter appointment time (HH:MM): ");
    char time[6];
    fgets(time, sizeof(time), stdin);
    sscanf(time, "%d:%d", &newAppointment.dateTime.tm_hour, &newAppointment.dateTime.tm_min);
    newAppointment.dateTime.tm_sec = 0;

    appointments[appointmentCount++] = newAppointment;

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        Appointment ap = appointments[i];
        char dateTimeStr[20];
        strftime(dateTimeStr, sizeof(dateTimeStr), "%Y-%m-%d %H:%M", &ap.dateTime);
        printf("Appointment %d:\n", i + 1);
        printf("Title: %s\n", ap.title);
        printf("Description: %s\n", ap.description);
        printf("Date & Time: %s\n", dateTimeStr);
        printf("-------------------------\n");
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled to delete.\n");
        return;
    }
    
    int index;
    printf("\nEnter the appointment number to delete (1-%d): ", appointmentCount);
    scanf("%d", &index);
    getchar(); // To consume the newline character left by scanf

    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully.\n");
}

void menu() {
    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

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
                printf("Exiting...\n");
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