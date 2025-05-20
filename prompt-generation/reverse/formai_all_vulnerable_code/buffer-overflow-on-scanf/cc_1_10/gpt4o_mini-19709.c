//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    char date[20];
    char time[10];
    char description[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void clearScreen();
void menu();

void clearScreen() {
    // Clear the console screen
    printf("\033[H\033[J");
}

void menu() {
    int choice;
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

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
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            menu();
    }
    menu(); // Re-display menu after action
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached!\n");
        return;
    }

    Appointment app;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", app.date);
    printf("Enter time (HH:MM): ");
    scanf("%s", app.time);
    printf("Enter description: ");
    getchar(); // Consume newline
    fgets(app.description, sizeof(app.description), stdin);
    app.description[strcspn(app.description, "\n")] = '\0'; // Remove trailing newline

    appointments[appointmentCount] = app;
    appointmentCount++;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. Date: %s, Time: %s, Description: %s\n", 
               i + 1, appointments[i].date, appointments[i].time, appointments[i].description);
    }
    printf("\n");
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    viewAppointments();
    int index;
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > appointmentCount) {
        printf("Invalid index! Please try again.\n");
        deleteAppointment();
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    clearScreen();
    menu();
    return 0;
}