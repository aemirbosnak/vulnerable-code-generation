//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
/*
 * Appointment Scheduler program using C language
 * This program allows users to schedule appointments and view existing appointments
 * 
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold appointment data
struct appointment {
    int id;
    char name[50];
    char date[20];
    char time[10];
};

// Array to store appointments
struct appointment appointments[100];

// Counter to keep track of number of appointments
int numAppointments = 0;

// Function to display main menu
void displayMainMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Schedule appointment\n");
    printf("2. View appointments\n");
    printf("3. Exit\n\n");
}

// Function to schedule appointment
void scheduleAppointment() {
    struct appointment newAppointment;
    
    printf("Schedule an appointment:\n");
    
    // Get name from user
    printf("Name: ");
    fgets(newAppointment.name, 50, stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = 0;
    
    // Get date from user
    printf("Date (MM/DD/YYYY): ");
    fgets(newAppointment.date, 20, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0;
    
    // Get time from user
    printf("Time (HH:MM AM/PM): ");
    fgets(newAppointment.time, 10, stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = 0;
    
    // Assign unique ID to appointment
    newAppointment.id = numAppointments + 1;
    
    // Add appointment to array
    appointments[numAppointments] = newAppointment;
    numAppointments++;
    
    printf("\nAppointment scheduled successfully!\n");
}

// Function to display existing appointments
void viewAppointments() {
    printf("Existing appointments:\n\n");
    
    // Loop through all appointments and display them
    for (int i = 0; i < numAppointments; i++) {
        printf("ID: %d\n", appointments[i].id);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n\n", appointments[i].time);
    }
}

int main() {
    int choice;
    
    // Loop until user chooses to exit
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}