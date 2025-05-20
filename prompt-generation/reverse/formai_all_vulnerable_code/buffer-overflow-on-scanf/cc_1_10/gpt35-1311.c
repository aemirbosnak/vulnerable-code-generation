//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define 'Appointment' struct
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char name[50];
} Appointment;

// Function to print a formatted date and time
void printDateTime(int day, int month, int year, int hour, int minute) {
    printf("%02d/%02d/%02d %02d:%02d", day, month, year, hour, minute);
}

// Function to print a list of appointments
void printAppointmentList(Appointment* appts, int numAppts) {
    printf("Schedule:\n");
    for(int i = 0; i < numAppts; i++) {
        printf("%s at ", appts[i].name);
        printDateTime(appts[i].day, appts[i].month, appts[i].year, appts[i].hour, appts[i].minute);
        printf("\n");
    }
}

// Function to add a new appointment
void addAppointment(Appointment* appts, int* numAppts) {
    // Get input from user
    printf("Enter name: ");
    scanf("%s", appts[*numAppts].name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appts[*numAppts].day, &appts[*numAppts].month, &appts[*numAppts].year);
    printf("Enter time (hh:mm): ");
    scanf("%d:%d", &appts[*numAppts].hour, &appts[*numAppts].minute);
    
    // Increment numAppts
    (*numAppts)++;
    
    printf("Appointment registered!\n");
}

int main() {
    // Initialize variables
    Appointment appointments[100];
    int numAppointments = 0;
    int selection = 0;
    
    // Print welcome message
    printf("Welcome to the Appointment Scheduler!\n\n");
    
    // Loop until user quits
    while(selection != 4) {
        // Print menu options
        printf("\nMenu:\n");
        printf("1. View Schedule\n");
        printf("2. Add Appointment\n");
        printf("3. Delete Appointment\n");
        printf("4. Quit\n");
        
        // Get user input
        printf("Enter option: ");
        scanf("%d", &selection);
        
        switch(selection) {
            case 1:
                printAppointmentList(appointments, numAppointments);
                break;
            case 2:
                addAppointment(appointments, &numAppointments);
                break;
            case 3:
                // TODO: Implement delete function
                printf("This feature is not yet implemented. Please try again later.");
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }
    
    return 0;
}