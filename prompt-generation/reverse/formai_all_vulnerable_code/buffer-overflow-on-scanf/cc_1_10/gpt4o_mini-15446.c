//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define CONTENT_LENGTH 256

typedef struct {
    int id;
    char date[11]; // "YYYY-MM-DD"
    char time[6]; // "HH:MM"
    char description[CONTENT_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached! Can't add more appointments.\n");
        return;
    }

    Appointment new_appointment;
    new_appointment.id = appointment_count + 1;

    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%10s", new_appointment.date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%5s", new_appointment.time);
    printf("Enter appointment description: ");
    getchar(); // to consume newline
    fgets(new_appointment.description, CONTENT_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // remove newline

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments found!\n");
        return;
    }
    printf("\nAppointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("ID: %d | Date: %s | Time: %s | Description: %s\n",
               appointments[i].id,
               appointments[i].date,
               appointments[i].time,
               appointments[i].description);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > appointment_count) {
        printf("Invalid appointment ID.\n");
        return;
    }

    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment with ID %d deleted successfully!\n", id);
}

void menu() {
    int choice;
    while (1) {
        printf("\n----- Appointment Scheduler -----\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting the appointment scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    menu();
    return 0;
}