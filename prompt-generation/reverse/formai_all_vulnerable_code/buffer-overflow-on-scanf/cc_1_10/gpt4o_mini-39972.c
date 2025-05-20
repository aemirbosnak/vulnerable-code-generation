//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_LENGTH 256

typedef struct {
    char title[MAX_LENGTH];
    char date[MAX_LENGTH];
    char time[MAX_LENGTH];
    char description[MAX_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached.\n");
        return;
    }
    
    Appointment newAppointment;
    printf("Enter title: ");
    fgets(newAppointment.title, MAX_LENGTH, stdin);
    newAppointment.title[strcspn(newAppointment.title, "\n")] = '\0'; // Remove newline
    
    printf("Enter date (YYYY-MM-DD): ");
    fgets(newAppointment.date, MAX_LENGTH, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = '\0'; // Remove newline

    printf("Enter time (HH:MM): ");
    fgets(newAppointment.time, MAX_LENGTH, stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = '\0'; // Remove newline

    printf("Enter description: ");
    fgets(newAppointment.description, MAX_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = '\0'; // Remove newline

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added successfully.\n");
}

void displayAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Description: %s\n", appointments[i].description);
        printf("\n");
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    displayAppointments();
    
    int idx;
    printf("Select appointment number to delete (1-%d): ", appointmentCount);
    scanf("%d", &idx);
    getchar(); // Consume newline

    if (idx < 1 || idx > appointmentCount) {
        printf("Invalid selection!\n");
        return;
    }
    
    // Shift appointments to fill the deleted slot
    for (int i = idx - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully.\n");
}

void showMenu() {
    printf("Appointment Scheduler\n");
    printf("=====================\n");
    printf("1. Add Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice = 0;

    while (1) {
        showMenu();
        printf("\nSelect an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1: 
                addAppointment();
                break;
            case 2: 
                displayAppointments();
                break;
            case 3: 
                deleteAppointment();
                break;
            case 4: 
                printf("Exiting the scheduler. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }
    
    return 0;
}