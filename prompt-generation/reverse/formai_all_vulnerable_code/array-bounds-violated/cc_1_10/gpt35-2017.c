//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    int id;
    char name[50];
    char date[20];
    char time[10];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS]; // Declare an array of appointments
int nextAvailableId = 1; // The ID of the next appointment to be scheduled

// Display the main menu options
void displayMenu() {
    printf("Appointment Scheduler:\n");
    printf("1. Schedule an appointment\n");
    printf("2. Show all scheduled appointments\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
}

// Schedule a new appointment
void scheduleAppointment() {
    // Check if there is space to schedule a new appointment
    if (nextAvailableId > MAX_APPOINTMENTS) {
        printf("Sorry, no available appointment slots.\n");
        return;
    }
    
    Appointment newAppointment;
    newAppointment.id = nextAvailableId++;
    
    printf("Enter your name:\n");
    scanf(" %[^\n]s", newAppointment.name);
    
    printf("Enter the date of the appointment (MM/DD/YYYY):\n");
    scanf(" %s", newAppointment.date);
    
    printf("Enter the time of the appointment (HH:MM AM/PM):\n");
    scanf(" %s", newAppointment.time);
    
    appointments[newAppointment.id-1] = newAppointment;
    
    printf("Appointment scheduled successfully with ID #%d.\n", newAppointment.id);
}

// Show all scheduled appointments
void showAppointments() {
    printf("Scheduled Appointments:\n");
    
    for (int i = 0; i < nextAvailableId-1; i++) {
        printf("Appointment #%d:\n", appointments[i].id);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
    }
}

// Cancel an appointment
void cancelAppointment() {
    int idToCancel;
    printf("Enter the ID of the appointment to cancel:\n");
    scanf(" %d", &idToCancel);
    
    if (idToCancel < 1 || idToCancel >= nextAvailableId) {
        printf("Invalid appointment ID.\n");
        return;
    }
    
    // Shift all appointments after the cancelled appointment backwards in the array
    for (int i = idToCancel-1; i < nextAvailableId-1; i++) {
        appointments[i] = appointments[i+1];
    }
    
    // Decrement the ID of the next available appointment
    nextAvailableId--;
    
    printf("Appointment #%d has been cancelled.\n", idToCancel);
}

int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                showAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}