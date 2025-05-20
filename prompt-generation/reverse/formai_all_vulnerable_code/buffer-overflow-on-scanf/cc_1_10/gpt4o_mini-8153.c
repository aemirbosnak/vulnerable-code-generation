//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function prototypes
void add_appointment();
void list_appointments();
void save_appointments();
void load_appointments();

int main() {
    int choice;

    load_appointments();

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Save Appointments\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                save_appointments();
                break;
            case 4:
                save_appointments();
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Please delete an appointment to add a new one.\n");
        return;
    }

    printf("Enter appointment name: ");
    fgets(appointments[appointment_count].name, MAX_NAME_LENGTH, stdin);
    appointments[appointment_count].name[strcspn(appointments[appointment_count].name, "\n")] = 0; // Remove trailing newline

    printf("Enter appointment date: ");
    fgets(appointments[appointment_count].date, MAX_DATE_LENGTH, stdin);
    appointments[appointment_count].date[strcspn(appointments[appointment_count].date, "\n")] = 0; // Remove trailing newline

    appointment_count++;
    printf("Appointment added successfully!\n");
}

void list_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s\n", i + 1, appointments[i].name, appointments[i].date);
    }
}

void save_appointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Error saving appointments.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s | %s\n", appointments[i].name, appointments[i].date);
    }
    fclose(file);
    printf("Appointments saved to appointments.txt\n");
}

void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No previous appointments found.\n");
        return;
    }

    while (fscanf(file, "%49[^|]|%29[^\n]\n", appointments[appointment_count].name, appointments[appointment_count].date) == 2) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) {
            break;
        }
    }
    fclose(file);
    printf("Previous appointments loaded.\n");
}