//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define global variables
#define MAX_LENGTH 256
#define MAX_APPOINTMENTS 50

// Define struct for appointment
typedef struct Appointment {
    char date[MAX_LENGTH];
    char time[MAX_LENGTH];
    char name[MAX_LENGTH];
    char type[MAX_LENGTH];
} Appointment;

// Define function to display appointments
void display_appointments(Appointment* appointments, int num_appointments) {
    printf("\n%-15s%-15s%-15s%-15s\n", "Date", "Time", "Name", "Type");
    for(int i=0; i<num_appointments; i++) {
        printf("%-15s%-15s%-15s%-15s\n", 
            appointments[i].date, 
            appointments[i].time, 
            appointments[i].name, 
            appointments[i].type);
    }
}

// Define function to add new appointment
void add_appointment(Appointment* appointments, int* num_appointments) {
    // Check if there is already maximum number of appointments
    if(*num_appointments >= MAX_APPOINTMENTS) {
        printf("\nMaximum number of appointments reached. Cannot add more appointments.\n");
        return;
    }
    
    // Create new appointment
    Appointment new_appointment;
    printf("\nEnter date of appointment (MM/DD/YYYY format): ");
    scanf("%s", new_appointment.date);
    printf("Enter time of appointment (HH:MM format): ");
    scanf("%s", new_appointment.time);
    printf("Enter name of person for appointment: ");
    scanf("%s", new_appointment.name);
    printf("Enter type of appointment: ");
    scanf("%s", new_appointment.type);
    
    // Add new appointment to array
    appointments[*num_appointments] = new_appointment;
    *num_appointments += 1;
    
    printf("\nAppointment added!\n");
}

// Define function to remove existing appointment
void remove_appointment(Appointment* appointments, int* num_appointments) {
    // Check if there are any appointments
    if(*num_appointments == 0) {
        printf("\nNo appointments to remove.\n");
        return;
    }
    
    // Get user input for appointment to remove
    char name[MAX_LENGTH];
    printf("\nEnter name of person for appointment to remove: ");
    scanf("%s", name);
    
    // Find index of appointment with matching name
    int index = -1;
    for(int i=0; i<*num_appointments; i++) {
        if(strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    // Check if appointment was found
    if(index == -1) {
        printf("\nNo appointment found with that name.\n");
        return;
    }
    
    // Remove appointment from array
    for(int i=index; i<*num_appointments-1; i++) {
        appointments[i] = appointments[i+1];
    }
    *num_appointments -= 1;
    
    printf("\nAppointment removed!\n");
}

// Define function to find appointments on given date
void find_appointments(Appointment* appointments, int num_appointments) {
    // Get user input for date to search
    char date[MAX_LENGTH];
    printf("\nEnter date to find appointments (MM/DD/YYYY format): ");
    scanf("%s", date);
    
    // Print appointment(s) with matching date
    printf("\nAppointments on %s:\n", date);
    bool found = false;
    for(int i=0; i<num_appointments; i++) {
        if(strcmp(appointments[i].date, date) == 0) {
            printf("%s: %s with %s (%s)\n", 
                appointments[i].time, 
                appointments[i].type, 
                appointments[i].name, 
                appointments[i].date);
            found = true;
        }
    }
    if(!found) {
        printf("No appointments found on that date.\n");
    }
}

int main() {
    // Define variables
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    bool running = true;
    char command[MAX_LENGTH];
    
    // Loop until user quits
    while(running) {
        // Display menu
        printf("\n---Appointment Scheduler---\n");
        printf("1. Display appointments\n");
        printf("2. Add appointment\n");
        printf("3. Remove appointment\n");
        printf("4. Find appointments\n");
        printf("5. Quit\n");
        printf("---------------------------\n");
        printf("Enter command: ");
        scanf("%s", command);
        
        // Choose action based on command
        if(strcmp(command, "1") == 0) {
            display_appointments(appointments, num_appointments);
        } else if(strcmp(command, "2") == 0) {
            add_appointment(appointments, &num_appointments);
        } else if(strcmp(command, "3") == 0) {
            remove_appointment(appointments, &num_appointments);
        } else if(strcmp(command, "4") == 0) {
            find_appointments(appointments, num_appointments);
        } else if(strcmp(command, "5") == 0) {
            running = false;
            printf("\nGoodbye!\n");
        } else {
            printf("\nInvalid command.\n");
        }
    }
    
    return 0;
}