//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LEN 100

typedef struct {
    char description[MAX_DESC_LEN];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function prototypes
void addAppointment();
void viewAppointments();
void deleteAppointment();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("==================================\n");
        printf("      Appointment Scheduler       \n");
        printf("==================================\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("==================================\n");
        printf("Select an option (1-4): ");
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
                printf("Exiting... Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

// Function to add an appointment
void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached!\n");
        return;
    }

    printf("Enter description: ");
    fgets(appointments[appointment_count].description, MAX_DESC_LEN, stdin);
    appointments[appointment_count].description[strcspn(appointments[appointment_count].description, "\n")] = 0; // Remove newline

    printf("Enter date (YYYY-MM-DD): ");
    fgets(appointments[appointment_count].date, 11, stdin);
    appointments[appointment_count].date[strcspn(appointments[appointment_count].date, "\n")] = 0; // Remove newline

    printf("Enter time (HH:MM): ");
    fgets(appointments[appointment_count].time, 6, stdin);
    appointments[appointment_count].time[strcspn(appointments[appointment_count].time, "\n")] = 0; // Remove newline

    appointment_count++;
    printf("Appointment added successfully!\n");
}

// Function to view all appointments
void viewAppointments() {
    printf("\n===== View Appointments =====\n");
    if (appointment_count == 0) {
        printf("No appointments found.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n\n", appointments[i].time);
    }
}

// Function to delete an appointment
void deleteAppointment() {
    viewAppointments();

    if (appointment_count == 0) {
        return;
    }

    int index;
    printf("Select the appointment number to delete: ");
    scanf("%d", &index);
    clearInputBuffer();

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Appointment deleted successfully!\n");
}

// Function to clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}