//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESCRIPTION_LENGTH 256
#define FILE_NAME "appointments.txt"

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    char date[11]; // format YYYY-MM-DD
    char time[6];  // format HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void load_appointments() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return;
    }
    while (fscanf(file, "%[^\n]\n%[^\n]\n%[^\n]\n", appointments[appointment_count].description, appointments[appointment_count].date, appointments[appointment_count].time) != EOF) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) break; // Prevent overflow
    }
    fclose(file);
}

void save_appointments() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s\n%s\n%s\n", appointments[i].description, appointments[i].date, appointments[i].time);
    }
    fclose(file);
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum limit reached.\n");
        return;
    }
    printf("Enter appointment description: ");
    fgets(appointments[appointment_count].description, MAX_DESCRIPTION_LENGTH, stdin);
    appointments[appointment_count].description[strcspn(appointments[appointment_count].description, "\n")] = 0; // Removing newline
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appointments[appointment_count].date, 11, stdin);
    appointments[appointment_count].date[strcspn(appointments[appointment_count].date, "\n")] = 0; // Removing newline
    
    printf("Enter appointment time (HH:MM): ");
    fgets(appointments[appointment_count].time, 6, stdin);
    appointments[appointment_count].time[strcspn(appointments[appointment_count].time, "\n")] = 0; // Removing newline

    appointment_count++;
    save_appointments();
    printf("Appointment added successfully.\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].description, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    view_appointments();
    int index;
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &index);
    getchar(); // Consume newline left in buffer
    index--; // Convert to 0-based index

    if (index < 0 || index >= appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    save_appointments();
    printf("Appointment deleted successfully.\n");
}

int main() {
    load_appointments();
    int choice;

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left in buffer

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
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}