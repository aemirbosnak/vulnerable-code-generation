//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    char title[100];
    char date[11]; // Format: YYYY-MM-DD
    char time[6]; // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void displayMenu();
void executeChoice(int choice);
void recursiveMenu();


void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    printf("Enter appointment title: ");
    scanf(" %[^\n]", appointments[appointmentCount].title);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", appointments[appointmentCount].date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", appointments[appointmentCount].time);
    
    appointmentCount++;
    printf("Appointment added successfully!\n");
    recursiveMenu();
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
    } else {
        printf("Scheduled Appointments:\n");
        for (int i = 0; i < appointmentCount; i++) {
            printf("Appointment %d: %s on %s at %s\n",
                i + 1, appointments[i].title, appointments[i].date, appointments[i].time);
        }
    }
    recursiveMenu();
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
    } else {
        int index;
        printf("Enter the appointment number to delete (1 - %d): ", appointmentCount);
        scanf("%d", &index);
        if (index < 1 || index > appointmentCount) {
            printf("Invalid appointment number!\n");
        } else {
            for (int i = index - 1; i < appointmentCount - 1; i++) {
                appointments[i] = appointments[i + 1];
            }
            appointmentCount--;
            printf("Appointment deleted successfully!\n");
        }
    }
    recursiveMenu();
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void executeChoice(int choice) {
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
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            recursiveMenu();
    }
}

void recursiveMenu() {
    displayMenu();
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    executeChoice(choice);
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    recursiveMenu();
    return 0;
}