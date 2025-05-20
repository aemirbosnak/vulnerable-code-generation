//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define DATE_STRING_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[DATE_STRING_LENGTH]; // Format: YYYY-MM-DD
    char time[6]; // Format: HH:MM
    char description[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

// Function to display the current schedule
void displayAppointments() {
    printf("\nCurrent Schedule:\n");
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("  Name: %s\n", appointments[i].name);
        printf("  Date: %s\n", appointments[i].date);
        printf("  Time: %s\n", appointments[i].time);
        printf("  Description: %s\n", appointments[i].description);
    }
}

// Function to schedule a new appointment
void scheduleAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached! Cannot schedule more.\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter the name of the person: ");
    scanf(" %[^\n]", newAppointment.name);
    printf("Enter the date (YYYY-MM-DD): ");
    scanf(" %[^\n]", newAppointment.date);
    printf("Enter the time (HH:MM): ");
    scanf(" %[^\n]", newAppointment.time);
    printf("Enter the description: ");
    scanf(" %[^\n]", newAppointment.description);
    
    appointments[appointmentCount++] = newAppointment;
    printf("Appointment scheduled successfully!\n");
}

// Function to cancel an appointment
void cancelAppointment() {
    int appointmentNumber;
    printf("Enter appointment number to cancel: ");
    scanf("%d", &appointmentNumber);
    
    if (appointmentNumber < 1 || appointmentNumber > appointmentCount) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = appointmentNumber - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    appointmentCount--;
    printf("Appointment %d cancelled successfully!\n", appointmentNumber);
}

// Function to display a menu of options
void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Schedule Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("Exiting the Scheduler. Have a great day!\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    
    return 0;
}