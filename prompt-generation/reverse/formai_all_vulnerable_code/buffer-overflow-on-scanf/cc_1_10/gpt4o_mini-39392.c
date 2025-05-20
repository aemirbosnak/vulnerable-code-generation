//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define a structure for an appointment
typedef struct {
    char name[50];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

// Function prototypes
void addAppointment(Appointment appointments[], int *count);
void viewAppointments(Appointment appointments[], int count);
void deleteAppointment(Appointment appointments[], int *count);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointmentCount = 0;
    int choice;

    do {
        printf("\n=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline buffer

        switch (choice) {
            case 1:
                addAppointment(appointments, &appointmentCount);
                break;
            case 2:
                viewAppointments(appointments, appointmentCount);
                break;
            case 3:
                deleteAppointment(appointments, &appointmentCount);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached!\n");
        return;
    }

    Appointment newAppointment;

    printf("Enter appointment name: ");
    fgets(newAppointment.name, sizeof(newAppointment.name), stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(newAppointment.date, sizeof(newAppointment.date), stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0; // Remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(newAppointment.time, sizeof(newAppointment.time), stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = 0; // Remove newline

    appointments[*count] = newAppointment;
    (*count)++;
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n=== Scheduled Appointments ===\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("--------------------------\n");
    }

    printf("Total Appointments: %d\n", count);
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter the appointment number to delete (1 to %d): ", *count);
    scanf("%d", &index);
    getchar(); // Clear newline buffer

    if (index < 1 || index > *count) {
        printf("Invalid appointment number!\n");
        return;
    }

    // Shift appointments down
    for (int i = index - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    (*count)--;
    printf("Appointment deleted successfully!\n");
}