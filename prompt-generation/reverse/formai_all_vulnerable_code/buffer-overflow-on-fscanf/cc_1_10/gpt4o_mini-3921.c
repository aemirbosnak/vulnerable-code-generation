//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_LENGTH 100
#define FILE_NAME "appointments.txt"

struct Appointment {
    char title[MAX_LENGTH];
    char date[MAX_LENGTH];
    char time[MAX_LENGTH];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void load_appointments() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        while (fscanf(file, "%[^,],%[^,],%[^\n]\n", appointments[appointment_count].title, appointments[appointment_count].date, appointments[appointment_count].time) == 3) {
            appointment_count++;
        }
        fclose(file);
    }
}

void save_appointments() {
    FILE *file = fopen(FILE_NAME, "w");
    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s,%s,%s\n", appointments[i].title, appointments[i].date, appointments[i].time);
    }
    fclose(file);
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full.\n");
        return;
    }
    printf("Enter appointment title: ");
    fgets(appointments[appointment_count].title, MAX_LENGTH, stdin);
    appointments[appointment_count].title[strcspn(appointments[appointment_count].title, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appointments[appointment_count].date, MAX_LENGTH, stdin);
    appointments[appointment_count].date[strcspn(appointments[appointment_count].date, "\n")] = 0; // Remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(appointments[appointment_count].time, MAX_LENGTH, stdin);
    appointments[appointment_count].time[strcspn(appointments[appointment_count].time, "\n")] = 0; // Remove newline

    appointment_count++;
    save_appointments();
    printf("Appointment added successfully.\n");
}

void list_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d: %s on %s at %s\n", i + 1, appointments[i].title, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    list_appointments();
    if (appointment_count == 0) return;

    int index;
    printf("Enter the index of the appointment to delete: ");
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > appointment_count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    save_appointments();
    printf("Appointment deleted successfully.\n");
}

int main() {
    load_appointments();
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}