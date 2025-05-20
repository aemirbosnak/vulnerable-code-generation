//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum appointments reached.\n");
        return;
    }

    Appointment app;
    printf("Enter appointment name: ");
    scanf(" %[^\n]", app.name);
    printf("Enter description: ");
    scanf(" %[^\n]", app.description);

    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &app.day, &app.month, &app.year);
    printf("Enter time (hh mm): ");
    scanf("%d %d", &app.hour, &app.minute);

    appointments[num_appointments++] = app;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %02d/%02d/%d\n", appointments[i].day, appointments[i].month, appointments[i].year);
        printf("Time: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
        printf("-------------------------\n");
    }
}

void cancel_appointment() {
    int index;
    printf("Enter appointment number to cancel: ");
    scanf("%d", &index);

    if (index < 1 || index > num_appointments) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Shift appointments to remove the canceled one
    for (int i = index - 1; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    num_appointments--;
    printf("Appointment canceled successfully!\n");
}

void menu() {
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Appointment Scheduler\n");
    menu();
    return 0;
}