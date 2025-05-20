//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define DATE_LENGTH 11
#define TIME_LENGTH 6
#define NAME_LENGTH 50

typedef struct {
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
    char name[NAME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Limit reached.\n");
        return;
    }
    
    Appointment new_appointment;
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    
    printf("Enter time (HH:MM): ");
    scanf("%s", new_appointment.time);
    
    printf("Enter name of the person: ");
    scanf(" %[^\n]s", new_appointment.name);
    
    appointments[appointment_count] = new_appointment;
    appointment_count++;
    
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    printf("%-10s %-5s %-30s\n", "Date", "Time", "Name");
    for (int i = 0; i < appointment_count; i++) {
        printf("%-10s %-5s %-30s\n", appointments[i].date, appointments[i].time, appointments[i].name);
    }
}

void deleteAppointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the appointment you want to delete (0 to %d): ", appointment_count - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= appointment_count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void saveAppointments() {
    FILE *file = fopen("appointments.txt", "w");
    
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s %s %s\n", appointments[i].date, appointments[i].time, appointments[i].name);
    }
    
    fclose(file);
    printf("Appointments saved successfully!\n");
}

void loadAppointments() {
    FILE *file = fopen("appointments.txt", "r");
    
    if (!file) {
        printf("Error opening file! Starting with no appointments.\n");
        return;
    }

    while (fscanf(file, "%s %s %[^\n]s", appointments[appointment_count].date, appointments[appointment_count].time, appointments[appointment_count].name) != EOF) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) {
            printf("Maximum appointment limit reached. Stopping load.\n");
            break;
        }
    }
    
    fclose(file);
    printf("Appointments loaded successfully!\n");
}

void showMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadAppointments();
    
    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                saveAppointments();
                break;
            case 5:
                loadAppointments();
                break;
            case 6:
                saveAppointments();
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}