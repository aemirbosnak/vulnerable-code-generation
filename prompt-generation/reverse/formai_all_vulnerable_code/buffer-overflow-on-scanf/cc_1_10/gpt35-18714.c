//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the maximum number of appointments and the length of the appointment time string
#define MAX_APPOINTMENTS 10
#define APPOINTMENT_TIME_LENGTH 6

// Define a struct for the appointment
struct Appointment {
    char time[APPOINTMENT_TIME_LENGTH];
    char desc[100];
};

// Declare a global array of appointments
struct Appointment appointments[MAX_APPOINTMENTS];

// Declare a function to display the menu
void displayMenu();

// Declare a function to add an appointment
void addAppointment();

// Declare a function to remove an appointment
void removeAppointment();

// Declare a function to display the appointments
void displayAppointments();

// Define the main function
int main() {
    // Declare a variable for the user's menu choice
    int choice;
    
    // Loop indefinitely until the user chooses to exit
    while (1) {
        // Display the menu
        displayMenu();
        
        // Get the user's choice from the command line
        scanf("%d", &choice);
        
        // Handle the user's choice
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                removeAppointment();
                break;
            case 3:
                displayAppointments();
                break;
            case 4:
                // Exit the program
                printf("Exiting the program...\n");
                exit(0);
            default:
                // The user entered an invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    // Return 0 to indicate successful execution
    return 0;
}

// Define the function to display the menu
void displayMenu() {
    printf("Appointment Scheduler\n");
    printf("1. Add an appointment\n");
    printf("2. Remove an appointment\n");
    printf("3. Display appointments\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Define the function to add an appointment
void addAppointment() {
    // Check if there are too many appointments
    if (sizeof(appointments) / sizeof(appointments[0]) >= MAX_APPOINTMENTS) {
        printf("Error: There are too many appointments already.\n");
        return;
    }
    
    // Get the time and description of the appointment from the user
    char time[APPOINTMENT_TIME_LENGTH];
    char desc[100];
    printf("Enter the time of the appointment (hh:mm): ");
    scanf("%s", time);
    printf("Enter a description of the appointment: ");
    scanf("%s", desc);
    
    // Create a new appointment struct and add it to the array
    struct Appointment newAppointment;
    strcpy(newAppointment.time, time);
    strcpy(newAppointment.desc, desc);
    appointments[sizeof(appointments) / sizeof(appointments[0])] = newAppointment;
    
    printf("Appointment added successfully.\n");
}

// Define the function to remove an appointment
void removeAppointment() {
    // Get the time of the appointment to remove from the user
    char time[APPOINTMENT_TIME_LENGTH];
    printf("Enter the time of the appointment to remove (hh:mm): ");
    scanf("%s", time);
    
    // Look for the appointment in the array and remove it if found
    int i;
    for (i = 0; i < sizeof(appointments) / sizeof(appointments[0]); i++) {
        if (strcmp(appointments[i].time, time) == 0) {
            appointments[i] = (struct Appointment){ 0 };
            printf("Appointment removed successfully.\n");
            return;
        }
    }
    
    // The appointment was not found
    printf("Error: Appointment not found.\n");
}

// Define the function to display the appointments
void displayAppointments() {
    // Loop through the array and print out each appointment
    int i;
    for (i = 0; i < sizeof(appointments) / sizeof(appointments[0]); i++) {
        if (strlen(appointments[i].time) > 0) {
            printf("%s %s\n", appointments[i].time, appointments[i].desc);
        }
    }
}