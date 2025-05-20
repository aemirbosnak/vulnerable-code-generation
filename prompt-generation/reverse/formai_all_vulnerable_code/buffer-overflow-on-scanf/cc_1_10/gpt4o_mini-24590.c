//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11
#define MAX_TIME_LENGTH 6

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter the name of the person: ");
    getchar(); // Clear buffer
    fgets(new_appointment.name, MAX_NAME_LENGTH, stdin);
    strtok(new_appointment.name, "\n"); // Remove newline character

    printf("Enter the date (YYYY-MM-DD): ");
    fgets(new_appointment.date, MAX_DATE_LENGTH, stdin);
    strtok(new_appointment.date, "\n"); // Remove newline character

    printf("Enter the time (HH:MM): ");
    fgets(new_appointment.time, MAX_TIME_LENGTH, stdin);
    strtok(new_appointment.time, "\n"); // Remove newline character

    appointments[appointment_count++] = new_appointment;

    printf("Appointment added successfully!\n");
}

void list_appointments() {
    if (appointment_count == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("\nList of Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("-------------------------------\n");
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

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Appointment deleted successfully!\n");
}

void save_appointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s,%s,%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }

    fclose(file);
    printf("Appointments saved successfully to appointments.txt\n");
}

void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (!file) {
        printf("Error opening file for reading. Starting with an empty list.\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", appointments[appointment_count].name, appointments[appointment_count].date, appointments[appointment_count].time) != EOF) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) {
            printf("Reached maximum appointments limit while loading.\n");
            break;
        }
    }

    fclose(file);
    printf("Appointments loaded successfully from appointments.txt\n");
}

int main() {
    int choice;

    load_appointments();

    do {
        printf("\nAppointment Scheduler Menu:\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Save Appointments\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                save_appointments();
                break;
            case 5:
                save_appointments();
                printf("Exiting the application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}