//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100
#define FILE_NAME "appointments.txt"

typedef struct {
    int id;
    char description[MAX_DESC_LENGTH];
    char date[11];  // Format: YYYY-MM-DD
    char time[6];   // Format: HH:MM
} Appointment;

void addAppointment(Appointment *appointments, int *count);
void viewAppointments(Appointment *appointments, int count);
void deleteAppointment(Appointment *appointments, int *count);
void saveAppointments(Appointment *appointments, int count);
void loadAppointments(Appointment *appointments, int *count);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    loadAppointments(appointments, &count);
    
    while (1) {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                deleteAppointment(appointments, &count);
                break;
            case 4:
                saveAppointments(appointments, count);
                printf("Exiting the appointment scheduler. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addAppointment(Appointment *appointments, int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Maximum appointment limit reached.\n");
        return;
    }
    
    Appointment newAppointment;
    newAppointment.id = *count + 1; // Simple ID assignment
    
    printf("Enter description: ");
    fgets(newAppointment.description, MAX_DESC_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0; // Remove newline

    printf("Enter date (YYYY-MM-DD): ");
    fgets(newAppointment.date, sizeof(newAppointment.date), stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0;

    printf("Enter time (HH:MM): ");
    fgets(newAppointment.time, sizeof(newAppointment.time), stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = 0;

    appointments[*count] = newAppointment;
    (*count)++;

    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment *appointments, int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\n--- Upcoming Appointments ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Description: %s | Date: %s | Time: %s\n", 
               appointments[i].id,
               appointments[i].description,
               appointments[i].date,
               appointments[i].time);
    }
}

void deleteAppointment(Appointment *appointments, int *count) {
    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);

    int pos = -1;
    for (int i = 0; i < *count; i++) {
        if (appointments[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Appointment ID not found.\n");
        return;
    }

    for (int i = pos; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    (*count)--;
    printf("Appointment deleted successfully!\n");
}

void saveAppointments(Appointment *appointments, int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Unable to save appointments");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s\n", 
                appointments[i].id,
                appointments[i].description,
                appointments[i].date,
                appointments[i].time);
    }

    fclose(file);
    printf("Appointments saved successfully!\n");
}

void loadAppointments(Appointment *appointments, int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        return; // No previous appointments, just return
    }

    while (fscanf(file, "%d,%99[^,],%10[^,],%5[^\n]", 
                  &appointments[*count].id,
                  appointments[*count].description,
                  appointments[*count].date,
                  appointments[*count].time) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Appointments loaded successfully!\n");
}