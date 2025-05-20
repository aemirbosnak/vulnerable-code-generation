//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold appointment data
typedef struct {
    char patientName[50];
    char doctorName[50];
    char date[20];
    char time[10];
} Appointment;

// Function to display main menu options
void displayMenu() {
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Please choose an option from the following:\n");
    printf("1. Schedule a new appointment\n");
    printf("2. View all scheduled appointments\n");
    printf("3. Quit program\n");
}

// Function to get user input for a new appointment
void getAppointmentData(Appointment* appt) {
    printf("Please enter patient name: ");
    scanf(" %[^\n]", appt->patientName);
    printf("Please enter doctor name: ");
    scanf(" %[^\n]", appt->doctorName);
    printf("Please enter date (MM/DD/YYYY): ");
    scanf(" %[^\n]", appt->date);
    printf("Please enter time (HH:MM AM/PM): ");
    scanf(" %[^\n]", appt->time);
}

int main() {
    // Initialize array to hold appointments
    Appointment appointments[20];
    int numAppointments = 0;
    
    // Initialize variable for user input
    int choice;
    
    // Loop to display menu and get user input until they choose to quit
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1:
                // Get data for new appointment
                getAppointmentData(&appointments[numAppointments]);
                
                // Increment counter for number of appointments
                numAppointments++;
                printf("\nAppointment scheduled successfully!\n");
                break;
            case 2:
                // Display all scheduled appointments
                printf("Scheduled Appointments:\n");
                for (int i = 0; i < numAppointments; i++) {
                    printf("Patient Name: %s\n", appointments[i].patientName);
                    printf("Doctor Name: %s\n", appointments[i].doctorName);
                    printf("Date: %s\n", appointments[i].date);
                    printf("Time: %s\n", appointments[i].time);
                    printf("\n");
                }
                break;
            case 3:
                // Quit the program
                printf("Thank you for using the Appointment Scheduler! Goodbye.\n");
                exit(0);
            default:
                // Invalid choice, ask user to choose again
                printf("Invalid choice, please choose again.\n");
                break;
        }
    }
    return 0;
}