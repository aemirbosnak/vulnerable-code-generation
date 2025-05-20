//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DATE_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char date[MAX_DATE_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void displayMenu();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum reached.\n");
        return;
    }
    
    printf("Enter appointment title: ");
    fgets(appointments[appointmentCount].title, MAX_TITLE_LENGTH, stdin);
    strtok(appointments[appointmentCount].title, "\n"); // Remove trailing newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appointments[appointmentCount].date, MAX_DATE_LENGTH, stdin);
    strtok(appointments[appointmentCount].date, "\n"); // Remove trailing newline

    appointmentCount++;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n=== Scheduled Appointments ===\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d: %s on %s\n", i + 1, appointments[i].title, appointments[i].date);
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter the appointment number to delete (1 to %d): ", appointmentCount);
    scanf("%d", &index);
    clearBuffer();

    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Shift appointments to the left
    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully!\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}