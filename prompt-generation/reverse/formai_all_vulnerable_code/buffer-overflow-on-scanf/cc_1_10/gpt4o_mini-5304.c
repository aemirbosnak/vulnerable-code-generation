//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LEN 50
#define DESC_LEN 100

typedef struct {
    char name[NAME_LEN];
    char description[DESC_LEN];
    struct tm date_time; // Store date and time as struct tm
} Appointment;

void addAppointment(Appointment appointments[], int *count);
void viewAppointments(Appointment appointments[], int count);
void deleteAppointment(Appointment appointments[], int *count);
void saveAppointments(Appointment appointments[], int count);
void loadAppointments(Appointment appointments[], int *count);
void displayMenu();
void clearBuffer();

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    // Load existing appointments from a file
    loadAppointments(appointments, &count);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the newline character from input buffer

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
                break;
            case 5:
                printf("Exiting the appointment scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Exit\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. List is full.\n");
        return;
    }
    
    Appointment newAppointment;

    printf("Enter your name: ");
    fgets(newAppointment.name, NAME_LEN, stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = 0; // Remove new line

    printf("Enter description: ");
    fgets(newAppointment.description, DESC_LEN, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0; // Remove new line

    printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
    char datetime[20];
    fgets(datetime, 20, stdin);
    strptime(datetime, "%Y-%m-%d %H:%M", &newAppointment.date_time);

    appointments[*count] = newAppointment;
    (*count)++;
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\n--- Your Appointments ---\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        char buffer[100];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &appointments[i].date_time);
        printf("Date & Time: %s\n", buffer);
    }
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    clearBuffer();
    
    if (index < 1 || index > *count) {
        printf("Invalid appointment number.\n");
        return;
    }
    
    for (int i = index - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    (*count)--;
    printf("Appointment deleted successfully.\n");
}

void saveAppointments(Appointment appointments[], int count) {
    FILE *file = fopen("appointments.txt", "w");
    if (!file) {
        printf("Could not save appointments. File error.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%s", appointments[i].name, appointments[i].description,
                asctime(&appointments[i].date_time));
    }
    fclose(file);
    printf("Appointments saved successfully.\n");
}

void loadAppointments(Appointment appointments[], int *count) {
    FILE *file = fopen("appointments.txt", "r");
    if (!file) {
        printf("No saved appointments found. Starting fresh.\n");
        return;
    }

    while (!feof(file) && *count < MAX_APPOINTMENTS) {
        fgets(appointments[*count].name, NAME_LEN, file);
        appointments[*count].name[strcspn(appointments[*count].name, "\n")] = 0;

        fgets(appointments[*count].description, DESC_LEN, file);
        appointments[*count].description[strcspn(appointments[*count].description, "\n")] = 0;

        char date_time_str[100];
        fgets(date_time_str, 100, file);
        strptime(date_time_str, "%a %b %d %H:%M:%S %Y\n", &appointments[*count].date_time);

        (*count)++;
    }
    fclose(file);
    printf("Appointments loaded successfully.\n");
}