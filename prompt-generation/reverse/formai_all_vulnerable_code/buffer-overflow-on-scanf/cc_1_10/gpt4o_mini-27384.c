//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[DATE_LENGTH];
    char time[6];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void clearInputBuffer() {
    while (getchar() != '\n');
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot add more appointments.\n");
        return;
    }

    Appointment newAppointment;

    printf("Enter name for the appointment: ");
    fgets(newAppointment.name, MAX_NAME_LENGTH, stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = 0; // Remove newline character

    printf("Enter date for the appointment (YYYY-MM-DD): ");
    fgets(newAppointment.date, DATE_LENGTH, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0; // Remove newline character

    printf("Enter time for the appointment (HH:MM): ");
    fgets(newAppointment.time, 6, stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = 0; // Remove newline character

    appointments[appointmentCount++] = newAppointment;

    printf("Appointment added successfully!\n\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments found.\n\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s - %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
    printf("\n");
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n\n");
        return;
    }

    viewAppointments();
    int index;
    printf("Enter appointment number to delete: ");
    scanf("%d", &index);
    clearInputBuffer();

    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number.\n\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;

    printf("Appointment deleted successfully!\n\n");
}

void saveAppointmentsToFile() {
    FILE *file = fopen("appointments.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n\n");
        return;
    }

    for (int i = 0; i < appointmentCount; i++) {
        fprintf(file, "%s|%s|%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }

    fclose(file);
    printf("Appointments saved to appointments.txt successfully!\n\n");
}

void loadAppointmentsFromFile() {
    FILE *file = fopen("appointments.txt", "r");
    if (!file) {
        printf("No saved appointments found. Starting fresh.\n\n");
        return;
    }

    while (fscanf(file, "%49[^|]|%10[^|]|%5[^\n]\n", appointments[appointmentCount].name, appointments[appointmentCount].date, appointments[appointmentCount].time) == 3) {
        appointmentCount++;
        if (appointmentCount >= MAX_APPOINTMENTS) break;
    }

    fclose(file);
    printf("Appointments loaded successfully! %d appointments retrieved.\n\n", appointmentCount);
}

void displayMenu() {
    printf("Welcome to the Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadAppointmentsFromFile();

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

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
                saveAppointmentsToFile();
                break;
            case 5:
                loadAppointmentsFromFile();
                break;
            case 6:
                saveAppointmentsToFile();
                printf("Exiting program. Have a nice day!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n\n");
        }
    }

    return 0;
}