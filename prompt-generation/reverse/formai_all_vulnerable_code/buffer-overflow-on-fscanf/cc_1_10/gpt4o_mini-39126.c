//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    char date[11];    // Format: YYYY-MM-DD
    char time[6];     // Format: HH:MM
} Appointment;

Appointment* appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    appointments[appointmentCount] = (Appointment*)malloc(sizeof(Appointment));
    
    printf("Enter name: ");
    scanf("%s", appointments[appointmentCount]->name);
    
    printf("Enter description: ");
    scanf(" %100[^\n]", appointments[appointmentCount]->description);
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[appointmentCount]->date);
    
    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[appointmentCount]->time);
    
    appointmentCount++;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("[%d] %s - %s on %s at %s\n", 
            i + 1, 
            appointments[i]->name, 
            appointments[i]->description, 
            appointments[i]->date, 
            appointments[i]->time);
    }
}

void cancelAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to cancel.\n");
        return;
    }
    
    int index;
    printf("Enter the appointment number to cancel: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number!\n");
        return;
    }
    
    // Free memory of the appointment to be canceled
    free(appointments[index - 1]);
    
    // Shift remaining appointments
    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    appointmentCount--;
    printf("Appointment canceled successfully!\n");
}

void saveAppointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < appointmentCount; i++) {
        fprintf(file, "%s|%s|%s|%s\n",
                appointments[i]->name,
                appointments[i]->description,
                appointments[i]->date,
                appointments[i]->time);
    }
    
    fclose(file);
    printf("Appointments saved to file.\n");
}

void loadAppointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (!file) {
        printf("No saved appointments to load.\n");
        return;
    }
    
    while (!feof(file) && appointmentCount < MAX_APPOINTMENTS) {
        appointments[appointmentCount] = (Appointment*)malloc(sizeof(Appointment));
        fscanf(file, "%[^|]|%[^|]|%[^|]|%s\n",
               appointments[appointmentCount]->name,
               appointments[appointmentCount]->description,
               appointments[appointmentCount]->date,
               appointments[appointmentCount]->time);
        appointmentCount++;
    }
    
    fclose(file);
    printf("Appointments loaded successfully.\n");
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
    printf("------------------------------\n");
}

int main() {
    loadAppointments();
    
    int choice;
    while (1) {
        displayMenu();
        
        printf("Enter your choice: ");
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
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}