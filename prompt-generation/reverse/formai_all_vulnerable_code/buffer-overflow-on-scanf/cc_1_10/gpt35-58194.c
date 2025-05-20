//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_APPOINTMENTS 5

// struct to hold appointment information
typedef struct {
    char client_name[30];
    char date[15];
    char time[10];
} Appointment;

// function to display appointment information
void displayAppointment(Appointment appointment) {
    printf("Appointment details:\n");
    printf("Client Name: %s\n", appointment.client_name);
    printf("Date: %s\n", appointment.date);
    printf("Time: %s\n", appointment.time);
}

int main() {
    freopen ("output.txt", "w", stdout); // redirects output to the output.txt file
    
    printf("Welcome to the Appointment Scheduler!\n\n");
    
    int appointment_count = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    
    int choice;
    
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (appointment_count < MAX_APPOINTMENTS) {
                    // get appointment information from user
                    printf("\nEnter client name: ");
                    scanf("%s", appointments[appointment_count].client_name);
                    printf("Enter date (format: MM/DD/YYYY): ");
                    scanf("%s", appointments[appointment_count].date);
                    printf("Enter time (format: HH:MM AM/PM): ");
                    scanf("%s", appointments[appointment_count].time);
                    
                    // confirm appointment scheduling
                    printf("\nAppointment scheduled successfully!\n");
                    displayAppointment(appointments[appointment_count]);
                    
                    appointment_count++;
                } else {
                    printf("\nSorry, maximum appointments reached.\n");
                }
                break;
                
            case 2:
                if (appointment_count > 0) {
                    // display all appointments
                    printf("\nAll Appointments:\n");
                    for (int i = 0; i < appointment_count; i++) {
                        displayAppointment(appointments[i]);
                    }
                } else {
                    printf("\nNo appointments scheduled yet.\n");
                }
                break;
                
            case 3:
                printf("\nGoodbye!\n");
                break;
            
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}