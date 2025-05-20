//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Oops! Can't add more appointments, we are at capacity!\n");
        return;
    }
    
    Appointment newAppointment;
    printf("\nYay! Time to add a new appointment!\n");
    
    printf("Enter the name of the appointment: ");
    scanf("%s", newAppointment.name);
    printf("Enter the description: ");
    scanf(" %[^\n]s", newAppointment.description); // To read a line
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", newAppointment.date);
    printf("Enter the time (HH:MM): ");
    scanf("%s", newAppointment.time);
    
    appointments[appointmentCount] = newAppointment;
    appointmentCount++;
    
    printf("🎉 Appointment added successfully! 🎉\n");
}

void viewAppointments() {
    printf("\nLet's see your appointments!\n");
    if (appointmentCount == 0) {
        printf("No appointments found! 🎈\n");
        return;
    }
    
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("  Name: %s\n", appointments[i].name);
        printf("  Description: %s\n", appointments[i].description);
        printf("  Date: %s\n", appointments[i].date);
        printf("  Time: %s\n", appointments[i].time);
        printf("---------------------------\n");
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete! 🎈\n");
        return;
    }
    
    int index;
    viewAppointments();
    printf("Enter the number of the appointment you want to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointmentCount) {
        printf("🚫 Invalid appointment number! Please try again.\n");
        return;
    }
    
    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    appointmentCount--;
    printf("🌟 Appointment deleted successfully! 🌟\n");
}

void displayMenu() {
    printf("\n=========================\n");
    printf("    Appointment Scheduler    \n");
    printf("=========================\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("=========================\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
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
                printf("Exiting... Thank you for using the Appointment Scheduler! ✨\n");
                exit(0);
            default:
                printf("Oops! That's not a valid option. Try again! ❌\n");
                break;
        }
    }
    
    return 0;
}