//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int num_appointments;
int appointments[100];

// Function to add an appointment
void add_appointment(int appointment_id, int start_time, int end_time, char* description) {
    // Check if the number of appointments has reached the maximum limit
    if (num_appointments >= 100) {
        printf("Sorry, the maximum number of appointments has been reached.\n");
        return;
    }
    
    // Convert the start and end times to seconds since the epoch
    time_t start_time_secs = mktime(&(struct tm){0, 0, 0, 0, 0, start_time, 0, 0, 0});
    time_t end_time_secs = mktime(&(struct tm){0, 0, 0, 0, 0, end_time, 0, 0, 0});
    
    // Check if the appointment overlaps with an existing appointment
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i] == appointment_id) {
            printf("Sorry, this appointment already exists.\n");
            return;
        }
        
        if (appointments[i] > appointment_id) {
            continue;
        }
        
        if (appointments[i] < appointment_id) {
            // Check if the current appointment overlaps with the new appointment
            if (appointments[i] + 1 < appointment_id) {
                if (start_time_secs > appointments[i] && end_time_secs < appointments[i] + 1) {
                    printf("Sorry, this appointment overlaps with another appointment.\n");
                    return;
                }
            }
        }
    }
    
    // Add the appointment to the list
    appointments[num_appointments] = appointment_id;
    num_appointments++;
    
    // Print the new appointment
    printf("New appointment added: %d - %d - %s\n", appointment_id, start_time, description);
}

// Function to delete an appointment
void delete_appointment(int appointment_id) {
    // Check if the appointment exists
    if (appointments[appointment_id] == appointment_id) {
        // Delete the appointment from the list
        for (int i = appointment_id; i < num_appointments - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        num_appointments--;
        
        // Print the deleted appointment
        printf("Appointment deleted: %d - %d - %s\n", appointment_id, appointments[appointment_id], appointments[appointment_id]);
    } else {
        printf("Appointment not found.\n");
    }
}

// Function to display all appointments
void display_appointments() {
    // Print the header
    printf("Appointments:\n");
    
    // Print the appointments
    for (int i = 0; i < num_appointments; i++) {
        printf("ID: %d - Start: %d - End: %d - Description: %s\n", appointments[i], appointments[i], appointments[i] + 1, appointments[i] + 1);
    }
}

int main() {
    int choice;
    char command[100];
    
    // Loop until the user chooses to quit
    while (1) {
        // Get the user's choice
        printf("Enter your choice (add, delete, display, quit): ");
        fgets(command, sizeof(command), stdin);
        
        // Check if the user wants to quit
        if (strcmp(command, "quit") == 0) {
            break;
        }
        
        // Convert the command to an integer
        choice = atoi(command);
        
        // Check if the user wants to add an appointment
        if (choice == 1) {
            printf("Enter the appointment ID: ");
            fgets(command, sizeof(command), stdin);
            choice = atoi(command);
            
            printf("Enter the start time: ");
            fgets(command, sizeof(command), stdin);
            choice = atoi(command);
            
            printf("Enter the end time: ");
            fgets(command, sizeof(command), stdin);
            choice = atoi(command);
            
            printf("Enter the description: ");
            fgets(command, sizeof(command), stdin);
            choice = atoi(command);
            
            add_appointment(choice, choice, choice + 1, command);
        }
        
        // Check if the user wants to delete an appointment
        else if (choice == 2) {
            printf("Enter the appointment ID: ");
            fgets(command, sizeof(command), stdin);
            choice = atoi(command);
            
            delete_appointment(choice);
        }
        
        // Check if the user wants to display all appointments
        else if (choice == 3) {
            display_appointments();
        }
    }
    
    return 0;
}