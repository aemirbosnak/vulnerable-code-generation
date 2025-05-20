//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DETAILS_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char details[MAX_DETAILS_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int count;
} Scheduler;

// Function prototypes
void addAppointment(Scheduler* scheduler);
void listAppointments(const Scheduler* scheduler);
void deleteAppointment(Scheduler* scheduler);
void clearBuffer();

int main() {
    Scheduler scheduler = { .count = 0 };
    int choice;

    do {
        printf("\n===== Appointment Scheduler =====\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        clearBuffer();  // Clear buffer after taking input
        
        switch (choice) {
            case 1:
                addAppointment(&scheduler);
                break;
            case 2:
                listAppointments(&scheduler);
                break;
            case 3:
                deleteAppointment(&scheduler);
                break;
            case 4:
                printf("Exiting scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addAppointment(Scheduler* scheduler) {
    if (scheduler->count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot add more appointments.\n");
        return;
    }
    
    Appointment newAppointment;
    printf("Enter appointment title: ");
    fgets(newAppointment.title, MAX_TITLE_LENGTH, stdin);
    strtok(newAppointment.title, "\n");  // Remove newline character

    printf("Enter appointment details: ");
    fgets(newAppointment.details, MAX_DETAILS_LENGTH, stdin);
    strtok(newAppointment.details, "\n"); // Remove newline character

    printf("Enter date (YYYY-MM-DD): ");
    fgets(newAppointment.date, sizeof(newAppointment.date), stdin);
    strtok(newAppointment.date, "\n"); // Remove newline character

    printf("Enter time (HH:MM): ");
    fgets(newAppointment.time, sizeof(newAppointment.time), stdin);
    strtok(newAppointment.time, "\n"); // Remove newline character

    scheduler->appointments[scheduler->count++] = newAppointment;
    printf("Appointment added successfully!\n");
}

void listAppointments(const Scheduler* scheduler) {
    if (scheduler->count == 0) {
        printf("No appointments to display.\n");
        return;
    }
    
    printf("\n===== List of Appointments =====\n");
    for (int i = 0; i < scheduler->count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("  Title: %s\n", scheduler->appointments[i].title);
        printf("  Details: %s\n", scheduler->appointments[i].details);
        printf("  Date: %s\n", scheduler->appointments[i].date);
        printf("  Time: %s\n", scheduler->appointments[i].time);
    }
}

void deleteAppointment(Scheduler* scheduler) {
    if (scheduler->count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int appointmentNumber;
    printf("Enter appointment number to delete (1-%d): ", scheduler->count);
    scanf("%d", &appointmentNumber);
    clearBuffer();  // Clear buffer after taking input

    if (appointmentNumber < 1 || appointmentNumber > scheduler->count) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Shift appointments down to fill the gap
    for (int i = appointmentNumber - 1; i < scheduler->count - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }
    
    scheduler->count--;
    printf("Appointment deleted successfully!\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}