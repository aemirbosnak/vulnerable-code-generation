//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define struct for appointment
typedef struct{
    int month;
    int day;
    int year;
    char description[50];
} Appointment;

// Define function to get input from user
void getInput(Appointment* appt){
    printf("Enter month (1-12): ");
    scanf("%d", &appt->month);
    
    printf("Enter day (1-31): ");
    scanf("%d", &appt->day);
    
    printf("Enter year (1900-2100): ");
    scanf("%d", &appt->year);
    
    printf("Enter description (max 50 characters): ");
    scanf(" %[^\n]", appt->description);
}

// Define function to print appointment details
void printAppointment(Appointment appt){
    printf("\nAppointment Details:\n");
    printf("Date: %d/%d/%d\n", appt.month, appt.day, appt.year);
    printf("Description: %s\n", appt.description);
}

int main(){
    int choice = 0, i = 0;
    bool done = false;
    
    // Allocate memory for appointments array
    Appointment* appointments = malloc(10 * sizeof(Appointment));
    
    // Loop until user chooses to exit
    while(!done){
        printf("\nAppointment Scheduler Menu:\n");
        printf("1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Exit Program\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                // Get input from user for new appointment
                printf("\nEnter Appointment Info:\n");
                getInput(&appointments[i]);
                
                // Increment appointment counter
                i++;
                break;
            case 2:
                // Print all appointments
                if(i == 0){
                    printf("\nNo appointments scheduled.\n");
                } else {
                    printf("\nAll Appointments:\n");
                    for(int j=0; j < i; j++){
                        printAppointment(appointments[j]);
                    }
                }
                break;
            case 3:
                done = true;
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    
    // Free memory for appointments array
    free(appointments);
    
    return 0;
}