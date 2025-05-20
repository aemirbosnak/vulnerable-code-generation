//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char date[11];
    char time[6];
    char description[200];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter name: ");
    scanf(" %s", new_appointment.name);

    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %s", new_appointment.date);

    printf("Enter time (HH:MM): ");
    scanf(" %s", new_appointment.time);

    printf("Enter description: ");
    scanf(" %[^\n]", new_appointment.description);

    appointments[num_appointments++] = new_appointment;

    printf("Appointment added.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Description: %s\n\n", appointments[i].description);
    }
}

void edit_appointment() {
    char name[50];

    printf("Enter name of appointment to edit: ");
    scanf(" %s", name);

    int index = -1;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Appointment not found.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter new name: ");
    scanf(" %s", new_appointment.name);

    printf("Enter new date (YYYY-MM-DD): ");
    scanf(" %s", new_appointment.date);

    printf("Enter new time (HH:MM): ");
    scanf(" %s", new_appointment.time);

    printf("Enter new description: ");
    scanf(" %[^\n]", new_appointment.description);

    appointments[index] = new_appointment;

    printf("Appointment updated.\n");
}

void delete_appointment() {
    char name[50];

    printf("Enter name of appointment to delete: ");
    scanf(" %s", name);

    int index = -1;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Appointment not found.\n");
        return;
    }

    for (int i = index; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    num_appointments--;

    printf("Appointment deleted.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Edit appointment\n");
        printf("4. Delete appointment\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                edit_appointment();
                break;
            case 4:
                delete_appointment();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}