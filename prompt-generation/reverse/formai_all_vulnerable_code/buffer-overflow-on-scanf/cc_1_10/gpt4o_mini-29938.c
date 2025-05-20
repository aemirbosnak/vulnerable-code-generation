//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int id;
    char description[256];
    struct tm dateTime;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clearInputBuffer() {
    while (getchar() != '\n');
}

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum limit reached.\n");
        return;
    }

    Appointment newAppointment;
    newAppointment.id = appointment_count + 1;

    printf("Enter appointment description: ");
    fgets(newAppointment.description, sizeof(newAppointment.description), stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0; // Remove newline

    printf("Enter appointment date (yyyy-mm-dd): ");
    char date[11];
    scanf("%10s", date);
    printf("Enter appointment time (HH:MM): ");
    char time[6];
    scanf("%5s", time);
    clearInputBuffer();

    char datetime[20];
    snprintf(datetime, sizeof(datetime), "%s %s", date, time);
    strptime(datetime, "%Y-%m-%d %H:%M", &newAppointment.dateTime);

    appointments[appointment_count] = newAppointment;
    appointment_count++;
    printf("Appointment added successfully!\n");
}

void viewAppointment() {
    int id;
    printf("Enter appointment ID to view: ");
    scanf("%d", &id);
    clearInputBuffer();

    if (id < 1 || id > appointment_count) {
        printf("Invalid appointment ID.\n");
        return;
    }

    Appointment app = appointments[id - 1];
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &app.dateTime);
    printf("Appointment ID: %d\nDescription: %s\nDate & Time: %s\n", app.id, app.description, buffer);
}

void deleteAppointment() {
    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    if (id < 1 || id > appointment_count) {
        printf("Invalid appointment ID.\n");
        return;
    }

    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void listAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment app = appointments[i];
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &app.dateTime);
        printf("ID: %d, Description: %s, Date & Time: %s\n", app.id, app.description, buffer);
    }
}

void displayMenu() {
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointment\n");
    printf("3. Delete Appointment\n");
    printf("4. List Appointments\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: 
                addAppointment(); 
                break;
            case 2: 
                viewAppointment(); 
                break;
            case 3: 
                deleteAppointment(); 
                break;
            case 4: 
                listAppointments(); 
                break;
            case 5: 
                printf("Exiting the scheduler. Goodbye!\n"); 
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n"); 
                break;
        }
    }

    return 0;
}