//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    char date[MAX_STRING_LENGTH];
    char time[MAX_STRING_LENGTH];
} Appointment;

void addAppointment(Appointment appointments[], int *size);
void viewAppointments(Appointment appointments[], int size);
void deleteAppointment(Appointment appointments[], int *size);
void saveAppointments(Appointment appointments[], int size);
void loadAppointments(Appointment appointments[], int *size);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int size = 0;
    int choice;

    loadAppointments(appointments, &size);

    while (1) {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Save Appointments\n");
        printf("5. Load Appointments\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                addAppointment(appointments, &size);
                break;
            case 2:
                viewAppointments(appointments, size);
                break;
            case 3:
                deleteAppointment(appointments, &size);
                break;
            case 4:
                saveAppointments(appointments, size);
                break;
            case 5:
                loadAppointments(appointments, &size);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addAppointment(Appointment appointments[], int *size) {
    if (*size >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum limit reached.\n");
        return;
    }

    printf("Enter name: ");
    fgets(appointments[*size].name, sizeof(appointments[*size].name), stdin);
    appointments[*size].name[strcspn(appointments[*size].name, "\n")] = 0; // to remove newline

    printf("Enter date (YYYY-MM-DD): ");
    fgets(appointments[*size].date, sizeof(appointments[*size].date), stdin);
    appointments[*size].date[strcspn(appointments[*size].date, "\n")] = 0; // remove newline

    printf("Enter time (HH:MM): ");
    fgets(appointments[*size].time, sizeof(appointments[*size].time), stdin);
    appointments[*size].time[strcspn(appointments[*size].time, "\n")] = 0; // remove newline

    (*size)++;
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment appointments[], int size) {
    if (size == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("\n--- Appointments ---\n");
    for (int i = 0; i < size; i++) {
        printf("Appointment %d: %s on %s at %s\n", 
               i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void deleteAppointment(Appointment appointments[], int *size) {
    if (*size == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    viewAppointments(appointments, *size);
    
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // to consume the newline character

    if (index < 1 || index > *size) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < *size - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*size)--;
    printf("Appointment deleted successfully!\n");
}

void saveAppointments(Appointment appointments[], int size) {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s\n%s\n%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }

    fclose(file);
    printf("Appointments saved successfully!\n");
}

void loadAppointments(Appointment appointments[], int *size) {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No saved appointments found.\n");
        return;
    }

    while (fscanf(file, "%[^\n]\n%[^\n]\n%[^\n]\n", 
                  appointments[*size].name, 
                  appointments[*size].date, 
                  appointments[*size].time) == 3) {
        (*size)++;
    }

    fclose(file);
    printf("Appointments loaded successfully!\n");
}