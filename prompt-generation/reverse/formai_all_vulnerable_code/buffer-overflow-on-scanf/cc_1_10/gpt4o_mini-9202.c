//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    struct tm dateTime;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void clearBuffer();

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("=============================\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        clearBuffer(); // Clear newline character from the input buffer

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
        }
    }
    return 0;
}

void addAppointment() {
    if (appointmentCount == MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot add more appointments.\n");
        return;
    }

    Appointment newAppointment;
    newAppointment.id = appointmentCount + 1;

    printf("Enter appointment name: ");
    fgets(newAppointment.name, NAME_LENGTH, stdin);
    strtok(newAppointment.name, "\n"); // Remove newline character

    printf("Enter appointment description: ");
    fgets(newAppointment.description, DESC_LENGTH, stdin);
    strtok(newAppointment.description, "\n"); // Remove newline character

    printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
    char dateTimeInput[20];
    fgets(dateTimeInput, 20, stdin);
    strptime(dateTimeInput, "%Y-%m-%d %H:%M", &newAppointment.dateTime);

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added successfully.\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        Appointment ap = appointments[i];
        printf("ID: %d\n", ap.id);
        printf("Name: %s\n", ap.name);
        printf("Description: %s\n", ap.description);
        printf("Date & Time: %s", asctime(&ap.dateTime));
        printf("--------------------------\n");
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the appointment to delete: ");
    scanf("%d", &id);
    clearBuffer(); // Clear newline character

    if (id < 1 || id > appointmentCount) {
        printf("Invalid ID. Please try again.\n");
        return;
    }

    // Shift appointments down to fill the gap
    for (int i = id - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully.\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}