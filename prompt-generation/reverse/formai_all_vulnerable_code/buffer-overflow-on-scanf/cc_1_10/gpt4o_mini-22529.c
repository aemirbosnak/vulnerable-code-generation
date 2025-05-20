//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    char title[50];
    char date[11]; // format: YYYY-MM-DD
    char time[6];  // format: HH:MM
    char description[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count < MAX_APPOINTMENTS) {
        Appointment app;
        printf("Enter title: ");
        fgets(app.title, sizeof(app.title), stdin);
        app.title[strcspn(app.title, "\n")] = 0; // Remove newline

        printf("Enter date (YYYY-MM-DD): ");
        fgets(app.date, sizeof(app.date), stdin);
        app.date[strcspn(app.date, "\n")] = 0;

        printf("Enter time (HH:MM): ");
        fgets(app.time, sizeof(app.time), stdin);
        app.time[strcspn(app.time, "\n")] = 0;

        printf("Enter description: ");
        fgets(app.description, sizeof(app.description), stdin);
        app.description[strcspn(app.description, "\n")] = 0;

        appointments[appointment_count++] = app;
        printf("Appointment added successfully!\n");
    } else {
        printf("Appointment list is full!\n");
    }
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments found!\n");
        return;
    }
    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Description: %s\n\n", appointments[i].description);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete!\n");
        return;
    }
    int index;
    printf("Enter the appointment number to delete (1-%d): ", appointment_count);
    scanf("%d", &index);
    getchar(); // Consume newline character after integer input

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift appointments left
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Select an option: ");
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
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}