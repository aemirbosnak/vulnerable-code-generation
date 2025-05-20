//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100
#define MAX_DATE_LENGTH 20

typedef struct {
    char description[MAX_DESC_LENGTH];
    char date[MAX_DATE_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void clearInputBuffer();

int main() {
    int choice;

    do {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        clearInputBuffer(); // Clear the newline character from input buffer

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
                printf("Exiting the Appointment Scheduler.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot add more appointments.\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter appointment description: ");
    fgets(newAppointment.description, MAX_DESC_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(newAppointment.date, MAX_DATE_LENGTH, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0; // Remove newline

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s on %s\n", i + 1, appointments[i].description, appointments[i].date);
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter the appointment number to delete (1 - %d): ", appointmentCount);
    scanf("%d", &index);
    
    clearInputBuffer(); // Clear input buffer

    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number. Unable to delete.\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully!\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}