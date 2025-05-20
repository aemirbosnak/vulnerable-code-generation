//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define DATE_STRING_LENGTH 11
#define NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 150

typedef struct {
    char name[NAME_LENGTH];
    char date[DATE_STRING_LENGTH]; // Format: YYYY-MM-DD
    char time[6]; // Format: HH:MM
    char description[MAX_DESCRIPTION_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Max appointments reached!\n");
        return;
    }
    
    Appointment appt;
    printf("Enter your name: ");
    scanf(" %[^\n]", appt.name);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]", appt.date);
    printf("Enter appointment time (HH:MM): ");
    scanf(" %[^\n]", appt.time);
    printf("Enter a description: ");
    scanf(" %[^\n]", appt.description);
    
    appointments[appointment_count++] = appt;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s - %s at %s\n   Description: %s\n", 
               i + 1, appointments[i].name, appointments[i].date, 
               appointments[i].time, appointments[i].description);
    }
}

void cancelAppointment() {
    int index;
    printf("Enter the appointment number to cancel: ");
    scanf("%d", &index);
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment canceled successfully!\n");
}

void saveAppointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (!file) {
        printf("Error opening file to save appointments.\n");
        return;
    }
    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s;%s;%s;%s\n", appointments[i].name, 
                appointments[i].date, appointments[i].time, 
                appointments[i].description);
    }
    fclose(file);
    printf("Appointments saved successfully to appointments.txt.\n");
}

void loadAppointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (!file) {
        printf("No previous appointments found.\n");
        return;
    }

    while (fscanf(file, " %[^;];%[^;];%[^;];%[^\n]\n", 
                  appointments[appointment_count].name, 
                  appointments[appointment_count].date, 
                  appointments[appointment_count].time, 
                  appointments[appointment_count].description) != EOF) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) break;
    }
    fclose(file);
    printf("Appointments loaded successfully.\n");
}

void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    loadAppointments(); // Load existing appointments on startup

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                saveAppointments();
                break;
            case 5:
                loadAppointments();
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}