//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100
#define DATE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    char date[DATE_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    printf("Enter the appointment name: ");
    fgets(appointments[appointment_count].name, NAME_LENGTH, stdin);
    appointments[appointment_count].name[strcspn(appointments[appointment_count].name, "\n")] = 0; // Remove newline

    printf("Enter a description: ");
    fgets(appointments[appointment_count].description, DESC_LENGTH, stdin);
    appointments[appointment_count].description[strcspn(appointments[appointment_count].description, "\n")] = 0; // Remove newline

    printf("Enter the date (e.g., 2023-10-01): ");
    fgets(appointments[appointment_count].date, DATE_LENGTH, stdin);
    appointments[appointment_count].date[strcspn(appointments[appointment_count].date, "\n")] = 0; // Remove newline

    appointment_count++;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments to display.\n");
        return;
    }
    printf("\nCurrent Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf(" Name: %s\n", appointments[i].name);
        printf(" Description: %s\n", appointments[i].description);
        printf(" Date: %s\n", appointments[i].date);
        printf("--------------------------\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the appointment number to delete (1 to %d): ", appointment_count);
    scanf("%d", &index);
    getchar(); // Consume newline character

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

void display_menu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}