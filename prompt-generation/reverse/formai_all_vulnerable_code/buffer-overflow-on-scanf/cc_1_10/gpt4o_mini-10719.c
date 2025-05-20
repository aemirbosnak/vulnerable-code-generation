//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DATE_LENGTH 11
#define MAX_TIME_LENGTH 6

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char date[MAX_DATE_LENGTH]; // Format: YYYY-MM-DD
    char time[MAX_TIME_LENGTH]; // Format: HH:MM
} Appointment;

void addAppointment(Appointment appointments[], int *count);
void viewAppointments(Appointment appointments[], int count);
void deleteAppointment(Appointment appointments[], int *count);
void saveAppointments(Appointment appointments[], int count);
void loadAppointments(Appointment appointments[], int *count);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    loadAppointments(appointments, &count);

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments.\n");
        return;
    }

    printf("Enter appointment title: ");
    getchar(); // To consume the newline left by previous scanf
    fgets(appointments[*count].title, MAX_TITLE_LENGTH, stdin);
    appointments[*count].title[strcspn(appointments[*count].title, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appointments[*count].date, MAX_DATE_LENGTH, stdin);
    appointments[*count].date[strcspn(appointments[*count].date, "\n")] = 0; // Remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(appointments[*count].time, MAX_TIME_LENGTH, stdin);
    appointments[*count].time[strcspn(appointments[*count].time, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments to display.\n");
        return;
    }
    printf("\nYour Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Date: %s, Time: %s\n", i + 1,
               appointments[i].title,
               appointments[i].date,
               appointments[i].time);
    }
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    viewAppointments(appointments, *count);
    printf("Select appointment number to delete: ");
    scanf("%d", &index);
    index--; // Adjust for zero-based indexing

    if (index < 0 || index >= *count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*count)--;
    printf("Appointment deleted successfully!\n");
}

void saveAppointments(Appointment appointments[], int count) {
    FILE *file = fopen("appointments.dat", "wb");
    if (file == NULL) {
        printf("Could not save appointments.\n");
        return;
    }
    fwrite(appointments, sizeof(Appointment), count, file);
    fclose(file);
    printf("Appointments saved successfully!\n");
}

void loadAppointments(Appointment appointments[], int *count) {
    FILE *file = fopen("appointments.dat", "rb");
    if (file == NULL) {
        printf("No saved appointments found.\n");
        return;
    }
    *count = fread(appointments, sizeof(Appointment), MAX_APPOINTMENTS, file);
    fclose(file);
    printf("%d appointments loaded successfully!\n", *count);
}