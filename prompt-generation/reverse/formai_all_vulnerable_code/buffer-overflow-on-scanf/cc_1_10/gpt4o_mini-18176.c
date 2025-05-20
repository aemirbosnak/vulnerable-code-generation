//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DATE_LENGTH 11
#define MAX_TIME_LENGTH 6  // HH:MM format

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void loadAppointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file) {
        while (fscanf(file, "%99[^;];%10[^;];%5[^\n]\n", appointments[appointmentCount].title, appointments[appointmentCount].date, appointments[appointmentCount].time) != EOF && appointmentCount < MAX_APPOINTMENTS) {
            appointmentCount++;
        }
        fclose(file);
    }
}

void saveAppointments() {
    FILE *file = fopen("appointments.txt", "w");
    for (int i = 0; i < appointmentCount; i++) {
        fprintf(file, "%s;%s;%s\n", appointments[i].title, appointments[i].date, appointments[i].time);
    }
    fclose(file);
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot add more appointments.\n");
        return;
    }

    printf("Enter appointment title: ");
    scanf(" %[^\n]s", appointments[appointmentCount].title);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]s", appointments[appointmentCount].date);
    printf("Enter appointment time (HH:MM): ");
    scanf(" %[^\n]s", appointments[appointmentCount].time);
    
    appointmentCount++;
    saveAppointments();
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].title, appointments[i].date, appointments[i].time);
    }
    printf("\n");
}

void deleteAppointment() {
    int index;
    viewAppointments();
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    if(index < 1 || index > appointmentCount) {
        printf("Invalid appointment number.\n");
        return;
    }
    
    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    appointmentCount--;
    saveAppointments();
    printf("Appointment deleted successfully!\n");
}

void displayMenu() {
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadAppointments();
    
    int choice;
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
                deleteAppointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}