//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define TIME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void loadAppointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        return; // No appointments yet
    }
    while (fscanf(file, "%s %s\n", appointments[appointmentCount].name, appointments[appointmentCount].time) != EOF) {
        appointmentCount++;
    }
    fclose(file);
}

void saveAppointments() {
    FILE *file = fopen("appointments.txt", "w");
    for (int i = 0; i < appointmentCount; i++) {
        fprintf(file, "%s %s\n", appointments[i].name, appointments[i].time);
    }
    fclose(file);
}

void scheduleAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    char name[NAME_LENGTH];
    char time[TIME_LENGTH];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", time);

    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].time, time) == 0) {
            printf("Time slot already taken! Please choose another time.\n");
            return;
        }
    }

    strcpy(appointments[appointmentCount].name, name);
    strcpy(appointments[appointmentCount].time, time);
    appointmentCount++;
    saveAppointments();
    printf("Appointment scheduled for %s at %s\n", name, time);
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%s - %s\n", appointments[i].name, appointments[i].time);
    }
}

void displayMenu() {
    printf("\n===== Appointment Scheduler =====\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadAppointments();
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Exiting the scheduler.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}