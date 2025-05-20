//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of appointments
#define MAX_APPTS 10

// Define struct for appointment
typedef struct app {
    char name[50];
    int day;
    int month;
    int year;
    char time[10];
} Appointment;

// Function to print main menu
void printMainMenu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Remove Appointment\n");
    printf("4. Exit\n");
}

// Function to add an appointment
void addAppointment(Appointment *appointments, int *numAppointments) {
    // Check if maximum number of appointments has been reached
    if (*numAppointments == MAX_APPTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }
    
    // Prompt user for appointment details
    printf("Enter name: ");
    scanf(" %[^\n]s", appointments[*numAppointments].name);
    printf("Enter date (MM/DD/YYYY): ");
    scanf(" %d/%d/%d", &appointments[*numAppointments].month, &appointments[*numAppointments].day, &appointments[*numAppointments].year);
    printf("Enter time (HH:MM AM/PM): ");
    scanf(" %[^\n]s", appointments[*numAppointments].time);
    (*numAppointments)++;
    
    printf("Appointment added successfully.\n");
}

// Function to view all appointments
void viewAppointments(Appointment *appointments, int numAppointments) {
    // Check if any appointments exist
    if (numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    // Print header
    printf("%-20s %-15s %-15s %-10s\n", "Name", "Date", "Time", "Age");
    printf("-------------------- --------------- --------------- ----------\n");
    
    // Iterate over appointments and print details
    for (int i = 0; i < numAppointments; i++) {
        printf("%-20s %02d/%02d/%04d %-15s\n", appointments[i].name, appointments[i].month, appointments[i].day, appointments[i].year, appointments[i].time);
    }
}

// Function to remove a specific appointment
void removeAppointment(Appointment *appointments, int *numAppointments) {
    // Check if any appointments exist
    if (*numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    // Prompt user for appointment name
    printf("Enter name of appointment to remove: ");
    char name[50];
    scanf(" %[^\n]s", name);
    
    // Find appointment with matching name and remove it
    int found = 0;
    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            found = 1;
            for (int j = i; j < *numAppointments - 1; j++) {
                appointments[j] = appointments[j+1];
            }
            (*numAppointments)--;
            break;
        }
    }
    
    if (found) {
        printf("Appointment removed successfully.\n");
    } else {
        printf("Appointment not found.\n");
    }
}

int main() {
    // Initialize array for appointments
    Appointment appointments[MAX_APPTS];
    int numAppointments = 0;
    
    // Loop until user exits
    int choice;
    while (1) {
        printMainMenu();
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                removeAppointment(appointments, &numAppointments);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}