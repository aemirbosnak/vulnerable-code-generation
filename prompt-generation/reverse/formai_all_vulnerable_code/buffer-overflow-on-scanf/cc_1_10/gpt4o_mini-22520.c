//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int count;
} AppointmentScheduler;

void initializeScheduler(AppointmentScheduler *scheduler) {
    scheduler->count = 0;
}

void addAppointment(AppointmentScheduler *scheduler) {
    if (scheduler->count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot add more appointments.\n");
        return;
    }
    
    Appointment newAppointment;

    printf("Enter name: ");
    scanf(" %[^\n]", newAppointment.name);
    printf("Enter description: ");
    scanf(" %[^\n]", newAppointment.description);
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %s", newAppointment.date);
    printf("Enter time (HH:MM): ");
    scanf(" %s", newAppointment.time);

    scheduler->appointments[scheduler->count++] = newAppointment;
    printf("Appointment added successfully!\n");
}

void displayAppointments(const AppointmentScheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < scheduler->count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", scheduler->appointments[i].name);
        printf("Description: %s\n", scheduler->appointments[i].description);
        printf("Date: %s\n", scheduler->appointments[i].date);
        printf("Time: %s\n\n", scheduler->appointments[i].time);
    }
}

void deleteAppointment(AppointmentScheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    displayAppointments(scheduler);
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > scheduler->count) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Shift appointments to fill the gap
    for (int i = index - 1; i < scheduler->count - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }
    scheduler->count--;
    printf("Appointment deleted successfully!\n");
}

void saveAppointments(const AppointmentScheduler *scheduler) {
    FILE *file = fopen("appointments.txt", "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < scheduler->count; i++) {
        fprintf(file, "%s\n%s\n%s\n%s\n", 
                scheduler->appointments[i].name,
                scheduler->appointments[i].description,
                scheduler->appointments[i].date,
                scheduler->appointments[i].time);
    }

    fclose(file);
    printf("Appointments saved successfully!\n");
}

void loadAppointments(AppointmentScheduler *scheduler) {
    FILE *file = fopen("appointments.txt", "r");
    if (!file) {
        printf("No saved appointments found.\n");
        return;
    }

    while (!feof(file) && scheduler->count < MAX_APPOINTMENTS) {
        Appointment newAppointment;
        fscanf(file, " %[^\n]", newAppointment.name);
        fscanf(file, " %[^\n]", newAppointment.description);
        fscanf(file, " %s", newAppointment.date);
        fscanf(file, " %s", newAppointment.time);
        scheduler->appointments[scheduler->count++] = newAppointment;
    }

    fclose(file);
    printf("Appointments loaded successfully!\n");
}

void showMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
}

int main() {
    AppointmentScheduler scheduler;
    initializeScheduler(&scheduler);
    loadAppointments(&scheduler);

    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(&scheduler);
                break;
            case 2:
                displayAppointments(&scheduler);
                break;
            case 3:
                deleteAppointment(&scheduler);
                break;
            case 4:
                saveAppointments(&scheduler);
                break;
            case 5:
                loadAppointments(&scheduler);
                break;
            case 6:
                printf("Exiting the scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}