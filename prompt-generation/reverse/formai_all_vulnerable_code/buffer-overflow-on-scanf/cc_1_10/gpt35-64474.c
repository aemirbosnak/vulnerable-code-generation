//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the maximum number of appointments to be allowed
#define MAX_APPOINTMENTS 10

//Define the structure for an appointment
typedef struct {
    char name[50];
    char date[11];
    char time[6];
} Appointment;

//Declare global variables
Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

//Function to add an appointment
void addAppointment() {
    //Check if there is enough space for another appointment
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Sorry, maximum number of appointments reached.\n");
        return;
    }
    
    //Declare variables for appointment details
    char name[50], date[11], time[6];
    
    //Get user input for appointment details
    printf("Enter the name for the appointment:\n");
    scanf("%s", name);
    printf("Enter the date for the appointment (mm/dd/yyyy):\n");
    scanf("%s", date);
    printf("Enter the time for the appointment (hh:mm):\n");
    scanf("%s", time);
    
    //Create a new appointment with the user input
    Appointment newAppointment;
    strcpy(newAppointment.name, name);
    strcpy(newAppointment.date, date);
    strcpy(newAppointment.time, time);
    
    //Add the new appointment to the list of appointments
    appointments[numAppointments] = newAppointment;
    numAppointments++;
    
    //Print message to confirm appointment added
    printf("Appointment added successfully!\n");
}

//Function to view all appointments
void viewAppointments() {
    //Check if there are any appointments
    if (numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    //Print a table of all appointments
    printf("Appointments:\n");
    printf("%-20s %-12s %-8s\n", "Name", "Date", "Time");
    printf("--------------------------------\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%-20s %-12s %-8s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

//Main function
int main() {
    //Declare variable for user choice
    int choice;
    
    //Loop to display menu and get user input
    do {
        printf("\nAppointment Scheduler\n");
        printf("--------------------\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Quit\n\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        
        //Call the appropriate function based on user choice
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);
    
    return 0;
}