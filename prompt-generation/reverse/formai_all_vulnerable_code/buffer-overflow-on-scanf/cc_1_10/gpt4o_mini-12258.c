//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    struct tm time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. The schedule is full!\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter name for appointment: ");
    fgets(new_appointment.name, NAME_LENGTH, stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = 0; // Remove newline character

    printf("Enter description for appointment: ");
    fgets(new_appointment.description, DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline character

    printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
    char datetime[20];
    fgets(datetime, 20, stdin);

    strptime(datetime, "%Y-%m-%d %H:%M", &new_appointment.time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment for '%s' added successfully!\n", new_appointment.name);
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s: %s on %02d-%02d-%04d at %02d:%02d\n", 
            i + 1, 
            appointments[i].name, 
            appointments[i].description, 
            appointments[i].time.tm_mday, 
            appointments[i].time.tm_mon + 1, 
            appointments[i].time.tm_year + 1900, 
            appointments[i].time.tm_hour, 
            appointments[i].time.tm_min);
    }
}

void deleteAppointment() {
    viewAppointments();

    if (appointment_count == 0) return;

    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // consume newline

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Appointment number %d deleted successfully!\n", index);
}

void displayMenu() {
    printf("\nSherlock Holmes Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

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
                printf("Goodbye! May your days be filled with intrigue and mystery!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again!\n");
        }
    }
    
    return 0;
}