//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hour;
    int minute;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void displayMenu() {
    printf("\n----Appointment Scheduler----\n");
    printf("1. Book Appointment\n");
    printf("2. Cancel Appointment\n");
    printf("3. View Appointments\n");
    printf("4. Exit\n");
    printf("Enter the number of the action you want to perform: ");
}

void bookAppointment() {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the maximum number of appointments has been reached.\n");
        return;
    }
    
    printf("Enter the name of the patient: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    
    printf("Enter the hour of the appointment (0-23): ");
    int hour;
    scanf("%d", &hour);
    
    printf("Enter the minute of the appointment (0-59): ");
    int minute;
    scanf("%d", &minute);
    
    Appointment appt;
    strcpy(appt.name, name);
    appt.hour = hour;
    appt.minute = minute;
    
    appointments[numAppointments] = appt;
    numAppointments++;
    
    printf("Appointment booked successfully!\n");
}

void cancelAppointment() {
    if (numAppointments == 0) {
        printf("Sorry, there are no appointments to cancel.\n");
        return;
    }
    
    printf("Enter the name of the patient whose appointment you want to cancel: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("Appointment for %s at %02d:%02d has been cancelled.\n", name, appointments[i].hour, appointments[i].minute);
            found = 1;
            for (int j = i; j < numAppointments-1; j++) {
                appointments[j] = appointments[j+1];
            }
            numAppointments--;
            break;
        }
    }
    
    if (!found) {
        printf("Sorry, we could not find an appointment for %s.\n", name);
    }
}

void viewAppointments() {
    if (numAppointments == 0) {
        printf("There are no appointments booked.\n");
        return;
    }
    
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %02d:%02d\n", appointments[i].name, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    int choice = 0;
    
    while (choice != 4) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: bookAppointment(); break;
            case 2: cancelAppointment(); break;
            case 3: viewAppointments(); break;
            case 4: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    
    return 0;
}